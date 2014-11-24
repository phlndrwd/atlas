// TL1151

#include "atlas/grids/reduced_gg/reduced_gg.h"

namespace atlas {
namespace grids {
namespace reduced_gg {

void N576::construct()
{
  int N=576;
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
    81,
    90,
    96,
    96,
    100,
    108,
    120,
    120,
    125,
    135,
    144,
    150,
    160,
    160,
    180,
    180,
    180,
    192,
    192,
    200,
    216,
    216,
    225,
    225,
    240,
    240,
    243,
    250,
    256,
    270,
    270,
    288,
    288,
    288,
    300,
    300,
    320,
    320,
    320,
    360,
    360,
    360,
    360,
    360,
    360,
    375,
    375,
    384,
    384,
    400,
    400,
    400,
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
    480,
    486,
    500,
    500,
    512,
    512,
    540,
    540,
    540,
    540,
    540,
    576,
    576,
    576,
    576,
    576,
    600,
    600,
    600,
    600,
    640,
    640,
    640,
    640,
    640,
    640,
    640,
    648,
    675,
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
    729,
    750,
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
    810,
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
    1200,
    1215,
    1215,
    1215,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1280,
    1296,
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
    1440,
    1440,
    1440,
    1458,
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
    1920,
    1920,
    1920,
    1920,
    1944,
    1944,
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
    2025,
    2025,
    2025,
    2048,
    2048,
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
    2304,
    2304,
    2304,
    2304,
    2304,
    2304,
    2304
  };
  double lat[] = {
    89.8804456827784719,
    89.7255729558526696,
    89.5697856217696824,
    89.4137916389198608,
    89.2577192693127017,
    89.1016089681633332,
    88.9454774686923741,
    88.7893329321878753,
    88.6331798099955535,
    88.4770207352520117,
    88.3208573647545734,
    88.1646907929046932,
    88.0085217715860750,
    87.8523508343970292,
    87.6961783704840201,
    87.5400046703121433,
    87.3838299550740487,
    87.2276543961744437,
    87.0714781284899999,
    86.9153012596060961,
    86.7591238763861270,
    86.6029460497310453,
    86.4467678380840709,
    86.2905892900517415,
    86.1344104463894809,
    85.9782313415253441,
    85.8220520047416784,
    85.6658724611018272,
    85.5096927321836944,
    85.3535128366650326,
    85.1973327907948885,
    85.0411526087758034,
    84.8849723030763812,
    84.7287918846878512,
    84.5726113633365486,
    84.4164307476610247,
    84.2602500453596264,
    84.1040692633152673,
    83.9478884077006171,
    83.7917074840671319,
    83.6355264974216510,
    83.4793454522913123,
    83.3231643527797985,
    83.1669832026155547,
    83.0108020051939093,
    82.8546207636134540,
    82.6984394807075205,
    82.5422581590722757,
    82.3860768010908373,
    82.2298954089546896,
    82.0737139846827688,
    81.9175325301378621,
    81.7613510470415008,
    81.6051695369872050,
    81.4489880014520651,
    81.2928064418071443,
    81.1366248593268864,
    80.9804432551976276,
    80.8242616305246742,
    80.6680799863396203,
    80.5118983236059336,
    80.3557166432247669,
    80.1995349460398188,
    80.0433532328418806,
    79.8871715043728585,
    79.7309897613295817,
    79.5748080043670996,
    79.4186262341016800,
    79.2624444511139785,
    79.1062626559511131,
    78.9500808491294066,
    78.7938990311364051,
    78.6377172024327820,
    78.4815353634542276,
    78.3253535146132265,
    78.1691716563003638,
    78.0129897888859176,
    77.8568079127211661,
    77.7006260281393963,
    77.5444441354573826,
    77.3882622349760680,
    77.2320803269817020,
    77.0758984117467350,
    76.9197164895305434,
    76.7635345605803394,
    76.6073526251317531,
    76.4511706834095719,
    76.2949887356282659,
    76.1388067819927841,
    75.9826248226988525,
    75.8264428579335004,
    75.6702608878757985,
    75.5140789126968883,
    75.3578969325607630,
    75.2017149476243958,
    75.0455329580382369,
    74.8893509639465549,
    74.7331689654876641,
    74.5769869627942938,
    74.4208049559938587,
    74.2646229452087141,
    74.1084409305563696,
    73.9522589121498442,
    73.7960768900977087,
    73.6398948645044413,
    73.4837128354705413,
    73.3275308030927988,
    73.1713487674643375,
    73.0151667286749131,
    72.8589846868109845,
    72.7028026419558415,
    72.5466205941899176,
    72.3904385435906761,
    72.2342564902329229,
    72.0780744341888067,
    71.9218923755280315,
    71.7657103143179143,
    71.6095282506233985,
    71.4533461845073816,
    71.2971641160305438,
    71.1409820452516044,
    70.9847999722273642,
    70.8286178970127338,
    70.6724358196609188,
    70.5162537402232914,
    70.3600716587497743,
    70.2038895752885423,
    70.0477074898863776,
    69.8915254025885133,
    69.7353433134388752,
    69.5791612224800105,
    69.4229791297531875,
    69.2667970352983957,
    69.1106149391544591,
    68.9544328413590648,
    68.7982507419487490,
    68.6420686409590104,
    68.4858865384242961,
    68.3297044343781010,
    68.1735223288528829,
    68.0173402218802892,
    67.8611581134909727,
    67.7049760037147621,
    67.5487938925807043,
    67.3926117801169653,
    67.2364296663509862,
    67.0802475513094407,
    66.9240654350183206,
    66.7678833175028785,
    66.6117011987876708,
    66.4555190788966854,
    66.2993369578531713,
    66.1431548356798800,
    65.9869727123989094,
    65.8307905880317747,
    65.6746084625994513,
    65.5184263361224311,
    65.3622442086206235,
    65.2060620801134263,
    65.0498799506198253,
    64.8936978201582804,
    64.7375156887467966,
    64.5813335564029529,
    64.4251514231439018,
    64.2689692889863409,
    64.1127871539466554,
    63.9566050180407331,
    63.8004228812841419,
    63.6442407436920661,
    63.4880586052793205,
    63.3318764660604288,
    63.1756943260495092,
    63.0195121852603535,
    62.8633300437065188,
    62.7071479014011643,
    62.5509657583571723,
    62.3947836145871619,
    62.2386014701034611,
    62.0824193249180851,
    61.9262371790428290,
    61.7700550324892319,
    61.6138728852684778,
    61.4576907373916512,
    61.3015085888695168,
    61.1453264397126048,
    60.9891442899312466,
    60.8329621395355176,
    60.6767799885353156,
    60.5205978369403113,
    60.3644156847599831,
    60.2082335320035895,
    60.0520513786802113,
    59.8958692247987159,
    59.7396870703678644,
    59.5835049153961549,
    59.4273227598919362,
    59.2711406038634010,
    59.1149584473185499,
    58.9587762902652841,
    58.8025941327112918,
    58.6464119746641117,
    58.4902298161311336,
    58.3340476571196547,
    58.1778654976367164,
    58.0216833376893675,
    57.8655011772844219,
    57.7093190164285588,
    57.5531368551284004,
    57.3969546933903558,
    57.2407725312207845,
    57.0845903686258964,
    56.9284082056117668,
    56.7722260421843927,
    56.6160438783496431,
    56.4598617141132522,
    56.3036795494808970,
    56.1474973844581342,
    55.9913152190503922,
    55.8351330532630072,
    55.6789508871012515,
    55.5227687205702836,
    55.3665865536751625,
    55.2104043864208549,
    55.0542222188122636,
    54.8980400508541493,
    54.7418578825512654,
    54.5856757139082305,
    54.4294935449295920,
    54.2733113756198051,
    54.1171292059832894,
    53.9609470360243719,
    53.8047648657472450,
    53.6485826951561222,
    53.4924005242551104,
    53.3362183530482170,
    53.1800361815394140,
    53.0238540097325810,
    52.8676718376315762,
    52.7114896652401512,
    52.5553074925620152,
    52.3991253196008060,
    52.2429431463601048,
    52.0867609728434644,
    51.9305787990543308,
    51.7743966249961147,
    51.6182144506721770,
    51.4620322760858144,
    51.3058501012402743,
    51.1496679261387754,
    50.9934857507844441,
    50.8373035751803855,
    50.6811213993296477,
    50.5249392232352292,
    50.3687570469000931,
    50.2125748703271455,
    50.0563926935192285,
    49.9002105164791701,
    49.7440283392097555,
    49.5878461617137276,
    49.4316639839937508,
    49.2754818060524897,
    49.1192996278925520,
    48.9631174495165169,
    48.8069352709268998,
    48.6507530921262088,
    48.4945709131168883,
    48.3383887339013683,
    48.1822065544820290,
    48.0260243748612510,
    47.8698421950412865,
    47.7136600150244803,
    47.5574778348130636,
    47.4012956544092248,
    47.2451134738151808,
    47.0889312930330632,
    46.9327491120650109,
    46.7765669309130843,
    46.6203847495793937,
    46.4642025680659430,
    46.3080203863747286,
    46.1518382045077615,
    45.9956560224669531,
    45.8394738402542430,
    45.6832916578715142,
    45.5271094753206498,
    45.3709272926034970,
    45.2147451097218607,
    45.0585629266775243,
    44.9023807434722784,
    44.7461985601078496,
    44.5900163765859716,
    44.4338341929083356,
    44.2776520090766255,
    44.1214698250924755,
    43.9652876409575342,
    43.8091054566734144,
    43.6529232722416651,
    43.4967410876638993,
    43.3405589029416447,
    43.1843767180764289,
    43.0281945330697511,
    42.8720123479231177,
    42.7158301626379782,
    42.5596479772157963,
    42.4034657916579718,
    42.2472836059659471,
    42.0911014201411078,
    41.9349192341848251,
    41.7787370480984706,
    41.6225548618833727,
    41.4663726755408604,
    41.3101904890722338,
    41.1540083024788075,
    40.9978261157618320,
    40.8416439289225934,
    40.6854617419623210,
    40.5292795548822440,
    40.3730973676835774,
    40.2169151803675220,
    40.0607329929352645,
    39.9045508053879843,
    39.7483686177268183,
    39.5921864299529247,
    39.4360042420674262,
    39.2798220540714524,
    39.1236398659660907,
    38.9674576777524351,
    38.8112754894315657,
    38.6550933010045412,
    38.4989111124724204,
    38.3427289238362405,
    38.1865467350970107,
    38.0303645462557753,
    37.8741823573135221,
    37.7180001682712529,
    37.5618179791299340,
    37.4056357898905603,
    37.2494536005540695,
    37.0932714111214068,
    36.9370892215935100,
    36.7809070319713385,
    36.6247248422557732,
    36.4685426524477379,
    36.3123604625481136,
    36.1561782725578027,
    35.9999960824776721,
    35.8438138923085816,
    35.6876317020514051,
    35.5314495117069811,
    35.3752673212761550,
    35.2190851307597512,
    35.0629029401586081,
    34.9067207494735001,
    34.7505385587052658,
    34.5943563678546653,
    34.4381741769225371,
    34.2819919859096203,
    34.1258097948166963,
    33.9696276036445255,
    33.8134454123938539,
    33.6572632210654419,
    33.5010810296600070,
    33.3448988381783025,
    33.1887166466210530,
    33.0325344549889550,
    32.8763522632827261,
    32.7201700715030768,
    32.5639878796506821,
    32.4078056877262526,
    32.2516234957304633,
    32.0954413036639323,
    31.9392591115274236,
    31.7830769193215410,
    31.6268947270469312,
    31.4707125347042656,
    31.3145303422941694,
    31.1583481498172681,
    31.0021659572742436,
    30.8459837646656432,
    30.6898015719921382,
    30.5336193792543327,
    30.3774371864527915,
    30.2212549935881576,
    30.0650728006610066,
    29.9088906076719496,
    29.7527084146215195,
    29.5965262215103202,
    29.4403440283389273,
    29.2841618351079056,
    29.1279796418178059,
    28.9717974484691823,
    28.8156152550626032,
    28.6594330615986195,
    28.5032508680777354,
    28.3470686745005018,
    28.1908864808674622,
    28.0347042871791423,
    27.8785220934360396,
    27.7223398996387047,
    27.5661577057876315,
    27.4099755118833137,
    27.2537933179262559,
    27.0976111239170017,
    26.9414289298559773,
    26.7852467357437334,
    26.6290645415807035,
    26.4728823473674275,
    26.3167001531043319,
    26.1605179587919352,
    26.0043357644306390,
    25.8481535700209655,
    25.6919713755633694,
    25.5357891810582984,
    25.3796069865062037,
    25.2234247919075472,
    25.0672425972627728,
    24.9110604025723106,
    24.7548782078365974,
    24.5986960130560846,
    24.4425138182312125,
    24.2863316233623756,
    24.1301494284500109,
    23.9739672334945837,
    23.8177850384964565,
    23.6616028434560626,
    23.5054206483738177,
    23.3492384532501518,
    23.1930562580854307,
    23.0368740628800630,
    22.8806918676344715,
    22.7245096723490398,
    22.5683274770241589,
    22.4121452816602229,
    22.2559630862576050,
    22.0997808908167244,
    21.9435986953379434,
    21.7874164998216209,
    21.6312343042681690,
    21.4750521086779287,
    21.3188699130512909,
    21.1626877173886285,
    21.0065055216902863,
    20.8503233259566230,
    20.6941411301880471,
    20.5379589343848608,
    20.3817767385474369,
    20.2255945426761379,
    20.0694123467713013,
    19.9132301508332858,
    19.7570479548624505,
    19.6008657588590971,
    19.4446835628236236,
    19.2885013667563001,
    19.1323191706575031,
    18.9761369745275736,
    18.8199547783668173,
    18.6637725821756035,
    18.5075903859541988,
    18.3514081897030046,
    18.1952259934222909,
    18.0390437971123916,
    17.8828616007736265,
    17.7266794044063118,
    17.5704972080107673,
    17.4143150115873233,
    17.2581328151362321,
    17.1019506186578809,
    16.9457684221525327,
    16.7895862256204929,
    16.6334040290620884,
    16.4772218324775785,
    16.3210396358673222,
    16.1648574392316000,
    16.0086752425706926,
    15.8524930458848790,
    15.6963108491744965,
    15.5401286524398028,
    15.3839464556811141,
    15.2277642588987021,
    15.0715820620928689,
    14.9153998652639004,
    14.7592176684120613,
    14.6030354715376394,
    14.4468532746409295,
    14.2906710777222212,
    14.1344888807817579,
    13.9783066838198344,
    13.8221244868367403,
    13.6659422898327314,
    13.5097600928080972,
    13.3535778957630971,
    13.1973956986979815,
    13.0412135016130701,
    12.8850313045085940,
    12.7288491073848302,
    12.5726669102420221,
    12.4164847130804841,
    12.2603025159004240,
    12.1041203187021456,
    11.9479381214858797,
    11.7917559242519161,
    11.6355737270004695,
    11.4793915297318385,
    11.3232093324462593,
    11.1670271351439911,
    11.0108449378252846,
    10.8546627404904079,
    10.6984805431396044,
    10.5422983457731227,
    10.3861161483911868,
    10.2299339509940861,
    10.0737517535820498,
     9.9175695561553319,
     9.7613873587141740,
     9.6052051612588301,
     9.4490229637895311,
     9.2928407663065293,
     9.1366585688100681,
     8.9804763713003624,
     8.8242941737777052,
     8.6681119762422885,
     8.5119297786944053,
     8.3557475811342048,
     8.1995653835620210,
     8.0433831859780422,
     7.8872009883825136,
     7.7310187907756855,
     7.5748365931577526,
     7.4186543955289919,
     7.2624721978896218,
     7.1062900002398699,
     6.9501078025799545,
     6.7939256049101528,
     6.6377434072306558,
     6.4815612095417201,
     6.3253790118435615,
     6.1691968141363942,
     6.0130146164204739,
     5.8568324186960306,
     5.7006502209632526,
     5.5444680232224224,
     5.3882858254737309,
     5.2321036277174189,
     5.0759214299537003,
     4.9197392321828080,
     4.7635570344049700,
     4.6073748366204264,
     4.4511926388293563,
     4.2950104410320149,
     4.1388282432286161,
     3.9826460454194170,
     3.8264638476045829,
     3.6702816497843909,
     3.5140994519590221,
     3.3579172541287043,
     3.2017350562936917,
     3.0455528584541502,
     2.8893706606103717,
     2.7331884627625098,
     2.5770062649108310,
     2.4208240670555394,
     2.2646418691968382,
     2.1084596713349821,
     1.9522774734701485,
     1.7960952756025925,
     1.6399130777325301,
     1.4837308798601527,
     1.3275486819857139,
     1.1713664841094178,
     1.0151842862314806,
     0.8590020883521183,
     0.7028198904715476,
     0.5466376925899971,
     0.3904554947076834,
     0.2342732968248227,
     0.0780910989416438
  };
  setup_lat_hemisphere(N,lon,lat,DEG);
}

} // namespace reduced_gg
} // namespace grids
} // namespace atlas
