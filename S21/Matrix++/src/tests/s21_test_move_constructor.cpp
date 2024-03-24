#include "s21_test.h"

TEST(MatrixMoveConstructorTest, MoveConstructor1) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -3.5384034927476193, -0.4477221551645947, -4.268247053346828,
      2.4437953819151357,  -1.4689422299577815, 0.22305195062754546,
      2.8300307242550824,  2.815913171225187,   -1.8564359147245888,
      2.6270323764785077,  1.9712260169973632,  1.2236911391276353,
      -1.3291379807049717, -1.1209298949117033, -3.0813222514521676};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor2) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      4.757053877510181,   -3.476376792047847,  -0.5330185512907555,
      -2.1607038831218297, 4.585803052506236,   -4.957125914898909,
      -1.2035656598774223, -2.5935410152985607, 0.9877881577502814,
      2.722266759594265,   -1.9396794560376507, -2.7612615729202536,
      0.6295961487594024,  -4.668825489236199,  1.3312707035853801,
      3.2950521746575827,  1.9461247585522674,  -0.3233926000384111,
      -0.5619994775932913, -0.5087784689032642, 1.7868207523949025,
      -3.459346444282605,  3.908381398913937,   -0.6565302051274999,
      -3.3697856054293087, -1.0959880193789395, 4.374085512196313,
      -3.9958159448016084, 1.1205816742709152,  -3.8825578264913063,
      -0.913913055650676,  0.8612504591750305,  2.7056316310648665,
      -2.538960345447492,  -0.950048531395594,  1.5514687104585567};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor3) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-2.5076729239456075,  -0.1257415222143674,
                                4.079788937509965,    -3.6187530644276222,
                                -4.963015675009164,   -4.317793379244033,
                                -0.26170762285830396, 2.2711420833877636,
                                -2.8662328346480646,  0.28846761221453576};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor4) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      3.9714171249735966, -1.924582017353976, -4.566144289138986,
      -3.335407668107581, 4.012593700673502,  -3.3591812949049196,
      -4.229941222791149, 4.482699859331621,  -4.580727394257007,
      4.321459256826984,  -4.088743382907351, 4.783462667872174};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor5) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      -1.0269166207471292,   1.9286107625775806,  -1.7917909150284395,
      -1.284607202348731,    -0.3191659520859371, 4.35604394691341,
      1.271168484445706,     3.1205059861720983,  1.481692377277012,
      -1.7499196472027654,   -4.635268650229783,  -2.3941374886193403,
      4.099793541739743,     4.390058044456648,   4.530056239100681,
      -0.026953015566199667, -3.7935676906117255, 2.71798221021011,
      -2.025352664137443,    2.5322622032023876,  -2.22950697535408,
      3.398683922923885,     -1.9784412929964112, 4.013573037478968,
      4.340872938331442,     -4.959034311025469,  -1.6227444665772026,
      3.868483231273567,     -3.2689709494099137, -2.120631301885265};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor6) {
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      2.9888837038047154,  -1.3958445128723218, 4.586291554614165,
      -2.831581851596763,  -3.337281144608595,  -4.519641500044087,
      1.806149958320713,   1.010310515008542,   4.95560165404973,
      -3.182180829865142,  -1.6850306545272966, -3.03671473639485,
      -1.0607267118721317, -4.331412937028523,  0.8452047993302862,
      0.3703535387646255,  4.117811633676917,   0.6778043710515753};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor7) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{-0.1302783862075838, 0.5029459233550053,
                               -0.6194919770184351, 0.27622558716618695,
                               1.0585777116650537,  -1.2519080170888075,
                               4.618084686187885,   -4.409730629182867};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor8) {
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{-2.87380206636663, -1.2345258102589582, 0.856218673618959,
                    2.104731969542435, 1.7581778008183644,  1.5393699242688674};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor9) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{
      1.0326534651784867,   1.638184446741021,   -4.790046386518578,
      -2.7368974363592447,  -4.89890516504759,   -3.454666999389663,
      3.0025858963319116,   -3.0044820432641375, -2.355033064055653,
      -4.184581118866609,   3.9641474009335944,  -1.4133301897888142,
      -0.34775965990711377, 4.980195381839787,   -0.8563700355145833,
      2.439125555906503,    1.7765839776901027,  4.24523685075879,
      0.6435851293364658,   0.661870556748994,   -2.6302810753228,
      -2.3760523424837023,  3.076986925690372,   2.621171507147814};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor10) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      0.21321197915233103,  -4.190148144703892,  1.3251754179465465,
      2.4295534694062706,   1.5659911414259824,  0.5352866710925692,
      -0.46377109245817305, -4.484137353067455,  4.226819774585929,
      3.71691381707193,     3.3023337737297815,  -3.820239702723497,
      1.2948267686388935,   2.4424466523722907,  0.45558084257411835,
      -3.7162804109529093,  -3.6102904904661868, 1.676478961678213,
      2.7401484933617475,   -1.3139666569139044, -0.8495986241654734,
      -4.915716389142548,   -4.675001686057293,  -1.918437129583772,
      4.718598644176625,    -2.457406986731451,  -4.393956040557082,
      -2.5965895004277195,  -1.2999065504930876, 0.9323507129857589};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor11) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{-0.9497379981244851, 2.6768013735676854,
                               -0.5054495968602097, 2.868803676727559,
                               -1.1600199055184914, -0.342802972606723,
                               -4.093792944506842,  4.424029127495622};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor12) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      -0.9393223121580343, 2.3577308872362615,  -1.0632542628817498,
      3.3480314607249504,  3.7465507141166654,  0.05815621417074546,
      -2.994407084993732,  2.498221293488644,   0.2863053257839443,
      2.577359021448979,   4.171521655898417,   0.11740444738160427,
      -3.1113711061411173, -0.2780745470466055, 3.8122839492484335,
      1.4335349334447134,  -4.929523018605069,  -2.7769366687375117,
      -4.156115800741965,  1.6941171160445982,  0.3395501969681529,
      2.5073244797355345,  -3.5217619961495927, 1.2010842221283866,
      -1.035359905818054,  -1.0054767098686446, -3.2165497134278667,
      4.241921635923839,   2.6206641747657233,  -4.0916111158407675};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor13) {
  S21Matrix matrix(4, 2);
  double *arr1 =
      new double[8]{1.754107903234714,   1.6429515839682107, 4.672489143314399,
                    3.353339599488308,   -1.125347928450069, 4.446210321043573,
                    -2.6779527600049446, 1.6658320123832588};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor14) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      3.0431126543022113,   -4.637697530445061,  -1.551044120724736,
      3.7328000776002135,   -4.220107966967474,  4.562420136226569,
      0.049497977615416744, 4.162264007965479,   3.2585484578181614,
      4.5647302964054575,   -1.3597298778833888, -1.5917334708937902,
      1.3890393752280508,   -4.112067368543682,  -1.4327798274367112,
      -4.9865059130236595};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor15) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      -4.999958740617137, -4.495336755742771,  0.8120912247417289,
      4.683412726009426,  1.5089113847224418,  2.101153652983532,
      -1.399962589386241, -4.435741980479843,  -4.894235247756593,
      2.8677204272572707, -4.31733824476995,   -0.45706101031900204,
      3.4581148000874613, -1.3966113831224272, 4.63431418240514,
      2.156457619635894,  2.3809863061366805,  3.9967190425396684,
      2.623151984732889,  -0.6825090475689244};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor16) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -3.376501613625409,  -3.7362913827458657, -1.0007850010524857,
      -3.250944056481088,  0.07158136607477594, -4.370152861146954,
      -3.301207917800034,  -2.172698779145316,  4.137680468927639,
      -3.3626780354515162, -0.6921773483638365, -2.943683581585442,
      2.247270199667554,   -1.5631418684791685, -4.978335082482793,
      -1.0061704610321334, 1.587478435655302,   -4.522595658985105,
      1.316526437605905,   -3.829646875487398,  -0.08562762351728459,
      1.9915561543052256,  3.367979229218083,   -3.0450353387820774};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor17) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      4.664404896908623,    -2.275761631168185,  -0.8783744970593057,
      3.835935543095591,    -2.3663832816002417, -4.713071961160946,
      -0.2619677536386886,  -4.016281335073195,  2.602061957117776,
      -2.2808115775477544,  -0.9284275299919855, -3.289482623343163,
      3.7586131260256046,   -1.2573045111557732, 4.188035587847896,
      1.7848578506745207,   -3.6410649012801857, 4.844828976674423,
      0.12927805592881736,  2.462432352948838,   2.112671402877271,
      -0.32260559417474166, 4.95901852385361,    -2.9640864056254603,
      0.5134805795032324,   1.747204329963635,   2.827532525172691,
      -4.91496150320363,    2.6540593786533897,  4.281450292493856,
      3.877313713099724,    4.062973673019345,   3.5479746857844603,
      -3.878636007115488,   -2.3248425525613836, 4.173491922920055};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor18) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -2.7267183415324747, -4.8422400527928975, -0.5264826271182539,
      -0.122942069846661,  1.4925854093763844,  4.346007072075194,
      4.706308738284111,   -4.7231601547084345, -3.9295818659678208,
      0.3091113209719474,  -3.6325169184612327, -3.3571492213304133,
      -0.6646886873083844, 4.448134251944085,   2.5424076628882784};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor19) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      -3.602254310176627,  -1.0289494895059326, 2.346630004380545,
      -0.9851200731984768, 4.236689574570789,   -0.9454267568329318,
      2.696799641236428,   4.864044118358144,   -0.9200827613708391,
      -2.390432133439382,  3.2179426334663415,  1.6159891144819873,
      4.652189474330324,   0.5510199290674542,  1.187030805235886,
      -1.9489420298080384, 0.9182403528115941,  -0.5978892174053865,
      2.3199411029996266,  -2.419375870264122};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor20) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -0.36583608445798355, -1.7526226936575497, -2.505552109520016,
      -4.543954253394822,   -0.3541597536906993, -3.697493537592477,
      4.814869179618471,    -3.2138321756852752, -2.9043713749506708,
      -0.7470792063293183,  -1.501236589370758,  0.7857346132262988,
      -2.7181265896611126,  -1.887421988947123,  3.0934702030891152};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor21) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -2.4620378278486896, -3.97883824692065,   -1.44492042732431,
      -3.6630894837346393, 1.4376096811833214,  0.08159631538228851,
      -1.727819151033474,  4.60312065402996,    -0.14374083090926604,
      -2.74327826044096,   0.8819270803574817,  0.6135825874102423,
      -1.3719815655926713, 4.1533663243440415,  -1.64173651384142,
      2.281250563587128,   -3.1884956518041383, -0.8980950010103026,
      -2.5289803264223707, -2.958612023219951,  -3.9212193204660317,
      -1.4410482436179315, 3.084431034073914,   -3.3169731372976576};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor22) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      0.9438197446185832,   1.6731630768008765, 4.648797181381514,
      -0.25525179414264976, 2.9429218313314607, 0.4315176962924907,
      -1.9547284543243402,  -3.871849567698641, -3.7115510531644977,
      4.22800554405328,     -4.97305779505689,  4.285886346908063,
      -0.7187207809470912,  4.339252770597264,  -2.5497975624774085,
      -1.243788877730788,   -1.441812953381214, -2.4913418850429925,
      -2.1526059611986614,  -4.1977251363352615};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor23) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      4.558750355020724,  -2.021454319204322,  -0.5298721966374389,
      -4.472168466999569, -0.7539408558605434, -1.2465679347038594,
      3.723732355698111,  1.8363804143725844,  -4.456352109260628,
      -4.501792105871897, -2.163627856913565,  -3.8623834198609073};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor24) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      3.2705660626274025,  -3.3490763083997255, -3.958081247441755,
      3.5330472716403687,  -4.366980179461116,  4.674434153061881,
      -0.9922826099138575, -4.991945490883285,  -1.8788787872577206};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor25) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      3.0192762325549047,  3.834677396265576,   4.988559225270315,
      -0.3516352184773206, -0.2660251524170585, -3.413865403084415,
      -3.2413230267713287, 2.491071654195504,   -1.3011594639231516,
      2.8756014735071336,  2.156173106613317,   1.1428586470061823};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor26) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -0.7077789390960856, -4.379944133721855,  -4.6433564288126785,
      -0.4399823255998445, -0.7083674107444216, 1.7382073807642486,
      0.6648873104196955,  0.9784958050775519,  -2.0430651734760463,
      1.9101989186343342,  -0.3922525033597992, -3.995586848883681,
      1.993294691617752,   2.4922679971200736,  -3.539396540309747};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor27) {
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      3.594699418940767,   -1.3824908228211874, -0.8864818628768383,
      -1.4014952742899456, 3.9019732197006043,  -1.9730282775305952,
      -3.4920654997385103, -1.2548364243076762, -2.980845609581263,
      -0.9821729165548891, -1.1507390121959862, -0.0295799602466138,
      -4.119948726277578,  -1.500448101979016,  -4.521497779886166,
      4.4764660398496385,  -0.5115468581101092, 2.056930129767389};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor28) {
  S21Matrix matrix(5, 5);
  double *arr1 = new double[25]{
      1.6729821555239717,  2.4739820090969804,  -4.8044760093440475,
      3.860897337640626,   -2.414185905463694,  -2.403514605414311,
      3.780549604555892,   -0.7049300308367759, -0.4074507571842396,
      -3.8955770861102446, 2.4013734706218965,  4.327185332947085,
      3.1498030113270943,  0.46115451273475117, -0.9179737040530949,
      1.0614444592570909,  4.951521777925606,   0.5877691056905316,
      -1.1329179994278835, -0.8758948487876399, 2.619462959352231,
      1.9569900388197867,  -2.000088500115371,  1.8128988491209572,
      1.8279011037405803};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor29) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      -0.7794531092618282,  2.932147019999599,   -1.451673138348034,
      -0.44628930171794146, -1.9547909474613312, -3.368847677442842,
      2.9328388008033492,   -1.9502280617972034, -4.297316705033223,
      -4.981624325290703,   -0.7576126735548279, -4.273336241317035};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor30) {
  S21Matrix matrix(2, 4);
  double *arr1 =
      new double[8]{-3.908744939579382,  -0.8849055864169433, 3.731302715439938,
                    -2.6055780079125848, 4.394103389624618,   0.63329789497267,
                    -4.032328348102324,  -0.6398633524193222};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor31) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      3.927326308204524,  -0.4205701254455727, 2.75497687204523,
      3.498532695808274,  2.5214273730118117,  3.6087630288312518,
      2.798118327159295,  -2.0341507012718685, -1.1211950444770657,
      3.0941458536381905, 0.03695858698124699, 3.0230647145089318};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor32) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -0.4122402310292088, -0.6115466367603855, -0.3386073102101097,
      -3.9539848964363955, -3.1990875536905303, 4.77627353669139,
      -2.1131463672399087, -2.1034611514643275, -0.07495671711912166,
      -4.75878673739205,   -2.007177897491952,  -3.4200898468910603};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor33) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      0.11427768158431562, -3.7611737950765036, 1.2837260230864143,
      4.671524387599771,   -0.7831214324163973, -4.622552298464294,
      -2.709632457382499,  -3.237158825597135,  4.549293675561829,
      -1.4626139557110438, 4.563405297847359,   1.8040129545134143,
      4.567734676082143,   2.5155159788584545,  1.84741657175039,
      -2.4239665013819622, -1.993291249058542,  -3.273849565384983,
      3.091903459668808,   3.794060641551388,   -3.7139167606654677,
      -2.4614037896487186, 2.5108262673268387,  2.4713811921113162,
      3.1149762377697563,  -0.7217790613573651, -2.367155394919649,
      1.282407236731057,   0.46982921965311153, -3.3147682260548663,
      -3.9898243206661252, -4.388321979978347,  2.1296442395861455,
      -2.5739815713925807, 0.08594621089697352, -4.342150733235409};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor34) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      1.7141773685700157,  3.0294736407478897,  -1.359708379493246,
      -1.4194182806435531, 3.5037931376102023,  3.8282669142480916,
      -1.1391742287262527, -4.942080443618297,  -2.5280768036555124,
      3.0888327229054635,  3.6341261440888104,  -3.888462042464227,
      -4.396376769722532,  -3.9247537484456227, 4.501480234610234,
      -3.584436158990222,  -3.7071426554410314, 2.2816033372037223,
      -4.600034916668579,  0.12316589140095857};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor35) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-2.445252468674024, -0.39548417674182357,
                                1.608517761771207,  1.7495543174001362,
                                0.3096755967158549, 4.168761886731556,
                                1.6838666369304391, 4.249320720752166,
                                -1.700319964945546, -2.985071519403647};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor36) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{
      0.2909930375851495,  -0.7999556116655038,  -4.4744362606701005,
      -4.231319487623974,  -2.5647593042417793,  2.002765229200297,
      1.1248851721979545,  -2.4479076023647095,  -2.0473167565291805,
      4.985170632127163,   1.6605139275067256,   1.9033104865128356,
      0.36974223019072827, 4.544006291754608,    3.527698481131873,
      -0.4618464641389819, -0.7271750336520828,  -4.913300152002336,
      2.8079311379075147,  0.059619795054284275, 0.31209797283296936,
      2.810165783095427,   -3.5254940725008055,  -0.18261549435431945};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor37) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{
      -1.712353198188378,  -1.8338242379683711, -4.61495612938349,
      -4.575010462219381,  -2.9032874294278765, 1.6025725334261187,
      -3.3911913023492057, -0.3213185020934102, -2.6197970575168683,
      0.12137921036822341, 2.8139537412876114,  0.4157804367861502,
      0.8784706816174843,  -4.821805801335586,  -2.333118162564012,
      -2.134143418859702,  -0.790355941541887,  4.758262828577362,
      3.2550988969686845,  -4.380151093300261,  -1.0129681977335392,
      3.4656272624622115,  4.9825673433476325,  -0.1533485549832525};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor38) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{0.44246836860279437, -3.5814598414292753,
                               1.8744472227148883,  -3.287514182831014,
                               -0.8310140459137703, -4.1044385055097745};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor39) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -1.2145257187940461,  2.907452019568927,    -2.6500307137444477,
      2.6056179616697044,   -0.643303852330348,   2.48477747201839,
      -0.03903380122499467, -1.2750939492862958,  0.2952246000055805,
      1.621764718547439,    -0.15725222069024714, 2.1631238481409536};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor40) {
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      -0.44863088172329757, -4.61822928904911,   0.5013757266606351,
      -4.881471581759715,   0.646170146071742,   -0.8124719002640992,
      -4.243857076211315,   -4.349409930529319,  -3.4982525991151316,
      -0.03271592690540537, 2.7600957205809404,  -4.1250294062012145,
      2.9525072585160848,   -2.0979745224545674, -3.9017121938868304,
      -4.327888766309065,   4.51438420428811,    3.0995381423288944};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor41) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{
      -0.010070965221528283, 1.8911072787974597,  -1.8783277342389457,
      4.868018204703185,     -3.8554518948402716, 2.399284616887943,
      0.8887127524788969,    -3.625515492059428,  1.9066172760171654,
      2.8557711984354928,    2.8372652279264488,  -4.7885436104727646,
      -0.3609631802546236,   0.5657865653462739,  1.6102590152736527,
      3.1294433630633343,    4.462756864153803,   -2.241498499800424,
      2.928633382264236,     -4.555674103481236,  0.6504349654404828,
      -0.316482462907139,    4.423330824147683,   -4.808569743984139};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor42) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      -0.5690685846791705,  -4.543353074372867, -1.5801931642523503,
      0.48812947639251014,  3.2207830286374577, 4.160359963051919,
      3.197456011853223,    -1.177182783602083, 0.49762349503847414,
      -0.34519078574679707, 0.6985437007289175, 1.5851335222564273};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor43) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{-3.7447723018312784, -0.34517459944131,
                               -0.6535772873907728, 4.742206348508525,
                               2.7082864615149287,  -3.686569504496239,
                               -1.3561697579759135, -3.7859195831745374};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor44) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-0.6344540335513464, 4.454047241276728,
                                -1.1844422954736675, 1.0669333422772436,
                                1.1442498129519656,  -1.101177717678369,
                                1.1194498831983113,  2.6006026831703553,
                                -3.198563064834615,  -2.0740345542115413};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor45) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      1.1028661444934613,  3.866630531938158,   3.8655119209932316,
      4.134131750292724,   0.8932612619090978,  -0.07485224712359795,
      -2.99569659618941,   -3.547568462497014,  -2.9396271039571475,
      -1.0136008733122113, 4.176785904065966,   2.8972010522991614,
      2.413080245378559,   -1.5867254721944848, -3.917038899595886,
      -2.0647149254660215, 1.3695140310031242,  2.8635333988868608,
      -4.821650456589769,  4.085308033971646};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor46) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -0.8830278915936942, 1.1211316041940549,  -1.3145297208459494,
      -4.022460374530833,  -1.660309785784607,  -1.9458848547039196,
      -1.3306256383569028, -1.1700588177349425, -2.420345061127759,
      0.2600706141209672,  2.1312051823262497,  0.5701800412798788,
      2.893558796117751,   -3.3928063519329674, -2.0014158982553445,
      -3.5384880527095808};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor47) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{-4.797051541689803, 1.752990423843026,
                               2.3066068828717974, -0.6332164496104697,
                               -2.42948171966735,  -0.18048369456233093,
                               -2.922539764045582, 1.9466243999522517};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor48) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{-1.0012335087501958, 4.763025684069689,
                                0.34093596527340786, -1.325638150590136,
                                -2.892255114630513,  -4.1858959874354165,
                                4.67494644152103,    3.8780888484703997,
                                -4.751348387890673,  4.743680626868782};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor49) {
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      0.6045275824359493,  4.972825868143143,   2.9891831664391413,
      3.8961017465529384,  -4.478037198774441,  0.7065980484728565,
      4.538649691418049,   -4.723315421805129,  -2.676823577895404,
      1.0335205918818247,  0.8044893001581102,  -4.247459310594622,
      -2.6962828823924045, -1.3907017315537562, -3.5875438579417485,
      0.9963284264636387,  -1.700215125229254,  2.955064733366849};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor50) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{-4.879648289719983, -2.648271580518907,
                               -0.8620176192196318, -1.336173385288003};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor51) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{-2.82088489393157,   4.91290002903337,
                                -1.2174414482407037, 2.4550569731572427,
                                2.7763428287900647,  4.480744569756178,
                                -4.895120435163671,  3.5882211237734136,
                                1.889113868021722,   1.9426071983743443};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor52) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      0.19575795200873358, 0.7258009269229859, -1.163686616620904,
      2.798337450094923,   3.6805261630328747, 2.649481585099168,
      0.5683828573093219,  2.5322246477340133, 3.0358914445014342,
      -1.7686488161779934, -4.892872634048183, 3.6361872646452404,
      2.373004663431745,   -3.47147611932608,  -4.762973855691657};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor53) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      1.098064651655167,   -4.5460536162046905, 1.7786028031027667,
      -0.5137457275171471, 1.061525030095968,   2.327494580539425,
      0.979002707935078,   -4.737840680415375,  4.1567827656111245,
      -4.853505646379471,  3.0378260375174087,  -0.8992012919394181,
      0.04145675645314206, -1.6314450703308991, -2.7664066601269486,
      -4.238740959739928};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor54) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -1.2249038136786163, -2.333451045611562,  1.1250160237685858,
      1.6630020812094903,  1.255785869158962,   -1.5757929419618852,
      4.084426609358797,   -0.4794309753954318, -4.406959949996709,
      3.937259685572176,   4.866857716597673,   -2.7407556948106224,
      -4.378216483693995,  -2.7181080808895963, 0.4260116020769935,
      -0.3605259062181929, -2.8333522009141223, 4.533773588426389,
      0.7573116301800287,  -0.3011376585129675, 3.4475022215036617,
      -3.313608607190326,  1.0855669532403258,  1.5237516968090628};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor55) {
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      1.119055727174585,    -1.2570297848634882, 3.625901832251582,
      -0.1183427500481411,  2.0608585858025696,  4.423244543161536,
      -0.2584802911299233,  -4.407992169894089,  0.8886492781924069,
      0.009147288385799257, -1.7926071250925526, 3.941295498301109,
      0.2826938000071424,   -2.03568913050185,   2.000662093719826,
      -2.944340397644807,   0.21844449731971238, 3.5600453118648296};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor56) {
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{0.8589052751218782,  2.892729259796808, -1.5663959301015007,
                    -0.8420300516953354, 4.852888768017966, 1.2021398610461826};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor57) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      0.82772939204387,    2.643854655546801,  2.0473544751888015,
      2.179442720342072,   4.175798790285626,  3.3311123958214957,
      -3.699173794848786,  -4.416436389034743, -0.5513904523443935,
      -0.1750555627823358, 2.4371832732093015, 0.4136139002479924,
      -4.402882669992739,  1.4703665091165092, -1.2898225011726847,
      -1.7915512083993157, 0.7634392261964118, -4.474909996306774,
      -0.7399938935162167, -1.012377673412895};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor58) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -2.800989197212175,  -0.03817750941243325, 1.4724303832824557,
      3.3166268102288896,  -3.223795962968473,   3.3731467389627525,
      0.07982426736601766, -1.0542044691032393,  3.7045283916682514,
      4.572858222714084,   4.369958604571099,    2.215014849229565,
      -4.839354422738991,  -1.8439687306454955,  -3.2664091638563186};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor59) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      4.270314095581508,   4.493964407994538,   0.5592937812988623,
      -4.014728241204308,  1.3001533672276198,  0.9172849760303761,
      4.303300286069113,   4.247432386392482,   -4.268169442037635,
      -2.8810977094388743, -2.8672641468685853, 2.6919791758434,
      2.607282702747428,   2.064470169639386,   3.4300176435511567,
      -2.4382269897723075, 0.44888479271104664, -1.0354869325247886,
      1.4827205889402073,  4.503866060455032,   -4.783634169130409,
      2.8669537217462615,  0.6133085861741252,  -1.5242934917413677,
      -1.7024133525190042, -3.109044855472268,  -2.516797050940368,
      -2.395101090896424,  -3.1440071425100466, 4.058935271739774};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor60) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-0.6936491546058265,  0.7162598554651725,
                                -3.4327893314921756,  -3.1121106074641602,
                                2.859659400818556,    4.696195783955709,
                                2.1212976624117506,   3.1220720270297377,
                                -0.06144508572779728, -2.905975199566061};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor61) {
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{2.2150377433842383,  4.826610034043938, 4.064635668482733,
                    -3.8080922640870343, 3.813263220649052, 1.0992333080036865};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor62) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      0.15163316404815586, -1.7903664252400708, -4.623734519581747,
      1.8052728634974287,  -3.536890349977091,  -4.273045858626534,
      0.05330850159637812, 3.734465266821939,   -0.15721795197031785,
      1.2337548961846228,  -1.7807718757819355, -0.5640399695828568,
      2.7574709675312974,  -4.548887490282852,  0.7175535887935833};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor63) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{-2.0222865634492573, -3.665561635651149,
                               4.515990190950253, -2.329365266108577};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor64) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      -3.8164462687265956, -0.4276150144153892, 0.40410255819315566,
      -0.941139706195556,  0.0277921799696621,  -4.936771203339193,
      -3.903506079510086,  -3.7161565566598878, 0.3615036117357109,
      1.4513791618408636,  -0.2270355747046029, -4.454917518251041,
      -1.583377624351595,  -2.7246104195754395, -4.700632920295098};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor65) {
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      -3.1874186496401147, 4.93213558219146,    -0.5184168134697753,
      1.477099962628568,   4.533400156285051,   -4.879429028624531,
      -4.743848967226399,  4.265992784249537,   -1.4288929632248362,
      0.654073527876113,   -1.9477772029720164, 4.940092547266984,
      1.2285097402816278,  -3.2896823401544384, 2.198926254936798,
      3.3664028230383582,  2.3332290791100423,  0.5254539132475431};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor66) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{-3.692318956375983,  -0.44545020011550207,
                               -2.0934138800322124, -2.215109410705527,
                               -0.4626505700491954, 2.8596370308769448};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor67) {
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      1.7637516894074352,  -0.8660229784117988, 3.3685393538783934,
      -3.1437558925928952, 3.283505036192512,   0.5228613210306055,
      -4.195470830252322,  -2.8972990824686917, -1.1559330748961258,
      -2.1618192227907107, 3.1878664315772856,  2.260387797888904,
      -3.943984850298119,  -3.6596665192039657, 4.8329278790561965,
      1.815157094466108,   3.4330181232608084,  -2.4500039729109604};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor68) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{3.9760544462730127, -1.7324714283441747,
                               -4.504939089622929, -1.6290222200621263,
                               0.6083921652052133, -0.24244721488732157};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor69) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      2.691687728487575,  0.6302474842414476,  -4.937776480347543,
      -4.534955245466724, -0.8516060490309378, 0.36341665090758646,
      2.6088598826619425, 4.817034449717642,   0.4271856383615411,
      4.903278130977899,  -0.9162188710242436, 0.32657238906810804};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor70) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{-0.9369417325415164, 1.075440737657864,  3.440234394467703,
                    1.8214594415198846,  -2.798029650472343, 2.656675988875513,
                    2.506681422868776,   -2.056381260065596, 3.055921629310861};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor71) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{0.2717876271361117, -0.07457656336887908,
                                -4.194008860788564, -4.514666915892641,
                                -4.637316189633477, -2.66080540370634,
                                -4.089107479316275, 2.165322909551076,
                                4.345486116005164,  -3.1174536937966444};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor72) {
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      3.275705102325471,   4.269283196580657,    -4.30781923242413,
      3.6661064505866605,  -1.4684844646108228,  -3.2181099011427228,
      0.99070116192705,    -4.337897369056281,   0.7808416335788007,
      -0.9742912897728564, -0.17528963954036136, -3.030316939961939,
      -1.4716417444485819, -3.8911069677981205,  -2.8297314222231673,
      -3.2004451696305147, -0.4221457633773653,  3.147301112591718};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor73) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      -2.0191876429723288,  0.20213865101991058, -4.853427224028385,
      -1.2002952978920414,  -1.2101271264781444, 3.806220897244968,
      4.654762074803763,    1.2702133223256071,  0.5382691655942207,
      -3.676286778052721,   0.02627035560653912, -4.619576227513232,
      -4.265715002533804,   3.07066974150586,    -0.7186361788014297,
      -4.612715997679297,   3.6278340015186945,  3.5121528439982512,
      0.4970437957150704,   -1.540362682353038,  2.7322567818143018,
      -0.01963028902421904, 3.659246936089536,   3.8878971492141083,
      0.11254095268543196,  3.297934520193147,   4.459444790219752,
      -0.2610836512414325,  3.322505833981783,   -3.0062592326323023};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor74) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      -1.9185674493963356,  1.590773420474811,   0.10924933545300419,
      -1.1692828044412993,  -2.2662295734127955, 1.2408613830573696,
      -2.472597179753669,   4.7605681847109675,  -0.4636793122863594,
      -0.14885015669267343, -0.5976174781401831, 4.413141262685807};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor75) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{1.2342512866898065, -0.17849148629014167,
                                -4.630641182165278, 0.909991559776925,
                                -1.20835105749053,  -4.719582277231949,
                                4.309816936552378,  -2.18355898436297,
                                -0.918682944143403, 4.732289727195875};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor76) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -3.3969572320006156,  -0.37857712414352385, 0.9981365227652264,
      0.446531900730184,    3.259235356284126,    3.5683517722139886,
      -2.796287260026614,   3.6536608487449413,   2.9648107431292168,
      -3.773275531567981,   3.1731309056147126,   -1.9284142220665856,
      0.08616587317831481,  3.389363741165072,    -1.2412573192903755,
      4.672699920079882,    -0.4477507077161764,  1.3680727596821018,
      -3.0568750321283344,  3.676847750978549,    -4.949342095357313,
      -0.11160811516309899, -0.8401669031225536,  -1.2857017314547061};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor77) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      2.758277408518995,   0.025959093916419818, -4.928826228759597,
      -0.5446533021737476, 4.793528122584464,    3.772513929605907,
      -3.959741146293292,  2.22352868868931,     0.5552973704311768,
      4.078234196885678,   0.9657342007010996,   -2.2845997727082867,
      -1.1329076419650685, 1.0532412556922548,   1.1470217132903642};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor78) {
  S21Matrix matrix(5, 5);
  double *arr1 = new double[25]{
      -4.0173878868064286, 4.077125594325453,   3.5662560617320054,
      1.3607141942451673,  -1.7319550894912918, -0.5115087692616216,
      -2.7555135884834248, 0.1505227451596447,  -4.454899045521313,
      0.3978674131276305,  3.598745250851051,   4.547984689722245,
      2.197072659082804,   2.1389150476150354,  -1.3026902951835995,
      -3.024998814548465,  -2.5192065807316455, -0.42231342391127313,
      4.145829572695977,   2.0658698688539907,  -1.2712874766507976,
      -2.0981340550634697, -1.0451048635491555, -4.254503568333915,
      -1.9657454956947582};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor79) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      1.9431209342578804,  4.240004789720471,   -2.7677751904587398,
      -2.669872842927672,  -4.132898992468914,  -4.270761794878446,
      -4.361287220418002,  1.3636707996637671,  1.8511162928347549,
      4.240048966781716,   -3.051180419065994,  4.028270197384824,
      -4.439448029996922,  -4.3970837968939644, -1.357882051735392,
      -1.5190874739105311, -3.2716262710972552, -3.827747211668572,
      -4.3460928391987945, -1.6567999732521255, 2.658109062310805,
      -3.883706543401435,  3.6886035106132304,  -0.3278991391569184,
      0.6506365929681257,  0.5474497011437416,  -0.9074765327696799,
      1.070874481442102,   -1.4704132526921523, 3.839816804035898,
      0.3201495607445466,  -4.092206013302611,  0.7554880163321336,
      1.6624498086127737,  3.127788025934926,   1.0653842690784634};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor80) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      1.9268343411628575,   0.8941484710991299,  -4.581026269143068,
      3.1123706751827225,   -1.7887243947745004, -2.1634072295115336,
      -0.23581297790893885, 4.416763921521325,   4.423807715094121,
      -1.4416180434802692,  2.149745871735094,   -2.64542720339096,
      4.473906475097131,    2.7750731221248,     0.9908290387462007,
      -1.7799109386259637,  -4.112839170570489,  0.6401577056253194,
      -4.16557680626406,    2.5695112690437885};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor81) {
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      -3.996454618893882,  -1.470970979729601,   0.5535756060428012,
      2.9845159010189137,  1.5235349768074746,   2.1610694584017276,
      -3.333342663097194,  -0.8251817840861193,  4.056155763096104,
      -3.9956354910765777, -0.45176174892363274, 4.289808127269975,
      3.071029634454913,   4.183308425947086,    -2.9660785771640263,
      -4.671335559493707,  3.0371947034821716,   3.429687942761827};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor82) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -1.6520857569941452, 1.1324945889761722, 3.2124422649711875,
      3.4097597532844652,  4.389603892072184,  -0.5004502804552038,
      4.822648384901454,   -1.621522435459485, -3.573827280856122,
      -2.73018175923558,   3.920433493935354,  2.771878758480506,
      3.251311992277815,   4.3060518412729,    -3.5368789963388347};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor83) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -2.9733744492248046, -0.45524206561319946, 1.083407482495332,
      -3.3991774921984232, -3.8620895488174023,  2.8899193120215063,
      -1.9177000106009756, 2.2031019145948596,   -3.2538762923933495,
      -4.48701791234853,   4.366096576122027,    0.931491482600121,
      -4.511002495215487,  4.144198378918944,    -0.8506319159058009,
      -2.5578720536033126, -3.5716879259971037,  2.373263792178582,
      -4.913430451432349,  2.9869800686168393,   -2.0884738626792023,
      -1.4566353093679352, -2.421626288844961,   3.478248851965221};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor84) {
  S21Matrix matrix(2, 4);
  double *arr1 =
      new double[8]{0.8084748442669154, -2.294054427496212, -2.8898887963868014,
                    3.9279918182061966, 2.6567102534251816, 0.7733915577050441,
                    3.349775850548639,  -4.675653484742947};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor85) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -3.9615863956542685, 4.594217920774671,   -2.7538565501391954,
      1.087230485417626,   0.396705301735123,   -0.9682406575370548,
      -1.500521199356216,  -3.566742727252729,  2.7858757660884983,
      1.7861350026290008,  -0.8404607102512109, 4.787383928024324};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor86) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -4.021577464302272, 4.807628351099005,   -0.20043000289008006,
      3.190872802012226,  2.445598415976087,   -2.224076902692962,
      -0.920083347968129, 4.049363426163708,   0.8474497011679301,
      0.3694202827234374, -0.9079432885600642, -2.5230782672493146,
      -4.254228926151647, 0.4335894642766345,  3.5172511796816543};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(3, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor87) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      0.6416902541788723,   2.488822280462969,   3.612662092902701,
      -0.4400430831982689,  4.3691912415604826,  -4.767206986427902,
      -0.35233271324196647, 1.4403685843929068,  3.7660122734258845,
      -4.257595120664629,   -1.2714897466321338, 1.872852100106634};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor88) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      -2.842687331169018,  -3.460386787671373,   -1.9430711359477435,
      0.5660213809127299,  -2.1541031695740855,  0.0827070908125469,
      -4.450715113810251,  1.5449086883963492,   -0.5702605216284748,
      2.7783334402960813,  3.8573199086789884,   -2.3617195093510865,
      0.13127573242358803, 3.5779480919041102,   -2.1848076678808184,
      -1.927715782511065,  0.5298609054041545,   -1.2030997613743133,
      -4.3668110832775255, -0.09219965702869626, 3.2661072887833473,
      -4.027288924263966,  -3.2599161611469207,  3.0618157258926306,
      -0.6196638681712159, -1.4335975957512659,  -1.2754098052499407,
      -2.0795017988331086, -0.5027783664255328,  2.0410457074090935};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor89) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{
      -0.21339371790158967, -1.1297083602240332,  -3.3575370161637705,
      -4.5551204037363116,  -2.8939494056996007,  -4.007260751531901,
      1.1826698045415078,   2.497433940639233,    0.6669917670963788,
      -0.3564893075568687,  0.3984873487406295,   -2.238529758322377,
      -3.6775954685173815,  -4.369249930046138,   -1.4241737561563363,
      -4.989174135120451,   -3.3515612459099975,  2.6328809346722393,
      1.7008569070907988,   -0.07518036088644564, 3.6626876201244265,
      0.6155590383700869,   0.06622712121500474,  2.893465813199091};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor90) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{3.611399235867692, -4.525117380437286,
                               -2.054807078140529, -0.7297732499037757};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor91) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{1.5072113689136408, -3.170579167354312,
                               1.148735960888847, -1.4246095680168915};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor92) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      1.3633795334358867,  3.6700970868782825,  1.7854148154987293,
      2.949980508809449,   -4.917250668024906,  4.0683515005392685,
      3.353728754749458,   2.7929102850392997,  3.520566871121657,
      -3.8656220981403244, 0.7355105933021768,  1.0953984189828168,
      4.529044893321473,   2.0743174043866963,  2.729219080527246,
      -3.3561251973636876, -3.3022630565403355, -2.2973373993438773,
      -2.1134057705352927, -2.3971901750357483};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 5);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor93) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      1.2351990034198543, -1.049378629759572, -3.3222026206271815,
      4.724235222337704,  -2.272457072949053, 3.8823465838496034,
      2.0211881233314433, -2.607053811191753, 4.075778453088379,
      2.6270552890740557, -1.392020125958553, 0.6646285470941198};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor94) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{3.342486383339459, 3.6017220125173175,
                               3.2569047857479223, 1.7503816952243758};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(2, 2);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor95) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      -2.3639042988777668, 3.761887569674636,   -0.33989919429930815,
      3.628791771709217,   -1.2146436648288295, -4.78966379913503,
      3.4308777758680247,  -3.833610505862939,  3.237362113846917,
      -2.5564966990047813, 0.24985675469357727, -2.528458345227227,
      -4.838087657343491,  -3.6308356436459177, 3.9110107634727154,
      -0.9755091446673134, 0.953953300881782,   0.5858352628540615,
      1.3354823575856187,  3.120026951029793,   1.3254287701578535,
      -1.6384275012230356, 3.0886947809098437,  -1.2309570684116142,
      -1.974186567443179,  2.3720658171243496,  -3.4708046544327265,
      3.715761996330995,   4.66885461181575,    -2.53024257228334,
      4.215652407797499,   0.2978182248224215,  1.181000229143013,
      0.8247495132535683,  -3.5105817440470624, -3.6390788065915225};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(6, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor96) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      3.9119369058765674,  0.38376014499890676, -2.5182335782698226,
      0.5362600735070817,  4.770218456491751,   -1.0273305562714308,
      -0.5665041454281496, 2.561199343970052,   -1.4451169990834902,
      -2.03834159934573,   0.6443809336154498,  4.888280170455552};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor97) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      4.319917961443496,   -1.4667424511028382, 1.7720238828858097,
      -3.280591525099709,  -0.9434974602833996, -2.8412436913487737,
      -1.932278542673859,  0.868621296995963,   1.8012328103567263,
      -1.8125997922931858, -1.2056787787366527, -0.06234555028434663,
      -4.9761298573840715, -3.8865414104635922, -1.6148218308570539,
      4.726029247279055,   1.0870212128992272,  0.7267739671107432,
      -3.6875135203845346, 0.420446698176268};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor98) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      2.4158456893155877, -2.424314974258234,  -4.375002963457173,
      -1.970684349268923, 1.8572115146674193,  1.068575344795227,
      0.2065912875061091, -1.3901466997726253, 2.9138035692004145,
      3.147625035976789,  -1.8447615875532386, 2.492897249717987};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 3);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor99) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      -4.586595472969136,  -0.37653402853118756, 3.3779736622862657,
      -3.6535701562948217, 4.986132730969109,    4.067642681478915,
      -0.9897518958239795, 0.8294687133866869,   -4.6123901609865605,
      4.4487180885587545,  -0.2688566980071627,  2.2303333694104364,
      4.436395635132657,   2.9792899361312655,   4.473425303008316,
      3.4669980562465987,  -0.4973081227149283,  0.4128890533640508,
      3.2708766425213813,  -3.4312844294024982};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(5, 4);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}

TEST(MatrixMoveConstructorTest, MoveConstructor100) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -1.0890968520982671, 3.1320190945448374,  0.9917308752860308,
      -3.9898333155149492, -3.7058452115096827, 0.49685511567776697,
      -1.3295837139938271, 2.8261161489059505,  -3.90083308814709,
      -2.6332819940097716, -1.0475244767081051, -3.225673770774206,
      2.0857694004130227,  -2.82414584535696,   -0.9464355043840778,
      0.8563241846221938,  4.71839055924689,    2.818258868212836,
      -3.135241658331739,  0.27844204646139925, -4.678125333004196,
      3.8088348803912613,  1.4063875175191862,  1.1718776048766024};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix res(4, 6);
  res.fillMatrixFromArray(arr1);

  S21Matrix matrix2(std::move(matrix));

  delete[] arr1;

  ASSERT_TRUE(matrix2 == res);
}
