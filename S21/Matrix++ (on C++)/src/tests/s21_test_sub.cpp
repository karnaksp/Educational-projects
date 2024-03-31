#include "s21_test.h"

TEST(MatrixSubTest, SubMatrix1) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{7.77, 1.07, 5.64, 2.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{2.06, 1.75, 6.61, 2.08};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 2);
  double *arr3 = new double[4]{5.71, -0.68, -0.97, 0.26};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix2) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{4.34, 3.07, 3.03, 5.74, 7.01, 5.38, 3.25, 1.03,
                                5.98, 3.89, 5.74, 2.85, 9.73, 5.36, 9.95};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{8.72, 1.83, 4.47, 6.32, 5.65, 1.96, 4.32, 8.72,
                                1.77, 3.37, 7.01, 3.56, 2.12, 6.86, 7.85};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 5);
  double *arr3 =
      new double[15]{-4.38, 1.24, -1.44, -0.58, 1.36, 3.42, -1.07, -7.69,
                     4.21,  0.52, -1.27, -0.71, 7.61, -1.5, 2.1};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix3) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{3.96, 3.24, 4.74, 8.95, 6.91,
                                9.78, 2.11, 4.66, 1.98, 6.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{4.11, 7.84, 4.73, 4.07, 5.21, 8.12, 6.7,  4.49, 6.97,
                     7.1,  1.15, 7.53, 3.48, 7.74, 9.09, 4.47, 3.48, 9.51};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix4) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{1.5,  8.81, 6.06, 9.43, 4.57, 4.9,  3.5, 2.27,
                                6.55, 1.37, 4.37, 2.78, 2.07, 9.32, 2.25};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{8.09, 7.86, 7.28, 2.24, 6.14, 8.91, 5.45, 2.42,
                                5.37, 6.05, 3.67, 4.81, 6.62, 9.61, 6.36, 9.68,
                                4.0,  1.25, 2.44, 4.2,  5.19, 7.83, 1.53, 5.18};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix5) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{8.57, 6.66, 1.52, 2.85};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{2.03, 9.44, 7.47, 8.64};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 2);
  double *arr3 = new double[4]{6.54, -2.78, -5.95, -5.79};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix6) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{1.43, 6.11, 2.46, 7.78, 6.25, 7.25, 7.21, 5.77, 2.11,
                     8.24, 5.49, 8.68, 9.85, 4.17, 5.48, 6.65, 1.67, 7.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{3.17, 2.18, 5.12, 5.96, 8.65, 2.25, 1.64, 3.95, 7.18,
                     2.88, 3.46, 6.67, 5.8,  3.86, 5.76, 8.54, 1.38, 7.2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 =
      new double[18]{-1.74, 3.93, -2.66, 1.82, -2.4, 5.0,   5.57,  1.82, -5.07,
                     5.36,  2.03, 2.01,  4.05, 0.31, -0.28, -1.89, 0.29, 0.54};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix7) {
  S21Matrix matrix1(2, 5);
  double *arr1 =
      new double[10]{9.77, 3.2, 7.65, 9.97, 8.73, 5.03, 6.55, 7.71, 8.7, 7.88};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 =
      new double[10]{4.34, 5.39, 6.17, 4.51, 7.92, 4.32, 8.77, 1.11, 8.3, 1.16};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 5);
  double *arr3 = new double[10]{5.43, -2.19, 1.48, 5.46, 0.81,
                                0.71, -2.22, 6.6,  0.4,  6.72};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix8) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{9.26, 5.53, 6.47, 2.19, 6.92, 1.33,
                                8.29, 1.63, 5.86, 1.59, 2.95, 6.36};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 7);
  double *arr2 = new double[21]{5.9,  2.26, 8.79, 2.92, 2.17, 4.16, 9.56,
                                1.3,  8.89, 1.52, 8.56, 8.83, 8.28, 8.43,
                                9.61, 9.43, 1.78, 1.03, 7.89, 8.19, 8.75};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix9) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{6.15, 7.75, 9.14, 9.36, 9.64, 3.04,
                                8.18, 8.83, 3.19, 7.67, 9.26, 8.87};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{3.34, 7.55, 9.86, 3.08, 7.05, 5.47,
                                8.61, 4.41, 5.45, 8.05, 4.24, 6.27};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 2);
  double *arr3 = new double[12]{2.81,  0.2,  -0.72, 6.28,  2.59, -2.43,
                                -0.43, 4.42, -2.26, -0.38, 5.02, 2.6};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix10) {
  S21Matrix matrix1(4, 5);
  double *arr1 =
      new double[20]{9.98, 7.75, 4.77, 1.17, 4.17, 4.71, 5.58, 9.96, 5.87, 1.35,
                     2.17, 7.11, 5.66, 2.26, 7.89, 8.56, 9.29, 9.22, 1.7,  4.8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{5.15, 3.74, 8.31, 6.69, 5.44, 8.71, 1.83,
                                8.74, 1.17, 1.98, 2.98, 8.48, 8.11, 3.41,
                                2.7,  8.79, 4.92, 1.93, 7.86, 3.24};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 5);
  double *arr3 = new double[20]{4.83, 4.01,  -3.54, -5.52, -1.27, -4.0,  3.75,
                                1.22, 4.7,   -0.63, -0.81, -1.37, -2.45, -1.15,
                                5.19, -0.23, 4.37,  7.29,  -6.16, 1.56};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix11) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.51, 5.76, 3.98, 2.69, 4.51, 1.41};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{3.73, 6.04, 4.59, 1.25, 6.38, 2.91,
                                8.06, 1.34, 5.8,  5.26, 7.53, 6.87};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix12) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{3.39, 3.54, 5.4, 5.2, 5.21, 7.82, 1.04, 9.24};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{2.19, 1.04, 1.4,  6.2,  2.17, 1.92, 5.69, 7.42,
                                8.32, 9.7,  7.66, 3.13, 8.23, 2.92, 6.74};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix13) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{7.43, 1.33, 7.04, 6.76, 8.81, 6.57, 5.22, 7.66, 9.42,
                     4.88, 5.27, 5.53, 7.16, 3.1,  1.33, 3.5,  3.35, 5.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{9.2,  8.82, 3.17, 6.02, 3.89, 4.92, 3.13, 4.96, 7.64,
                     3.54, 2.88, 4.57, 1.3,  1.43, 2.39, 8.22, 5.16, 1.71};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 =
      new double[18]{-1.77, -7.49, 3.87, 0.74, 4.92, 1.65,  2.09,  2.7,   1.78,
                     1.34,  2.39,  0.96, 5.86, 1.67, -1.06, -4.72, -1.81, 3.78};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix14) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{6.56, 7.98, 4.62, 2.68, 7.36, 7.45};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{5.79, 8.81, 1.68, 2.76, 8.9,  4.48,
                                7.21, 7.93, 9.85, 9.46, 7.76, 7.98};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix15) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{7.75, 9.05, 8.34, 8.62, 2.69, 3.55,
                                2.42, 7.34, 1.4,  1.56, 5.88, 7.68};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{9.74, 7.76, 4.19, 9.61, 1.26, 5.85, 9.68,
                                2.64, 5.71, 6.01, 4.37, 8.86, 7.39, 4.19,
                                8.63, 2.29, 8.13, 5.62, 7.93, 7.05};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix16) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{8.66, 2.16, 6.61, 3.93, 3.64, 8.87, 8.62, 6.86, 5.26,
                     5.07, 4.22, 9.81, 9.47, 5.01, 6.46, 4.95, 1.71, 5.43,
                     6.27, 4.64, 6.82, 4.71, 3.8,  4.13, 3.76};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      7.33, 4.3,  2.23, 4.25, 6.23, 4.26, 3.01, 5.95, 9.63, 6.93, 4.23, 2.21,
      2.56, 1.56, 2.66, 4.84, 2.57, 7.39, 2.32, 4.37, 8.22, 6.04, 3.43, 3.1,
      7.89, 8.12, 3.96, 5.87, 1.6,  9.94, 9.04, 6.19, 1.41, 9.06, 5.27, 9.83};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix17) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{3.84, 2.26, 8.19, 6.8, 5.14, 9.51, 6.67, 5.55};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{5.56, 2.03, 5.96, 8.14, 5.72, 7.75, 4.7, 6.49};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 4);
  double *arr3 =
      new double[8]{-1.72, 0.23, 2.23, -1.34, -0.58, 1.76, 1.97, -0.94};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix18) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{2.61, 6.24, 7.3,  7.03, 5.2,  4.06,
                                3.51, 5.6,  4.82, 3.88, 2.24, 7.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{6.04, 5.22, 5.98, 3.23, 8.76, 8.49,
                                5.56, 4.05, 4.95, 4.26, 1.95, 8.0};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 6);
  double *arr3 = new double[12]{-3.43, 1.02, 1.32,  3.8,   -3.56, -4.43,
                                -2.05, 1.55, -0.13, -0.38, 0.29,  -0.66};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix19) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      8.01, 1.77, 4.69, 8.49, 9.6,  5.04, 6.11, 2.93, 4.34, 4.15, 4.53, 7.89,
      9.18, 8.23, 4.96, 3.33, 3.0,  8.89, 9.57, 3.34, 5.83, 9.37, 4.38, 9.01,
      7.16, 4.21, 1.88, 5.36, 7.32, 4.97, 5.78, 7.67, 1.58, 3.09, 9.89, 7.73};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      2.49, 6.14, 5.83, 4.48, 6.79, 5.13, 4.47, 5.53, 4.48, 1.68, 6.65, 3.79,
      8.61, 2.4,  9.4,  7.2,  7.7,  2.35, 9.12, 6.79, 2.07, 5.69, 4.01, 6.65,
      4.38, 7.61, 6.91, 8.57, 8.36, 3.2,  3.96, 4.31, 8.54, 2.34, 3.09, 4.85};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 6);
  double *arr3 =
      new double[36]{5.52,  -4.37, -1.14, 4.01, 2.81, -0.09, 1.64,  -2.6, -0.14,
                     2.47,  -2.12, 4.1,   0.57, 5.83, -4.44, -3.87, -4.7, 6.54,
                     0.45,  -3.45, 3.76,  3.68, 0.37, 2.36,  2.78,  -3.4, -5.03,
                     -3.21, -1.04, 1.77,  1.82, 3.36, -6.96, 0.75,  6.8,  2.88};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix20) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{7.37, 6.76, 8.35, 7.8,  1.46, 7.95,
                                1.71, 3.36, 2.37, 2.86, 8.08, 3.68};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{3.98, 2.97, 5.07, 6.25, 8.76, 7.29, 4.35,
                                4.55, 6.87, 2.89, 5.4,  9.27, 4.06, 7.77,
                                5.72, 5.52, 5.87, 3.87, 9.8,  9.72, 4.73};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix21) {
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{7.86, 9.18, 6.85, 1.9, 2.44, 7.3, 9.64, 1.44, 1.37, 2.42};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{7.17, 8.16, 5.37, 8.39, 9.68,
                                9.07, 4.37, 3.43, 9.56, 4.98};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 2);
  double *arr3 = new double[10]{0.69,  1.02, 1.48,  -6.49, -7.24,
                                -1.77, 5.27, -1.99, -8.19, -2.56};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix22) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{5.92, 1.85, 2.64, 3.28, 6.66, 6.5,  7.41, 2.51,
                                9.8,  9.11, 2.76, 6.54, 6.03, 6.8,  2.71, 6.46,
                                4.12, 6.5,  8.52, 1.62, 7.55, 2.33, 8.45, 9.98};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 7);
  double *arr2 = new double[35]{
      9.48, 2.89, 2.86, 3.52, 7.55, 6.79, 5.33, 9.47, 6.78, 6.49, 4.12, 9.32,
      6.31, 6.64, 9.51, 8.48, 8.99, 5.58, 9.42, 8.71, 5.67, 8.79, 9.23, 8.75,
      2.77, 4.15, 2.44, 8.74, 9.38, 3.37, 1.83, 2.75, 5.24, 4.79, 7.62};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix23) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{3.49, 2.95, 5.93, 7.71, 2.65, 1.84, 2.54, 7.57,
                                7.52, 8.66, 8.87, 2.01, 1.0,  8.43, 3.59, 1.41};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{1.36, 1.99, 3.15, 1.73, 4.94, 8.89, 1.71, 4.39,
                                9.85, 1.4,  9.03, 5.99, 1.79, 4.39, 1.96, 9.97};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 4);
  double *arr3 =
      new double[16]{2.13,  0.96, 2.78,  5.98,  -2.29, -7.05, 0.83, 3.18,
                     -2.33, 7.26, -0.16, -3.98, -0.79, 4.04,  1.63, -8.56};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix24) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{2.17, 8.24, 8.44, 5.38, 2.2,  1.66, 2.15,
                                5.82, 2.06, 2.2,  2.92, 1.04, 6.17, 8.22,
                                3.36, 6.66, 1.78, 5.82, 8.07, 7.88};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 =
      new double[20]{7.33, 5.29, 8.22, 1.33, 9.11, 5.26, 8.69, 2.64, 5.09, 8.7,
                     5.27, 9.02, 3.57, 5.73, 2.86, 5.51, 4.97, 1.85, 5.01, 4.4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 5);
  double *arr3 = new double[20]{-5.16, 2.95,  0.22,  4.05,  -6.91, -3.6, -6.54,
                                3.18,  -3.03, -6.5,  -2.35, -7.98, 2.6,  2.49,
                                0.5,   1.15,  -3.19, 3.97,  3.06,  3.48};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix25) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{2.22, 4.29, 7.83, 1.28, 5.18, 5.54, 1.66, 2.81,
                                4.08, 5.14, 2.19, 3.65, 6.4,  6.28, 8.39, 8.26,
                                6.21, 3.02, 1.64, 3.27, 2.64, 6.73, 4.37, 7.41,
                                9.32, 2.23, 9.3,  8.22, 6.45, 6.66};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{7.54, 8.76, 2.8,  6.92, 6.04, 1.76, 2.46, 8.04,
                                3.36, 3.02, 1.82, 8.87, 9.57, 8.31, 9.34, 9.8,
                                4.51, 6.13, 4.41, 5.8,  7.04, 8.57, 7.88, 9.9,
                                7.61, 6.14, 2.19, 3.81, 7.91, 5.89};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 6);
  double *arr3 = new double[30]{
      -5.32, -4.47, 5.03,  -5.64, -0.86, 3.78,  -0.8, -5.23, 0.72,  2.12,
      0.37,  -5.22, -3.17, -2.03, -0.95, -1.54, 1.7,  -3.11, -2.77, -2.53,
      -4.4,  -1.84, -3.51, -2.49, 1.71,  -3.91, 7.11, 4.41,  -1.46, 0.77};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix26) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{9.39, 3.33, 3.27, 4.3,  6.2,  6.98,
                                5.5,  3.24, 6.98, 8.69, 2.64, 4.19};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{1.01, 5.71, 2.84, 8.92, 9.83, 1.37, 1.83,
                                4.5,  9.54, 2.19, 1.23, 6.11, 1.68, 8.39,
                                9.75, 4.43, 4.72, 1.58, 6.92, 8.66, 6.78};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix27) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{2.11, 7.26, 9.65, 3.87, 3.45, 2.81, 9.35, 5.47, 2.05};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{8.95, 1.77, 4.22, 4.08, 5.56, 8.97, 8.07, 4.68,
                                5.05, 6.29, 2.15, 9.27, 8.93, 4.75, 8.32, 9.72};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix28) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{2.8,  8.66, 5.64, 2.0,  2.58, 7.19, 2.09, 10.0,
                                9.36, 9.06, 8.84, 5.03, 5.4,  8.9,  8.42, 1.76,
                                4.21, 4.93, 5.08, 7.41, 2.25, 6.67, 1.88, 5.7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{5.05, 4.28, 9.5,  1.47, 6.17, 1.64, 4.37, 1.09,
                                3.08, 9.5,  4.62, 8.51, 1.73, 9.86, 5.91, 6.01,
                                8.02, 1.44, 9.91, 4.43, 4.93, 4.59, 6.78, 1.7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 4);
  double *arr3 =
      new double[24]{-2.25, 4.38,  -3.86, 0.53,  -3.59, 5.55,  -2.28, 8.91,
                     6.28,  -0.44, 4.22,  -3.48, 3.67,  -0.96, 2.51,  -4.25,
                     -3.81, 3.49,  -4.83, 2.98,  -2.68, 2.08,  -4.9,  4.0};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix29) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{7.55, 2.67, 4.59, 4.84, 4.24, 3.09, 8.02, 7.83,
                                1.23, 2.68, 5.94, 3.55, 7.19, 3.47, 5.64, 3.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{8.88, 9.37, 6.13, 2.99, 3.22, 4.16, 1.21, 6.34, 2.35,
                     7.12, 4.16, 5.47, 5.01, 1.72, 3.81, 7.89, 2.15, 8.59,
                     2.84, 6.84, 5.03, 1.04, 2.29, 4.22, 2.29};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix30) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.29, 8.9, 5.04, 9.18, 2.67, 5.79};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{9.56, 6.65, 7.42, 4.53, 8.75, 4.58};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 3);
  double *arr3 = new double[6]{-0.27, 2.25, -2.38, 4.65, -6.08, 1.21};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix31) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{4.63, 6.12, 8.14, 8.71, 2.75, 4.28,
                                5.98, 1.12, 4.93, 6.23, 3.42, 6.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{8.28, 1.28, 6.07, 9.07, 7.93, 6.21,
                                5.25, 8.62, 1.63, 9.97, 4.38, 9.04};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 6);
  double *arr3 = new double[12]{-3.65, 4.84, 2.07, -0.36, -5.18, -1.93,
                                0.73,  -7.5, 3.3,  -3.74, -0.96, -2.26};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix32) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{1.29, 9.53, 8.29, 5.54, 5.77, 4.81, 1.82, 6.46,
                                5.9,  8.36, 6.35, 2.8,  3.06, 2.4,  5.39, 8.29,
                                2.9,  6.16, 3.7,  1.17, 2.43, 8.68, 3.41, 6.41};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{8.72, 9.52, 5.19, 1.45, 8.65, 8.65, 3.01, 3.12,
                                2.95, 4.73, 9.93, 1.4,  7.88, 2.95, 7.85, 5.13,
                                6.25, 1.7,  7.36, 4.09, 1.17, 3.38, 4.33, 2.12};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 4);
  double *arr3 =
      new double[24]{-7.43, 0.01, 3.1,   4.09,  -2.88, -3.84, -1.19, 3.34,
                     2.95,  3.63, -3.58, 1.4,   -4.82, -0.55, -2.46, 3.16,
                     -3.35, 4.46, -3.66, -2.92, 1.26,  5.3,   -0.92, 4.29};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix33) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{1.74, 7.28, 8.71, 9.84, 9.06, 7.11, 8.39, 8.16,
                                6.61, 6.94, 7.99, 2.36, 8.9,  6.99, 9.56, 2.99,
                                7.58, 7.49, 7.15, 2.55, 5.51, 7.51, 3.23, 4.79,
                                1.16, 1.7,  9.09, 3.84, 3.6,  1.17};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 6);
  double *arr2 = new double[42]{
      9.13, 3.14, 7.86, 1.09, 6.42, 4.28, 2.07, 4.18, 4.69, 4.96, 2.66,
      3.31, 3.53, 7.29, 8.56, 2.17, 5.38, 1.39, 9.76, 4.71, 9.1,  4.58,
      8.35, 1.41, 9.73, 7.88, 7.51, 2.45, 8.74, 1.97, 4.87, 2.02, 8.74,
      1.11, 9.82, 6.77, 5.52, 1.95, 4.17, 6.74, 1.01, 3.57};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix34) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{3.27, 6.79, 1.01, 9.5,  4.06, 9.29, 3.74, 4.83,
                                2.17, 3.5,  1.6,  9.8,  7.96, 1.05, 2.64, 8.79,
                                5.99, 6.82, 1.95, 1.62, 2.1,  9.03, 2.87, 2.4,
                                3.65, 1.99, 4.83, 7.11, 8.69, 7.02};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{7.81, 2.0,  1.75, 8.42, 3.54, 3.67, 7.99, 6.62,
                                8.03, 3.3,  9.96, 4.2,  1.11, 4.13, 2.76, 1.9,
                                4.58, 9.3,  6.78, 1.58, 2.35, 2.61, 7.77, 7.68,
                                5.46, 1.74, 1.05, 4.78, 6.89, 1.53};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 5);
  double *arr3 = new double[30]{
      -4.54, 4.79, -0.74, 1.08,  0.52,  5.62, -4.25, -1.79, -5.86, 0.2,
      -8.36, 5.6,  6.85,  -3.08, -0.12, 6.89, 1.41,  -2.48, -4.83, 0.04,
      -0.25, 6.42, -4.9,  -5.28, -1.81, 0.25, 3.78,  2.33,  1.8,   5.49};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix35) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{9.14, 9.48, 8.85, 7.48, 3.95, 9.5, 3.09, 3.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{5.32, 7.03, 5.23, 6.69, 1.45, 1.22, 6.03, 2.54};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 2);
  double *arr3 = new double[8]{3.82, 2.45, 3.62, 0.79, 2.5, 8.28, -2.94, 0.64};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix36) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{2.96, 3.65, 8.14, 8.48, 7.73, 4.78, 8.24, 4.0,
                                6.9,  4.49, 9.62, 6.69, 8.46, 6.57, 4.43};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{6.67, 2.28, 3.47, 4.27, 4.44, 4.14, 1.55, 1.51,
                                2.26, 9.17, 7.01, 6.43, 7.18, 8.93, 9.85};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 3);
  double *arr3 =
      new double[15]{-3.71, 1.37,  4.67, 4.21, 3.29, 0.64,  6.69, 2.49,
                     4.64,  -4.68, 2.61, 0.26, 1.28, -2.36, -5.42};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix37) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{8.18, 8.65, 8.34, 2.32, 4.6,  2.39,
                                6.77, 9.46, 5.97, 9.1,  7.77, 8.59};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{2.05, 4.62, 1.33, 4.89, 7.71, 6.27, 1.18,
                                9.85, 2.54, 5.83, 9.68, 1.91, 3.26, 2.55,
                                6.16, 3.77, 5.39, 6.14, 6.62, 4.24, 9.66};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix38) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{2.86, 6.68, 8.53, 1.32, 3.07,
                                2.76, 3.37, 4.74, 8.44, 7.76};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{1.86, 1.99, 9.78, 8.09, 3.49,
                                2.72, 5.67, 2.23, 5.14, 3.88};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 5);
  double *arr3 = new double[10]{1.0,  4.69, -1.25, -6.77, -0.42,
                                0.04, -2.3, 2.51,  3.3,   3.88};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix39) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{6.32, 6.15, 5.62, 1.37, 9.47, 4.42, 7.27, 7.0,
                                9.88, 6.06, 1.74, 2.92, 3.63, 8.98, 1.15, 8.16,
                                7.6,  6.3,  6.08, 8.88, 4.61, 9.56, 3.7,  3.23};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{7.19, 8.82, 9.47, 1.82, 6.33, 6.12, 7.84, 8.89,
                                9.68, 2.95, 2.2,  2.25, 5.89, 2.29, 7.92, 6.93,
                                6.41, 5.9,  6.77, 6.43, 6.22, 9.91, 8.61, 4.66};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 6);
  double *arr3 =
      new double[24]{-0.87, -2.67, -3.85, -0.45, 3.14,  -1.7,  -0.57, -1.89,
                     0.2,   3.11,  -0.46, 0.67,  -2.26, 6.69,  -6.77, 1.23,
                     1.19,  0.4,   -0.69, 2.45,  -1.61, -0.35, -4.91, -1.43};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix40) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{7.09, 5.25, 5.63, 8.81, 7.29, 7.52,
                                7.68, 2.74, 7.97, 2.93, 4.41, 6.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{9.11, 1.63, 9.04, 5.51, 1.48, 4.87, 7.13,
                                9.96, 7.59, 7.99, 3.5,  9.17, 5.06, 5.08,
                                5.19, 2.45, 2.94, 2.33, 4.8,  3.62, 2.62};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix41) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{7.1, 1.12, 3.12, 3.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{2.16, 5.88, 3.14, 8.64};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 2);
  double *arr3 = new double[4]{4.94, -4.76, -0.02, -4.81};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix42) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{3.52, 2.9,  1.66, 9.63, 5.77, 6.06, 3.14, 2.96, 6.53,
                     7.98, 2.21, 8.48, 8.5,  9.7,  3.13, 8.88, 7.63, 9.13};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{6.72, 1.88, 2.92, 9.13, 2.22, 4.16, 5.49, 1.8,  8.9,
                     7.25, 8.2,  4.45, 7.05, 4.09, 9.24, 8.84, 2.23, 5.9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 =
      new double[18]{-3.2, 1.02,  -1.26, 0.5,  3.55, 1.9,   -2.35, 1.16, -2.37,
                     0.73, -5.99, 4.03,  1.45, 5.61, -6.11, 0.04,  5.4,  3.23};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix43) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{5.86, 4.72, 1.84, 3.55, 3.31, 1.6,  4.6, 9.17, 7.41,
                     6.6,  6.49, 1.06, 8.72, 7.15, 5.14, 7.4, 2.44, 6.61};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{8.02, 7.0,  3.47, 2.44, 5.34, 7.0, 6.59, 8.04, 8.19,
                     3.94, 3.39, 6.13, 7.26, 5.86, 2.8, 7.72, 9.03, 1.81};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 = new double[18]{-2.16, -2.28, -1.63, 1.11,  -2.03, -5.4,
                                -1.99, 1.13,  -0.78, 2.66,  3.1,   -5.07,
                                1.46,  1.29,  2.34,  -0.32, -6.59, 4.8};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix44) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{9.64, 7.47, 2.0, 2.6,  4.41, 7.35,
                                9.27, 6.86, 6.4, 3.25, 3.43, 9.7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 7);
  double *arr2 = new double[21]{4.71, 6.24, 8.72, 5.85, 6.0,  9.68, 6.56,
                                7.29, 7.05, 4.76, 7.61, 8.05, 1.97, 4.75,
                                6.72, 2.14, 5.42, 3.32, 2.87, 8.2,  7.52};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix45) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{5.59, 6.81, 6.28, 5.31};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{6.56, 8.34, 6.42, 8.72};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 2);
  double *arr3 = new double[4]{-0.97, -1.53, -0.14, -3.41};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix46) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{6.1,  7.71, 6.96, 5.77, 7.37, 9.02, 10.0,
                                6.05, 5.13, 9.67, 3.01, 1.95, 8.98, 4.42,
                                7.24, 7.56, 6.72, 2.33, 6.49, 5.91};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{5.62, 2.37, 9.96, 4.8,  4.63, 4.03, 7.48,
                                2.89, 9.24, 1.33, 3.15, 6.23, 4.85, 8.48,
                                4.7,  1.33, 5.61, 3.98, 8.59, 7.39};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 5);
  double *arr3 = new double[20]{0.48, 5.34,  -3.0, 0.97,  2.74,  4.99, 2.52,
                                3.16, -4.11, 8.34, -0.14, -4.28, 4.13, -4.06,
                                2.54, 6.23,  1.11, -1.65, -2.1,  -1.48};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix47) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{7.93, 2.4,  6.31, 5.84, 9.56, 6.9,  9.47, 5.55,
                                9.59, 4.58, 6.85, 2.14, 5.97, 9.02, 3.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{8.83, 3.28, 8.55, 6.87, 9.58, 8.79, 3.89, 3.72,
                                4.12, 7.55, 5.8,  1.5,  9.95, 2.7,  2.07};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 5);
  double *arr3 =
      new double[15]{-0.9, -0.88, -2.24, -1.03, -0.02, -1.89, 5.58, 1.83,
                     5.47, -2.97, 1.05,  0.64,  -3.98, 6.32,  1.42};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix48) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{2.68, 6.1,  1.25, 7.75, 5.32, 4.77, 7.38, 5.23, 1.43,
                     1.12, 1.53, 4.98, 1.96, 4.31, 8.84, 2.02, 3.54, 5.87};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 7);
  double *arr2 =
      new double[28]{8.09, 3.91, 4.44, 5.52, 1.31, 7.99, 4.16, 8.29, 2.24, 3.45,
                     3.3,  4.27, 8.18, 1.63, 9.16, 5.21, 3.66, 9.97, 1.64, 5.32,
                     7.75, 8.71, 1.77, 9.2,  1.91, 6.33, 5.26, 8.29};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix49) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{9.25, 2.11, 6.25, 5.52, 8.39, 9.93,
                                2.72, 5.2,  4.45, 4.67, 5.61, 6.0};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{7.57, 5.33, 6.58, 2.33, 4.51, 2.21,
                                6.02, 9.0,  8.76, 2.1,  1.05, 6.99};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 3);
  double *arr3 = new double[12]{1.68, -3.22, -0.33, 3.19, 3.88, 7.72,
                                -3.3, -3.8,  -4.31, 2.57, 4.56, -0.99};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix50) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{1.74, 9.64, 8.18, 7.47, 8.03, 2.14,
                                8.75, 7.75, 7.36, 5.46, 3.44, 4.81};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{8.32, 3.38, 9.78, 1.77, 4.89, 6.43,
                                3.07, 3.8,  2.11, 5.87, 9.57, 9.5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 2);
  double *arr3 = new double[12]{-6.58, 6.26, -1.6, 5.7,   3.14,  -4.29,
                                5.68,  3.95, 5.25, -0.41, -6.13, -4.69};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix51) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.6, 8.61, 1.62, 9.03, 1.6, 5.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{3.92, 7.74, 4.9, 1.79, 9.59, 2.66};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 3);
  double *arr3 = new double[6]{5.68, 0.87, -3.28, 7.24, -7.99, 3.08};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix52) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{3.9,  9.77, 8.44, 1.06, 2.68, 3.97, 5.67, 8.59,
                                5.82, 4.15, 2.14, 5.43, 8.1,  7.33, 9.26, 6.71,
                                3.15, 2.05, 2.77, 9.04, 1.81, 8.36, 8.82, 3.94};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 5);
  double *arr2 = new double[35]{
      3.89, 7.85, 9.05, 4.21, 2.34, 6.99, 4.54, 6.45, 3.35, 6.35, 3.3,  3.68,
      2.64, 8.54, 7.94, 6.17, 1.45, 4.25, 1.39, 1.49, 5.08, 5.77, 2.56, 1.17,
      1.77, 8.1,  1.19, 3.97, 3.7,  7.22, 1.76, 2.4,  4.65, 1.53, 1.17};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix53) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{9.49, 7.61, 1.14, 5.38, 5.11, 3.59, 4.01, 7.62, 3.89,
                     6.89, 1.19, 4.04, 6.96, 6.18, 1.38, 4.57, 6.62, 2.27};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{9.9,  7.95, 4.8,  1.06, 8.02, 4.63, 3.27, 2.92, 7.54,
                     6.01, 4.63, 5.23, 7.51, 9.22, 5.77, 2.06, 8.69, 2.25};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 = new double[18]{-0.41, -0.34, -3.66, 4.32, -2.91, -1.04,
                                0.74,  4.7,   -3.65, 0.88, -3.44, -1.19,
                                -0.55, -3.04, -4.39, 2.51, -2.07, 0.02};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix54) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{6.13, 3.02, 3.22, 2.14, 1.39, 8.38, 9.42,
                                8.83, 3.39, 3.51, 2.29, 7.33, 3.25, 2.59,
                                2.37, 7.7,  9.9,  1.71, 2.59, 7.98};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{7.93, 2.09, 5.33, 3.51, 4.43, 8.17, 9.1,
                                5.85, 3.71, 5.58, 7.96, 5.72, 4.73, 5.77,
                                6.06, 9.26, 4.94, 9.22, 2.63, 9.48};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 5);
  double *arr3 = new double[20]{-1.8,  0.93,  -2.11, -1.37, -3.04, 0.21,  0.32,
                                2.98,  -0.32, -2.07, -5.67, 1.61,  -1.48, -3.18,
                                -3.69, -1.56, 4.96,  -7.51, -0.04, -1.5};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix55) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{9.16, 9.07, 3.17, 6.62, 3.36, 2.15,
                                7.99, 3.83, 4.11, 6.52, 8.72, 6.55};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{5.43, 2.19, 3.97, 7.17, 2.48, 3.22,
                                1.64, 7.82, 7.36, 7.03, 4.54, 8.04};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 6);
  double *arr3 = new double[12]{3.73, 6.88,  -0.8,  -0.55, 0.88, -1.07,
                                6.35, -3.99, -3.25, -0.51, 4.18, -1.49};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix56) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{5.52, 5.34, 9.3,  6.0,  8.7, 4.5,  7.49, 9.19,
                                6.18, 8.1,  2.68, 6.74, 8.9, 2.24, 1.71};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{3.91, 4.03, 6.19, 8.49, 7.15, 1.8,  8.05, 9.32,
                                5.47, 6.7,  7.63, 5.49, 5.12, 1.55, 1.5,  7.49,
                                7.25, 4.25, 4.84, 6.54, 9.96, 3.63, 6.43, 2.16};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix57) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{6.15, 1.76, 9.26, 8.24, 9.08, 9.97, 6.35,
                                4.82, 6.32, 3.84, 2.78, 5.4,  7.99, 8.17,
                                9.63, 4.46, 9.21, 6.06, 3.4,  5.72};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{2.12, 9.85, 6.22, 1.77, 8.38, 8.93, 8.39, 3.73,
                                6.29, 6.69, 1.23, 6.56, 4.01, 9.55, 8.26, 6.39,
                                7.52, 5.88, 8.37, 5.02, 5.22, 3.18, 9.78, 5.99,
                                4.06, 1.66, 8.46, 5.39, 6.31, 1.95};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix58) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{5.53, 4.21, 9.99, 5.0, 6.13, 9.68};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{9.99, 5.19, 4.69, 9.82, 1.0, 5.72};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 3);
  double *arr3 = new double[6]{-4.46, -0.98, 5.3, -4.82, 5.13, 3.96};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix59) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{4.19, 5.32, 4.73, 2.21, 8.32, 5.51, 9.92, 5.82, 3.64,
                     3.98, 5.93, 6.08, 9.96, 2.81, 7.04, 3.82, 3.99, 4.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{3.41, 1.21, 8.32, 7.68, 3.58, 3.05, 4.54, 1.14, 3.3,
                     1.51, 7.88, 4.65, 1.72, 6.71, 9.74, 5.66, 6.28, 5.47};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 6);
  double *arr3 = new double[18]{0.78, 4.11, -3.59, -5.47, 4.74,  2.46,
                                5.38, 4.68, 0.34,  2.47,  -1.95, 1.43,
                                8.24, -3.9, -2.7,  -1.84, -2.29, -0.57};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix60) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{1.03, 4.93, 5.26, 7.4,  8.25, 4.35, 1.4,  1.11,
                                3.63, 6.63, 8.61, 3.26, 2.78, 3.88, 5.11, 5.39,
                                4.89, 5.25, 1.91, 6.32, 5.89, 7.14, 1.74, 3.73};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{8.3,  5.5,  9.91, 2.29, 3.36, 2.79, 7.64, 3.99,
                                2.69, 1.47, 1.06, 9.99, 3.72, 4.93, 3.9,  4.54,
                                1.88, 1.33, 1.2,  4.84, 5.42, 8.48, 5.88, 7.96};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 6);
  double *arr3 =
      new double[24]{-7.27, -0.57, -4.65, 5.11,  4.89,  1.56,  -6.24, -2.88,
                     0.94,  5.16,  7.55,  -6.73, -0.94, -1.05, 1.21,  0.85,
                     3.01,  3.92,  0.71,  1.48,  0.47,  -1.34, -4.14, -4.23};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix61) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{4.4,  4.51, 5.34, 4.17, 4.29, 5.93, 7.2,  2.35,
                                7.24, 9.06, 5.93, 9.34, 4.93, 2.48, 9.14, 7.32,
                                9.42, 6.06, 7.28, 6.17, 4.93, 4.44, 4.81, 2.49};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{2.6,  1.9,  3.33, 2.67, 7.4,  5.32, 4.47, 3.64,
                                4.84, 5.63, 8.54, 5.9,  2.52, 8.31, 2.58, 4.74,
                                7.11, 6.37, 6.98, 8.05, 4.73, 3.77, 1.74, 2.03};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 4);
  double *arr3 =
      new double[24]{1.8,  2.61,  2.01,  1.5,   -3.11, 0.61,  2.73, -1.29,
                     2.4,  3.43,  -2.61, 3.44,  2.41,  -5.83, 6.56, 2.58,
                     2.31, -0.31, 0.3,   -1.88, 0.2,   0.67,  3.07, 0.46};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix62) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{9.98, 9.9,  4.87, 9.82, 3.92, 8.57, 8.38, 6.73,
                                9.39, 3.13, 8.89, 3.55, 7.94, 1.39, 2.3,  3.47,
                                8.18, 9.65, 7.69, 2.38, 8.98, 8.14, 6.44, 8.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 5);
  double *arr2 = new double[35]{
      4.2,  5.3,  2.38, 7.04, 4.58, 1.59, 5.79, 2.61, 5.82, 2.01, 7.72, 9.57,
      8.9,  5.03, 9.32, 3.24, 1.91, 3.77, 8.29, 9.19, 5.29, 2.74, 1.41, 4.44,
      2.43, 8.93, 3.45, 3.95, 8.29, 9.2,  5.75, 7.36, 8.15, 6.01, 8.29};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix63) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{9.77, 9.89, 1.57, 6.77, 4.92, 1.08,
                                1.92, 4.39, 6.26, 9.2,  5.41, 3.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{6.86, 3.38, 3.92, 2.45, 7.72, 6.2,
                                4.85, 7.96, 6.32, 5.69, 9.82, 7.24};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 3);
  double *arr3 = new double[12]{2.91,  6.51,  -2.35, 4.32, -2.8,  -5.12,
                                -2.93, -3.57, -0.06, 3.51, -4.41, -4.15};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix64) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{8.84, 8.05, 7.11, 8.45, 1.39, 6.8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{7.66, 4.19, 2.18, 8.81, 7.3,  5.41,
                                3.85, 3.49, 1.72, 7.19, 2.13, 1.28};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix65) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{3.32, 2.22, 3.42, 7.78, 7.69,
                                3.44, 4.95, 8.95, 7.07, 6.91};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{3.82, 4.85, 4.78, 4.23, 7.09,
                                5.21, 5.56, 9.68, 3.01, 3.45};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 2);
  double *arr3 = new double[10]{-0.5,  -2.63, -1.36, 3.55, 0.6,
                                -1.77, -0.61, -0.73, 4.06, 3.46};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix66) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{6.08, 5.6, 2.09, 7.0, 8.9, 9.85};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{5.72, 2.49, 2.9, 7.33, 6.84, 5.64};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 2);
  double *arr3 = new double[6]{0.36, 3.11, -0.81, -0.33, 2.06, 4.21};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix67) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{3.77, 8.56, 9.46, 1.02, 1.47, 5.05,
                                2.88, 1.8,  5.67, 9.48, 5.46, 4.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{2.77, 8.83, 3.72, 2.69, 9.09, 9.82, 6.25,
                                9.27, 8.66, 1.93, 7.2,  1.41, 1.84, 2.47,
                                8.95, 1.19, 4.39, 3.67, 7.14, 4.71};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix68) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{9.44, 3.24, 1.8,  2.68, 9.04, 3.83, 7.81, 6.85,
                                9.99, 2.43, 2.77, 2.95, 4.91, 9.09, 8.11, 4.03,
                                1.8,  3.38, 4.03, 3.36, 6.52, 2.71, 7.89, 8.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 7);
  double *arr2 = new double[35]{
      5.34, 2.56, 2.87, 8.57, 3.75, 4.54, 3.52, 4.76, 3.09, 6.73, 9.18, 1.21,
      9.97, 5.05, 6.85, 9.69, 8.31, 2.47, 7.45, 4.95, 9.08, 2.56, 7.52, 9.72,
      3.66, 4.01, 5.55, 7.94, 4.1,  8.9,  1.34, 5.09, 3.38, 2.22, 5.58};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix69) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{9.12, 1.55, 3.94, 2.1,  4.5,  5.2,  6.46, 3.23, 4.38,
                     1.03, 4.66, 3.17, 7.37, 7.39, 4.43, 5.44, 4.29, 9.21,
                     5.72, 4.53, 1.36, 1.57, 7.12, 4.96, 6.29};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      4.81, 4.17, 3.92, 6.75, 3.23, 1.25, 2.18, 5.92, 5.54, 8.5,  2.16, 6.64,
      1.01, 1.7,  6.28, 9.34, 8.53, 6.4,  7.63, 7.63, 4.53, 4.68, 8.2,  1.45,
      2.44, 4.88, 3.64, 9.95, 9.9,  7.41, 7.57, 2.83, 1.41, 8.6,  5.35, 5.71};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix70) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{4.35, 8.84, 2.41, 4.43, 4.81, 5.61, 3.49, 7.92,
                                9.51, 8.46, 2.7,  9.85, 9.26, 3.43, 6.71, 7.07,
                                8.15, 6.66, 3.93, 2.55, 9.09, 1.73, 9.68, 7.08,
                                1.92, 5.06, 6.82, 8.37, 9.37, 2.97};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{5.47, 9.76, 6.46, 1.37, 9.13, 8.25, 3.08, 2.08,
                                5.91, 7.69, 6.3,  2.75, 1.93, 8.81, 3.23, 5.65,
                                2.91, 6.42, 4.69, 7.88, 7.76, 2.01, 6.27, 1.26,
                                9.02, 8.27, 2.88, 9.78, 2.3,  4.83};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 6);
  double *arr3 = new double[30]{
      -1.12, -0.92, -4.05, 3.06,  -4.32, -2.64, 0.41, 5.84,  3.6,   0.77,
      -3.6,  7.1,   7.33,  -5.38, 3.48,  1.42,  5.24, 0.24,  -0.76, -5.33,
      1.33,  -0.28, 3.41,  5.82,  -7.1,  -3.21, 3.94, -1.41, 7.07,  -1.86};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix71) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{9.15, 2.19, 1.5,  1.05, 4.38, 9.35, 6.38, 2.43,
                                9.94, 3.0,  4.37, 1.44, 2.57, 1.81, 5.72};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{1.93, 9.63, 6.04, 6.36, 7.36, 7.33, 4.78, 1.55,
                                6.4,  1.15, 5.3,  4.15, 4.89, 7.99, 5.7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(5, 3);
  double *arr3 =
      new double[15]{7.22, -7.44, -4.54, -5.31, -2.98, 2.02,  1.6, 0.88,
                     3.54, 1.85,  -0.93, -2.71, -2.32, -6.18, 0.02};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix72) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{8.59, 4.83, 1.39, 6.4,  8.31, 6.81, 3.08, 5.74, 3.69,
                     6.89, 6.02, 3.55, 8.73, 9.56, 4.26, 9.01, 8.92, 2.67};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 =
      new double[28]{6.43, 2.33, 8.35, 8.32, 5.22, 4.26, 2.95, 5.51, 6.44, 8.23,
                     6.31, 2.97, 7.83, 6.26, 7.85, 4.04, 4.08, 5.85, 6.39, 1.83,
                     9.51, 6.2,  8.42, 6.03, 4.23, 2.82, 3.66, 1.48};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix73) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      9.33, 1.49, 4.81, 2.18, 1.36, 1.13, 6.22, 2.01, 7.27, 9.51, 4.27, 6.37,
      6.72, 5.77, 7.22, 4.47, 8.56, 2.2,  1.65, 3.33, 1.6,  3.23, 7.14, 2.74,
      4.41, 5.32, 6.61, 1.06, 7.97, 5.61, 1.49, 8.84, 1.27, 9.79, 3.58, 2.82};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      8.79, 3.56, 7.62, 5.5,  9.18, 4.68, 4.96, 6.54, 6.97, 8.68, 1.77, 3.9,
      8.51, 3.33, 3.45, 1.63, 6.12, 9.62, 2.58, 5.29, 5.5,  8.37, 2.79, 8.61,
      8.61, 8.78, 9.18, 4.25, 8.49, 7.03, 2.98, 3.32, 7.34, 3.22, 9.28, 2.89};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 6);
  double *arr3 = new double[36]{
      0.54,  -2.07, -2.81, -3.32, -7.82, -3.55, 1.26, -4.53, 0.3,
      0.83,  2.5,   2.47,  -1.79, 2.44,  3.77,  2.84, 2.44,  -7.42,
      -0.93, -1.96, -3.9,  -5.14, 4.35,  -5.87, -4.2, -3.46, -2.57,
      -3.19, -0.52, -1.42, -1.49, 5.52,  -6.07, 6.57, -5.7,  -0.07};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix74) {
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{7.21, 1.07, 7.21, 6.86, 9.27, 9.38, 6.75, 8.2,  3.67,
                     8.23, 4.65, 5.17, 9.08, 3.5,  9.89, 3.61, 8.75, 9.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 7);
  double *arr2 =
      new double[28]{6.6,  3.54, 5.28, 2.45, 7.05, 2.52, 9.8,  3.76, 5.65, 1.11,
                     8.86, 7.17, 5.55, 9.07, 3.44, 2.82, 8.73, 8.56, 3.22, 4.49,
                     8.45, 6.8,  2.93, 5.9,  5.19, 4.24, 5.11, 3.32};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix75) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{7.7, 1.28, 8.49, 8.21, 2.11, 5.61, 7.9, 6.02, 9.37};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 =
      new double[9]{7.95, 2.48, 2.98, 3.89, 1.15, 9.53, 8.0, 4.85, 7.29};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 3);
  double *arr3 =
      new double[9]{-0.25, -1.2, 5.51, 4.32, 0.96, -3.92, -0.1, 1.17, 2.08};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix76) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{7.62, 2.73, 7.5,  5.73, 2.56, 5.23, 8.55, 6.94,
                                7.95, 3.1,  2.57, 1.7,  3.92, 2.06, 6.12, 1.95,
                                5.75, 7.8,  3.95, 2.02, 5.14, 5.77, 3.34, 6.26};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{9.07, 4.55, 9.61, 2.2,  2.46, 3.98, 8.23, 9.99,
                                6.85, 1.44, 5.42, 2.46, 7.59, 6.37, 2.72, 2.37,
                                1.33, 5.17, 7.91, 1.87, 9.97, 7.22, 5.46, 6.68};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 4);
  double *arr3 =
      new double[24]{-1.45, -1.82, -2.11, 3.53,  0.1,   1.25,  0.32,  -3.05,
                     1.1,   1.66,  -2.85, -0.76, -3.67, -4.31, 3.4,   -0.42,
                     4.42,  2.63,  -3.96, 0.15,  -4.83, -1.45, -2.12, -0.42};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix77) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{5.17, 6.07, 2.91, 7.34, 8.89, 2.86, 6.51,
                                3.15, 8.24, 6.34, 5.76, 4.29, 6.84, 9.08,
                                6.72, 6.92, 5.74, 2.43, 1.42, 4.87};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{6.12, 3.76, 5.81, 8.65, 9.02, 6.29, 5.07, 2.59,
                                8.01, 2.59, 4.79, 8.43, 6.54, 2.72, 9.65, 8.57,
                                3.39, 7.88, 2.5,  5.37, 3.18, 1.32, 5.8,  8.4,
                                1.06, 5.38, 8.54, 5.58, 3.39, 4.21};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix78) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{2.99, 7.13, 2.19, 4.63, 7.27, 1.04, 8.33, 9.69,
                                5.92, 3.08, 9.79, 4.93, 4.8,  6.16, 2.43, 1.07,
                                3.04, 6.15, 8.95, 9.83, 9.36, 4.91, 4.94, 3.05};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{2.81, 4.58, 2.45, 7.13, 2.21, 9.84, 3.21, 5.28,
                                4.07, 7.37, 7.18, 9.34, 2.99, 6.31, 5.46, 5.0,
                                2.79, 7.62, 6.68, 9.75, 1.75, 6.02, 1.89, 9.43};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 6);
  double *arr3 =
      new double[24]{0.18, 2.55,  -0.26, -2.5,  5.06, -8.8,  5.12,  4.41,
                     1.85, -4.29, 2.61,  -4.41, 1.81, -0.15, -3.03, -3.93,
                     0.25, -1.47, 2.27,  0.08,  7.61, -1.11, 3.05,  -6.38};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix79) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{3.69, 5.17, 4.55, 7.37, 9.15, 1.38};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{4.61, 4.73, 4.92, 7.13, 3.79, 6.27};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 2);
  double *arr3 = new double[6]{-0.92, 0.44, -0.37, 0.24, 5.36, -4.89};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix80) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{3.51, 7.74, 6.61, 1.37, 6.11, 3.81, 4.26, 3.27,
                                8.62, 6.61, 9.59, 9.01, 9.39, 9.53, 1.03};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{5.42, 1.64, 1.59, 2.07, 8.36, 9.58, 6.13, 6.84,
                                6.34, 6.91, 5.55, 1.6,  4.87, 7.4,  6.42, 7.12,
                                6.31, 3.54, 9.11, 2.2,  3.19, 1.49, 8.16, 2.41};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix81) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{8.17, 4.65, 7.38, 7.36, 7.07, 9.3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{3.47, 5.04, 10.0, 3.97, 6.89, 8.39,
                                4.1,  3.42, 3.11, 5.7,  6.3,  3.54};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix82) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{2.68, 6.92, 3.25, 1.96, 2.65, 2.84};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{1.26, 4.36, 6.94, 8.32, 5.53, 5.29,
                                9.99, 7.61, 4.56, 1.67, 2.57, 9.44};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix83) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{2.33, 8.76, 5.26, 6.32, 9.4,  2.82, 2.19, 4.17,
                                1.35, 9.17, 5.47, 9.42, 8.47, 4.88, 3.85, 4.67,
                                6.97, 8.78, 1.93, 8.24, 9.14, 1.42, 2.93, 8.39,
                                7.31, 8.82, 9.17, 9.28, 8.24, 4.85};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 7);
  double *arr2 = new double[42]{
      4.34, 4.61, 8.34, 5.29, 3.38, 5.53, 3.15, 5.51, 7.32, 9.13, 7.56,
      3.09, 6.11, 8.01, 2.54, 5.31, 3.66, 1.87, 8.54, 1.62, 1.62, 2.12,
      7.5,  6.54, 6.52, 3.68, 9.32, 6.42, 5.57, 5.51, 9.51, 7.44, 1.24,
      7.94, 9.8,  6.63, 3.59, 9.38, 9.15, 5.59, 3.27, 9.92};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix84) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{8.46, 9.64, 7.26, 6.85, 1.34, 2.52};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{8.65, 1.98, 5.09, 5.46, 2.99, 5.52};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 3);
  double *arr3 = new double[6]{-0.19, 7.66, 2.17, 1.39, -1.65, -3.0};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix85) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{6.76, 3.77, 6.49, 2.86, 2.73, 3.65, 6.48, 5.33,
                                7.32, 4.17, 6.09, 1.22, 3.7,  6.18, 5.54};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{7.43, 1.36, 8.71, 4.82, 2.5,  1.07, 3.45, 6.6,
                                9.03, 5.38, 2.02, 2.04, 9.77, 6.14, 4.94};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 5);
  double *arr3 =
      new double[15]{-0.67, 2.41,  -2.22, -1.96, 0.23,  2.58, 3.03, -1.27,
                     -1.71, -1.21, 4.07,  -0.82, -6.07, 0.04, 0.6};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix86) {
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{3.52, 3.94, 8.1, 1.37, 2.46, 8.43, 9.55, 5.5, 3.36};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{7.03, 3.02, 1.41, 4.14, 5.93, 3.85, 2.09, 7.5,
                                6.07, 4.75, 4.63, 9.38, 1.42, 8.77, 6.31, 1.67};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix87) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{8.19, 3.87, 7.07, 4.87, 3.17, 2.28};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{5.77, 7.6, 9.45, 5.0, 5.33, 4.56};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(2, 3);
  double *arr3 = new double[6]{2.42, -3.73, -2.38, -0.13, -2.16, -2.28};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix88) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{5.28, 9.14, 1.95, 3.36, 6.35, 6.72};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{1.67, 2.75, 2.73, 4.94, 8.54, 6.63};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(3, 2);
  double *arr3 = new double[6]{3.61, 6.39, -0.78, -1.58, -2.19, 0.09};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix89) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{6.59, 8.35, 9.62, 7.7, 1.43, 9.71,
                                9.6,  1.19, 4.03, 8.0, 5.9,  3.1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{2.36, 1.1,  2.57, 2.22, 6.66, 3.72,
                                2.85, 3.42, 3.59, 3.74, 7.95, 1.3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 3);
  double *arr3 = new double[12]{4.23, 7.25,  7.05, 5.48, -5.23, 5.99,
                                6.75, -2.23, 0.44, 4.26, -2.05, 1.8};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix90) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{6.66, 1.2,  5.86, 2.26, 9.83, 7.37, 9.73, 6.0,
                                7.41, 7.59, 8.37, 2.95, 2.86, 4.53, 6.56, 8.09,
                                5.16, 5.66, 8.76, 7.46, 7.9,  8.52, 2.05, 8.51};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 5);
  double *arr2 = new double[35]{
      3.13, 5.11, 8.8,  5.29, 2.71, 5.96, 2.22, 9.41, 2.01, 2.16, 6.89, 8.05,
      1.55, 9.96, 2.94, 2.73, 7.58, 2.28, 6.04, 1.0,  4.33, 9.51, 1.34, 2.54,
      4.16, 8.76, 6.33, 8.68, 2.92, 3.36, 3.52, 1.47, 2.05, 6.14, 2.38};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix91) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{2.48, 7.24, 1.01, 8.69, 5.0,  5.98, 7.75, 1.15,
                                8.74, 6.52, 9.15, 3.7,  8.04, 9.69, 6.2,  9.79};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{1.03, 8.97, 3.05, 8.74, 2.34, 9.37, 3.43, 4.38,
                                6.94, 6.81, 1.27, 4.61, 4.18, 8.23, 1.84, 2.46};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 4);
  double *arr3 =
      new double[16]{1.45, -1.73, -2.04, -0.05, 2.66, -3.39, 4.32, -3.23,
                     1.8,  -0.29, 7.88,  -0.91, 3.86, 1.46,  4.36, 7.33};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix92) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{4.53, 2.3,  5.59, 5.1,  8.38, 7.52, 1.14, 7.11, 5.49,
                     6.59, 5.36, 3.86, 6.12, 7.18, 9.94, 2.64, 2.11, 8.97,
                     2.2,  8.01, 3.98, 8.82, 8.0,  2.94, 9.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      2.39, 8.24, 6.15, 3.46, 4.1,  8.73, 3.03, 1.56, 6.22, 7.18, 7.23, 1.32,
      1.82, 5.34, 7.81, 5.46, 6.67, 3.12, 7.6,  9.51, 1.33, 4.74, 3.4,  3.28,
      7.12, 6.67, 7.57, 9.19, 7.59, 5.83, 9.77, 6.88, 1.95, 7.46, 6.61, 1.37};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix93) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{7.45, 1.53, 3.85, 9.76, 3.36, 5.95,
                                8.67, 3.86, 5.04, 5.9,  5.37, 6.76};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{6.2,  8.62, 7.01, 4.75, 4.85, 3.05,
                                4.18, 4.19, 9.88, 1.67, 1.23, 1.63};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 3);
  double *arr3 = new double[12]{1.25, -7.09, -3.16, 5.01, -1.49, 2.9,
                                4.49, -0.33, -4.84, 4.23, 4.14,  5.13};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix94) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{5.83, 3.58, 6.56, 5.24, 7.35,
                                7.78, 6.85, 5.23, 2.92, 4.94};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{8.2,  2.56, 7.24, 7.35, 8.64, 7.91, 1.35, 7.41, 2.2,
                     3.55, 9.98, 6.8,  4.06, 3.24, 6.3,  8.48, 4.36, 4.66};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix95) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{7.38, 6.23, 7.79, 4.0,  8.81, 2.78, 4.9,
                                6.78, 2.98, 4.28, 5.53, 5.64, 6.99, 3.29,
                                4.95, 7.66, 5.07, 5.31, 5.74, 3.97};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{1.7,  9.52, 8.63, 2.65, 4.03, 9.74, 1.6,
                                6.11, 5.13, 8.06, 8.52, 9.13, 2.62, 3.36,
                                1.07, 4.34, 3.12, 6.35, 9.19, 4.95};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 5);
  double *arr3 = new double[20]{5.68, -3.29, -0.84, 1.35,  4.78,  -6.96, 3.3,
                                0.67, -2.15, -3.78, -2.99, -3.49, 4.37,  -0.07,
                                3.88, 3.32,  1.95,  -1.04, -3.45, -0.98};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix96) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{9.17, 7.32, 9.37, 7.05, 5.96, 3.41, 7.77, 3.17};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{7.7,  8.83, 5.0, 4.07, 9.35, 6.19, 8.84, 2.21,
                                2.89, 5.73, 3.6, 8.9,  4.51, 8.45, 3.03};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix97) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{8.62, 5.31, 5.64, 4.18, 5.37, 1.42,
                                9.31, 1.0,  6.91, 1.58, 6.66, 5.21};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{8.61, 3.71, 4.36, 6.02, 5.39, 5.96, 2.61,
                                1.26, 6.51, 5.68, 4.28, 2.6,  8.7,  7.37,
                                3.37, 6.73, 3.39, 2.8,  4.35, 9.37};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixSubTest, SubMatrix98) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{4.72, 7.64, 9.65, 7.36, 1.22, 1.67, 6.38, 7.65,
                                3.8,  5.37, 9.78, 8.66, 2.64, 1.78, 7.07, 7.16,
                                2.75, 5.39, 5.42, 8.75, 2.51, 8.63, 9.0,  6.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{1.02, 7.3,  9.37, 7.51, 7.37, 1.74, 5.13, 1.64,
                                5.2,  5.6,  1.35, 6.26, 4.69, 4.61, 5.86, 3.24,
                                7.54, 3.77, 9.35, 2.81, 7.19, 5.37, 4.85, 9.21};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(4, 6);
  double *arr3 =
      new double[24]{3.7,   0.34,  0.28,  -0.15, -6.15, -0.07, 1.25, 6.01,
                     -1.4,  -0.23, 8.43,  2.4,   -2.05, -2.83, 1.21, 3.92,
                     -4.79, 1.62,  -3.93, 5.94,  -4.68, 3.26,  4.15, -3.12};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix99) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{7.74, 6.53, 3.61, 8.21, 6.35, 2.5,  7.42, 6.8,
                                8.6,  7.01, 6.93, 9.93, 3.53, 7.68, 7.71, 1.93,
                                6.83, 5.22, 9.76, 7.03, 2.54, 7.7,  5.51, 6.69,
                                7.26, 2.25, 6.04, 6.47, 3.2,  1.82};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{5.47, 5.31, 4.0,  2.66, 6.92, 1.66, 6.6,  3.32,
                                9.31, 7.63, 4.01, 6.62, 6.76, 2.16, 6.94, 5.79,
                                6.43, 4.43, 9.9,  6.96, 3.45, 2.15, 3.98, 7.38,
                                1.04, 8.04, 2.66, 2.09, 5.79, 5.32};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 5);
  double *arr3 = new double[30]{
      2.27,  1.22, -0.39, 5.55,  -0.57, 0.84,  0.82, 3.48, -0.71, -0.62,
      2.92,  3.31, -3.23, 5.52,  0.77,  -3.86, 0.4,  0.79, -0.14, 0.07,
      -0.91, 5.55, 1.53,  -0.69, 6.22,  -5.79, 3.38, 4.38, -2.59, -3.5};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 - matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}

TEST(MatrixSubTest, SubMatrix100) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{3.74, 6.69, 3.48, 6.63, 4.45, 7.38, 1.05, 5.0,  9.04,
                     2.0,  8.75, 4.91, 1.62, 2.43, 6.57, 7.98, 1.35, 1.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{4.03, 7.12, 9.06, 5.27, 8.85, 5.19, 4.89, 4.49, 3.28,
                     2.44, 5.82, 7.89, 1.71, 4.96, 5.33, 1.53, 3.21, 3.5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedSub(6, 3);
  double *arr3 = new double[18]{-0.29, -0.43, -5.58, 1.36,  -4.4,  2.19,
                                -3.84, 0.51,  5.76,  -0.44, 2.93,  -2.98,
                                -0.09, -2.53, 1.24,  6.45,  -1.86, -2.0};
  expectedSub.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result -= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedSub);
}
