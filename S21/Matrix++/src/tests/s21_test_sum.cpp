#include "s21_test.h"

TEST(MatrixSumTest, SumMatrix1) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{6.21, 5.34, 1.37, 3.71, 3.77, 6.06,
                                6.4,  4.48, 6.23, 8.65, 1.13, 6.81};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{8.72, 7.26, 8.09, 2.97, 3.49, 7.46, 2.53,
                                8.04, 1.71, 9.4,  4.78, 7.91, 7.46, 9.11,
                                6.89, 9.85, 9.04, 5.95, 3.98, 7.37};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix2) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{9.34, 1.49, 4.12, 8.4,  7.11, 3.92, 5.58, 6.64,
                                4.43, 4.95, 7.86, 2.92, 9.37, 5.3,  1.38, 5.86,
                                5.06, 7.54, 9.28, 8.65, 7.18, 3.49, 3.39, 7.66,
                                5.08, 8.74, 8.16, 7.46, 6.43, 9.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 6);
  double *arr2 = new double[42]{
      2.2,  9.92, 4.86, 9.38, 3.16, 4.62, 8.92, 1.68, 3.88, 5.57, 8.43,
      4.77, 7.4,  7.46, 3.8,  9.47, 6.78, 2.79, 2.96, 7.04, 8.1,  3.84,
      2.08, 6.98, 9.97, 4.49, 1.62, 5.62, 4.22, 7.39, 9.18, 7.85, 5.19,
      8.83, 3.8,  2.87, 3.02, 5.89, 8.3,  7.7,  1.0,  2.22};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix3) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{2.88, 7.74, 7.29, 1.61, 4.89, 4.04, 7.31, 7.34,
                                9.66, 6.52, 7.86, 7.73, 5.15, 1.9,  5.38, 2.91,
                                6.25, 8.33, 1.98, 6.86, 1.37, 5.7,  7.34, 4.07};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{3.88, 4.38, 2.89, 4.27, 2.12, 8.93, 1.12, 3.84,
                                3.37, 9.16, 5.67, 2.53, 7.18, 8.76, 9.76, 6.56,
                                4.27, 5.77, 7.71, 9.74, 3.67, 1.39, 6.63, 3.26};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 6);

  double *arr3 =
      new double[24]{6.76,  12.12, 10.18, 5.88,  7.01,  12.97, 8.43,  11.18,
                     13.03, 15.68, 13.53, 10.26, 12.33, 10.66, 15.14, 9.47,
                     10.52, 14.1,  9.69,  16.6,  5.04,  7.09,  13.97, 7.33};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix4) {
  S21Matrix matrix1(5, 4);
  double *arr1 =
      new double[20]{3.41, 9.6, 1.64, 5.94, 8.03, 6.38, 6.08, 6.96, 4.38, 2.98,
                     9.45, 2.9, 6.08, 4.39, 6.53, 2.35, 4.01, 6.42, 7.89, 1.06};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 =
      new double[20]{9.47, 5.54, 7.01, 6.7,  3.57, 1.44, 7.46, 1.8,  7.59, 3.61,
                     3.6,  5.18, 7.55, 9.83, 6.04, 5.64, 5.95, 4.08, 2.67, 7.5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 4);

  double *arr3 = new double[20]{12.88, 15.14, 8.65, 12.64, 11.6,  7.82,  13.54,
                                8.76,  11.97, 6.59, 13.05, 8.08,  13.63, 14.22,
                                12.57, 7.99,  9.96, 10.5,  10.56, 8.56};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix5) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{3.31, 5.43, 8.35, 2.79, 5.17, 6.44, 5.9, 7.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{1.06, 4.09, 9.8,  2.02, 3.39, 3.13, 3.09, 4.76,
                                2.1,  3.3,  3.99, 6.34, 9.73, 3.28, 1.22};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix6) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{2.97, 1.36, 5.94, 8.46, 2.1,  2.25, 7.38, 2.72, 8.33,
                     4.06, 6.76, 5.53, 1.75, 8.86, 6.62, 6.5,  9.23, 9.87};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{7.83, 9.64, 8.09, 1.52, 5.12, 8.08, 1.37, 6.9,  1.79,
                     2.78, 7.47, 8.11, 6.37, 2.93, 6.84, 6.96, 9.15, 7.48};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 6);

  double *arr3 = new double[18]{10.8, 11.0,  14.03, 9.98,  7.22,  10.33,
                                8.75, 9.62,  10.12, 6.84,  14.23, 13.64,
                                8.12, 11.79, 13.46, 13.46, 18.38, 17.35};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix7) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{5.83, 7.86, 7.8,  3.27, 6.96, 2.93,
                                5.85, 5.6,  2.95, 9.65, 1.82, 2.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{4.92, 6.29, 3.34, 1.56, 8.31, 4.57,
                                6.98, 1.37, 5.92, 8.34, 6.9,  9.79};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 3);
  double *arr3 = new double[12]{10.75, 14.15, 11.14, 4.83,  15.27, 7.5,
                                12.83, 6.97,  8.87,  17.99, 8.72,  12.72};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix8) {
  S21Matrix matrix1(4, 5);
  double *arr1 =
      new double[20]{3.18, 1.03, 5.58, 2.91, 9.31, 2.82, 3.37, 5.83, 8.54, 6.8,
                     4.57, 8.84, 7.71, 2.3,  3.07, 8.55, 3.91, 6.68, 5.41, 2.8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 =
      new double[20]{3.09, 8.07, 7.78, 2.65, 3.32, 8.6, 6.45, 2.13, 2.74, 5.71,
                     8.15, 2.59, 8.34, 6.09, 1.14, 4.8, 2.82, 1.45, 4.96, 2.72};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);

  double *arr3 = new double[20]{6.27, 9.1,   13.36, 5.56,  12.63, 11.42, 9.82,
                                7.96, 11.28, 12.51, 12.72, 11.43, 16.05, 8.39,
                                4.21, 13.35, 6.73,  8.13,  10.37, 5.52};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix9) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{4.86, 9.31, 7.64, 8.77, 8.89, 5.19, 6.66, 6.56,
                                7.74, 1.88, 7.26, 4.16, 9.87, 7.41, 7.23, 3.3,
                                2.29, 8.38, 8.62, 4.66, 1.98, 6.99, 8.21, 7.75};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{9.25, 8.72, 7.32, 9.33, 5.4,  1.7,  7.7,  8.97,
                                3.38, 9.56, 3.4,  9.38, 5.51, 1.61, 6.72, 9.47,
                                1.06, 9.47, 3.55, 4.33, 7.16, 7.27, 6.62, 2.69};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 6);

  double *arr3 =
      new double[24]{14.11, 18.03, 14.96, 18.1,  14.29, 6.89,  14.36, 15.53,
                     11.12, 11.44, 10.66, 13.54, 15.38, 9.02,  13.95, 12.77,
                     3.35,  17.85, 12.17, 8.99,  9.14,  14.26, 14.83, 10.44};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix10) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{6.79, 5.04, 1.98, 3.36, 6.43, 8.71, 5.71, 5.72,
                                6.24, 4.26, 2.62, 8.3,  2.66, 4.73, 6.7,  1.21,
                                9.76, 3.74, 7.35, 2.06, 3.61, 6.08, 4.17, 3.83,
                                6.98, 1.82, 7.52, 6.86, 7.76, 5.23};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{7.92, 4.6,  9.03, 7.06, 6.2,  2.53, 9.62, 9.81,
                                6.93, 1.34, 2.72, 6.94, 8.1,  6.91, 2.32, 7.24,
                                3.29, 7.11, 2.32, 5.89, 8.41, 8.63, 5.26, 1.68,
                                6.23, 9.44, 9.41, 9.28, 1.3,  8.73};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 5);

  double *arr3 = new double[30]{
      14.71, 9.64,  11.01, 10.42, 12.63, 11.24, 15.33, 15.53, 13.17, 5.6,
      5.34,  15.24, 10.76, 11.64, 9.02,  8.45,  13.05, 10.85, 9.67,  7.95,
      12.02, 14.71, 9.43,  5.51,  13.21, 11.26, 16.93, 16.14, 9.06,  13.96};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix11) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{6.09, 3.7,  3.32, 8.1,  5.12, 5.63, 9.17, 9.25,
                                5.5,  9.87, 4.6,  5.42, 7.24, 9.71, 2.73, 7.26,
                                6.19, 4.88, 9.6,  2.3,  1.18, 7.43, 1.94, 6.47,
                                7.3,  4.58, 2.23, 1.92, 7.59, 9.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{2.87, 2.75, 6.13, 4.45, 2.07, 1.85, 9.98, 3.06,
                                6.17, 4.12, 3.57, 3.01, 6.43, 1.59, 6.84, 9.87,
                                5.47, 5.34, 8.09, 5.49, 7.89, 1.69, 9.13, 3.92,
                                2.74, 3.56, 6.81, 9.18, 7.92, 1.83};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 5);

  double *arr3 = new double[30]{
      8.96, 6.45, 9.45,  12.55, 7.19,  7.48,  19.15, 12.31, 11.67, 13.99,
      8.17, 8.43, 13.67, 11.3,  9.57,  17.13, 11.66, 10.22, 17.69, 7.79,
      9.07, 9.12, 11.07, 10.39, 10.04, 8.14,  9.04,  11.1,  15.51, 11.76};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix12) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{1.91, 3.89, 5.45, 5.96, 2.59, 4.8,
                                3.96, 3.84, 4.57, 5.4,  5.6,  1.4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{9.24, 6.03, 7.79, 6.66, 2.98, 5.68,
                                6.85, 5.7,  7.39, 8.09, 3.74, 7.82};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 3);
  double *arr3 = new double[12]{11.15, 9.92, 13.24, 12.62, 5.57, 10.48,
                                10.81, 9.54, 11.96, 13.49, 9.34, 9.22};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix13) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{1.83, 4.11, 3.96, 6.16, 9.99, 8.02, 2.64, 5.72, 4.2,
                     2.26, 4.71, 6.59, 6.26, 4.09, 7.63, 9.88, 7.88, 3.03,
                     5.48, 3.04, 4.91, 5.23, 6.1,  8.82, 7.31};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{9.4,  5.04, 9.6,  8.67, 4.98, 8.45, 8.42, 5.73, 3.49,
                     1.27, 2.86, 6.64, 7.24, 5.25, 4.93, 8.16, 9.36, 1.08,
                     7.47, 4.22, 3.13, 6.76, 1.6,  3.84, 2.89};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 5);

  double *arr3 = new double[25]{11.23, 9.15,  13.56, 14.83, 14.97, 16.47, 11.06,
                                11.45, 7.69,  3.53,  7.57,  13.23, 13.5,  9.34,
                                12.56, 18.04, 17.24, 4.11,  12.95, 7.26,  8.04,
                                11.99, 7.7,   12.66, 10.2};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix14) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      7.62, 6.29, 7.79, 9.02, 4.52, 6.7,  7.91, 9.76, 4.87, 6.96, 6.3,  1.33,
      2.24, 1.91, 8.24, 8.74, 4.39, 1.19, 7.95, 6.99, 4.14, 9.67, 7.13, 9.89,
      6.07, 7.74, 5.23, 2.6,  1.03, 7.63, 9.31, 1.74, 3.04, 7.52, 6.75, 1.7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 7);
  double *arr2 =
      new double[49]{8.55, 8.97, 1.33, 6.0,  2.59, 5.51, 6.04, 3.22, 6.55, 8.74,
                     5.88, 8.36, 3.41, 1.31, 2.58, 9.39, 3.18, 7.37, 4.62, 7.63,
                     6.88, 7.03, 1.6,  1.15, 4.09, 4.24, 1.96, 8.58, 7.67, 5.61,
                     5.39, 9.26, 9.4,  8.84, 6.68, 2.12, 1.48, 7.06, 1.99, 4.94,
                     7.76, 1.67, 4.59, 3.56, 1.95, 5.76, 7.77, 2.89, 8.54};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix15) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{6.26, 4.58, 9.85, 7.08, 9.84, 4.84, 1.68, 4.14, 4.06,
                     9.77, 4.84, 8.62, 7.31, 9.72, 3.18, 8.26, 3.11, 7.38};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{8.18, 1.32, 1.03, 2.73, 9.49, 6.06, 3.97, 3.07, 3.99,
                     2.58, 7.14, 8.81, 5.21, 8.48, 1.64, 4.46, 5.59, 3.16};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 6);
  double *arr3 = new double[18]{14.44, 5.9,  10.88, 9.81,  19.33, 10.9,
                                5.65,  7.21, 8.05,  12.35, 11.98, 17.43,
                                12.52, 18.2, 4.82,  12.72, 8.7,   10.54};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix16) {
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{8.21, 1.33, 5.76, 5.7, 7.15, 6.36, 1.08, 4.01, 9.88, 4.12};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{5.65, 4.02, 9.61, 9.79, 2.14, 9.93, 4.07, 1.1, 6.25, 8.62};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 2);
  double *arr3 = new double[10]{13.86, 5.35, 15.37, 15.49, 9.29,
                                16.29, 5.15, 5.11,  16.13, 12.74};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix17) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{9.68, 3.32, 4.01, 5.75, 1.84, 9.18, 4.72,
                                1.6,  8.25, 8.09, 2.67, 5.39, 4.25, 2.8,
                                3.23, 2.95, 8.71, 8.98, 6.92, 6.28};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{7.81, 2.94, 1.9,  7.98, 1.12, 2.12, 2.44,
                                9.34, 9.34, 3.49, 4.45, 1.8,  9.73, 1.68,
                                4.75, 7.88, 2.83, 3.84, 4.29, 7.93};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);

  double *arr3 = new double[20]{17.49, 6.26,  5.91,  13.73, 2.96,  11.3,  7.16,
                                10.94, 17.59, 11.58, 7.12,  7.19,  13.98, 4.48,
                                7.98,  10.83, 11.54, 12.82, 11.21, 14.21};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix18) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{9.12, 3.23, 5.83, 3.37, 1.38, 8.06, 2.33, 1.15,
                                4.58, 9.22, 5.75, 2.21, 5.78, 2.92, 8.66, 2.53,
                                8.04, 6.1,  6.39, 5.28, 3.49, 9.57, 2.63, 8.57,
                                8.42, 7.43, 2.79, 4.14, 6.08, 7.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{7.0,  3.77, 6.51, 1.11, 1.61, 6.46, 6.11, 9.6,
                                5.26, 9.8,  4.34, 8.78, 9.56, 9.06, 4.74, 8.13,
                                3.67, 1.27, 4.62, 5.33, 3.18, 8.74, 6.27, 4.02,
                                9.39, 5.52, 3.38, 3.06, 3.38, 3.93};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 6);
  double *arr3 = new double[30]{
      16.12, 7.0,   12.34, 4.48,  2.99,  14.52, 8.44,  10.75, 9.84,  19.02,
      10.09, 10.99, 15.34, 11.98, 13.4,  10.66, 11.71, 7.37,  11.01, 10.61,
      6.67,  18.31, 8.9,   12.59, 17.81, 12.95, 6.17,  7.2,   9.46,  10.97};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix19) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{1.47, 8.12, 6.36, 1.24, 6.44, 8.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{8.31, 7.7, 2.36, 6.89, 5.28, 5.38};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 3);
  double *arr3 = new double[6]{9.78, 15.82, 8.72, 8.13, 11.72, 13.42};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix20) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{7.8,  9.31, 2.98, 9.4,  2.9,  4.31, 2.24, 3.75,
                                1.44, 7.77, 6.37, 9.94, 2.37, 9.05, 7.11, 1.75,
                                8.75, 3.53, 6.85, 2.02, 1.89, 8.74, 9.37, 2.55,
                                6.3,  7.75, 6.42, 3.93, 9.36, 2.69};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 6);
  double *arr2 = new double[42]{
      1.41, 1.62, 1.73, 9.41, 7.06, 8.63, 7.55, 3.73, 6.44, 4.05, 2.15,
      5.12, 7.83, 2.19, 7.15, 1.7,  2.26, 8.78, 2.67, 8.48, 1.68, 1.56,
      3.71, 6.05, 7.01, 5.26, 4.84, 5.26, 6.14, 3.46, 7.84, 6.68, 9.98,
      4.1,  8.41, 5.2,  3.78, 7.86, 2.29, 9.8,  5.82, 5.32};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix21) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{1.15, 5.7, 8.3, 5.97, 5.66, 6.19, 2.89, 1.93, 1.41};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{4.58, 1.22, 3.83, 5.15, 2.7,  8.39, 7.49, 3.49,
                                8.27, 3.97, 6.3,  8.42, 4.05, 9.33, 4.05, 6.78};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix22) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      4.74, 5.15, 8.3,  6.61, 7.57, 9.08, 2.6,  4.54, 5.99, 1.14, 5.13, 6.04,
      5.26, 8.84, 1.42, 7.7,  3.7,  6.51, 4.21, 4.48, 6.84, 1.15, 1.3,  1.79,
      8.63, 5.85, 2.41, 6.39, 5.23, 6.88, 8.46, 4.84, 9.16, 9.97, 6.95, 1.46};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 7);
  double *arr2 =
      new double[49]{8.88, 6.42, 9.61, 5.92, 6.29, 8.92, 4.3,  8.93, 7.32, 8.52,
                     9.16, 8.71, 1.72, 5.17, 3.18, 5.75, 2.81, 5.32, 7.02, 3.03,
                     1.06, 6.0,  9.25, 7.53, 4.4,  1.45, 3.38, 7.03, 8.05, 9.92,
                     5.97, 8.35, 4.32, 1.99, 2.44, 2.49, 5.15, 3.01, 6.21, 7.63,
                     5.67, 1.93, 9.51, 7.45, 1.61, 9.32, 8.11, 8.14, 8.07};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix23) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{2.35, 9.79, 7.17, 9.06, 1.53, 3.07, 5.79, 9.4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{7.93, 2.45, 2.79, 6.68, 4.78, 9.92, 4.86, 8.81};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 4);

  double *arr3 =
      new double[8]{10.28, 12.24, 9.96, 15.74, 6.31, 12.99, 10.65, 18.21};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix24) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{6.28, 5.51, 2.76, 8.3,  1.64, 8.49, 8.08, 8.15,
                                7.62, 3.03, 9.97, 7.12, 1.39, 7.07, 6.69};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{2.35, 8.04, 9.69, 8.74, 3.17, 1.2,  3.55, 2.62,
                                4.61, 1.7,  4.63, 9.78, 6.42, 2.99, 9.0,  5.0,
                                2.83, 1.78, 6.41, 5.9,  2.67, 1.59, 8.19, 8.78};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix25) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{1.75, 7.79, 3.77, 4.16, 5.09, 3.05};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{1.08, 3.72, 6.74, 7.46, 4.72, 7.11};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);
  double *arr3 = new double[6]{2.83, 11.51, 10.51, 11.62, 9.81, 10.16};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix26) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{8.89, 3.17, 2.54, 1.18, 5.24, 3.6,  6.72, 3.2,  9.6,
                     7.34, 4.36, 1.5,  4.41, 3.6,  7.73, 3.52, 7.76, 2.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 7);
  double *arr2 =
      new double[28]{6.94, 9.48, 8.62, 1.39, 8.55, 3.79, 7.37, 5.14, 5.35, 5.43,
                     2.34, 5.85, 3.88, 1.77, 7.03, 1.34, 5.97, 4.66, 1.85, 8.75,
                     8.8,  4.31, 7.85, 5.67, 3.78, 9.13, 8.39, 1.85};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix27) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{2.49, 6.95, 9.05, 7.81, 6.03, 2.36, 8.12, 9.21,
                                6.26, 9.18, 8.29, 1.06, 8.06, 8.7,  1.16, 2.16,
                                1.07, 9.94, 2.66, 9.93, 9.09, 2.42, 9.26, 9.02,
                                2.5,  2.2,  3.75, 4.09, 2.99, 7.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{4.78, 7.06, 8.4,  6.4,  4.15, 8.67, 3.37, 3.53,
                                1.4,  1.43, 4.26, 3.13, 2.04, 1.24, 5.83, 2.65,
                                3.65, 2.36, 4.76, 6.62, 6.99, 4.38, 4.28, 9.64,
                                1.81, 9.89, 9.92, 6.68, 2.37, 1.78};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 5);
  double *arr3 = new double[30]{
      7.27,  14.01, 17.45, 14.21, 10.18, 11.03, 11.49, 12.74, 7.66, 10.61,
      12.55, 4.19,  10.1,  9.94,  6.99,  4.81,  4.72,  12.3,  7.42, 16.55,
      16.08, 6.8,   13.54, 18.66, 4.31,  12.09, 13.67, 10.77, 5.36, 9.61};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix28) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{4.48, 5.21, 8.0, 3.89};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{5.78, 7.15, 4.09, 7.24};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 2);

  double *arr3 = new double[4]{10.26, 12.36, 12.09, 11.13};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix29) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{1.52, 6.72, 1.38, 1.63, 4.39, 8.06, 5.09, 3.91};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{6.67, 4.85, 8.55, 2.54, 1.68, 5.26, 7.45, 5.88,
                                8.69, 3.76, 2.82, 8.71, 8.48, 7.28, 2.01};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix30) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{1.98, 9.39, 5.53, 7.46, 7.47, 6.81, 3.06, 2.2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{4.92, 5.42, 5.57, 9.72, 1.16, 4.98, 7.52, 4.7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 2);
  double *arr3 =
      new double[8]{6.9, 14.81, 11.1, 17.18, 8.63, 11.79, 10.58, 6.9};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix31) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{1.38, 3.28, 2.95, 4.5,  3.72, 3.31,
                                9.3,  5.65, 7.58, 8.95, 2.11, 7.11};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{8.72, 8.02, 6.08, 4.23, 7.26, 5.22,
                                9.2,  3.75, 9.72, 3.08, 7.75, 3.82};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 3);

  double *arr3 = new double[12]{10.1, 11.3, 9.03, 8.73,  10.98, 8.53,
                                18.5, 9.4,  17.3, 12.03, 9.86,  10.93};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix32) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      6.79, 1.7,  9.84, 9.86, 5.05, 6.68, 7.29, 6.1,  3.04, 1.57, 6.65, 6.89,
      1.91, 5.37, 8.18, 7.75, 3.08, 6.01, 4.34, 7.85, 8.48, 6.13, 7.22, 8.98,
      8.76, 5.88, 8.72, 4.83, 8.59, 7.05, 9.14, 6.55, 7.43, 4.26, 9.25, 6.95};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      1.36, 9.43, 9.06, 3.96, 7.38, 9.83, 1.29, 7.35, 1.06, 5.08, 5.46, 7.4,
      9.23, 6.72, 4.93, 8.79, 4.2,  4.54, 1.4,  2.69, 5.83, 6.41, 3.78, 5.38,
      8.03, 1.33, 5.64, 2.25, 8.06, 8.87, 1.8,  1.38, 7.76, 9.22, 9.25, 9.83};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 6);

  double *arr3 = new double[36]{
      8.15, 11.13, 18.9,  13.82, 12.43, 16.51, 8.58,  13.45, 4.1,
      6.65, 12.11, 14.29, 11.14, 12.09, 13.11, 16.54, 7.28,  10.55,
      5.74, 10.54, 14.31, 12.54, 11.0,  14.36, 16.79, 7.21,  14.36,
      7.08, 16.65, 15.92, 10.94, 7.93,  15.19, 13.48, 18.5,  16.78};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix33) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{4.03, 9.24, 9.08, 9.38, 8.72, 1.62};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{4.84, 1.09, 3.89, 1.97, 7.16, 4.21};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);

  double *arr3 = new double[6]{8.87, 10.33, 12.97, 11.35, 15.88, 5.83};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix34) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{
      3.0, 6.47, 7.37, 1.36, 1.31, 3.89, 2.39, 8.72, 2.98, 2.59, 6.21, 9.0, 3.7,
      7.5, 2.48, 2.99, 3.23, 4.36, 9.03, 9.2,  9.33, 7.99, 5.23, 4.37, 1.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{5.27, 4.11, 3.65, 5.22, 6.78, 9.74, 4.75, 3.85, 7.0,
                     5.28, 7.57, 6.67, 5.72, 4.15, 4.78, 4.74, 8.37, 1.79,
                     3.65, 7.82, 5.77, 3.98, 5.67, 1.91, 3.39};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 5);
  double *arr3 = new double[25]{8.27,  10.58, 11.02, 6.58,  8.09,  13.63, 7.14,
                                12.57, 9.98,  7.87,  13.78, 15.67, 9.42,  11.65,
                                7.26,  7.73,  11.6,  6.15,  12.68, 17.02, 15.1,
                                11.97, 10.9,  6.28,  4.43};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix35) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{9.59, 2.53, 6.72, 2.89, 1.97, 6.69,
                                2.13, 6.66, 4.14, 2.07, 8.87, 6.24};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{1.53, 6.77, 4.26, 1.56, 3.02, 4.25, 3.52,
                                7.88, 5.09, 4.4,  9.7,  3.04, 3.74, 6.45,
                                7.69, 7.27, 5.24, 9.6,  7.09, 4.45};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix36) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{4.46, 3.26, 3.29, 1.32, 9.09, 9.78,
                                3.04, 7.25, 9.98, 9.19, 1.92, 2.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{2.78, 2.43, 4.95, 6.11, 8.36, 7.95,
                                6.47, 7.35, 3.62, 2.55, 2.55, 1.94};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 4);

  double *arr3 = new double[12]{7.24, 5.69, 8.24, 7.43,  17.45, 17.73,
                                9.51, 14.6, 13.6, 11.74, 4.47,  4.03};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix37) {
  S21Matrix matrix1(5, 6);
  double *arr1 =
      new double[30]{7.73, 3.83, 7.35, 9.36, 4.53, 6.74, 5.03, 4.69, 9.92, 2.16,
                     4.48, 8.15, 5.85, 1.87, 4.27, 5.64, 3.46, 2.08, 5.78, 5.1,
                     9.61, 8.93, 9.56, 4.91, 8.46, 2.37, 1.66, 4.81, 8.65, 1.0};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{1.74, 5.39, 9.51, 3.67, 4.6,  1.58, 2.58, 7.58,
                                9.21, 2.39, 8.55, 7.15, 1.31, 9.86, 2.44, 7.59,
                                2.46, 2.56, 3.75, 4.27, 7.85, 5.57, 4.67, 2.21,
                                3.08, 2.46, 6.4,  6.27, 8.39, 5.25};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 6);

  double *arr3 = new double[30]{
      9.47,  9.22, 16.86, 13.03, 9.13,  8.32,  7.61, 12.27, 19.13, 4.55,
      13.03, 15.3, 7.16,  11.73, 6.71,  13.23, 5.92, 4.64,  9.53,  9.37,
      17.46, 14.5, 14.23, 7.12,  11.54, 4.83,  8.06, 11.08, 17.04, 6.25};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix38) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{3.54, 2.2,  9.69, 3.54, 6.1,  3.74, 5.77, 8.47,
                                9.82, 4.36, 2.82, 5.44, 2.43, 9.15, 7.13, 7.65,
                                9.34, 2.45, 9.38, 8.47, 2.46, 3.12, 8.69, 8.74,
                                6.57, 7.19, 9.42, 4.98, 8.43, 6.29};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 7);
  double *arr2 = new double[42]{
      7.85, 1.55, 2.83, 6.32, 2.62, 5.3,  8.59, 3.92, 1.93, 7.81, 6.14,
      1.76, 4.56, 4.02, 4.28, 7.81, 8.51, 7.93, 8.75, 6.21, 6.09, 5.29,
      2.41, 6.44, 8.82, 3.74, 3.3,  2.8,  2.06, 6.93, 4.46, 5.1,  9.03,
      2.79, 7.75, 7.4,  8.97, 7.64, 1.14, 4.05, 10.0, 8.79};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix39) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{7.28, 6.9, 5.46, 5.25};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{9.63, 8.75, 2.8, 5.84};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 2);

  double *arr3 = new double[4]{16.91, 15.65, 8.26, 11.09};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix40) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{3.09, 7.12, 4.6,  7.96, 9.06, 5.36, 5.91, 7.86, 6.29,
                     7.09, 6.09, 8.25, 7.74, 3.08, 2.77, 7.7,  6.26, 5.99};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{7.7,  7.63, 8.63, 3.14, 2.37, 9.97, 1.52, 6.1,  4.5,
                     9.12, 3.03, 1.09, 4.05, 3.54, 5.55, 8.59, 2.09, 8.38};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 6);
  double *arr3 = new double[18]{10.79, 14.75, 13.23, 11.1,  11.43, 15.33,
                                7.43,  13.96, 10.79, 16.21, 9.12,  9.34,
                                11.79, 6.62,  8.32,  16.29, 8.35,  14.37};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix41) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{8.71, 3.61, 1.24, 7.15, 8.28, 7.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{3.47, 1.64, 5.15, 7.75, 6.07, 6.11,
                                5.22, 1.65, 7.05, 7.94, 8.22, 7.88};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix42) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{2.75, 8.17, 6.91, 4.33, 9.79, 3.07,
                                1.83, 3.68, 3.45, 3.2,  8.76, 3.23};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{2.75, 4.28, 2.21, 7.95, 8.08, 4.84,
                                5.41, 8.33, 1.49, 5.04, 8.62, 9.24};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 6);
  double *arr3 = new double[12]{5.5,  12.45, 9.12, 12.28, 17.87, 7.91,
                                7.24, 12.01, 4.94, 8.24,  17.38, 12.47};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix43) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{2.6,  8.73, 1.03, 1.62, 7.93, 3.35, 5.85, 5.26,
                                7.72, 2.06, 9.63, 9.58, 7.35, 3.69, 7.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{5.29, 9.05, 5.25, 6.5,  7.11, 3.98, 3.18, 7.06,
                                1.75, 9.31, 2.3,  9.77, 4.85, 6.73, 1.83};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 5);

  double *arr3 =
      new double[15]{7.89, 17.78, 6.28,  8.12,  15.04, 7.33,  9.03, 12.32,
                     9.47, 11.37, 11.93, 19.35, 12.2,  10.42, 9.57};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix44) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{3.75, 8.57, 6.31, 5.56, 7.04, 6.12, 8.11, 7.23,
                                3.95, 7.5,  2.95, 4.03, 1.36, 4.19, 4.23, 2.54};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{4.25, 3.78, 3.0,  8.07, 3.89, 2.8,  2.24, 6.95, 4.37,
                     4.04, 8.06, 8.86, 2.96, 9.08, 8.18, 7.61, 7.89, 8.63,
                     3.88, 3.29, 4.72, 8.05, 3.85, 1.53, 6.13};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix45) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{1.73, 2.53, 9.04, 9.51, 9.66,
                                6.57, 5.36, 2.25, 3.37, 6.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{1.52, 4.09, 1.51, 9.39, 6.21,
                                2.61, 3.71, 2.99, 3.39, 7.08};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 5);
  double *arr3 = new double[10]{3.25, 6.62, 10.55, 18.9, 15.87,
                                9.18, 9.07, 5.24,  6.76, 13.26};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix46) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{8.5, 5.88, 6.87, 4.2, 7.58, 3.0, 6.05, 1.54};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{8.41, 8.94, 4.96, 8.14, 9.35, 3.03, 5.53, 3.92,
                                6.11, 6.11, 9.78, 7.91, 3.24, 2.03, 9.57};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix47) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{1.19, 9.17, 4.73, 6.64, 5.01, 7.32,
                                8.17, 6.81, 1.47, 3.94, 8.37, 9.39};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{5.69, 2.18, 1.15, 8.82, 1.59, 6.55,
                                5.85, 1.11, 7.57, 1.41, 6.95, 8.99};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 6);

  double *arr3 = new double[12]{6.88,  11.35, 5.88, 15.46, 6.6,   13.87,
                                14.02, 7.92,  9.04, 5.35,  15.32, 18.38};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix48) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{6.51, 6.0, 7.55, 8.95, 5.06, 4.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{7.25, 8.21, 1.72, 8.54, 3.28, 8.81};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);

  double *arr3 = new double[6]{13.76, 14.21, 9.27, 17.49, 8.34, 13.59};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix49) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{7.11, 2.07, 6.75, 1.49, 9.87, 6.36,
                                7.02, 2.85, 4.57, 6.91, 9.53, 6.68};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{3.23, 7.03, 7.29, 5.55, 7.85, 4.73,
                                5.27, 5.79, 1.02, 4.51, 9.04, 2.75};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 4);
  double *arr3 = new double[12]{10.34, 9.1,  14.04, 7.04,  17.72, 11.09,
                                12.29, 8.64, 5.59,  11.42, 18.57, 9.43};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix50) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{5.13, 7.3,  9.68, 1.96, 6.0,  5.59, 4.27, 8.92, 3.37,
                     8.33, 6.65, 2.37, 6.26, 2.02, 1.97, 3.29, 1.33, 6.76,
                     6.4,  2.74, 2.54, 2.61, 4.18, 6.29, 6.97};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      4.34, 3.68, 2.5,  2.57, 8.48, 6.2,  6.28, 4.97, 3.65, 2.49, 2.47, 4.12,
      4.4,  8.55, 3.39, 2.99, 4.93, 9.06, 1.73, 6.86, 4.97, 7.37, 4.86, 5.24,
      3.23, 6.38, 3.71, 4.15, 3.26, 4.58, 9.1,  8.79, 8.02, 7.04, 3.46, 5.57};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix51) {
  S21Matrix matrix1(4, 5);
  double *arr1 =
      new double[20]{2.41, 5.64, 4.01, 5.78, 1.62, 2.23, 8.18, 3.88, 8.98, 7.15,
                     2.95, 2.07, 1.33, 6.41, 3.63, 9.94, 9.94, 1.49, 8.71, 3.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{4.05, 3.56, 5.42, 6.28, 4.62, 7.69, 5.26,
                                7.31, 2.92, 9.19, 7.98, 5.83, 6.12, 3.37,
                                6.14, 7.13, 6.31, 2.84, 1.11, 5.09};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);
  double *arr3 = new double[20]{6.46,  9.2,   9.43,  12.06, 6.24, 9.92, 13.44,
                                11.19, 11.9,  16.34, 10.93, 7.9,  7.45, 9.78,
                                9.77,  17.07, 16.25, 4.33,  9.82, 8.59};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix52) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{5.95, 5.97, 3.33, 6.74, 1.84, 7.9,
                                8.64, 7.09, 1.05, 3.43, 9.77, 4.45};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{7.79, 9.86, 6.39, 6.97, 6.34, 6.21,
                                7.78, 8.23, 5.81, 1.54, 5.27, 9.05};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 2);

  double *arr3 = new double[12]{13.74, 15.83, 9.72, 13.71, 8.18,  14.11,
                                16.42, 15.32, 6.86, 4.97,  15.04, 13.5};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix53) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{5.18, 9.96, 7.22, 7.85, 2.62, 7.83,
                                9.83, 2.99, 3.37, 2.61, 4.78, 6.94};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{9.7,  5.13, 4.34, 3.41, 9.64, 3.53,
                                5.33, 3.8,  8.37, 2.46, 4.55, 6.18};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 4);
  double *arr3 = new double[12]{14.88, 15.09, 11.56, 11.26, 12.26, 11.36,
                                15.16, 6.79,  11.74, 5.07,  9.33,  13.12};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix54) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{9.81, 6.93, 8.52, 7.27, 7.16, 5.64, 7.81, 5.62, 2.45,
                     3.69, 8.54, 1.55, 7.0,  8.7,  2.0,  6.14, 2.44, 9.73};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 =
      new double[28]{2.63, 8.71, 6.7,  2.17, 1.6,  5.65, 7.77, 4.61, 1.57, 7.19,
                     6.48, 6.68, 3.51, 5.93, 5.71, 1.92, 9.29, 5.67, 4.86, 6.4,
                     9.26, 9.66, 4.34, 7.61, 4.62, 7.33, 6.4,  8.33};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix55) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{2.95, 6.81, 1.65, 4.66, 1.57, 7.59, 4.88,
                                3.67, 5.09, 1.22, 9.21, 3.03, 2.43, 5.5,
                                4.22, 7.22, 8.04, 1.46, 2.3,  2.06};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{7.09, 9.25, 8.36, 4.2,  3.69, 4.97, 1.45,
                                3.34, 5.17, 8.31, 5.94, 4.03, 1.87, 4.73,
                                5.39, 9.58, 4.71, 3.36, 4.19, 9.41};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);

  double *arr3 = new double[20]{10.04, 16.06, 10.01, 8.86,  5.26, 12.56, 6.33,
                                7.01,  10.26, 9.53,  15.15, 7.06, 4.3,   10.23,
                                9.61,  16.8,  12.75, 4.82,  6.49, 11.47};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix56) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{2.96, 7.77, 2.3,  4.78, 7.67, 1.32, 1.71, 7.63, 7.71,
                     8.21, 6.24, 4.73, 2.54, 7.01, 1.7,  4.02, 3.31, 2.71,
                     1.93, 6.24, 5.53, 8.92, 6.2,  4.02, 3.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{7.52, 2.48, 7.36, 8.58, 4.85, 5.0,  3.81, 6.04, 6.76,
                     6.58, 8.98, 3.81, 9.2,  2.56, 8.48, 8.05, 1.67, 9.46,
                     9.57, 7.5,  9.84, 3.67, 2.04, 8.87, 5.62};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 5);

  double *arr3 = new double[25]{10.48, 10.25, 9.66,  13.36, 12.52, 6.32,  5.52,
                                13.67, 14.47, 14.79, 15.22, 8.54,  11.74, 9.57,
                                10.18, 12.07, 4.98,  12.17, 11.5,  13.74, 15.37,
                                12.59, 8.24,  12.89, 9.11};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix57) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{5.37, 2.25, 5.14, 7.79, 6.17, 1.6,
                                6.37, 4.81, 1.79, 6.58, 1.0,  1.96};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{9.21, 3.44, 8.06, 5.61, 4.06, 9.04,
                                5.86, 4.96, 2.31, 5.65, 5.79, 7.78};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 3);

  double *arr3 = new double[12]{14.58, 5.69, 13.2, 13.4,  10.23, 10.64,
                                12.23, 9.77, 4.1,  12.23, 6.79,  9.74};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix58) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{1.98, 2.78, 8.15, 4.01, 7.05, 6.13, 5.15, 9.72,
                                5.52, 6.66, 2.31, 4.47, 9.14, 2.98, 4.35, 5.15,
                                6.55, 4.78, 6.63, 2.88, 8.79, 3.08, 6.74, 6.98};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 7);
  double *arr2 = new double[35]{
      7.94, 9.77, 2.68, 2.27, 1.86, 5.08, 7.14, 2.18, 9.56, 7.17, 4.81, 2.38,
      3.58, 4.85, 2.1,  4.25, 4.41, 7.01, 8.1,  5.79, 2.15, 7.98, 4.05, 6.43,
      3.87, 8.02, 3.74, 5.65, 8.26, 6.32, 1.99, 7.84, 7.52, 3.56, 5.94};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix59) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{9.02, 9.34, 5.68, 3.56, 5.55, 4.34, 1.03, 4.52, 9.95,
                     5.9,  6.3,  7.71, 8.77, 7.67, 3.09, 4.34, 3.2,  5.73};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 =
      new double[28]{4.92, 9.52, 6.65, 1.87, 7.54, 7.23, 8.42, 5.73, 4.45, 3.88,
                     2.83, 3.21, 5.96, 8.05, 1.75, 2.17, 3.22, 2.13, 5.11, 2.08,
                     4.97, 1.73, 4.7,  6.83, 8.87, 4.85, 5.54, 3.65};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix60) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{4.56, 5.6, 5.1, 8.82, 7.78, 6.36, 7.06, 1.4, 5.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 =
      new double[9]{2.49, 4.0, 3.62, 5.59, 9.93, 2.61, 6.59, 3.08, 7.29};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 3);
  double *arr3 =
      new double[9]{7.05, 9.6, 8.72, 14.41, 17.71, 8.97, 13.65, 4.48, 13.19};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix61) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{4.6,  8.14, 7.74, 4.26, 5.23, 6.46, 7.79, 4.16,
                                6.52, 1.95, 6.86, 6.05, 8.87, 1.93, 2.45};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{2.21, 4.8,  3.44, 9.84, 9.11, 8.21, 4.22, 6.73,
                                8.49, 3.93, 9.67, 2.83, 9.38, 7.64, 9.67, 8.07,
                                4.3,  3.03, 3.31, 1.43, 1.43, 3.5,  8.91, 8.84};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix62) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{2.43, 1.45, 4.27, 7.08, 5.58, 5.2, 4.31, 4.45, 1.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{6.18, 1.88, 1.24, 6.54, 7.76, 8.94, 9.13, 4.8,
                                4.7,  2.11, 8.4,  5.32, 2.59, 3.33, 9.04, 9.52};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix63) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{5.0,  5.81, 5.82, 1.54, 2.57, 1.06,
                                5.35, 6.48, 8.36, 2.18, 8.42, 9.98};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{4.46, 4.48, 5.12, 7.64, 2.57, 1.86,
                                8.1,  6.45, 8.99, 5.43, 3.62, 4.44};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 2);

  double *arr3 = new double[12]{9.46,  10.29, 10.94, 9.18, 5.14,  2.92,
                                13.45, 12.93, 17.35, 7.61, 12.04, 14.42};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix64) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{1.26, 3.36, 8.3,  3.47, 2.12, 8.59, 1.18, 7.17,
                                2.39, 6.17, 2.1,  9.88, 6.33, 3.75, 5.76, 4.4,
                                1.95, 3.32, 8.28, 1.84, 2.17, 3.83, 2.37, 7.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{9.04, 2.99, 6.31, 9.91, 7.21, 7.84, 9.64, 1.59,
                                9.78, 8.62, 2.59, 1.34, 6.02, 8.2,  6.65, 6.74,
                                3.66, 8.5,  7.03, 8.36, 7.25, 9.82, 6.59, 7.72};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 6);

  double *arr3 =
      new double[24]{10.3,  6.35,  14.61, 13.38, 9.33,  16.43, 10.82, 8.76,
                     12.17, 14.79, 4.69,  11.22, 12.35, 11.95, 12.41, 11.14,
                     5.61,  11.82, 15.31, 10.2,  9.42,  13.65, 8.96,  15.55};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix65) {
  S21Matrix matrix1(4, 5);
  double *arr1 =
      new double[20]{8.12, 4.71, 5.63, 1.22, 9.2,  5.85, 9.59, 2.41, 1.08, 9.16,
                     4.53, 6.98, 6.52, 5.01, 7.24, 5.41, 4.93, 2.32, 5.65, 4.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{8.13, 9.82, 6.17, 7.44, 7.29, 4.4,  3.92,
                                1.35, 1.77, 4.24, 4.07, 5.9,  7.47, 5.79,
                                9.88, 2.87, 2.44, 3.28, 3.74, 4.26};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);
  double *arr3 = new double[20]{16.25, 14.53, 11.8, 8.66, 16.49, 10.25, 13.51,
                                3.76,  2.85,  13.4, 8.6,  12.88, 13.99, 10.8,
                                17.12, 8.28,  7.37, 5.6,  9.39,  9.16};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix66) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{8.65, 6.4,  3.97, 4.12, 8.88, 2.0,
                                2.09, 6.11, 1.66, 8.29, 9.54, 9.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{4.81, 9.48, 2.03, 3.79, 3.97, 2.47,
                                4.33, 8.71, 9.3,  3.89, 4.39, 6.65};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 2);
  double *arr3 = new double[12]{13.46, 15.88, 6.0,   7.91,  12.85, 4.47,
                                6.42,  14.82, 10.96, 12.18, 13.93, 16.58};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix67) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{6.44, 9.72, 5.19, 1.57, 1.59, 9.96, 8.9, 4.76};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{3.41, 4.99, 7.03, 6.78, 1.79, 7.22, 7.09, 4.37};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 2);

  double *arr3 =
      new double[8]{9.85, 14.71, 12.22, 8.35, 3.38, 17.18, 15.99, 9.13};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix68) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{5.17, 6.7,  9.88, 7.29, 1.14, 7.58, 1.99, 2.04, 9.19,
                     9.73, 1.67, 5.09, 9.38, 1.75, 6.05, 2.65, 1.98, 1.84};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 7);
  double *arr2 =
      new double[28]{7.72, 1.68, 6.52, 8.03, 1.09, 9.52, 8.39, 8.35, 1.76, 5.82,
                     9.45, 7.83, 2.91, 5.15, 3.83, 1.17, 5.46, 8.15, 4.01, 1.08,
                     3.53, 4.85, 6.86, 6.03, 7.89, 1.73, 9.03, 6.2};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix69) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{8.96, 7.55, 1.04, 7.71, 1.97,
                                9.25, 1.02, 4.14, 4.14, 7.22};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{2.3, 1.38, 5.33, 1.13, 8.33, 4.43, 5.25, 8.25, 4.98,
                     2.5, 8.65, 8.53, 9.63, 2.21, 7.9,  6.14, 8.22, 3.2};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix70) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{3.5,  6.96, 5.32, 1.98, 8.28, 3.53, 1.13, 8.18,
                                4.81, 3.58, 7.15, 8.01, 3.56, 6.55, 6.05, 7.74,
                                5.9,  2.26, 3.58, 3.91, 4.76, 1.26, 5.31, 4.47};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{7.77, 3.18, 1.78, 4.5,  8.84, 4.17, 6.04, 5.13,
                                2.61, 7.01, 7.99, 5.12, 5.96, 8.44, 1.52, 5.65,
                                8.88, 3.89, 9.2,  7.89, 4.05, 4.82, 4.55, 2.95};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 4);
  double *arr3 =
      new double[24]{11.27, 10.14, 7.1,   6.48,  17.12, 7.7,   7.17, 13.31,
                     7.42,  10.59, 15.14, 13.13, 9.52,  14.99, 7.57, 13.39,
                     14.78, 6.15,  12.78, 11.8,  8.81,  6.08,  9.86, 7.42};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix71) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{1.11, 8.0, 1.92, 9.97, 2.68, 3.95, 1.5, 1.0};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{2.33, 7.8, 8.71, 5.12, 3.08, 3.21, 7.63, 2.92};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 2);

  double *arr3 =
      new double[8]{3.44, 15.8, 10.63, 15.09, 5.76, 7.16, 9.13, 3.92};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix72) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{1.49, 3.47, 4.31, 2.28, 8.21, 6.57, 1.72, 8.39};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{2.9,  7.82, 5.88, 9.55, 2.59, 3.32, 4.84, 7.92,
                                9.24, 1.2,  5.61, 7.88, 3.76, 5.15, 2.35};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix73) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{2.23, 7.33, 1.45, 6.35, 6.61, 6.55, 7.98, 6.38,
                                4.0,  2.09, 6.97, 5.43, 3.13, 7.53, 3.97, 4.93,
                                8.61, 8.13, 7.24, 8.9,  5.57, 6.28, 6.72, 3.13};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{5.2,  5.26, 8.43, 3.51, 4.44, 6.97, 4.29, 1.78,
                                3.82, 5.51, 6.98, 7.3,  6.03, 2.48, 5.31, 3.19,
                                2.27, 3.62, 4.29, 5.38, 4.59, 7.86, 7.06, 7.0};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 4);

  double *arr3 =
      new double[24]{7.43,  12.59, 9.88,  9.86,  11.05, 13.52, 12.27, 8.16,
                     7.82,  7.6,   13.95, 12.73, 9.16,  10.01, 9.28,  8.12,
                     10.88, 11.75, 11.53, 14.28, 10.16, 14.14, 13.78, 10.13};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix74) {
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{6.06, 4.63, 5.19, 5.22, 1.79, 1.01, 1.9, 5.7, 3.06, 8.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{3.54, 5.61, 4.5, 3.05, 2.38, 3.53, 2.87, 6.3, 7.45, 7.64};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 2);

  double *arr3 = new double[10]{9.6,  10.24, 9.69, 8.27,  4.17,
                                4.54, 4.77,  12.0, 10.51, 16.21};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix75) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{6.52, 5.07, 2.77, 7.59, 2.87, 7.66,
                                6.8,  2.97, 2.05, 6.56, 8.69, 9.43};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{1.35, 8.24, 8.42, 1.34, 6.76, 4.51,
                                2.73, 5.94, 7.19, 9.77, 7.68, 2.05};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 6);

  double *arr3 = new double[12]{7.87, 13.31, 11.19, 8.93,  9.63,  12.17,
                                9.53, 8.91,  9.24,  16.33, 16.37, 11.48};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix76) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{1.23, 3.34, 6.52, 9.76, 9.82, 7.76, 8.08, 4.62, 9.66};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{3.67, 4.88, 8.09, 9.28, 6.39, 6.17, 4.81, 4.21,
                                1.07, 9.11, 4.79, 9.53, 3.72, 1.94, 4.0,  4.56};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix77) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{5.64, 8.1,  8.85, 3.72, 2.38, 6.92, 9.79, 6.16,
                                2.99, 7.52, 5.26, 9.16, 3.18, 8.63, 4.81, 4.42,
                                9.83, 2.59, 4.35, 4.84, 1.09, 1.88, 7.12, 6.42};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{8.54, 7.3,  4.07, 5.32, 7.29, 9.44, 4.45, 9.1,
                                8.67, 3.77, 5.98, 6.02, 1.76, 4.43, 9.3,  3.22,
                                9.64, 8.02, 2.96, 9.15, 8.32, 6.91, 9.2,  2.19};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 4);
  double *arr3 =
      new double[24]{14.18, 15.4,  12.92, 9.04,  9.67, 16.36, 14.24, 15.26,
                     11.66, 11.29, 11.24, 15.18, 4.94, 13.06, 14.11, 7.64,
                     19.47, 10.61, 7.31,  13.99, 9.41, 8.79,  16.32, 8.61};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix78) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{4.29, 8.42, 6.51, 3.5,  8.98, 3.19, 3.51, 7.42,
                                6.34, 2.55, 9.16, 9.12, 2.72, 8.01, 9.31, 2.42,
                                4.27, 9.59, 6.65, 5.43, 9.28, 7.95, 7.54, 6.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{5.73, 7.81, 2.7,  2.32, 1.14, 9.09, 6.85, 6.31,
                                6.1,  4.12, 4.74, 5.53, 9.13, 8.28, 7.95, 4.39,
                                4.69, 8.47, 2.81, 7.37, 8.26, 4.8,  6.7,  9.3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 4);

  double *arr3 =
      new double[24]{10.02, 16.23, 9.21, 5.82,  10.12, 12.28, 10.36, 13.73,
                     12.44, 6.67,  13.9, 14.65, 11.85, 16.29, 17.26, 6.81,
                     8.96,  18.06, 9.46, 12.8,  17.54, 12.75, 14.24, 15.39};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix79) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{3.51, 5.63, 9.56, 8.89, 3.47, 1.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{8.07, 1.38, 8.93, 5.18, 1.01, 1.37};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);
  double *arr3 = new double[6]{11.58, 7.01, 18.49, 14.07, 4.48, 2.86};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix80) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{4.12, 9.65, 8.06, 3.53, 5.8,  4.82, 6.42,
                                7.37, 7.19, 9.83, 3.59, 2.97, 4.02, 3.46,
                                9.87, 8.32, 6.8,  6.96, 6.79, 1.46};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{6.73, 7.01, 4.67, 3.34, 4.12, 7.53, 4.17,
                                7.98, 8.88, 3.08, 2.59, 9.73, 6.49, 2.29,
                                6.06, 1.79, 8.3,  4.95, 1.51, 1.96};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 5);
  double *arr3 = new double[20]{10.85, 16.66, 12.73, 6.87,  9.92, 12.35, 10.59,
                                15.35, 16.07, 12.91, 6.18,  12.7, 10.51, 5.75,
                                15.93, 10.11, 15.1,  11.91, 8.3,  3.42};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix81) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{6.59, 8.31, 1.07, 5.68, 2.45, 5.83, 6.06, 7.12, 7.4,
                     5.78, 5.58, 3.36, 8.06, 4.31, 8.11, 2.19, 5.43, 3.59};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{3.08, 6.7,  4.48, 7.39, 9.28, 7.6,  8.27, 5.57, 4.08,
                     3.12, 6.55, 7.8,  5.36, 5.0,  2.82, 1.19, 8.42, 3.95};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 3);

  double *arr3 = new double[18]{9.67,  15.01, 5.55,  13.07, 11.73, 13.43,
                                14.33, 12.69, 11.48, 8.9,   12.13, 11.16,
                                13.42, 9.31,  10.93, 3.38,  13.85, 7.54};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix82) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{6.12, 9.82, 8.32, 8.43, 4.38, 2.89, 1.81, 2.77};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{1.1, 6.2, 4.54, 4.8, 2.87, 2.95, 1.45, 1.56};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(2, 4);

  double *arr3 =
      new double[8]{7.22, 16.02, 12.86, 13.23, 7.25, 5.84, 3.26, 4.33};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix83) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{6.29, 3.28, 7.29, 2.81, 6.86, 8.45};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{3.96, 3.46, 5.59, 2.01, 1.86, 7.79};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);

  double *arr3 = new double[6]{10.25, 6.74, 12.88, 4.82, 8.72, 16.24};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix84) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      7.31, 2.47, 5.75, 2.17, 7.71, 3.56, 8.22, 8.86, 6.97, 2.53, 4.59, 4.87,
      5.38, 8.24, 9.93, 7.41, 1.55, 9.94, 5.37, 1.61, 3.71, 4.11, 3.78, 7.54,
      2.96, 1.83, 2.32, 3.93, 9.21, 3.27, 1.26, 2.9,  7.89, 1.42, 7.46, 6.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      9.38, 2.15, 6.3,  3.32, 7.4,  4.52, 7.38, 9.23, 2.81, 5.49, 4.99, 7.59,
      4.35, 8.44, 6.94, 5.91, 7.76, 1.49, 2.53, 5.71, 5.62, 4.58, 2.19, 5.73,
      8.34, 5.28, 6.84, 5.27, 7.87, 7.38, 1.01, 7.13, 8.87, 6.91, 3.4,  9.83};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 6);
  double *arr3 = new double[36]{
      16.69, 4.62,  12.05, 5.49, 15.11, 8.08,  15.6,  18.09, 9.78,
      8.02,  9.58,  12.46, 9.73, 16.68, 16.87, 13.32, 9.31,  11.43,
      7.9,   7.32,  9.33,  8.69, 5.97,  13.27, 11.3,  7.11,  9.16,
      9.2,   17.08, 10.65, 2.27, 10.03, 16.76, 8.33,  10.86, 15.87};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix85) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{4.81, 5.12, 1.3, 7.05, 5.08, 6.96, 1.94, 5.44};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{5.23, 7.46, 8.97, 7.11, 7.84, 1.08, 1.76, 6.94};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 2);

  double *arr3 =
      new double[8]{10.04, 12.58, 10.27, 14.16, 12.92, 8.04, 3.7, 12.38};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix86) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{6.59, 2.99, 9.99, 7.67, 4.25, 2.63};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{6.84, 8.1, 8.74, 7.22, 6.61, 1.64};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 2);
  double *arr3 = new double[6]{13.43, 11.09, 18.73, 14.89, 10.86, 4.27};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix87) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{8.44, 8.49, 5.67, 1.22, 7.56, 1.57, 7.21,
                                2.02, 2.27, 3.12, 6.92, 6.89, 2.02, 6.95,
                                2.57, 3.52, 9.35, 2.79, 8.38, 5.08};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{4.74, 2.89, 5.8,  3.64, 5.67, 6.86, 2.95, 6.06,
                                9.21, 9.89, 1.53, 1.61, 9.39, 5.22, 8.49, 1.72,
                                8.56, 5.49, 3.54, 1.74, 2.95, 3.91, 9.89, 5.87,
                                2.08, 9.0,  2.9,  6.73, 8.89, 2.65};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix88) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{8.41, 4.25, 1.23, 5.61, 4.35, 7.86, 1.82, 1.86,
                                9.08, 4.56, 6.03, 7.84, 9.51, 2.85, 3.98, 3.44,
                                2.28, 2.12, 1.38, 9.64, 5.15, 3.95, 4.98, 8.63,
                                8.13, 7.75, 7.2,  7.56, 5.46, 7.07};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{5.42, 8.28, 3.42, 4.68, 7.34, 9.72, 8.26, 7.07,
                                7.02, 2.57, 4.6,  2.72, 3.89, 7.29, 8.26, 6.93,
                                2.28, 5.18, 5.23, 9.67, 1.32, 3.23, 9.78, 3.92,
                                1.36, 7.17, 5.97, 3.61, 8.39, 8.58};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(6, 5);
  double *arr3 = new double[30]{
      13.83, 12.53, 4.65,  10.29, 11.69, 17.58, 10.08, 8.93,  16.1,  7.13,
      10.63, 10.56, 13.4,  10.14, 12.24, 10.37, 4.56,  7.3,   6.61,  19.31,
      6.47,  7.18,  14.76, 12.55, 9.49,  14.92, 13.17, 11.17, 13.85, 15.65};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix89) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{5.11, 4.38, 3.63, 8.0,  1.28, 3.07, 9.3,  7.43,
                                7.98, 9.3,  3.6,  8.41, 6.22, 7.18, 8.23, 2.79};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{3.98, 6.27, 8.35, 5.99, 7.09, 7.42, 2.82, 5.64,
                                3.63, 1.72, 5.39, 2.87, 1.2,  2.68, 8.68, 3.96};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 4);
  double *arr3 =
      new double[16]{9.09,  10.65, 11.98, 13.99, 8.37, 10.49, 12.12, 13.07,
                     11.61, 11.02, 8.99,  11.28, 7.42, 9.86,  16.91, 6.75};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix90) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{3.39, 6.7,  3.36, 8.22, 1.22, 8.35, 7.43, 9.02,
                                2.1,  4.35, 6.19, 9.74, 7.78, 1.9,  4.55, 5.4,
                                1.2,  6.13, 5.83, 7.23, 6.59, 7.09, 1.72, 4.41,
                                5.07, 3.28, 7.26, 9.43, 3.61, 3.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{3.84, 6.24, 5.02, 2.13, 9.29, 3.42, 8.24, 9.74,
                                9.89, 9.13, 5.1,  5.98, 4.43, 6.4,  7.63, 7.75,
                                1.96, 6.48, 9.3,  2.47, 9.72, 5.02, 8.31, 2.47,
                                2.85, 8.69, 8.41, 4.06, 2.84, 9.51};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 6);

  double *arr3 = new double[30]{
      7.23,  12.94, 8.38,  10.35, 10.51, 11.77, 15.67, 18.76, 11.99, 13.48,
      11.29, 15.72, 12.21, 8.3,   12.18, 13.15, 3.16,  12.61, 15.13, 9.7,
      16.31, 12.11, 10.03, 6.88,  7.92,  11.97, 15.67, 13.49, 6.45,  12.85};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix91) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{2.61, 2.22, 5.47, 8.66, 5.53,
                                7.45, 5.21, 8.35, 4.01, 1.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{2.07, 7.58, 4.49, 4.21, 4.96, 4.49, 2.12, 2.89, 9.04,
                     9.68, 9.07, 1.51, 7.67, 2.16, 4.36, 3.98, 7.51, 6.13};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix92) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{5.69, 5.67, 6.46, 2.94, 3.62, 1.95,
                                4.56, 9.77, 3.35, 9.83, 1.46, 3.67};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{6.46, 3.22, 4.65, 6.75, 3.29, 8.53,
                                3.47, 3.13, 8.32, 7.63, 7.04, 2.1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 3);

  double *arr3 = new double[12]{12.15, 8.89, 11.11, 9.69,  6.91, 10.48,
                                8.03,  12.9, 11.67, 17.46, 8.5,  5.77};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix93) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{7.27, 3.3, 9.2, 4.91, 7.64, 3.81, 7.43, 9.9, 5.56};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{2.24, 3.8, 8.21, 9.55, 5.95, 1.9,  8.65, 6.59,
                                6.28, 5.0, 8.93, 6.3,  2.66, 8.65, 1.88, 5.8};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix94) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{5.69, 7.91, 6.79, 2.28, 4.88, 8.97, 9.29, 1.21, 6.37};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 =
      new double[9]{1.03, 4.43, 3.73, 3.88, 7.96, 5.79, 3.77, 8.77, 9.66};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 3);

  double *arr3 =
      new double[9]{6.72, 12.34, 10.52, 6.16, 12.84, 14.76, 13.06, 9.98, 16.03};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix95) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      3.53, 9.24, 6.48, 9.22, 5.95, 6.2,  7.38, 9.71, 4.81, 2.79, 1.12, 2.48,
      4.99, 3.95, 3.37, 4.97, 6.85, 5.09, 3.2,  1.13, 5.04, 5.67, 2.34, 6.56,
      3.04, 4.74, 3.2,  3.43, 9.76, 1.7,  4.51, 4.98, 3.42, 2.61, 8.27, 6.4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 7);
  double *arr2 =
      new double[49]{9.67, 6.94, 7.17, 8.25, 2.2,  7.31, 8.27, 7.08, 3.98, 6.26,
                     9.24, 2.55, 5.39, 4.57, 8.89, 8.42, 5.93, 7.12, 5.58, 8.82,
                     3.09, 9.92, 9.6,  4.88, 5.22, 4.16, 4.23, 6.79, 9.41, 8.14,
                     8.5,  5.32, 4.93, 3.98, 5.87, 9.99, 5.74, 9.96, 3.1,  7.54,
                     6.05, 4.17, 6.38, 6.79, 2.7,  3.87, 2.57, 4.37, 7.32};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix96) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{3.09, 1.46, 2.02, 5.57, 6.03, 9.46,
                                8.7,  9.48, 3.38, 7.91, 3.32, 1.29};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{4.02, 4.03, 8.65, 7.06, 2.47, 7.38,
                                4.79, 6.6,  9.0,  5.91, 2.78, 4.77};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(3, 4);
  double *arr3 = new double[12]{7.11,  5.49,  10.67, 12.63, 8.5, 16.84,
                                13.49, 16.08, 12.38, 13.82, 6.1, 6.06};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix97) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{2.85, 3.88, 8.08, 6.22, 4.2, 2.14, 9.15, 7.15, 9.84};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{5.11, 2.78, 6.71, 8.38, 3.51, 5.92, 9.47, 6.71,
                                5.17, 6.26, 9.61, 6.27, 9.19, 8.86, 5.39, 1.41};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSumTest, SumMatrix98) {
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{2.39, 1.5, 3.01, 9.01, 1.13, 7.74, 1.56, 1.08, 9.52, 8.22};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{9.97, 7.84, 1.89, 6.69, 3.86, 5.79, 9.46, 4.0, 5.72, 1.87};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 2);
  double *arr3 = new double[10]{12.36, 9.34,  4.9,  15.7,  4.99,
                                13.53, 11.02, 5.08, 15.24, 10.09};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix99) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{7.18, 8.87, 7.37, 2.45, 9.14, 3.76, 4.66, 1.62,
                                3.22, 8.84, 1.61, 3.62, 4.14, 1.67, 2.16, 4.98,
                                2.65, 9.76, 7.92, 1.96, 5.17, 2.77, 7.17, 2.01,
                                9.86, 9.86, 5.79, 1.36, 6.17, 2.25};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 =
      new double[30]{7.27, 3.11, 5.7,  2.88, 6.15, 8.01, 3.68, 5.34, 7.18, 4.08,
                     2.46, 8.74, 8.32, 5.72, 5.63, 3.21, 8.02, 8.85, 7.9,  3.09,
                     3.47, 2.18, 8.81, 3.23, 1.75, 9.52, 8.68, 2.53, 7.35, 9.2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(5, 6);
  double *arr3 = new double[30]{
      14.45, 11.98, 13.07, 5.33, 15.29, 11.77, 8.34,  6.96,  10.4,  12.92,
      4.07,  12.36, 12.46, 7.39, 7.79,  8.19,  10.67, 18.61, 15.82, 5.05,
      8.64,  4.95,  15.98, 5.24, 11.61, 19.38, 14.47, 3.89,  13.52, 11.45};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result += matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSum);
}

TEST(MatrixSumTest, SumMatrix100) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{8.47, 1.91, 3.71, 9.51, 8.39, 3.53, 4.2, 2.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{6.33, 7.68, 3.38, 4.14, 1.36, 5.53, 8.1, 9.44};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSum(4, 2);

  double *arr3 =
      new double[8]{14.8, 9.59, 7.09, 13.65, 9.75, 9.06, 12.3, 11.48};
  expectedSum.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 + matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  ASSERT_TRUE(result == expectedSum);
}
