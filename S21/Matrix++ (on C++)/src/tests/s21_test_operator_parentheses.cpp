#include "s21_test.h"

TEST(MatrixOperatorParenthesesTest, OperatorParentheses1) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      -3.669951278363861, -0.9737042948455823, -3.5304558736309866,
      1.1162937380270073, 3.259624292051088,   -1.4945975322068827,
      4.9703929480851965, 1.1301418823675249,  -0.7156174878538089,
      2.5796805903891595, -4.350168490518444,  2.373244185117187,
      -0.923038923028157, -3.753785527351842,  -1.302367991019826};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses2) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -2.8050906460533485, 2.7576077498828724,  2.4363488786874417,
      -2.5612523622738435, 0.03342850422052912, 1.1871745308859536,
      -3.1145255433175145, -4.5632525723665465, 4.890915931281588,
      2.6469212302523273,  0.8592302633933491,  1.7385669973699756,
      2.8647136134287807,  -0.8310342281929248, -4.08656712708383,
      4.139761209066174};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses3) {
  // Create the matrix
  S21Matrix matrix(4, 2);
  double *arr1 =
      new double[8]{0.7628583958976431,  2.049934220778904, 2.4498503127854834,
                    0.5008972915175445,  1.907872557676706, -3.826609055200895,
                    -2.0651688091452214, -0.514023646339786};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses4) {
  // Create the matrix
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      2.3642707873007494, 0.46256309935949425, -4.376639170903344,
      3.8045277944138363, 3.697478374864623,   2.565676133294403,
      -2.359360580028218, -1.1562146669089879, -0.2877840901636288,
      1.8489623260320762, 0.11861615215685095, -3.134479239392692,
      -3.883944283843901, 2.200495715399585,   -4.717853917530314};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses5) {
  // Create the matrix
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      4.457628541827663,   -4.099788911313812,   -3.9735978364116162,
      -1.1279604614527994, 3.0611787560257966,   -3.736667281240078,
      1.718498048272111,   0.3449666307003527,   3.5383561232329512,
      -1.649035891290751,  -0.36105616890985903, 3.470374184264994,
      -1.654001852246596,  3.2149799661860996,   1.1954898399952345,
      0.8333576953399824,  4.8607356849058,      -4.049058511908678,
      4.60217432828588,    -3.4358800816619226,  4.016581651200218,
      2.3066582483682243,  3.223348994783578,    -2.703245859991097,
      4.539501005937602,   -2.037719404388847,   1.589302356081479,
      -4.503542182308678,  -1.561305962559052,   2.091761342752765};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses6) {
  // Create the matrix
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      -1.184573107455178,  -3.9806164989039248, 2.6899616836333635,
      -2.2570767027432606, -1.54942773390085,   -3.9211800911743087,
      0.6052666095954784,  2.3762536675073136,  0.9966112694100673,
      -1.1011756963541721, -1.1307166619847928, 2.4864367197901727,
      -4.35400795409279,   3.933528445356364,   -2.0312579070847656,
      -1.052862728457018,  4.667317422797284,   2.5993617625087726};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses7) {
  // Create the matrix
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{
      2.2803831272625423,  4.557557296243246,    -0.5220394008363911,
      -2.188057237027623,  -0.46997769972054115, 3.6950564620105517,
      -2.800836331160922,  1.8520208887654181,   -4.881326611597924,
      -0.5815564224440077, -3.125809235405612,   2.8996278631285826};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses8) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      -2.7047237550526724,  -0.41325199380637745, 0.23887015220986463,
      3.1249857049910155,   2.867793156150241,    -2.0307411810360856,
      -4.349501328097274,   -0.9231733187075495,  2.582473008410852,
      4.2563910246736505,   2.7480274091531527,   -1.8201205745834423,
      -0.3509051253204145,  4.106517968529316,    2.7881194300756986,
      0.5996507397318016,   2.8251107921960568,   -4.582664918008005,
      -3.538899426335489,   -0.5573711826639949,  0.5251031164502713,
      -4.895145992482156,   4.181449187122222,    -1.5048954320696293,
      0.057968518959969906, -4.03624086491879,    -4.133052163500853,
      -1.3761979573471326,  -4.891798448164577,   3.791672096286252};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses9) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      2.5702643534749123, 2.5477433530985403,  -0.7060313713550297,
      1.9309835045083918, -0.3511877581540377, 1.433192481669968,
      1.336761107495433,  0.937200685144683,   1.8846405370014443};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses10) {
  // Create the matrix
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{4.316636509121416,   -4.168733280417625,
                                -1.033385801355342,  -3.9040779776670886,
                                0.26512193687021934, -2.1901733040182068,
                                -3.06523931485851,   -1.9050689103114173,
                                -1.6208144738328567, -1.2454307929620203};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses11) {
  // Create the matrix
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -2.7033294571399136, -3.033137845858901,   -1.5449974899174035,
      -2.28425972514951,   1.7889408244347536,   -1.0944179909997964,
      -3.6616714927364735, -3.8775105466927773,  -2.634942030456622,
      -3.866146208649923,  -1.0835384161546937,  1.9672911617074709,
      -3.7876680385236297, 2.9867932397074624,   -0.7382135643734768,
      -1.7457665984634385, 0.10417073397781085,  4.239487828024654,
      -0.5411455044285276, -2.199993195937733,   -3.8626839029371665,
      -4.384450256901177,  0.042204298345626334, 1.2761572062178281};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses12) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      0.07757301158321717, -1.32416180150692, -2.6427872608728356,
      3.1393085239437575,  4.51284739730402,  4.3609328695473,
      -0.1167714373828721, 4.787480327458194, -2.9370475924712203};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses13) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      4.435713927453676,   2.464854797008096,   2.0838595154413255,
      -1.0653074124131177, 1.1261507238022865,  1.1498387827271408,
      -1.3739012072356616, -1.3328174032515951, 2.907624236946491,
      1.2321116674529335,  0.18761092662737688, -3.856192153435262,
      1.7388579826621005,  0.5564971590432766,  -4.28552183274358,
      4.0751996859184665};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses14) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -4.6213807773459035, 4.846648978173425,    4.456202354582947,
      1.4866233887682085,  2.2623216489697526,   -2.368421075419369,
      -3.539405689085263,  -3.208822204088987,   2.3065860021736206,
      3.3828478777434263,  -0.12388593530501879, -2.3913950411125895,
      4.2547075892323445,  -1.3239017120711871,  -2.9274426140943577,
      -4.829016459785623};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses15) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      4.168298439299582,   0.34610883180202645, 1.519601804979712,
      0.12645504645089822, -1.7550421613461231, 0.9576458100199092,
      2.413436363420961,   -0.969166121117353,  -2.758127836751566,
      0.477004852391552,   -1.4370491618820278, -4.956810860718103,
      -2.537722960189698,  -0.5087903157404536, -0.9009488769368499,
      4.288532615332416,   -1.875042650755531,  -1.6062059470248666};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses16) {
  // Create the matrix
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{1.7732870205005247,  3.476292372475889,
                               1.1827346808661865,  1.9755387318810511,
                               -1.7352317013231389, -0.5233578760963749};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses17) {
  // Create the matrix
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -2.4357102923601026, 2.5424839413212386, -0.9113579184983376,
      -2.852594616803381,  -1.273140725739892, 2.6988119474288936,
      -2.100491702409526,  2.7027240655743743, 4.226115658098145,
      3.3999463411567312,  -4.23776651225129,  3.4650862929554016,
      -2.800874651208587,  4.9768580902839386, 3.976833411627405};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses18) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{1.9365399986500451,  -3.182059180064909, 3.81070332435619,
                    -1.7467181946585875, 3.969663781787988,  2.593254260653487};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses19) {
  // Create the matrix
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      -3.417176194466478, 4.65239050860472,    -3.538104126426842,
      -4.200279714251781, -1.2170972655334742, 4.430430190752887,
      -4.703748057299455, 0.8890324875308329,  1.5396491021956233,
      -1.594102309125632, -4.118538253712557,  3.7390932280167313};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses20) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      -2.645456390635408,  -0.04870774257593702, -1.9143995898741286,
      -4.8970997285550935, 1.4982224981882997,   1.7404537080511506,
      3.7447197587744103,  -3.333878527204238,   -0.7403334087201614,
      -1.3810506806375313, 2.398479221534206,    -2.574401032236687,
      0.27148482869769275, -0.5313668840165562,  -2.403181366602458,
      -3.822144818691063,  -3.2732080116513442,  -4.11419260434545};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses21) {
  // Create the matrix
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{2.2275793033412654,  -4.206326480273973,
                               -3.0078903474698224, 3.494872091424261,
                               -1.3436935859303412, -0.31169720120879507,
                               2.0581348564320647,  1.3130286081673068};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses22) {
  // Create the matrix
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{1.6652860323253957,  -1.8888747160343478,
                                3.809865409806596,   1.1151714985324048,
                                -1.8191412047384747, -1.8850796051336194,
                                -3.660125245632051,  3.872338935518645,
                                2.1180577000305103,  0.4776662677144188};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses23) {
  // Create the matrix
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      4.226382489746914,  1.6468936675512857,  -3.7177357415899093,
      4.003473867454787,  4.629027971149707,   -4.8424389016676965,
      -3.853916331731675, 2.3027134693485163,  4.191291498533689,
      -1.861529930959688, -1.1089370770511264, -1.9728509649519141,
      4.485782963323155,  -1.0759326526026811, 3.113501046158918};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses24) {
  // Create the matrix
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{-2.6063073030068296, 0.9647058056424171,
                               1.5628106545706375,  1.3984983747267332,
                               -4.942234897621104,  -4.900200041751437};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses25) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -2.201424912331734,  3.8973735752715974,  -4.89889749865323,
      -2.6713879370245475, -1.998911365022893,  2.9313475621203153,
      -3.1565901705182844, 2.7051045905050515,  2.3410341911967256,
      2.3910891683131394,  -3.3956908054932313, -3.8960064352912935};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses26) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -4.162989351542238,  -2.689049395543078, -0.5829278121181289,
      -0.5562584303139992, -4.860240864483446, 1.336601346800343,
      -3.595954835104447,  3.3065492516005754, -0.2559301391966713,
      0.44619658454695355, -4.712028824265081, -1.0666385201947195};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses27) {
  // Create the matrix
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      -1.5852681969618256, 0.8023402803146773,  -0.8788824869334135,
      -0.9868758193455189, 4.686023323903719,   -3.8074693783510307,
      4.939802385921897,   -0.7094437988312938, -1.5728396047356008,
      4.349626887435289,   -3.4994857152067937, 4.806089628668005};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses28) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      -1.8978954489871445, -4.557869300444054,  4.2764784800156495,
      -4.409187498814326,  -3.0589408945531025, 0.5742431099695775,
      3.170548413639123,   0.9576834948331676,  0.45489602631121606};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses29) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      1.8688985962518467,   4.687078333932908,   1.4322903700049574,
      -3.2651612713819524,  -3.459502977077066,  -0.3115759366061699,
      -0.20378164409760036, 0.5774167384074822,  -4.5869449905675665,
      -1.1800915382626052,  3.5558447741967285,  -2.392196822139531,
      -4.00035965757651,    -4.99687822360321,   4.380524057930895,
      -0.4166064916595724,  -2.9220380593851667, -2.1980553538063354};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses30) {
  // Create the matrix
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      -1.7342600666129115, -2.4404006769903597, 4.701735069348699,
      1.9252070468200175,  -3.23410575583418,   -3.49005516699017,
      -3.9335790084022304, 0.35953124410975423, -3.507413393428682,
      2.179769433010291,   3.7036698473854894,  -4.7626680830412225,
      1.5109378398187445,  -4.499795215373186,  4.302824196571368,
      -0.572613970779722,  2.684067920686786,   2.338328913619126,
      3.2353908975959644,  -4.696610309667406,  -3.5658175720520746,
      1.8161705017742626,  -4.40285732031654,   -1.662326873797272,
      2.828344430098822,   -3.842427502762764,  -1.9812135761518967,
      -3.1184586299593553, -3.889403463175772,  -2.1336073409012437,
      -3.5716275392510632, -2.05580579767912,   0.3672154198636157,
      0.10878244603338949, 0.6430757727267888,  4.745106528950059};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses31) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -4.518853148486182,  -4.127071015323022,  -0.740681413360865,
      -0.4547052127374993, -1.0558803019503915, 4.972858415781323,
      3.2967003679676647,  4.303454653807906,   4.784059962255135,
      1.3865891593055926,  3.573884037793949,   1.8433654492509106};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses32) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      3.7542639675826024,  -1.8225977087609557,  2.0543616963751674,
      0.6746769758155011,  1.3729162386141534,   -1.0375951680712046,
      -1.373871348927087,  -0.8274724009772605,  -0.4226345334430679,
      -2.370920027734824,  4.300097749980617,    0.02818113449838222,
      -1.4504653686145952, -4.551734676607396,   -3.8301901224077417,
      2.9628402722055043,  -0.23295325828568458, 4.477680023572262};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses33) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      -0.8826308745870106, -4.220893554119219,   -2.7762418568122116,
      -2.5204232893280922, -0.18701153182969144, 2.618988921002093,
      -1.5727793178064395, -0.7219501364405261,  -0.694026337856215,
      2.7588554480739784,  1.9937202123164388,   -0.5921924617807006,
      -1.6240328222982283, 2.607231360508571,    -3.931323626843819};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses34) {
  // Create the matrix
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{-0.34210199667309116, 0.9796652003038027,
                               -3.17055561220391,    3.6702175235575893,
                               2.0658707378788,      -0.8877350724381703,
                               3.1364657963707785,   1.722890362678494};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses35) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -1.5142827574178854, -1.224135758498429, -0.139286277621804,
      -3.4439525724784223, -1.497884277511531, 2.2304363585060436,
      1.0522045100199762,  3.131614279798262,  -2.3341236256010256,
      -0.4063033973959653, 0.5699456209923968, 1.1985408565927944,
      3.3532354167529412,  -2.24952083590489,  1.515332687000103,
      2.1970082731311145};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses36) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      -0.5752753332029616, -0.918312906128258, 3.2264250322640358,
      -1.3101895468457547, 3.765330940581194,  2.9022287255567916,
      0.7848413927931528,  3.942723231946477,  -2.7068781901931063};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses37) {
  // Create the matrix
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      -3.1219112955382498, 2.6430351018193363,  -1.8375666047749748,
      -3.070798544822937,  0.4319898995293423,  -4.811375264258359,
      -4.333528673783515,  2.8864717061984724,  2.579216859944723,
      -4.162496792655105,  -3.0302598198373665, -0.0021487038300724848,
      -4.98480986542978,   3.9602394001155847,  -4.12139272808896};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses38) {
  // Create the matrix
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      -3.4519453611355355, 0.6476609215819842,   -0.24356875384187227,
      0.421818334003464,   4.237848847046225,    2.052057373489821,
      2.2864321752689865,  -0.08040094264528097, 2.1921728956810007,
      4.576639961710123,   -0.8941413208255389,  0.6705365655337623,
      -1.2984492553911209, 0.10145101440923199,  -4.1109621279471265,
      3.365803491935754,   3.082796717477086,    -4.4579126286923305,
      -3.4088175240981022, -3.0972352733347055,  -4.2786735202755,
      3.400572277108342,   3.4725115746338773,   -2.8749105481964476};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses39) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -1.4324893188232313, -3.4107708130629897, 4.8071893830010435,
      -1.78800938455265,   -3.570373617713952,  3.5999825336663545,
      -1.1035986704342085, -4.473581149910654,  0.130598866943469,
      0.6495546564013042,  -1.8563489449102057, -0.316256510884914,
      2.8775425124186524,  -2.722769647802558,  1.078658734290495,
      -3.669366960267093};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses40) {
  // Create the matrix
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      -1.900895894883682,   -4.372269776216174,  1.5969706065159475,
      -3.71262767816945,    -0.6131610376122474, -0.7916445648027723,
      3.224883825176466,    -3.9852894482723977, 1.848648927191138,
      -0.05372399264114769, 0.6221694882758939,  0.49473524421792536,
      -4.804894333894633,   -3.0979789889139884, 4.266797363761212,
      2.5802482050757733,   2.8834572851374842,  -4.147050655215093,
      -0.11194029289771645, -2.213615358741232};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses41) {
  // Create the matrix
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      0.8515225797120562,  2.5163019006991547,  2.2456880231341927,
      -2.0028831687706674, -3.7315262603575894, 1.6827658769034102,
      -1.310328618056733,  -1.5109140850127698, 1.020747749319293,
      -2.002867709784737,  -4.0946469945296196, 3.9884562146077034};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses42) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{-2.800132188344342, -1.7458315897310719,
                               2.583587608406578,  -0.41768552500315526,
                               -4.254503783488563, -1.9418080606099872};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses43) {
  // Create the matrix
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{
      3.57998289791092,    4.114637575281606,   4.459831323652367,
      -0.4256053651951328, 4.600916572586218,   0.4337442311561581,
      4.801625636149842,   4.465335565132172,   1.8635385708314,
      -4.960097578003131,  -2.9586269757000605, 0.48284235729280134,
      4.491289629399972,   2.5291845258385006,  -0.2430046643258441,
      -1.3211453739114063, -3.4078416396869615, 1.7153054846109503,
      1.9086479196290052,  1.1423563788035533};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses44) {
  // Create the matrix
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-1.3400153301303694, 0.5130047980452579,
                                4.105040138892633,   1.4698684866182576,
                                -1.006766889840521,  3.2798804494286493,
                                1.7923677952457595,  -1.46245979340447,
                                0.7083025694620702,  -2.0785101610974888};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses45) {
  // Create the matrix
  S21Matrix matrix(5, 5);
  double *arr1 = new double[25]{
      -4.88442638670413,   -3.2365285837954283, 3.2790446384992595,
      2.0907699663142,     4.768924052501294,   0.07089165780563356,
      0.48815510260280437, -4.699536841301963,  1.9337533438765542,
      -1.4604161027549631, 3.788499251460708,   -1.1625526531109944,
      0.3292708690686297,  -3.972829496594331,  -3.00494356150839,
      2.7326290629230208,  -4.151340100171581,  -4.847629009809853,
      1.2641337060966054,  -3.3253596329247195, 1.9918229587488758,
      -1.484511333824753,  -3.9586172012322987, 4.505944980888234,
      -1.9631537535859223};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses46) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      3.957311773568394,   -3.5825006494068647, -4.86689759752554,
      -4.3868233270332135, 3.3868550624105396,  -4.224067880405969,
      -4.500356826854734,  -1.9583877490341317, -0.32714321707947036,
      0.7287240865290334,  -3.4349796825959302, 0.44851466176421884,
      2.7356557813180418,  0.6377484013749335,  3.2252875872156697};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses47) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{0.26717612604735574, 0.9725536302165683, 4.195109187599302,
                    3.60908953418188,    3.592918746144223,  -4.35264101637909};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses48) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      -2.75816003827026,   -3.4260115637161004, 1.395405730011058,
      -2.805095907302154,  -0.3696991322011396, 3.7038641463987716,
      1.7893910408363043,  2.8693525884597015,  4.901874056004084,
      -0.2823805844045504, -3.283961803804747,  2.162498737747807,
      -2.875962245309982,  2.629226036932728,   -2.725972584000859,
      -0.9921837789581414, -0.6986108618927043, 2.197713896573629};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses49) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      -4.869203224250775,  -2.9708409714639963, 0.15617148273270054,
      -3.153663426883605,  0.4480467795865124,  1.2077001081561125,
      0.5237192038097858,  -2.912741530462145,  2.9348630343493545,
      -3.4737625357890356, -3.3953637236381793, 1.4194680337887409,
      2.419157344324576,   -3.2121298220850694, 1.939206359120476,
      0.33523322386851095, -1.4263252938892457, -0.3625227992368272,
      4.202424181793319,   4.935457390618296,   -2.4524810133136974,
      -3.5575882882929877, -2.576905025947527,  4.510779856760903,
      -2.346976098731756,  -2.024191236251005,  3.002165600210013,
      3.255310768581607,   2.2408269954316493,  3.0838326161561866};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses50) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      1.550244752452997,   1.9365488753378965,   -4.296089163149101,
      -4.64073974649771,   -4.467400811740557,   2.092088008969622,
      -2.360193221596587,  2.004791524330127,    1.1863622920671633,
      -4.28007507616246,   4.364931066744592,    -2.495495827598979,
      -0.4656453841025856, -0.16160304408767256, -4.559228333176202,
      1.8499483362365856,  1.1235701311136603,   0.27350200306114125,
      0.3432916135391606,  0.3741834731624234,   -1.6439712953048549,
      -4.801540903807846,  -0.20060563896509453, -4.449182383098169,
      -3.7812185485719496, 1.606528946419906,    0.18185750292842862,
      -2.4761361265754713, 4.613799208698415,    -2.4452246230677597};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses51) {
  // Create the matrix
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-2.587376394420091,  -1.3484643107077234,
                                3.853198691202401,   4.331049353945538,
                                -0.5963004943390571, 0.3812918749255978,
                                2.3548252158153025,  0.22488678804941387,
                                3.1248156806570684,  -0.4549947991292651};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses52) {
  // Create the matrix
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      -2.847735969432812,  -1.2702349467416765, 4.901509888886755,
      4.210690347593884,   0.5880860177278677,  -0.5247759511911019,
      3.7276971785277695,  -2.577572463872617,  -0.42580788349088294,
      0.17941496074686292, -4.921557956550988,  -4.026039298764751,
      0.1830945137456199,  2.09499080203278,    -4.947525620154323,
      -3.1222681017830913, 1.061050826440507,   -1.414792858979832,
      -4.144000672291463,  -3.590774849030062,  -3.859873253656886,
      3.089316066456931,   -0.3881265161522718, 1.386428935780267,
      -3.3041934339260215, 4.819388943251248,   -0.4877095656623087,
      4.913337358229239,   -3.9867882715881366, 0.7170817241600922,
      2.318888958673395,   0.38771884427824066, -3.882348040103103,
      4.517443947833481,   -3.7467493773562097, -4.044815139583363};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses53) {
  // Create the matrix
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{
      -4.937606038579378,  -0.15530998149732245, -0.13400581015381352,
      -3.5778076114200683, 3.6459318702093775,   1.4453308181008975,
      4.25843423760276,    4.811220432376219,    2.984552596145445,
      4.805885207982513,   -1.3097875784130588,  3.9861948564452465};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses54) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      -2.8614563422819064, -4.9755232948252095,  -1.1249255618992104,
      -4.889205320370943,  1.3674160012319527,   2.787127434256824,
      0.12232984086077892, -2.032014532054646,   -1.0394578536419843,
      -2.2261270356579974, -0.08152090042838811, 2.149629496355077,
      4.086209255597025,   -0.9849470144478545,  -1.8967203324218285,
      1.273334379163801,   1.9467452347548804,   -3.0650137784225895,
      4.182589028121074,   -0.11406185840913441, 4.167994961839778,
      -2.6997930783769206, -2.5220429445513726,  -4.192827786789653,
      4.201503638870644,   0.3583671160111237,   0.9984937614552925,
      -1.7330400331423048, 4.884403958455211,    2.5972374185656255};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses55) {
  // Create the matrix
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{-3.2868870150647655, -3.902094150832922,
                                0.856352140233553,   -4.403028162200492,
                                -2.379376990038481,  1.0612524030096306,
                                1.5123191007637207,  1.497808065934069,
                                -1.0193815445276266, -1.4758580047719336};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses56) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      -3.925953299220084,  -0.6401059444467201, -4.097130158477597,
      3.348607052815977,   4.542612075616548,   0.4474945303759785,
      -4.824897173407469,  1.9979208589217574,  -3.339129443750516,
      4.52300432725815,    -4.061098454571251,  -2.0974970806359607,
      1.0290470602097548,  4.587173501380443,   -1.0525461188746146,
      1.919497397679006,   -4.158017066579801,  4.645500958608395,
      0.8561460053041561,  4.183921173710308,   -2.7918658472402758,
      -1.0209154424394287, -4.03325519053193,   1.589647847417007,
      -2.8052856389236593, -4.175007709492416,  -1.9698626264218388,
      1.3623416445452072,  4.020859265358396,   2.8876613097917065};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses57) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      -1.1173709463835966, 4.368471459003061,   -3.1689669943073753,
      -3.9718057442030466, -3.394919883217793,  -2.4672080933248806,
      1.6879717357408826,  -0.4243190856885928, 3.0524586737570907,
      4.013405535204045,   0.8666166059503224,  0.8598952906105808,
      0.9920151833499267,  4.779403362440776,   2.86667748224464};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses58) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -4.473780351687685,  2.3170694670009677,  4.7524340926845525,
      2.450067608042837,   -3.2313111235823833, -4.561032261646868,
      4.481001064095334,   -3.446772578618329,  -0.671126279846578,
      2.272306021238264,   1.7321980049807228,  -0.7353161163071507,
      2.5062070037864412,  -4.1092566327361535, -2.3834312930266943,
      -0.07480821803694582};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses59) {
  // Create the matrix
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{2.8572664624637394,  -1.1387147392501507,
                               -2.2436894733865644, 0.5533610287323656,
                               3.286451314751215,   -1.8142222638829653,
                               -4.128226924197395,  4.827841346228361};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses60) {
  // Create the matrix
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{0.21447810938546397, -1.189011124556456,
                               -1.4751383603808343, 1.0261454610763385,
                               2.035500387852264,   3.780161240193605,
                               1.9426101655867907,  4.146369666288251};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses61) {
  // Create the matrix
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      1.2525872174710582,  -2.0241343045943405, 0.8330368335846705,
      0.9916802619273213,  1.1890662453199532,  2.1700418953097698,
      -1.587086775486065,  2.804563441073827,   -2.6635678104988947,
      3.248654974469897,   -2.0472852267818165, 0.15569446284002275,
      3.508692150853019,   -0.616097033822756,  0.008229924192733051,
      0.21377760989513472, -3.8814107613250837, 0.01939862884163901,
      4.187602481985337,   -3.3768677518610724};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses62) {
  // Create the matrix
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{
      3.17115049541734,    -4.943495348739538,   1.2966478370399948,
      3.6636558262441046,  -0.34912064834684386, -1.9095636973126053,
      1.7510834770373602,  -1.338643235866476,   4.705176504681608,
      2.665341320799193,   -4.107076469934324,   -0.147152048215208,
      -0.3325365830279292, 1.074467384767491,    -3.0886260038296207};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses63) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      -0.3533346206526833, -1.9284885551519348, 3.9499237640180755,
      1.4087215921083507,  -1.633884790670371,  -2.7229709307976737,
      -3.1799195637271627, -1.8194798340235274, -0.5331590239587474};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses64) {
  // Create the matrix
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      -2.3095444149442756, 0.9954771106740985,  4.915018872474388,
      1.8028903188764724,  -1.9301808053707905, 3.6552920646384663,
      -1.4872614537698894, -4.287959860799769,  2.962838037322978,
      2.1322501513511236,  2.847144741357549,   -4.157357122089428,
      -3.6113627220924682, -3.007626577635097,  3.8194888084354552,
      -0.8932756245564839, 2.2067033991809373,  1.0335188144883398};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses65) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      -2.4067529204073335, -2.3972943274889333, 0.35374378916585236,
      0.8097726411241766,  -0.9197569039973006, -3.5740641192024403,
      -1.8712348518471167, 0.6507960110758191,  4.717832813982724,
      1.0561973451617526,  3.10749612239913,    1.3305208370677075,
      2.010625704607504,   1.5639617937685522,  4.113395381038339};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses66) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -1.5213661545455692, 0.3654847355976498,   -0.500089845337123,
      -0.8494304390355998, 3.295975132371069,    0.07580414463995577,
      4.225295275677759,   -3.9497021439103506,  2.047049307439872,
      4.485647891318612,   -0.03134806939578105, 3.057835744235753};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses67) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -2.081019920969122,  0.9000255170167719,  -1.4578343237314506,
      1.5918053160587773,  0.3890989812512622,  3.178353778966258,
      -0.5326340722784506, -3.4476084724407996, 2.283891578447781,
      -3.8062143730899933, -4.491743127740087,  -4.994997636542066};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses68) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      1.9594424344930133,  -4.057987865840671,  0.35663238506796624,
      0.599236122332675,   2.524593450751466,   2.058470831767379,
      -3.8742556287733354, 4.565901911876766,   -0.2672797987946076,
      2.0097127619320556,  3.1396793511836822,  4.7488260576446315,
      2.9677569600663576,  -1.9245493649409031, -3.7234241715310414,
      3.8723230896241407,  -0.5705761479385991, -3.1000249640236643,
      -4.7405536928129335, 4.675811924572439,   1.6512684133402598,
      -1.642193545264703,  -2.204709119449509,  -0.22012919639403172,
      -4.480270622403996,  0.613541624893525,   -2.657067245354332,
      -2.030152891306659,  0.6905457487450093,  -0.14286197095440656};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses69) {
  // Create the matrix
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{
      -3.1926546862333516, -2.111990401274262,  0.7003060830917676,
      -4.984612807872262,  -3.759375007979582,  -2.152274280005735,
      -4.220069933473384,  -1.5347205698574684, -4.107775851098893,
      2.722933020845728,   2.060648102999137,   2.0148491312912764,
      -0.6446831093611385, 0.7466417440975199,  -0.7455430244661265,
      3.231629928759677,   0.6400250771082465,  -3.009804702440092,
      4.929181109672907,   -1.2031827469408185, -3.431113463054971,
      2.6658772088125033,  4.373208027157144,   0.03974641857036687,
      -3.5878508163447553, 2.823554259659023,   -3.0769329276793145,
      -4.430843921902192,  -2.0718981523934668, 2.2972600946959094};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses70) {
  // Create the matrix
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-1.012087244142216,  -4.808332164070719,
                                0.41385062127301353, 4.248513384612915,
                                0.14300573385012338, 0.9063126017368539,
                                -4.290940325778857,  4.32485835841543,
                                0.7381602553227395,  2.255351017604018};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses71) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      -1.9004887682409821, 4.153513272018346,   -2.2895485787943204,
      -3.7592232625119957, -1.4254592140450906, -1.554557534275749,
      -3.8702160672567887, -1.2276243272456746, 4.539562914700348,
      0.7704143031764428,  -2.398073926309162,  3.5691596516553155,
      -2.1165114087822587, -2.409814836631319,  -4.226177819474671,
      4.124827559108496};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses72) {
  // Create the matrix
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{
      4.314495918864706,   3.847704076937042,   1.4310468501843863,
      -1.3349788545734178, -2.841683912925369,  0.7278772923829893,
      -0.3897226604989861, 0.4065841293445942,  -3.49927860425037,
      0.8361739427222492,  -4.656627674253279,  1.8315161465658072,
      -4.0806043163669585, -2.2870554704730406, 4.292590240266215,
      2.6849917945163444,  -4.434392078101663,  -2.2406972492358945,
      4.015100964591687,   4.5389157671127,     1.5569692606598418,
      -2.2067136493855743, 4.766076292100022,   1.6825651966719777};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses73) {
  // Create the matrix
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{
      0.2501846521166131,  -2.288042848270507,  4.199045163069442,
      -4.387282729180553,  -0.6972616597868955, 3.983469737799812,
      -4.7284501616041394, -3.728385027115255,  -0.637281696641157,
      2.044999490798334,   2.339356115846554,   -3.5842133923897213};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses74) {
  // Create the matrix
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-2.763211194148928,  -3.3368217069259387,
                                1.7196263834482872,  -0.03843299042785908,
                                -3.7928662892166995, 0.4612696646225203,
                                -1.0915596049172405, -1.262795501095507,
                                4.662480444134891,   -4.231421437484726};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses75) {
  // Create the matrix
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      0.7011501673546663,  4.459067078616464,   -0.8527113665043187,
      -2.3153982470379084, -0.6706627288877236, -0.4734735012423785,
      -3.069349559026894,  1.133256069705178,   1.561970055659211,
      -0.8327552799792581, 2.458224282810443,   -2.626989089414722};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses76) {
  // Create the matrix
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{
      -3.361399199804047,    -1.9978702507353296, -4.047138039328505,
      -3.9775251927353414,   4.454019567227993,   2.971002611492416,
      3.1109315720549695,    -3.654175646031299,  2.2193016960876566,
      3.9415965041229875,    -3.6857952620395174, -0.13085265128541934,
      2.428742256556582,     -3.863384272573903,  4.470322927456529,
      -0.011594868153101956, -0.9045674566274711, 1.771487334665073,
      1.0544821790009458,    -3.5885976719997306};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses77) {
  // Create the matrix
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{-2.499453839025323,  -2.1478892340368896,
                                -2.9134423115332844, 4.948547941127142,
                                -3.8036894110631128, -4.225997337790414,
                                -4.322130006359291,  0.10599398257407167,
                                2.009841437658233,   2.559761544655352};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 5 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses78) {
  // Create the matrix
  S21Matrix matrix(2, 3);
  double *arr1 =
      new double[6]{4.776911486031134, 4.775973797343822,  0.2698519243320874,
                    1.36309406900721,  -4.509743658406173, 2.390902300238956};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses79) {
  // Create the matrix
  S21Matrix matrix(3, 6);
  double *arr1 = new double[18]{
      3.294930523761826,   1.5131723424889412, -3.18204366129208,
      -4.60333364337543,   3.869336835122663,  4.7138139113492965,
      -1.9189591138365794, 2.3549004649311804, -2.3024326798998174,
      1.3109962152718673,  -3.545630326155033, -2.5728811880898594,
      0.18075808927347126, 0.5288819302866319, 2.6205374146313254,
      0.9269758323292603,  -3.272986024598344, 2.6255657063892386};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses80) {
  // Create the matrix
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{
      2.1166910378616732,   -2.9736906772208114, -1.485641327995043,
      -0.553690851357822,   3.244017394273225,   4.927769507891002,
      2.086086086717054,    4.502815741680424,   -0.46759286199576255,
      1.25850298745386,     -2.216425598544837,  2.190079788573441,
      -0.46461747841434864, -3.58177164568366,   4.2520765422099736,
      -3.538767819052354};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses81) {
  // Create the matrix
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{-0.09775099846219515, -4.040393873656396,
                               -4.695398491023102,   4.839625067401469,
                               -4.774909501599463,   1.1649585702711605,
                               -3.9519519983804194,  -1.9992252388159915};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses82) {
  // Create the matrix
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{
      1.6460462622599294,  2.0540213232819395,  4.2146925080332185,
      -2.7160163258690817, -0.9593096587937673, 1.7224483325484075,
      2.8222323530443303,  -2.4527967271069873, -0.8455139871351447,
      0.2590454147886767,  1.311309237537297,   -0.522802328355799,
      1.5385994896283854,  -3.4093804088852164, -3.6717252398898728};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses83) {
  // Create the matrix
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{
      -0.7340695554233108,  2.608761481754163,   1.1497620683175258,
      3.1273321566170544,   1.5520942007907843,  -3.9971743502395185,
      3.5154488962959114,   4.938831890521811,   -1.2604941568507346,
      -1.223547813836341,   3.5809192161586676,  4.258687507723847,
      -0.42974077526866417, -2.1847921047590435, -4.769371616080701,
      -0.876038345525604,   3.3973403947418,     2.0883345177689003,
      -2.9501373654715826,  -1.640500348751488,  0.8696191650685243,
      0.2516806566532983,   -2.0392460244403,    3.0599701342707064,
      0.8982726839961499,   0.26605678806884114, 4.121673403766112,
      -1.3442015497292048,  -1.6739929026824085, 1.51489253817254};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses84) {
  // Create the matrix
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      1.9411782133974302,  2.5202483015956894,  1.7864341509938173,
      -1.3574542657555866, 4.622404812120205,   3.8077811569279625,
      2.942585857556458,   2.398075169710337,   3.841527536859065,
      3.2236958614171467,  4.762300369178865,   4.79022890101197,
      -4.113650502009935,  4.85157323343212,    -1.9736118151677728,
      4.876185900009226,   -2.8688070967698573, -3.3898482051693257,
      -1.9647320258619603, 3.1135625649544547,  4.341291586458382,
      2.911840995835747,   -3.0416381021284202, -1.6163401378864695,
      -2.645456595485931,  -3.229116221678182,  -0.2770367226407968,
      2.7763707800383672,  0.532648429006894,   -1.4665724461183824,
      1.0254008043482852,  -3.1823269076603444, 2.8640426430377346,
      -4.740673773272045,  -1.061456357817523,  0.22669400213553104};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses85) {
  // Create the matrix
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{
      1.2450786213894895,  4.348875599485853,  -1.9015899168253325,
      -3.7388101515513927, -4.166248325424369, 2.931913180175277,
      4.808947104211503,   4.131271591524371,  1.9258394986367922,
      1.4291409154786958,  2.0244928864917844, -3.729987811565827};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses86) {
  // Create the matrix
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{-0.23909377976058632, -1.0613070722434026,
                               -0.6688767235081592, 2.5698000458211077};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses87) {
  // Create the matrix
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{
      0.6833061268350606, -1.08755659329143,  -3.9939115733697763,
      3.3929055991118044, 3.105646776430195,  2.284229618876102,
      2.8656674707708234, 2.7713172753268633, -1.2886143529695704,
      4.052624234568258,  1.8230382845222914, -4.0235909446897375};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 6 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses88) {
  // Create the matrix
  S21Matrix matrix(6, 3);
  double *arr1 = new double[18]{
      -1.8459293517551432, 1.60911429817377,      3.512380078719241,
      -3.2177442330852344, -3.929655946567272,    0.609377587797165,
      -0.6622309132465434, 3.9348002402700537,    3.9797084836609873,
      2.473017949956815,   1.63464985417912,      4.579751955093373,
      3.373872680952518,   3.9851107852313223,    -2.955100541168789,
      0.37077035651822676, -0.015104503513066803, -0.7305366617236437};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses89) {
  // Create the matrix
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{
      2.387788209038751,    -2.1463251361125013, 3.735211714701043,
      4.955073673406439,    -3.4011125107765707, -4.039711573533679,
      -0.08319430122303206, -3.525479405004126,  4.729722755363342};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses90) {
  // Create the matrix
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{4.038699262599696, -3.4740594296050387,
                               1.0809647384608967, -1.4427960644372773};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses91) {
  // Create the matrix
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{2.9753639169568435,   -4.7193839405877425,
                                -4.897670724885073,   2.7820593047323054,
                                -0.10935702088656019, 1.3753220085248472,
                                -3.3998889315001204,  4.401049934556832,
                                -3.9449021243432236,  0.9661453939622682};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses92) {
  // Create the matrix
  S21Matrix matrix(2, 4);
  double *arr1 =
      new double[8]{0.2364042098079464, 3.477711958708724,   4.589715123665631,
                    4.248267332890395,  -1.3267767217220627, 4.897339843196701,
                    -3.080693126352819, 3.875025390081724};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses93) {
  // Create the matrix
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{
      3.492360204447447,  -2.9590519760182064,  3.4878483142589385,
      -4.760058545023914, -0.39245962850054283, 3.4182389865018727,
      3.7740790195002702, 0.19078946441197697,  -2.255487340616887,
      -2.873477791103811, -3.3883858678061687,  -3.2536698258046712};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses94) {
  // Create the matrix
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{2.4301122942824724, -1.342251585365013,
                               -0.389746327771161, 4.9333990221897555,
                               -3.354155803981802, -3.1214733457727073};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 3 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses95) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{1.1895071812383744, -0.048195907383185244,
                               4.331117009325995,  -2.1722208015936575,
                               1.7965341211217662, -0.5329293802252897};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses96) {
  // Create the matrix
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{
      -3.685265680861244, -1.409850476441492, 1.8164778221984061,
      -1.165200729046978, -4.580832486016552, -2.6234049639683876,
      2.6096412104608655, 3.7381228786651484, -3.3877439958202005,
      2.707244791285923,  2.314470215202528,  3.2359512542129547};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 4 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses97) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{2.034556066306843,   -0.4388526366234693,
                               -1.1890886689684677, -3.2517364160285567,
                               -0.5728832354997868, -3.4700775103613966};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses98) {
  // Create the matrix
  S21Matrix matrix(3, 2);
  double *arr1 =
      new double[6]{4.954950267676331,  3.953585306760738, 3.374379676352259,
                    -4.956478798883715, 2.789919183602719, -4.547006874924053};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses99) {
  // Create the matrix
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{0.959096152042628,    0.11106818963493215,
                                4.074990984696491,    -4.116569239352663,
                                -2.5866394778327684,  -2.546555672797343,
                                -2.636684385401985,   4.977415065859004,
                                0.036187923640210506, 2.834594787638718};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}

TEST(MatrixOperatorParenthesesTest, OperatorParentheses100) {
  // Create the matrix
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{
      -1.5485722028131699,  0.6212724595424373,  -0.34956701967706927,
      -2.891967454360814,   3.608220828687255,   -3.180453759125337,
      -0.41002696723935905, -1.5497111861227522, -1.345147000055297,
      1.1111461079945144,   3.915803487998714,   2.286329092505551};
  matrix.fillMatrixFromArray(arr1);

  // Test accessing valid indices
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      ASSERT_TRUE(matrix({i}, {j}) == arr1[i * 2 + j]);
    }
  }

  // Test accessing out-of-bounds indices
  EXPECT_THROW(matrix({100}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {100}), std::out_of_range);
  EXPECT_THROW(matrix({-1}, {0}), std::out_of_range);
  EXPECT_THROW(matrix({0}, {-1}), std::out_of_range);

  // Cleanup
  delete[] arr1;
}
