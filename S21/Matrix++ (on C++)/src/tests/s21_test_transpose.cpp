#include "s21_test.h"

TEST(MatrixTransposeTest, Transpose1) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{5.69, 8.03, 8.97, 1.76, 6.95, 7.93,
                                9.75, 3.82, 5.24, 3.54, 1.91, 1.72};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 2);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose2) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{9.51, 1.05, 4.74, 4.97, 7.65, 6.18,
                                4.51, 2.74, 7.32, 4.05, 3.9,  1.98};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 6);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose3) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{2.69, 4.01, 2.81, 1.35, 4.56, 4.24,
                                5.95, 9.79, 8.25, 2.15, 7.37, 1.51};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 4);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose4) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      6.53, 2.23, 9.87, 4.48, 2.64, 5.95, 9.74, 9.85, 8.04, 6.96, 4.38, 5.24,
      7.06, 5.13, 3.84, 3.34, 3.96, 2.33, 1.44, 9.76, 3.22, 7.54, 1.25, 1.88,
      4.64, 6.72, 3.64, 9.35, 8.31, 6.79, 7.55, 9.39, 1.35, 7.86, 4.58, 3.81};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 6);
  double *arr2 = new double[36]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose5) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{2.11, 5.2,  7.96, 6.92, 5.65, 1.96, 3.09, 2.69,
                                7.5,  5.76, 1.71, 6.99, 9.73, 8.74, 4.91, 6.17,
                                4.1,  1.23, 6.15, 5.1,  3.5,  6.68, 2.3,  9.68,
                                6.55, 5.42, 8.77, 4.58, 1.42, 2.72};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 6);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose6) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{8.99, 3.34, 9.82, 6.46, 6.11, 1.69, 3.8, 4.69, 6.57};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 3);
  double *arr2 = new double[9]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose7) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{6.03, 5.36, 7.1,  7.06, 9.77, 2.89,
                                1.43, 3.09, 9.32, 6.42, 6.52, 3.04};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 3);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose8) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{4.27, 9.18, 6.54, 3.32, 7.4, 8.49, 9.98, 5.22};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose9) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{3.74, 4.93, 9.45, 9.96, 9.94, 6.94, 7.24,
                                2.12, 4.47, 8.14, 7.98, 9.99, 3.08, 8.91,
                                9.99, 9.2,  1.06, 2.61, 2.88, 5.74};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose10) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      1.08, 5.42, 6.22, 9.74, 7.73, 3.59, 5.85, 6.03, 4.71, 4.95, 3.91, 9.14,
      2.49, 5.26, 9.18, 3.04, 7.38, 3.94, 7.55, 7.14, 2.63, 6.66, 8.72, 5.52,
      1.54, 8.65, 5.31, 7.05, 2.62, 7.03, 7.82, 8.6,  7.64, 9.01, 5.85, 8.84};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 6);
  double *arr2 = new double[36]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose11) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{9.9,  6.93, 1.73, 3.55, 6.96, 9.87, 6.66, 8.59, 1.34,
                     4.09, 7.9,  9.25, 2.0,  5.1,  1.87, 7.46, 3.91, 2.42};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose12) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{3.59, 8.89, 4.32, 1.88, 1.38, 3.08, 8.23, 3.45,
                                8.98, 9.06, 2.81, 7.15, 6.13, 9.4,  9.51, 6.51,
                                4.31, 6.21, 8.07, 4.48, 6.99, 2.44, 3.3,  4.06,
                                4.07, 2.15, 2.94, 1.34, 8.83, 6.63};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 6);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose13) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{1.64, 4.7, 9.24, 9.34, 9.61, 2.32, 7.73, 4.75};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose14) {
  S21Matrix matrix(4, 5);
  double *arr1 =
      new double[20]{3.26, 8.03, 3.28, 8.22, 8.54, 5.1,  9.65, 2.81, 8.64, 2.33,
                     3.88, 7.62, 5.75, 3.04, 2.21, 5.07, 3.03, 6.71, 4.93, 4.5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 4);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose15) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{6.27, 4.19, 2.77, 8.79, 6.62, 7.85, 2.24, 7.88, 6.35};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 3);
  double *arr2 = new double[9]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose16) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{9.47, 8.14, 1.45, 5.34, 6.52, 5.68};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 2);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose17) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{8.72, 8.45, 5.38, 9.33, 9.65, 7.2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 3);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose18) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{7.95, 8.42, 1.58, 1.56, 8.6, 8.74, 2.3, 7.18, 2.34};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 3);
  double *arr2 = new double[9]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose19) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{9.71, 4.77, 7.72, 6.78, 6.7,  6.93,
                                5.7,  3.14, 4.08, 5.87, 5.89, 5.88};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 4);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose20) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{8.65, 7.64, 6.98, 3.12, 4.28, 5.9, 6.26, 7.47, 9.36};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 3);
  double *arr2 = new double[9]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose21) {
  S21Matrix matrix(2, 5);
  double *arr1 =
      new double[10]{1.83, 3.96, 8.0, 1.47, 7.62, 9.49, 3.78, 4.91, 7.54, 4.44};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose22) {
  S21Matrix matrix(5, 5);
  double *arr1 =
      new double[25]{1.77, 2.13, 2.23, 8.05, 6.45, 7.1,  5.73, 3.59, 2.43,
                     5.61, 3.69, 2.8,  9.04, 2.93, 7.79, 1.7,  5.72, 6.02,
                     5.66, 8.86, 4.28, 8.41, 8.52, 7.88, 2.63};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 5);
  double *arr2 = new double[25]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose23) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{7.04, 4.74, 9.53, 1.53};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 2);
  double *arr2 = new double[4]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose24) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{9.25, 5.68, 9.87, 4.39, 8.27, 9.29, 1.58, 1.03,
                                3.02, 8.51, 8.29, 2.13, 2.38, 6.56, 7.48, 6.25,
                                6.92, 2.59, 2.51, 5.08, 7.05, 8.97, 4.81, 5.75,
                                8.2,  3.91, 3.09, 6.88, 2.71, 3.96};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 5);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose25) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{7.48, 2.08, 4.07, 7.42, 9.21, 6.11,
                                2.83, 7.45, 4.03, 7.28, 1.98, 1.21};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 3);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose26) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{3.1,  2.33, 5.88, 3.76, 4.35, 1.08, 2.02, 6.73, 6.74,
                     7.97, 8.93, 6.59, 3.51, 2.74, 4.71, 4.64, 4.83, 6.61};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 3);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose27) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{3.39, 8.53, 4.17, 8.91, 8.19,
                                7.18, 9.71, 4.48, 6.36, 8.29};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 5);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose28) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{7.16, 8.95, 3.01, 6.26, 1.05, 4.65, 3.69,
                                4.22, 1.15, 9.57, 5.46, 1.66, 3.16, 4.99,
                                4.42, 9.43, 1.58, 1.27, 9.58, 2.37};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 4);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose29) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{4.13, 7.18, 8.08, 6.18, 5.0,  6.2,  5.44, 1.59,
                                8.88, 5.06, 9.37, 6.04, 1.51, 9.82, 9.96};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 3);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose30) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{6.62, 7.06, 3.14, 5.08, 9.68, 3.91, 6.58, 4.89,
                                6.33, 9.72, 2.51, 2.4,  9.72, 7.8,  5.21};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 3);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose31) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{7.27, 2.77, 4.0,  6.24, 5.9,  4.38, 7.78, 4.57, 9.25,
                     6.5,  5.75, 9.05, 2.63, 7.72, 9.78, 1.32, 8.78, 3.02};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose32) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{1.34, 1.88, 6.85, 2.17, 7.35, 1.19, 2.67, 1.05, 3.45,
                     2.32, 2.58, 2.81, 8.55, 4.81, 6.12, 2.4,  5.48, 9.83};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose33) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{1.76, 3.85, 3.37, 1.79, 8.09, 3.94, 3.81, 3.45};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose34) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{3.19, 6.94, 4.85, 2.81, 4.22, 5.97,
                                6.67, 8.48, 8.52, 6.02, 2.06, 5.67};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 6);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose35) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{3.54, 1.39, 9.39, 8.53, 3.62, 5.22};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 2);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose36) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{2.38, 7.99, 7.06, 3.41, 9.23, 2.2, 5.44, 9.22,
                                7.84, 4.2,  1.87, 5.48, 7.64, 7.1, 7.06};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose37) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{1.83, 7.28, 7.1, 1.25, 2.59, 6.65};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 3);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose38) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{2.1, 8.4, 8.08, 9.7, 7.01, 5.79, 2.03, 5.85};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 2);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose39) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{9.78, 9.09, 9.38, 7.52, 3.13, 1.77, 8.78, 7.41};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose40) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{1.15, 8.47, 6.96, 2.16, 1.04, 8.82, 6.73, 6.4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 2);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose41) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{4.94, 4.62, 5.64, 7.96, 4.47, 8.4,  9.41, 3.03, 4.55,
                     1.59, 2.41, 3.99, 7.17, 2.24, 3.37, 2.04, 8.92, 2.99};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 3);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose42) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{9.65, 3.3,  6.06, 9.27, 8.94, 6.85, 3.21, 7.66,
                                2.31, 7.19, 7.43, 10.0, 2.75, 9.69, 9.68};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose43) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{1.75, 2.43, 9.86, 7.89, 4.43, 9.72, 1.27, 2.58, 6.3,
                     1.04, 6.95, 6.82, 9.11, 4.78, 7.28, 5.21, 2.94, 2.71};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose44) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{3.66, 4.46, 9.6,  7.5,  8.11, 1.59, 2.05, 1.58,
                                8.95, 1.04, 6.05, 9.41, 2.5,  5.67, 3.7,  8.81,
                                4.63, 2.78, 8.9,  8.01, 4.98, 2.24, 3.04, 7.9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 4);
  double *arr2 = new double[24]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose45) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{6.93, 3.48, 6.73, 6.31, 5.65, 1.34};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 2);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose46) {
  S21Matrix matrix(5, 4);
  double *arr1 =
      new double[20]{6.04, 7.48, 9.75, 8.6,  2.83, 3.83, 3.2,  3.86, 7.03, 2.71,
                     6.5,  4.77, 3.38, 3.78, 4.0,  8.74, 8.14, 6.53, 6.38, 3.6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose47) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{1.88, 1.16, 4.61, 1.13, 8.66, 5.14, 5.79, 6.5,
                                2.9,  6.17, 9.78, 4.92, 1.1,  8.31, 6.07, 4.59,
                                7.38, 9.91, 1.05, 5.92, 8.87, 6.33, 4.25, 6.1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 6);
  double *arr2 = new double[24]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose48) {
  S21Matrix matrix(5, 5);
  double *arr1 =
      new double[25]{1.63, 9.45, 4.02, 8.68, 1.53, 1.46, 5.53, 5.14, 1.03,
                     5.05, 8.29, 6.78, 3.92, 8.84, 6.64, 2.98, 6.26, 6.02,
                     6.83, 7.75, 9.57, 2.05, 5.77, 9.75, 6.2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 5);
  double *arr2 = new double[25]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose49) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{1.18, 4.43, 6.76, 1.44, 2.93, 8.25, 4.51, 6.45, 3.97,
                     4.36, 7.08, 9.89, 2.05, 9.31, 5.43, 2.35, 5.86, 7.79};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 3);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose50) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{4.33, 7.14, 3.71, 2.28, 2.48, 8.0,  7.61, 2.0,  5.34,
                     6.31, 7.46, 9.31, 6.41, 8.14, 2.07, 1.85, 6.71, 3.29};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 3);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose51) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{4.62, 4.05, 8.12, 5.63, 9.76, 9.53, 7.33, 1.75};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose52) {
  S21Matrix matrix(5, 5);
  double *arr1 =
      new double[25]{2.54, 9.4,  6.33, 4.85, 9.71, 5.64, 9.36, 3.64, 3.24,
                     1.57, 8.24, 9.9,  5.9,  8.35, 7.86, 5.7,  9.16, 1.89,
                     1.83, 8.04, 3.57, 4.84, 7.44, 8.91, 6.17};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 5);
  double *arr2 = new double[25]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose53) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{1.73, 6.54, 2.27, 8.43, 1.02, 2.56, 3.53, 4.33, 4.71,
                     5.68, 2.48, 1.41, 1.59, 1.91, 1.52, 5.99, 2.87, 5.63};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose54) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{1.16, 5.27, 8.83, 2.32, 8.69, 1.36, 5.3,  9.46,
                                9.69, 7.5,  5.89, 9.11, 8.86, 1.86, 6.96, 4.28};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 4);
  double *arr2 = new double[16]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose55) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{9.05, 6.07, 4.22, 6.46, 3.12, 3.57,
                                8.67, 1.03, 4.87, 1.32, 9.74, 1.77};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 2);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose56) {
  S21Matrix matrix(5, 4);
  double *arr1 =
      new double[20]{9.46, 3.31, 5.18, 3.95, 3.78, 8.9,  3.65, 3.26, 9.19, 2.72,
                     2.31, 8.92, 8.52, 2.52, 1.56, 4.08, 5.72, 7.36, 9.13, 5.7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose57) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{6.91, 8.8,  3.28, 8.88, 4.19, 3.81,
                                7.15, 4.35, 7.19, 4.68, 4.11, 9.21};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 6);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose58) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{5.29, 3.55, 1.76, 7.06, 6.8,  4.22, 5.53, 9.53, 4.85,
                     6.57, 9.6,  7.43, 1.56, 8.96, 1.3,  2.96, 3.32, 7.47};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 3);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose59) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{9.68, 1.94, 9.86, 6.13, 8.89, 3.96, 6.57, 5.91};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 2);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose60) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{5.28, 3.42, 8.38, 2.29, 1.96, 1.78, 2.53, 5.07,
                                4.84, 2.45, 4.81, 3.01, 1.82, 1.37, 2.39, 4.4,
                                2.28, 4.13, 9.98, 3.79, 5.49, 3.48, 2.88, 6.82};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 4);
  double *arr2 = new double[24]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose61) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{4.68, 3.89, 6.98, 1.51, 7.09, 6.63, 9.38, 7.87,
                                3.87, 1.56, 3.35, 5.26, 9.5,  2.8,  4.37, 6.46};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 4);
  double *arr2 = new double[16]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose62) {
  S21Matrix matrix(2, 5);
  double *arr1 =
      new double[10]{9.12, 1.84, 9.56, 6.53, 7.6, 1.8, 3.63, 1.41, 9.25, 8.41};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose63) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{6.32, 3.93, 3.87, 5.64, 6.8,  7.69, 6.01, 3.57,
                                1.67, 8.91, 2.31, 1.54, 4.42, 8.07, 3.38};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose64) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      3.95, 2.05, 5.56, 2.24, 3.69, 7.39, 7.35, 4.04, 1.96, 8.67, 5.53, 1.51,
      7.5,  2.71, 6.86, 9.65, 9.76, 1.78, 5.39, 2.95, 7.4,  9.06, 6.71, 3.79,
      9.49, 4.31, 9.44, 1.92, 5.6,  1.79, 5.9,  7.55, 7.99, 4.78, 3.47, 6.14};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 6);
  double *arr2 = new double[36]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose65) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{8.57, 4.49, 6.98, 3.87, 2.83, 4.54, 1.51, 3.86};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose66) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{3.87, 4.92, 1.72, 3.31, 3.75, 4.18, 5.56,
                                5.57, 9.67, 1.5,  5.38, 8.11, 3.14, 8.57,
                                8.85, 5.17, 5.79, 4.66, 6.14, 6.05};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose67) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{8.32, 4.68, 5.91, 8.07, 4.41, 2.82, 6.69, 8.36,
                                2.67, 3.03, 3.39, 2.96, 7.01, 2.47, 3.13};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 3);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose68) {
  S21Matrix matrix(4, 5);
  double *arr1 =
      new double[20]{2.97, 8.61, 3.2,  2.47, 6.9, 1.4,  3.67, 3.54, 4.67, 2.07,
                     7.71, 4.83, 7.27, 5.49, 7.7, 6.06, 8.72, 5.42, 9.81, 7.73};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 4);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose69) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{6.76, 5.25, 5.53, 1.49, 5.95, 2.56, 9.01,
                                9.03, 8.14, 7.65, 7.56, 5.03, 5.57, 6.04,
                                3.8,  3.46, 9.22, 6.72, 4.47, 5.81};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose70) {
  S21Matrix matrix(2, 5);
  double *arr1 =
      new double[10]{4.8, 2.98, 7.96, 2.49, 4.98, 2.06, 6.88, 4.21, 4.23, 4.62};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose71) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{2.27, 4.99, 4.26, 3.4, 1.63, 5.78};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 3);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose72) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{7.23, 4.76, 5.74, 4.68, 9.37, 6.97, 1.44, 5.73,
                                9.58, 3.08, 8.35, 6.11, 8.04, 9.58, 5.45, 5.75,
                                1.13, 7.56, 6.18, 3.62, 8.25, 4.26, 2.83, 5.27,
                                9.84, 9.34, 9.63, 9.0,  3.36, 1.34};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 5);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose73) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{2.06, 1.75, 4.61, 2.11, 7.94, 3.9,  1.47,
                                8.82, 7.73, 1.12, 4.01, 6.61, 1.01, 3.68,
                                8.12, 3.57, 7.53, 8.07, 3.01, 8.41};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose74) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{5.16, 7.96, 4.24, 6.2,  9.7, 9.79, 2.95, 2.79,
                                5.39, 6.66, 9.23, 8.58, 4.3, 3.15, 3.54};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 3);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose75) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{2.18, 2.39, 1.49, 6.61, 4.42, 5.25,
                                7.79, 8.82, 1.49, 9.63, 9.68, 9.48};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 6);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose76) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{7.57, 7.45, 4.38, 2.17, 7.46, 2.46, 5.1,  3.25, 6.24,
                     1.99, 1.62, 6.5,  1.49, 4.49, 5.65, 9.31, 2.0,  9.39};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 6);
  double *arr2 = new double[18]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose77) {
  S21Matrix matrix(3, 3);
  double *arr1 =
      new double[9]{9.9, 3.99, 9.92, 2.42, 1.49, 8.8, 1.43, 1.7, 9.81};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 3);
  double *arr2 = new double[9]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose78) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{2.82, 3.56, 2.98, 8.16, 5.69, 8.65, 1.86,
                                9.41, 8.84, 5.97, 2.05, 2.28, 8.42, 7.19,
                                8.54, 3.74, 1.9,  8.46, 3.95, 1.31};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose79) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{5.11, 9.62, 9.41, 2.53, 8.76, 5.38};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 2);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose80) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{1.8,  8.48, 5.38, 4.04, 3.79, 9.82, 1.06, 4.22,
                                2.64, 3.43, 4.68, 1.94, 1.86, 4.13, 1.52, 2.17,
                                8.47, 3.53, 9.3,  6.22, 9.06, 2.52, 2.46, 3.04,
                                2.34, 3.31, 3.92, 3.89, 4.77, 3.26};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 5);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose81) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{1.91, 9.97, 2.09, 3.29};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 2);
  double *arr2 = new double[4]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose82) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{8.53, 10.0, 9.46, 5.08, 8.43, 6.25,
                                8.11, 3.49, 3.56, 7.93, 7.67, 1.31};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 3);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose83) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{1.05, 5.39, 7.18, 9.15, 5.38, 1.78};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 3);
  double *arr2 = new double[6]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose84) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{2.24, 7.72, 9.62, 8.84, 3.79, 5.98, 6.03,
                                9.48, 5.88, 6.75, 2.41, 9.59, 8.49, 9.86,
                                4.98, 3.94, 3.64, 5.59, 3.3,  8.98};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 5);
  double *arr2 = new double[20]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose85) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{1.64, 5.01, 5.96, 6.83, 4.97,
                                9.03, 6.55, 7.05, 6.11, 9.03};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose86) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{6.62, 2.41, 7.41, 2.28, 6.1, 5.33, 7.05, 7.59};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 4);
  double *arr2 = new double[8]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose87) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{2.58, 3.98, 2.79, 1.48, 3.05, 5.95, 6.66, 3.14,
                                5.03, 5.95, 1.11, 1.56, 6.46, 1.57, 7.54};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose88) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{8.64, 2.67, 8.87, 1.44, 8.58, 1.84, 7.7,  9.84,
                                3.98, 6.06, 4.28, 5.55, 3.23, 4.38, 3.48, 3.95,
                                1.01, 9.7,  1.67, 1.65, 9.86, 4.43, 3.48, 9.65};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 6);
  double *arr2 = new double[24]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose89) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{9.93, 4.41, 9.31, 6.54, 5.5,  9.46, 9.04, 2.68,
                                8.64, 5.24, 7.05, 9.2,  4.19, 5.61, 2.27};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 3);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose90) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{6.0,  4.21, 5.19, 5.15, 3.71, 4.64, 4.94, 5.17,
                                2.88, 6.61, 1.11, 7.65, 9.88, 1.05, 5.58};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose91) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{7.09, 8.87, 2.56, 8.38, 6.63, 5.22, 6.65, 1.08,
                                5.06, 3.12, 9.45, 2.35, 3.43, 8.21, 4.61, 6.54,
                                1.01, 6.83, 3.74, 5.94, 3.44, 7.72, 4.56, 2.58,
                                2.83, 6.3,  7.37, 6.59, 9.82, 4.82};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 6);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose92) {
  S21Matrix matrix(5, 5);
  double *arr1 =
      new double[25]{7.9,  4.23, 5.26, 7.21, 9.4,  6.02, 7.36, 5.94, 4.33,
                     5.89, 7.84, 1.64, 9.14, 3.22, 3.47, 4.14, 5.94, 6.51,
                     1.66, 2.38, 8.47, 8.15, 2.83, 4.65, 2.01};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 5);
  double *arr2 = new double[25]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose93) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{7.66, 9.42, 8.19, 4.31, 2.89, 8.63, 3.53, 4.12,
                                2.03, 3.63, 4.3,  9.49, 1.16, 4.89, 2.98};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(3, 5);
  double *arr2 = new double[15]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose94) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{5.29, 6.17, 8.31, 4.42, 2.95,
                                5.05, 4.09, 8.88, 2.42, 2.11};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose95) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{2.33, 7.55, 7.05, 6.5,  8.77, 3.05, 4.23, 7.69,
                                1.44, 2.03, 7.91, 8.07, 1.25, 8.09, 6.76, 6.07};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(4, 4);
  double *arr2 = new double[16]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose96) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{7.48, 2.16, 3.05, 7.53, 9.11, 2.39,
                                4.69, 3.62, 1.62, 6.45, 1.57, 3.47};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(2, 6);
  double *arr2 = new double[12]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose97) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{1.77, 2.24, 2.96, 6.49, 5.11, 4.76, 1.69, 7.74,
                                3.82, 6.94, 4.57, 8.08, 2.2,  7.72, 6.63, 6.59,
                                4.01, 7.85, 2.16, 8.36, 7.18, 2.46, 2.51, 1.14,
                                8.17, 2.88, 2.93, 2.13, 2.29, 8.76};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 5);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose98) {
  S21Matrix matrix(6, 6);
  double *arr1 = new double[36]{
      5.79, 8.29, 1.05, 1.69, 6.44, 5.27, 4.88, 7.95, 3.0,  8.73, 7.71, 2.94,
      4.72, 7.2,  1.23, 8.81, 2.87, 3.8,  9.58, 3.06, 5.14, 9.5,  9.61, 5.56,
      7.38, 6.24, 3.24, 2.6,  2.88, 6.73, 4.52, 1.99, 6.18, 3.63, 8.19, 9.0};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 6);
  double *arr2 = new double[36]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose99) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{6.99, 9.74, 5.91, 5.58, 9.21,
                                5.31, 6.11, 4.94, 6.53, 5.58};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(5, 2);
  double *arr2 = new double[10]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}

TEST(MatrixTransposeTest, Transpose100) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{4.96, 9.64, 6.43, 5.74, 3.56, 1.05, 6.42, 2.52,
                                2.84, 5.03, 7.34, 8.43, 4.57, 1.4,  5.56, 3.37,
                                9.41, 9.21, 5.57, 9.69, 7.95, 6.51, 6.11, 2.98,
                                8.01, 8.36, 5.3,  6.6,  4.13, 3.77};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedTranspose(6, 5);
  double *arr2 = new double[30]{0};
  expectedTranspose.fillMatrixFromArray(arr2);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      expectedTranspose(j, i) = matrix(i, j);
    }
  }

  S21Matrix result = matrix.Transpose();

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedTranspose);
}
