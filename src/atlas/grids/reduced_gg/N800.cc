// TL1599

#include "atlas/grids/reduced_gg/reduced_gg.h"

namespace atlas {
namespace grids {
namespace reduced_gg {

void N800::construct()
{
  int N=800;
  int lon[] = {
    18,
    25,
    32,
    40,
    45,
    50,
    60,
    60,
    72,
    72,
    75,
    80,
    90,
    90,
    96,
    100,
    108,
    120,
    120,
    125,
    128,
    135,
    144,
    150,
    160,
    160,
    180,
    180,
    192,
    192,
    200,
    200,
    216,
    216,
    225,
    240,
    240,
    240,
    250,
    250,
    256,
    270,
    288,
    288,
    288,
    300,
    300,
    320,
    320,
    320,
    324,
    360,
    360,
    360,
    360,
    360,
    375,
    375,
    375,
    384,
    400,
    400,
    400,
    405,
    432,
    432,
    432,
    432,
    450,
    450,
    450,
    480,
    480,
    480,
    480,
    486,
    500,
    500,
    500,
    512,
    512,
    540,
    540,
    540,
    540,
    576,
    576,
    576,
    576,
    576,
    576,
    600,
    600,
    600,
    625,
    625,
    625,
    625,
    625,
    640,
    640,
    648,
    675,
    675,
    675,
    675,
    720,
    720,
    720,
    720,
    720,
    720,
    720,
    720,
    729,
    750,
    750,
    750,
    768,
    768,
    768,
    800,
    800,
    800,
    800,
    800,
    800,
    810,
    864,
    864,
    864,
    864,
    864,
    864,
    864,
    864,
    864,
    900,
    900,
    900,
    900,
    900,
    900,
    960,
    960,
    960,
    960,
    960,
    960,
    960,
    960,
    960,
    960,
    972,
    972,
    1000,
    1000,
    1000,
    1000,
    1000,
    1024,
    1024,
    1024,
    1024,
    1080,
    1080,
    1080,
    1080,
    1080,
    1080,
    1080,
    1080,
    1080,
    1125,
    1125,
    1125,
    1125,
    1125,
    1125,
    1125,
    1152,
    1152,
    1152,
    1152,
    1152,
    1200,
    1200,
    1200,
    1200,
    1200,
    1200,
    1200,
    1200,
    1215,
    1215,
    1250,
    1250,
    1250,
    1250,
    1250,
    1250,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1296,
    1296,
    1350,
    1350,
    1350,
    1350,
    1350,
    1350,
    1350,
    1350,
    1350,
    1350,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1440,
    1458,
    1458,
    1458,
    1500,
    1500,
    1500,
    1500,
    1500,
    1500,
    1500,
    1500,
    1536,
    1536,
    1536,
    1536,
    1536,
    1536,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1600,
    1620,
    1620,
    1620,
    1620,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1728,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1800,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1875,
    1920,
    1920,
    1920,
    1920,
    1920,
    1920,
    1920,
    1920,
    1920,
    1944,
    1944,
    1944,
    1944,
    1944,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2000,
    2025,
    2025,
    2025,
    2025,
    2025,
    2048,
    2048,
    2048,
    2048,
    2048,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2160,
    2187,
    2187,
    2187,
    2187,
    2187,
    2187,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2250,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2400,
    2430,
    2430,
    2430,
    2430,
    2430,
    2430,
    2430,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2500,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2560,
    2592,
    2592,
    2592,
    2592,
    2592,
    2592,
    2592,
    2592,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2700,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2880,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    2916,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3000,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3072,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3125,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200,
    3200
  };
  double lat[] = {
    89.9139104325669081,
    89.8023885203636780,
    89.6902080109974662,
    89.5778786964386597,
    89.4654929365581921,
    89.3530798626488831,
    89.2406515240936358,
    89.1282137977327693,
    89.0157698889264708,
    88.9033216937618533,
    88.7908704052784969,
    88.6784168115416804,
    88.5659614539728324,
    88.4535047168093769,
    88.3410468802710938,
    88.2285881535182597,
    88.1161286958287064,
    88.0036686306289795,
    87.8912080550420995,
    87.7787470465388253,
    87.6662856676684754,
    87.5538239694856912,
    87.4413619940750806,
    87.3288997764373676,
    87.2164373459200704,
    87.1039747273143661,
    86.9915119417060652,
    86.8790490071431236,
    86.7665859391633489,
    86.6541227512162919,
    86.5416594550029572,
    86.4291960607501721,
    86.3167325774363974,
    86.2042690129764537,
    86.0918053743740046,
    85.9793416678496527,
    85.8668778989467398,
    85.7544140726217137,
    85.6419501933192890,
    85.5294862650371073,
    85.4170222913803627,
    85.3045582756092244,
    85.1920942206784844,
    85.0796301292730561,
    84.9671660038377752,
    84.8547018466040157,
    84.7422376596119165,
    84.6297734447308727,
    84.5173092036771436,
    84.4048449380286172,
    84.2923806492391492,
    84.1799163386500737,
    84.0674520075010463,
    83.9549876569395366,
    83.8425232880292128,
    83.7300589017572605,
    83.6175944990414877,
    83.5051300807360377,
    83.3926656476369885,
    83.2802012004869709,
    83.1677367399798584,
    83.0552722667645611,
    82.9428077814486358,
    82.8303432846014260,
    82.7178787767572601,
    82.6054142584178095,
    82.4929497300547894,
    82.3804851921119763,
    82.2680206450074962,
    82.1555560891353167,
    82.0430915248671511,
    81.9306269525541779,
    81.8181623725280218,
    81.7056977851024868,
    81.5932331905745798,
    81.4807685892254483,
    81.3683039813218585,
    81.2558393671166357,
    81.1433747468498439,
    81.0309101207495530,
    80.9184454890324361,
    80.8059808519046499,
    80.6935162095623468,
    80.5810515621923429,
    80.4685869099725579,
    80.3561222530727690,
    80.2436575916547099,
    80.1311929258728810,
    80.0187282558748763,
    79.9062635818015679,
    79.7937989037876747,
    79.6813342219620893,
    79.5688695364480907,
    79.4564048473637285,
    79.3439401548220644,
    79.2314754589313424,
    79.1190107597955574,
    79.0065460575141856,
    78.8940813521828801,
    78.7816166438933152,
    78.6691519327336266,
    78.5566872187884542,
    78.4442225021391124,
    78.3317577828638321,
    78.2192930610377886,
    78.1068283367333720,
    77.9943636100202582,
    77.8818988809654940,
    77.7694341496336961,
    77.6569694160871364,
    77.5445046803857707,
    77.4320399425875223,
    77.3195752027481120,
    77.2071104609214700,
    77.0946457171594659,
    76.9821809715123919,
    76.8697162240285792,
    76.7572514747548809,
    76.6447867237365728,
    76.5323219710172964,
    76.4198572166393717,
    76.3073924606436549,
    76.1949277030697090,
    76.0824629439557896,
    75.9699981833389586,
    75.8575334212550558,
    75.7450686577388410,
    75.6326038928239370,
    75.5201391265429720,
    75.4076743589275509,
    75.2952095900082554,
    75.1827448198148431,
    75.0702800483760626,
    74.9578152757199092,
    74.8453505018734830,
    74.7328857268630458,
    74.6204209507142053,
    74.5079561734517597,
    74.3954913950997820,
    74.2830266156816919,
    74.1705618352201981,
    74.0580970537373986,
    73.9456322712547944,
    73.8331674877932471,
    73.7207027033730355,
    73.6082379180139128,
    73.4957731317351346,
    73.3833083445553171,
    73.2708435564926504,
    73.1583787675648836,
    73.0459139777891977,
    72.9334491871824042,
    72.8209843957608172,
    72.7085196035403243,
    72.5960548105364580,
    72.4835900167643103,
    72.3711252222385752,
    72.2586604269736341,
    72.1461956309834278,
    72.0337308342816129,
    71.9212660368814767,
    71.8088012387959935,
    71.6963364400377685,
    71.5838716406192077,
    71.4714068405522767,
    71.3589420398487562,
    71.2464772385201144,
    71.1340124365775353,
    71.0215476340319327,
    70.9090828308939791,
    70.7966180271741194,
    70.6841532228825002,
    70.5716884180290691,
    70.4592236126235463,
    70.3467588066754246,
    70.2342940001939695,
    70.1218291931882334,
    70.0093643856670838,
    69.8968995776392177,
    69.7844347691130338,
    69.6719699600969022,
    69.5595051505988380,
    69.4470403406268417,
    69.3345755301885873,
    69.2221107192917060,
    69.1096459079436158,
    68.9971810961515502,
    68.8847162839226144,
    68.7722514712638002,
    68.6597866581819005,
    68.5473218446835517,
    68.4348570307753477,
    68.3223922164636122,
    68.2099274017546264,
    68.0974625866545438,
    67.9849977711693185,
    67.8725329553049050,
    67.7600681390670019,
    67.6476033224612934,
    67.5351385054933360,
    67.4226736881685156,
    67.3102088704921613,
    67.1977440524694885,
    67.0852792341056272,
    66.9728144154055514,
    66.8603495963742063,
    66.7478847770163952,
    66.6354199573368362,
    66.5229551373401904,
    66.4104903170309910,
    66.2980254964137146,
    66.1855606754926953,
    66.0730958542722817,
    65.9606310327566661,
    65.8481662109499695,
    65.7357013888562705,
    65.6232365664795481,
    65.5107717438237245,
    65.3983069208926082,
    65.2858420976900078,
    65.1733772742196038,
    65.0609124504850200,
    64.9484476264898518,
    64.8359828022375950,
    64.7235179777317029,
    64.6110531529755434,
    64.4985883279724419,
    64.3861235027256527,
    64.2736586772384157,
    64.1611938515138576,
    64.0487290255551045,
    63.9362641993651621,
    63.8237993729470503,
    63.7113345463036893,
    63.5988697194379782,
    63.4864048923527662,
    63.3739400650508529,
    63.2614752375349596,
    63.1490104098078220,
    63.0365455818720477,
    62.9240807537303013,
    62.8116159253851336,
    62.6991510968390386,
    62.5866862680945388,
    62.4742214391540784,
    62.3617566100200449,
    62.2492917806948185,
    62.1368269511807014,
    62.0243621214800243,
    61.9118972915949897,
    61.7994324615278785,
    61.6869676312808153,
    61.5745028008559885,
    61.4620379702554800,
    61.3495731394814072,
    61.2371083085357881,
    61.1246434774206548,
    61.0121786461379898,
    60.8997138146897328,
    60.7872489830778449,
    60.6747841513041948,
    60.5623193193706513,
    60.4498544872790546,
    60.3373896550312239,
    60.2249248226289282,
    60.1124599900739298,
    59.9999951573679695,
    59.8875303245127242,
    59.7750654915099062,
    59.6626006583611499,
    59.5501358250680966,
    59.4376709916323307,
    59.3252061580554653,
    59.2127413243390421,
    59.1002764904845961,
    58.9878116564936263,
    58.8753468223676606,
    58.7628819881081625,
    58.6504171537165604,
    58.5379523191942894,
    58.4254874845427778,
    58.3130226497634041,
    58.2005578148575324,
    58.0880929798265271,
    57.9756281446716812,
    57.8631633093943663,
    57.7506984739958256,
    57.6382336384773808,
    57.5257688028402541,
    57.4133039670857031,
    57.3008391312149499,
    57.1883742952292025,
    57.0759094591296403,
    56.9634446229174571,
    56.8509797865938182,
    56.7385149501598463,
    56.6260501136166710,
    56.5135852769654363,
    56.4011204402072011,
    56.2886556033430736,
    56.1761907663741198,
    56.0637259293013770,
    55.9512610921259181,
    55.8387962548487451,
    55.7263314174708810,
    55.6138665799933349,
    55.5014017424170873,
    55.3889369047431046,
    55.2764720669723673,
    55.1640072291058132,
    55.0515423911443946,
    54.9390775530890281,
    54.8266127149406231,
    54.7141478767001033,
    54.6016830383683214,
    54.4892181999462011,
    54.3767533614345808,
    54.2642885228343417,
    54.1518236841463292,
    54.0393588453713463,
    53.9268940065102598,
    53.8144291675638726,
    53.7019643285329806,
    53.5894994894184080,
    53.4770346502209080,
    53.3645698109412834,
    53.2521049715802874,
    53.1396401321386946,
    53.0271752926172368,
    52.9147104530166530,
    52.8022456133376892,
    52.6897807735810559,
    52.5773159337474780,
    52.4648510938376518,
    52.3523862538522735,
    52.2399214137920467,
    52.1274565736576463,
    52.0149917334497189,
    51.9025268931689610,
    51.7900620528160189,
    51.6775972123915466,
    51.5651323718961834,
    51.4526675313305546,
    51.3402026906953139,
    51.2277378499910370,
    51.1152730092183774,
    51.0028081683779106,
    50.8903433274702692,
    50.7778784864960286,
    50.6654136454557573,
    50.5529488043500450,
    50.4404839631794886,
    50.3280191219446138,
    50.2155542806460105,
    50.1030894392842185,
    49.9906245978597923,
    49.8781597563732646,
    49.7656949148251684,
    49.6532300732160365,
    49.5407652315464091,
    49.4283003898167692,
    49.3158355480276569,
    49.2033707061795624,
    49.0909058642730116,
    48.9784410223084663,
    48.8659761802864310,
    48.7535113382074030,
    48.6410464960718230,
    48.5285816538802237,
    48.4161168116330316,
    48.3036519693307156,
    48.1911871269737446,
    48.0787222845625735,
    47.9662574420976497,
    47.8537925995793998,
    47.7413277570083068,
    47.6288629143847757,
    47.5163980717092329,
    47.4039332289821189,
    47.2914683862038530,
    47.1790035433748400,
    47.0665387004955136,
    46.9540738575662715,
    46.8416090145875259,
    46.7291441715596747,
    46.6166793284831158,
    46.5042144853582187,
    46.3917496421854167,
    46.2792847989650653,
    46.1668199556975409,
    46.0543551123832344,
    45.9418902690225082,
    45.8294254256157458,
    45.7169605821633169,
    45.6044957386655625,
    45.4920308951228520,
    45.3795660515355337,
    45.2671012079039627,
    45.1546363642284945,
    45.0421715205094699,
    44.9297066767472302,
    44.8172418329421163,
    44.7047769890944480,
    44.5923121452045734,
    44.4798473012727982,
    44.3673824572994775,
    44.2549176132849382,
    44.1424527692294362,
    44.0299879251333692,
    43.9175230809970003,
    43.8050582368206420,
    43.6925933926046213,
    43.5801285483492151,
    43.4676637040547575,
    43.3551988597215114,
    43.2427340153497823,
    43.1302691709398971,
    43.0178043264921044,
    42.9053394820067027,
    42.7928746374839974,
    42.6804097929242232,
    42.5679449483276997,
    42.4554801036946898,
    42.3430152590254849,
    42.2305504143203265,
    42.1180855695794918,
    42.0056207248032649,
    41.8931558799918946,
    41.7806910351456366,
    41.6682261902647753,
    41.5557613453495449,
    41.4432965004002156,
    41.3308316554170290,
    41.2183668104002408,
    41.1059019653500997,
    40.9934371202668402,
    40.8809722751507039,
    40.7685074300019608,
    40.6560425848208240,
    40.5435777396075423,
    40.4311128943623430,
    40.3186480490854606,
    40.2061832037771225,
    40.0937183584375703,
    39.9812535130670312,
    39.8687886676657115,
    39.7563238222338526,
    39.6438589767716607,
    39.5313941312793631,
    39.4189292857571729,
    39.3064644402053176,
    39.1939995946240032,
    39.0815347490134357,
    38.9690699033738284,
    38.8566050577053943,
    38.7441402120083396,
    38.6316753662828631,
    38.5192105205291710,
    38.4067456747474694,
    38.2942808289379499,
    38.1818159831007975,
    38.0693511372362465,
    37.9568862913444534,
    37.8444214454256382,
    37.7319565994799717,
    37.6194917535076527,
    37.5070269075088802,
    37.3945620614838177,
    37.2820972154326782,
    37.1696323693556110,
    37.0571675232528221,
    36.9447026771244964,
    36.8322378309708043,
    36.7197729847919234,
    36.6073081385880172,
    36.4948432923592918,
    36.3823784461058963,
    36.2699135998280084,
    36.1574487535258058,
    36.0449839071994447,
    35.9325190608491098,
    35.8200542144749505,
    35.7075893680771372,
    35.5951245216558547,
    35.4826596752112380,
    35.3701948287434575,
    35.2577299822526697,
    35.1452651357390451,
    35.0328002892027399,
    34.9203354426439034,
    34.8078705960626991,
    34.6954057494592831,
    34.5829409028337835,
    34.4704760561863850,
    34.3580112095172296,
    34.2455463628264383,
    34.1330815161142027,
    34.0206166693806509,
    33.9081518226259249,
    33.7956869758501668,
    33.6832221290535330,
    33.5707572822361655,
    33.4582924353981923,
    33.3458275885397768,
    33.2333627416610327,
    33.1208978947621162,
    33.0084330478431625,
    32.8959682009043206,
    32.7835033539456759,
    32.6710385069674274,
    32.5585736599696816,
    32.4461088129525734,
    32.3336439659162096,
    32.2211791188607606,
    32.1087142717863330,
    31.9962494246930618,
    31.8837845775810749,
    31.7713197304505108,
    31.6588548833014727,
    31.5463900361340990,
    31.4339251889485389,
    31.3214603417448600,
    31.2089954945232257,
    31.0965306472837604,
    30.9840658000265528,
    30.8716009527517592,
    30.7591361054594792,
    30.6466712581498300,
    30.5342064108229430,
    30.4217415634789248,
    30.3092767161178820,
    30.1968118687399496,
    30.0843470213452093,
    29.9718821739338281,
    29.8594173265058842,
    29.7469524790615054,
    29.6344876316007699,
    29.5220227841237914,
    29.4095579366307653,
    29.2970930891217129,
    29.1846282415967586,
    29.0721633940560018,
    28.9596985464995846,
    28.8472336989275782,
    28.7347688513401067,
    28.6223040037372840,
    28.5098391561191917,
    28.3973743084859471,
    28.2849094608376639,
    28.1724446131744202,
    28.0599797654963155,
    27.9475149178034670,
    27.8350500700959742,
    27.7225852223739437,
    27.6101203746374537,
    27.4976555268866036,
    27.3851906791215214,
    27.2727258313422709,
    27.1602609835489801,
    27.0477961357416952,
    26.9353312879205617,
    26.8228664400856545,
    26.7104015922370479,
    26.5979367443749020,
    26.4854718964992202,
    26.3730070486101589,
    26.2605422007077927,
    26.1480773527921890,
    26.0356125048634652,
    25.9231476569217207,
    25.8106828089670230,
    25.6982179609994503,
    25.5857531130191305,
    25.4732882650261239,
    25.3608234170205122,
    25.2483585690024093,
    25.1358937209718896,
    25.0234288729290242,
    24.9109640248739019,
    24.7984991768066330,
    24.6860343287272777,
    24.5735694806359248,
    24.4611046325326562,
    24.3486397844175677,
    24.2361749362907410,
    24.1237100881522437,
    24.0112452400021503,
    23.8987803918405604,
    23.7863155436675520,
    23.6738506954832069,
    23.5613858472875997,
    23.4489209990807979,
    23.3364561508629045,
    23.2239913026339799,
    23.1115264543941095,
    22.9990616061433819,
    22.8865967578818506,
    22.7741319096096042,
    22.6616670613267281,
    22.5492022130332757,
    22.4367373647293356,
    22.3242725164149860,
    22.2118076680902981,
    22.0993428197553499,
    21.9868779714102018,
    21.8744131230549357,
    21.7619482746896367,
    21.6494834263143687,
    21.5370185779291887,
    21.4245537295342032,
    21.3120888811294336,
    21.1996240327149792,
    21.0871591842909325,
    20.9746943358573468,
    20.8622294874142682,
    20.7497646389617927,
    20.6372997904999806,
    20.5248349420289031,
    20.4123700935486525,
    20.2999052450592394,
    20.1874403965607812,
    20.0749755480533274,
    19.9625106995369705,
    19.8500458510117319,
    19.7375810024777039,
    19.6251161539349468,
    19.5126513053835389,
    19.4001864568235334,
    19.2877216082550156,
    19.1752567596780068,
    19.0627919110926207,
    18.9503270624988929,
    18.8378622138969014,
    18.7253973652866925,
    18.6129325166683408,
    18.5004676680419244,
    18.3880028194074896,
    18.2755379707650967,
    18.1630731221148132,
    18.0506082734566995,
    17.9381434247908160,
    17.8256785761172409,
    17.7132137274360133,
    17.6007488787471900,
    17.4882840300508668,
    17.3758191813470724,
    17.2633543326358705,
    17.1508894839173180,
    17.0384246351915039,
    16.9259597864584599,
    16.8134949377182572,
    16.7010300889709242,
    16.5885652402165604,
    16.4761003914552369,
    16.3636355426869500,
    16.2511706939117850,
    16.1387058451298238,
    16.0262409963411230,
    15.9137761475456916,
    15.8013112987436308,
    15.6888464499349940,
    15.5763816011198255,
    15.4639167522981609,
    15.3514519034701067,
    15.2389870546356949,
    15.1265222057949575,
    15.0140573569479621,
    14.9015925080948097,
    14.7891276592354846,
    14.6766628103700931,
    14.5641979614986692,
    14.4517331126212678,
    14.3392682637379245,
    14.2268034148487441,
    14.1143385659537604,
    14.0018737170529732,
    13.8894088681465142,
    13.7769440192344064,
    13.6644791703166479,
    13.5520143213933970,
    13.4395494724646341,
    13.3270846235304283,
    13.2146197745908278,
    13.1021549256458840,
    12.9896900766956591,
    12.8772252277402064,
    12.7647603787795489,
    12.6522955298137934,
    12.5398306808429485,
    12.4273658318670623,
    12.3149009828862024,
    12.2024361339004201,
    12.0899712849097654,
    11.9775064359142736,
    11.8650415869139891,
    11.7525767379089956,
    11.6401118888993338,
    11.5276470398850410,
    11.4151821908661812,
    11.3027173418427669,
    11.1902524928148850,
    11.0777876437825888,
    10.9653227947458802,
    10.8528579457048977,
    10.7403930966595986,
    10.6279282476100665,
    10.5154633985563333,
    10.4029985494984683,
    10.2905337004365300,
    10.1780688513705346,
    10.0656040023005673,
     9.9531391532266600,
     9.8406743041488323,
     9.7282094550671481,
     9.6157446059816749,
     9.5032797568924607,
     9.3908149077995446,
     9.2783500587029391,
     9.1658852096027204,
     9.0534203604989401,
     8.9409555113916461,
     8.8284906622808670,
     8.7160258131666808,
     8.6035609640491213,
     8.4910961149282027,
     8.3786312658040032,
     8.2661664166765600,
     8.1537015675459212,
     8.0412367184121418,
     7.9287718692752440,
     7.8163070201352935,
     7.7038421709923401,
     7.5913773218464105,
     7.4789124726975551,
     7.3664476235458247,
     7.2539827743912433,
     7.1415179252339023,
     7.0290530760737990,
     6.9165882269110126,
     6.8041233777455679,
     6.6916585285775394,
     6.5791936794069397,
     6.4667288302337971,
     6.3542639810581880,
     6.2417991318801587,
     6.1293342826997534,
     6.0168694335169919,
     5.9044045843319406,
     5.7919397351446378,
     5.6794748859550959,
     5.5670100367634561,
     5.4545451875696651,
     5.3420803383737878,
     5.2296154891759015,
     5.1171506399759901,
     5.0046857907741478,
     4.8922209415704323,
     4.7797560923648366,
     4.6672912431574192,
     4.5548263939482352,
     4.4423615447373335,
     4.3298966955247504,
     4.2174318463105154,
     4.1049669970946780,
     3.9925021478772873,
     3.8800372986584084,
     3.7675724494380400,
     3.6551076002162484,
     3.5426427509930689,
     3.4301779017685790,
     3.3177130525428047,
     3.2052482033156946,
     3.0927833540874392,
     2.9803185048580136,
     2.8678536556274428,
     2.7553888063958158,
     2.6429239571631338,
     2.5304591079294587,
     2.4179942586948169,
     2.3055294094592842,
     2.1930645602228616,
     2.0805997109856498,
     1.9681348617476113,
     1.8556700125088474,
     1.7432051632693839,
     1.6307403140292842,
     1.5182754647885481,
     1.4058106155472403,
     1.2933457663053975,
     1.1808809170630714,
     1.0684160678203256,
     0.9559512185771597,
     0.8434863693336252,
     0.7310215200897852,
     0.6185566708456652,
     0.5060918216013165,
     0.3936269723567895,
     0.2811621231120843,
     0.1686972738673029,
     0.0562324246224324
  };
  setup_lat_hemisphere(N,lon,lat,DEG);
}

} // namespace reduced_gg
} // namespace grids
} // namespace atlas
