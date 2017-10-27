/*
 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @author Willem Deconinck
/// @date   Nov 2013

#ifndef HaloExchange_h
#define HaloExchange_h

#include <string>
#include <vector>
#include <stdexcept>

#include "eckit/memory/SharedPtr.h"
#include "eckit/memory/Owned.h"
#include "eckit/exception/Exceptions.h"
#include "atlas/parallel/mpi/mpi.h"
#include "atlas/parallel/mpi/Statistics.h"

#include "atlas/array/ArrayView.h"
#include "atlas/array/SVector.h"
#include "atlas/runtime/Log.h"

namespace atlas {
namespace parallel {

class HaloExchange: public eckit::Owned {

public: // types
    typedef eckit::SharedPtr<HaloExchange> Ptr;
public:
  HaloExchange();
  HaloExchange(const std::string& name);
  virtual ~HaloExchange() {}

public: // methods

  const std::string& name() const { return name_; }

  void setup( const int part[],
              const int remote_idx[], const int base,
              size_t size );

  template <typename DATA_TYPE, int RANK>
  void execute( array::ArrayView<DATA_TYPE, RANK>& field, const size_t var_strides[], const size_t var_shape[], size_t var_rank ) const;

  template <typename DATA_TYPE>
  void execute( DATA_TYPE field[], size_t nb_vars ) const;

  template <typename DATA_TYPE, int RANK>
  void execute( array::ArrayView<DATA_TYPE,RANK>& field ) const;

  template <typename DATA_TYPE, int RANK>
  void execute( array::ArrayView<DATA_TYPE,RANK>&& field ) const;


private: // methods

  void create_mappings( std::vector<int>& send_map, std::vector<int>& recv_map, size_t nb_vars ) const;

  template<int N, int P>
  void create_mappings_impl( std::vector<int>& send_map, std::vector<int>& recv_map, size_t nb_vars ) const;

  size_t index(size_t i, size_t j, size_t k, size_t ni, size_t nj, size_t nk) const { return( i + ni*( j + nj*k) ); }

  size_t index(size_t i, size_t j, size_t ni, size_t nj) const { return( i + ni*j ); }


  template< typename DATA_TYPE, int RANK>
  void pack_send_buffer( const array::ArrayView<DATA_TYPE, RANK>& field,
                         const size_t var_strides[],
                         const size_t var_shape[],
                         size_t var_rank,
                         array::SVector<DATA_TYPE>& send_buffer ) const;

  template< typename DATA_TYPE, int RANK>
  void pack_send_cuda( const array::ArrayView<DATA_TYPE, RANK>& field,
                                       const size_t var_strides[],
                                       const size_t var_shape[],
                                       size_t var_rank,
                                       array::SVector<DATA_TYPE>& send_buffer ) const;
  template< typename DATA_TYPE, int RANK>
  void unpack_recv_buffer(const array::SVector<DATA_TYPE>& recv_buffer,
                          array::ArrayView<DATA_TYPE, RANK>& field,
                          const size_t var_strides[],
                          const size_t var_shape[],
                          size_t var_rank ) const;

  template<typename DATA_TYPE, int RANK>
  void var_info( const array::ArrayView<DATA_TYPE,RANK>& arr,
                 std::vector<size_t>& varstrides,
                 std::vector<size_t>& varshape ) const;

private: // data
  std::string name_;
  bool is_setup_;

  int               sendcnt_;
  int               recvcnt_;
  std::vector<int>  sendcounts_;
  std::vector<int>  senddispls_;
  std::vector<int>  recvcounts_;
  std::vector<int>  recvdispls_;
  array::SVector<int>  sendmap_;
  std::vector<int>  recvmap_;
  int parsize_;

  int nproc;
  int myproc;

  std::vector<int> bounds_;
  int par_bound_;

};


template<typename DATA_TYPE, int RANK>
void HaloExchange::execute(array::ArrayView<DATA_TYPE, RANK>& field, const size_t var_strides[], const size_t var_shape[], size_t var_rank ) const
{
  if( ! is_setup_ )
  {
    throw eckit::SeriousBug("HaloExchange was not setup",Here());
  }

  ATLAS_TRACE("HaloExchange",{"halo-exchange"});

  int tag=1;
  size_t var_size = std::accumulate(var_shape,var_shape+var_rank,1,std::multiplies<size_t>());
  int send_size  = sendcnt_ * var_size;
  int recv_size  = recvcnt_ * var_size;

  array::SVector<DATA_TYPE  > send_buffer(send_size);
  array::SVector<DATA_TYPE  > recv_buffer(recv_size);
  std::vector<int        > send_displs(nproc    );
  std::vector<int        > recv_displs(nproc    );
  std::vector<int        > send_counts(nproc    );
  std::vector<int        > recv_counts(nproc    );

  std::vector<eckit::mpi::Request> send_req(nproc    );
  std::vector<eckit::mpi::Request> recv_req(nproc    );

  for (int jproc=0; jproc < nproc; ++jproc)
  {
    send_counts[jproc] = sendcounts_[jproc]*var_size;
    recv_counts[jproc] = recvcounts_[jproc]*var_size;
    send_displs[jproc] = senddispls_[jproc]*var_size;
    recv_displs[jproc] = recvdispls_[jproc]*var_size;
  }

  ATLAS_TRACE_MPI( IRECEIVE ) {
    /// Let MPI know what we like to receive
    for(int jproc=0; jproc < nproc; ++jproc)
    {
      if(recv_counts[jproc] > 0)
      {
          recv_req[jproc] = parallel::mpi::comm().iReceive(&recv_buffer[recv_displs[jproc]], recv_counts[jproc], jproc, tag);
      }
    }
  }

  /// Pack
  pack_send_buffer(field,var_strides,var_shape,var_rank,send_buffer);

  /// Send
  ATLAS_TRACE_MPI( ISEND ) {
    for(int jproc=0; jproc < nproc; ++jproc)
    {
      if(send_counts[jproc] > 0)
      {
          send_req[jproc] = parallel::mpi::comm().iSend(
              &send_buffer[send_displs[jproc]],
              send_counts[jproc], jproc, tag);
      }
    }
  }

  /// Wait for receiving to finish
  ATLAS_TRACE_MPI( WAIT, "mpi-wait receive" ) {
    for (int jproc=0; jproc < nproc; ++jproc)
    {
      if( recvcounts_[jproc] > 0)
      {
          parallel::mpi::comm().wait(recv_req[jproc]);
      }
    }
  }

  /// Unpack
  unpack_recv_buffer(recv_buffer,field,var_strides,var_shape,var_rank);

  /// Wait for sending to finish
  ATLAS_TRACE_MPI( WAIT, "mpi-wait send" ) {
    for (int jproc=0; jproc < nproc; ++jproc)
    {
      if( sendcounts_[jproc] > 0)
      {
          parallel::mpi::comm().wait(send_req[jproc]);
      }
    }
  }
}

#ifdef ATLAS_GRIDTOOLS_STORAGE_BACKEND_CUDA
#ifdef __CUDACC__
template<typename DATA_TYPE, int RANK>
__global__ void pack_kernel(int sendcnt, array::SVector<int> sendmap,
         const array::ArrayView<DATA_TYPE, RANK> field, array::SVector<DATA_TYPE> send_buffer) {

    const size_t p = blockIdx.x*blockDim.x + threadIdx.x;
    const size_t i = blockIdx.y*blockDim.y + threadIdx.y;

    if(p >= sendcnt || i >= field.data_view().template length<1>() ) return;

    const size_t buff_idx = field.data_view().template length<1>() * p + i;

    send_buffer[buff_idx] = field.data(p, i);
}

template<typename DATA_TYPE, int RANK>
void HaloExchange::pack_send_cuda( const array::ArrayView<DATA_TYPE, RANK>& field,
                                     const size_t var_strides[],
                                     const size_t var_shape[],
                                     size_t var_rank,
                                     array::SVector<DATA_TYPE>& send_buffer ) const
{
    const unsigned int block_size_x = 32;
    const unsigned int block_size_y = 4;
    dim3 threads(block_size_x, block_size_y);
    dim3 blocks((sendcnt_+block_size_x-1)/block_size_x, (var_shape[0]+block_size_y-1)/block_size_y);

    pack_kernel<<<blocks,threads>>>(sendcnt_, sendmap_, field, send_buffer);
}
#endif
#endif

template<int RANK>
struct halo_packer;

template<>
struct halo_packer<1>
{
    template<typename DATA_TYPE>
    static void pack(const unsigned int sendcnt, array::SVector<int> const & sendmap,
                     const array::ArrayView<DATA_TYPE, 1>& field, array::SVector<DATA_TYPE>& send_buffer )
    {
      size_t ibuf = 0;
      for(int p=0; p < sendcnt; ++p)
      {
        const size_t pp = sendmap[p];
        send_buffer[ibuf++] = field(pp);
      }
    }
};

template<>
struct halo_packer<2>
{
    template<typename DATA_TYPE>
    static void pack(const unsigned int sendcnt, array::SVector<int> const & sendmap, const array::ArrayView<DATA_TYPE, 2>& field, array::SVector<DATA_TYPE>& send_buffer )
    {
      size_t ibuf = 0;

      for(int p=0; p < sendcnt; ++p)
      {
        const size_t pp = sendmap[p];
        for( size_t i=0; i< field.data_view().template length<1>(); ++i ) {
          send_buffer[ibuf++] = field(pp, i);
        }
      }
    }
};

template<>
struct halo_packer<3>
{
    template<typename DATA_TYPE>
    static void pack(const unsigned int sendcnt, array::SVector<int> const & sendmap, const array::ArrayView<DATA_TYPE, 3>& field, array::SVector<DATA_TYPE>& send_buffer )
    {
      size_t ibuf = 0;
      for(int p=0; p < sendcnt; ++p)
      {
        const size_t pp = sendmap[p];
        for( size_t i=0; i< field.data_view().template length<1>(); ++i ) {
          for( size_t j=0; j< field.data_view().template length<2>(); ++j ) {
              send_buffer[ibuf++] = field(pp, i,j);
          }
        }
      }
    }
};

template<>
struct halo_packer<4>
{
    template<typename DATA_TYPE>
    static void pack(const unsigned int sendcnt, array::SVector<int> const & sendmap, const array::ArrayView<DATA_TYPE, 4>& field, array::SVector<DATA_TYPE>& send_buffer )
    {
        size_t ibuf = 0;
        for(int p=0; p < sendcnt; ++p)
        {
          const size_t pp = sendmap[p];
          for( size_t i=0; i< field.data_view().template length<1>(); ++i ) {
            for( size_t j=0; j< field.data_view().template length<2>(); ++j ) {
                for( size_t k=0; k< field.data_view().template length<3>(); ++k ) {

                send_buffer[ibuf++] = field(pp,i,j,k);
                }
            }
          }
        }
    }
};

template<typename DATA_TYPE, int RANK>
void HaloExchange::pack_send_buffer( const array::ArrayView<DATA_TYPE, RANK>& field,
                                     const size_t var_strides[],
                                     const size_t var_shape[],
                                     size_t var_rank,
                                     array::SVector<DATA_TYPE>& send_buffer ) const
{
  ATLAS_TRACE();
  size_t ibuf = 0;
  size_t send_stride = var_strides[0]*var_shape[0];

  switch( RANK )
  {
  case 1:
#if ATLAS_GRIDTOOLS_STORAGE_BACKEND_CUDA
    pack_send_cuda(field,  var_strides, var_shape, var_rank, send_buffer);
#else
    halo_packer<RANK>::pack(sendcnt_, sendmap_, field, send_buffer);
#endif
    std::cout << parallel::mpi::comm().rank() << " END IF " << std::endl;
    break;
  case 2:
    halo_packer<RANK>::pack(sendcnt_, sendmap_, field, send_buffer);
    break;
  case 3:
    halo_packer<RANK>::pack(sendcnt_, sendmap_, field, send_buffer);
    break;
  case 4:
    halo_packer<RANK>::pack(sendcnt_, sendmap_, field, send_buffer);
    break;
  default:
    NOTIMP;
  }
}

template<typename DATA_TYPE, int RANK>
void HaloExchange::unpack_recv_buffer( const array::SVector<DATA_TYPE>& recv_buffer,
                                       array::ArrayView<DATA_TYPE,RANK>& field,
                                       const size_t var_strides[],
                                       const size_t var_shape[],
                                       size_t var_rank ) const
{
  ATLAS_TRACE();
//  bool field_changed = false;
//  DATA_TYPE tmp;
  size_t ibuf = 0;
  size_t recv_stride = var_strides[0]*var_shape[0];

  switch( var_rank )
  {
  case 1:
    for(int p=0; p < recvcnt_; ++p)
    {
      const size_t pp = recv_stride*recvmap_[p];
      for( size_t i=0; i<var_shape[0]; ++i)
      {
//        tmp = field[ pp + i*var_strides[0] ];
        field.data()[ pp + i*var_strides[0] ] = recv_buffer[ibuf++];
//        if( tmp != field[ pp + i*var_strides[0] ] )
//          field_changed = true;
      }
    }
    break;
  case 2:
    for(int p=0; p < recvcnt_; ++p)
    {
      const size_t pp = recv_stride*recvmap_[p];
      for( size_t i=0; i<var_shape[0]; ++i )
      {
        for( size_t j=0; j<var_shape[1]; ++j )
        {
//          tmp = field[ pp + i*var_strides[0] + j*var_strides[1] ];
          field.data()[ pp + i*var_strides[0] + j*var_strides[1] ]
              = recv_buffer[ibuf++];
//          if( field[ pp + i*var_strides[0] + j*var_strides[1] ] != tmp )
//            field_changed = true;
        }
      }
    }
    break;
  case 3:
    for(int p=0; p < recvcnt_; ++p)
    {
      const size_t pp = recv_stride*recvmap_[p];
      for( size_t i=0; i<var_shape[0]; ++i )
      {
        for( size_t j=0; j<var_shape[1]; ++j )
        {
          for( size_t k=0; k<var_shape[2]; ++k )
          {
//            tmp = field[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] ];
            field.data()[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] ]
                = recv_buffer[ibuf++];
//            if( field[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] ] != tmp )
//              field_changed = true;
          }
        }
      }
    }
    break;
  case 4:
    for(int p=0; p < recvcnt_; ++p)
    {
      const size_t pp = recv_stride*recvmap_[p];
      for( size_t i=0; i<var_shape[0]; ++i )
      {
        for( size_t j=0; j<var_shape[1]; ++j )
        {
          for( size_t k=0; k<var_shape[2]; ++k )
          {
           for( size_t l=0; l<var_shape[3]; ++l )
           {
//            tmp = field[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] +l*var_strides[3] ];
            field.data()[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] + l*var_strides[3] ]
                = recv_buffer[ibuf++];
//            if( field[ pp + i*var_strides[0] + j*var_strides[1] + k*var_strides[2] +l*var_strides[3] ] != tmp )
//              field_changed = true;
           }
          }
        }
      }
    }
    break;
  default:
    NOTIMP;
  }
//  if( !field_changed )
//    std::cout << "WARNING: halo-exchange did not change field" << std::endl;
}

template<typename DATA_TYPE>
void HaloExchange::execute( DATA_TYPE field[], size_t nb_vars ) const
{
    throw eckit::AssertionFailed("Call not supported");

//  size_t strides[] = {1};
//  size_t shape[] = {nb_vars};
//  execute( field, strides, shape, 1);
}


template<typename DATA_TYPE, int RANK>
void HaloExchange::var_info( const array::ArrayView<DATA_TYPE,RANK>& arr,
                             std::vector<size_t>& varstrides,
                             std::vector<size_t>& varshape ) const
{
  int rank = std::max(1,RANK-1) ;
  varstrides.resize(rank);
  varshape.resize(rank);

  if( RANK>1 )
  {
    size_t stride=1;
    for( int j=RANK-1; j>0; --j ) {
      varstrides[j-1] = stride;
      varshape[j-1] = arr.shape(j);
      stride *= varshape[j-1];
    }
//    varstrides.assign(arr.strides()+1,arr.strides()+RANK);
//    varshape.assign(arr.shape()+1,arr.shape()+RANK);
  }
  else
  {
    varstrides[0] = 1;
    varshape[0] = 1;
  }
}

template <typename DATA_TYPE, int RANK>
void HaloExchange::execute( array::ArrayView<DATA_TYPE,RANK>&& field ) const
{
    execute(field);
}
template <typename DATA_TYPE, int RANK>
void HaloExchange::execute( array::ArrayView<DATA_TYPE,RANK>& field ) const
{
  //if( field.shape(0) == parsize_)
  if( true ){
    std::vector<size_t> varstrides, varshape;
    var_info( field, varstrides, varshape );
    execute( field, varstrides.data(), varshape.data(), varstrides.size() );
  }
  else
  {
    Log::error() << "Passed field with rank " << RANK << " and shape(0) " << field.shape(0) << std::endl;
    Log::error() << "parsize_ = " << parsize_ << std::endl;
    NOTIMP; // Need to implement with parallel ranks > 1
  }
}

//----------------------------------------------------------------------------------------------------------------------
// C wrapper interfaces to C++ routines
extern "C"
{
  HaloExchange* atlas__HaloExchange__new ();
  void atlas__HaloExchange__delete (HaloExchange* This);
  void atlas__HaloExchange__setup (HaloExchange* This, int part[], int remote_idx[], int base, int size);
  void atlas__HaloExchange__execute_strided_int (HaloExchange* This, int field[], int var_strides[], int var_shape[], int var_rank);
  void atlas__HaloExchange__execute_strided_long (HaloExchange* This, long field[], int var_strides[], int var_shape[], int var_rank);
  void atlas__HaloExchange__execute_strided_float (HaloExchange* This, float field[], int var_strides[], int var_shape[], int var_rank);
  void atlas__HaloExchange__execute_strided_double (HaloExchange* This, double field[], int var_strides[], int var_shape[], int var_rank);
  void atlas__HaloExchange__execute_int (HaloExchange* This, int field[], int var_rank);
  void atlas__HaloExchange__execute_float (HaloExchange* This, float field[], int var_rank);
  void atlas__HaloExchange__execute_double (HaloExchange* This, double field[], int var_rank);

}

//----------------------------------------------------------------------------------------------------------------------

} // namespace parallel
} // namespace atlas

#endif // HaloExchange_h
