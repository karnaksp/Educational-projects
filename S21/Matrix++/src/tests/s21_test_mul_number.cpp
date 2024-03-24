#include "s21_test.h"

TEST(MatrixMulNumberTest, MulNumber1) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{3, 4, 7, 8, 1, 7, 2, 2, 4, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{27, 36, 63, 72, 9, 63, 18, 18, 36, 81};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber2) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{7, 10, 6, 4, 5, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 3);
  double *arr2 = new double[6]{70, 100, 60, 40, 50, 100};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber3) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{4, 5, 2, 9, 10, 6, 6, 3, 5, 5, 9, 2,
                                8, 9, 2, 4, 1,  2, 2, 8, 1, 2, 1, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 4);
  double *arr2 = new double[24]{16, 20, 8, 36, 40, 24, 24, 12, 20, 20, 36, 8,
                                32, 36, 8, 16, 4,  8,  8,  32, 4,  8,  4,  4};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber4) {
  S21Matrix matrix(5, 5);
  double *arr1 = new double[25]{7, 9, 5, 5, 4, 7, 1, 8,  8, 2, 6, 10, 6,
                                2, 4, 7, 7, 1, 2, 9, 10, 4, 2, 2, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 5);
  double *arr2 =
      new double[25]{63, 81, 45, 45, 36, 63, 9,  72, 72, 18, 54, 90, 54,
                     18, 36, 63, 63, 9,  18, 81, 90, 36, 18, 18, 18};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber5) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{1, 3, 10, 10, 2, 6, 10, 1, 1, 5, 8, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{1, 3, 10, 10, 2, 6, 10, 1, 1, 5, 8, 5};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber6) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{2, 10, 1, 7, 3, 6, 10, 9, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{4, 20, 2, 14, 6, 12, 20, 18, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber7) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{3, 9, 3, 9, 6, 3, 4, 10, 7, 8, 6, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{12, 36, 12, 36, 24, 12, 16, 40, 28, 32, 24, 24};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber8) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{7, 1, 6, 1, 8, 7, 8, 9, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{56, 8, 48, 8, 64, 56, 64, 72, 32};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber9) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{3, 2, 9, 8, 1, 9, 4, 3, 9, 10, 9, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{24, 16, 72, 64, 8, 72, 32, 24, 72, 80, 72, 48};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber10) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{10, 1, 7, 6, 9, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 3);
  double *arr2 = new double[6]{20, 2, 14, 12, 18, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber11) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{8, 7, 5, 4, 3, 3, 5, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{80, 70, 50, 40, 30, 30, 50, 60};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber12) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{4, 2, 4, 2, 8, 10, 5, 6, 8, 8, 5, 1, 10, 2, 1, 9, 10, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 3);
  double *arr2 = new double[18]{28, 14, 28, 14, 56, 70, 35, 42, 56,
                                56, 35, 7,  70, 14, 7,  63, 70, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber13) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{5, 5, 10, 1, 8, 4, 7, 6, 10, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{40, 40, 80, 8, 64, 32, 56, 48, 80, 56};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber14) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{3, 2, 7, 4, 8, 4, 8, 8, 1, 7, 4, 7, 1, 6, 7,
                                7, 6, 6, 3, 9, 3, 5, 8, 3, 5, 7, 4, 5, 3, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 5);
  double *arr2 =
      new double[30]{9,  6,  21, 12, 24, 12, 24, 24, 3, 21, 12, 21, 3,  18, 21,
                     21, 18, 18, 9,  27, 9,  15, 24, 9, 15, 21, 12, 15, 9,  27};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber15) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{4, 6, 5, 5, 1, 7, 1, 9, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{36, 54, 45, 45, 9, 63, 9, 81, 9};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber16) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{3, 4, 9, 9, 1,  2, 6, 10, 2, 4,
                                4, 7, 5, 9, 10, 1, 7, 5,  2, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{6, 8,  18, 18, 2,  4, 12, 20, 4, 8,
                                8, 14, 10, 18, 20, 2, 14, 10, 4, 12};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber17) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{5, 1, 1, 6, 6, 1, 2, 7, 7, 5, 2, 9, 8, 5, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 3);
  double *arr2 =
      new double[15]{20, 4, 4, 24, 24, 4, 8, 28, 28, 20, 8, 36, 32, 20, 8};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber18) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{3, 1, 4, 2, 4, 1, 6, 5, 3, 10, 7, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{27, 9, 36, 18, 36, 9, 54, 45, 27, 90, 63, 18};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber19) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{10, 6, 6, 7, 9, 2, 9, 10, 9, 6, 7, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{10, 6, 6, 7, 9, 2, 9, 10, 9, 6, 7, 10};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber20) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{9, 10, 2, 5, 10, 7, 6, 9, 8, 3,
                                3, 10, 1, 6, 2,  4, 6, 9, 7, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 5);
  double *arr2 = new double[20]{9, 10, 2, 5, 10, 7, 6, 9, 8, 3,
                                3, 10, 1, 6, 2,  4, 6, 9, 7, 1};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber21) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{7, 7, 3, 3, 5, 4, 8, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{35, 35, 15, 15, 25, 20, 40, 5};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 5;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber22) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{5, 7, 3, 9, 10, 10, 3, 9, 4, 1, 3, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{40, 56, 24, 72, 80, 80, 24, 72, 32, 8, 24, 40};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber23) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{7, 1, 10, 4, 9, 9, 4, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 4);
  double *arr2 = new double[8]{7, 1, 10, 4, 9, 9, 4, 10};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber24) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{4, 7, 8, 1, 3, 1, 1, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 4);
  double *arr2 = new double[8]{24, 42, 48, 6, 18, 6, 6, 30};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber25) {
  S21Matrix matrix(5, 6);
  double *arr1 =
      new double[30]{10, 3, 5, 10, 3, 3, 8, 2, 2, 4, 6,  2, 2, 2, 3,
                     5,  3, 8, 7,  7, 2, 1, 7, 2, 6, 10, 3, 3, 2, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 6);
  double *arr2 =
      new double[30]{40, 12, 20, 40, 12, 12, 32, 8,  8, 16, 24, 8,  8,  8, 12,
                     20, 12, 32, 28, 28, 8,  4,  28, 8, 24, 40, 12, 12, 8, 40};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber26) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{6, 7, 7, 10, 8, 2, 5, 2, 7, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{48, 56, 56, 80, 64, 16, 40, 16, 56, 8};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber27) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{3, 4, 6, 6, 4, 9, 3, 1, 6, 8,
                                2, 1, 4, 8, 3, 4, 6, 8, 5, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{15, 20, 30, 30, 20, 45, 15, 5,  30, 40,
                                10, 5,  20, 40, 15, 20, 30, 40, 25, 20};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 5;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber28) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{1, 1, 7, 6, 2, 8, 4, 5, 1, 4, 1, 2, 4, 7, 6, 9, 5, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 3);
  double *arr2 = new double[18]{10, 10, 70, 60, 20, 80, 40, 50, 10,
                                40, 10, 20, 40, 70, 60, 90, 50, 20};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber29) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{8, 1, 2, 10, 7, 1, 3, 10, 2, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{32, 4, 8, 40, 28, 4, 12, 40, 8, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber30) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{2, 9, 9, 6, 6, 5, 2, 9, 1, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{4, 18, 18, 12, 12, 10, 4, 18, 2, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber31) {
  S21Matrix matrix(6, 6);
  double *arr1 =
      new double[36]{3,  4, 3, 1, 6, 10, 10, 8, 2, 7, 6, 6, 7, 3, 5, 5, 3, 8,
                     10, 5, 2, 2, 5, 8,  10, 2, 7, 3, 3, 7, 1, 1, 2, 9, 6, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 6);
  double *arr2 = new double[36]{27, 36, 27, 9,  54, 90, 90, 72, 18, 63, 54, 54,
                                63, 27, 45, 45, 27, 72, 90, 45, 18, 18, 45, 72,
                                90, 18, 63, 27, 27, 63, 9,  9,  18, 81, 54, 54};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber32) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{3, 2, 7, 5, 9, 3, 2, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 4);
  double *arr2 = new double[8]{9, 6, 21, 15, 27, 9, 6, 3};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber33) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{2, 10, 3, 9, 4, 2, 8, 1, 1,  7,
                                6, 8,  9, 2, 9, 3, 5, 5, 10, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{10, 50, 15, 45, 20, 10, 40, 5,  5,  35,
                                30, 40, 45, 10, 45, 15, 25, 25, 50, 25};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 5;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber34) {
  S21Matrix matrix(5, 3);
  double *arr1 = new double[15]{9, 6, 6, 6, 8, 5, 3, 2, 9, 1, 3, 5, 1, 3, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 3);
  double *arr2 =
      new double[15]{36, 24, 24, 24, 32, 20, 12, 8, 36, 4, 12, 20, 4, 12, 40};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber35) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{2, 4, 8, 7, 9, 5, 1, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 4);
  double *arr2 = new double[8]{4, 8, 16, 14, 18, 10, 2, 20};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber36) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{10, 1, 3, 8, 8, 5, 8, 1, 1, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{10, 1, 3, 8, 8, 5, 8, 1, 1, 10};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber37) {
  S21Matrix matrix(3, 2);
  double *arr1 = new double[6]{10, 4, 5, 8, 8, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 2);
  double *arr2 = new double[6]{10, 4, 5, 8, 8, 9};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber38) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{4, 2, 7, 3, 1, 1, 4, 3, 5, 7, 3, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{4, 2, 7, 3, 1, 1, 4, 3, 5, 7, 3, 10};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber39) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{4, 5, 2, 10, 8, 3, 3, 4, 2, 2, 2, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{32, 40, 16, 80, 64, 24, 24, 32, 16, 16, 16, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber40) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{10, 3, 10, 2, 2, 6, 6, 4, 1, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{30, 9, 30, 6, 6, 18, 18, 12, 3, 3};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber41) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{7, 1, 6, 4, 10, 9,  8,  10, 7, 5,
                                6, 9, 8, 7, 6,  10, 10, 9,  5, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 5);
  double *arr2 = new double[20]{70, 10, 60, 40, 100, 90,  80,  100, 70, 50,
                                60, 90, 80, 70, 60,  100, 100, 90,  50, 60};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber42) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{10, 7,  2, 4, 8, 4, 3, 9, 7, 6,
                                2,  10, 5, 5, 1, 5, 1, 9, 6, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{80, 56, 16, 32, 64, 32, 24, 72, 56, 48,
                                16, 80, 40, 40, 8,  40, 8,  72, 48, 32};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber43) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{7, 5, 4, 1,  9, 5, 9, 7, 3, 7,
                                6, 2, 5, 10, 2, 7, 5, 6, 9, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{21, 15, 12, 3,  27, 15, 27, 21, 9,  21,
                                18, 6,  15, 30, 6,  21, 15, 18, 27, 15};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber44) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{4, 8, 8,  7, 8, 7, 4, 2, 10, 7, 7, 9,
                                9, 4, 10, 1, 2, 3, 2, 9, 9,  5, 3, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 6);
  double *arr2 = new double[24]{16, 32, 32, 28, 32, 28, 16, 8,  40, 28, 28, 36,
                                36, 16, 40, 4,  8,  12, 8,  36, 36, 20, 12, 36};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber45) {
  S21Matrix matrix(6, 6);
  double *arr1 =
      new double[36]{6, 3, 8,  1, 6, 6, 3, 6, 2, 4, 6, 3, 8, 10, 2, 8, 9, 4,
                     5, 2, 10, 4, 3, 4, 3, 9, 5, 1, 1, 8, 3, 9,  5, 3, 6, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 6);
  double *arr2 = new double[36]{42, 21, 56, 7,  42, 42, 21, 42, 14, 28, 42, 21,
                                56, 70, 14, 56, 63, 28, 35, 14, 70, 28, 21, 28,
                                21, 63, 35, 7,  7,  56, 21, 63, 35, 21, 42, 28};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber46) {
  S21Matrix matrix(5, 5);
  double *arr1 = new double[25]{1, 1, 8, 6,  7, 7, 1, 2, 8, 9, 9, 7, 6,
                                2, 2, 5, 10, 3, 7, 2, 1, 2, 3, 7, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 5);
  double *arr2 = new double[25]{2, 2, 16, 12, 14, 14, 2, 4, 16, 18, 18, 14, 12,
                                4, 4, 10, 20, 6,  14, 4, 2, 4,  6,  14, 8};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber47) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{5, 1, 1, 7, 5, 5, 6, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{40, 8, 8, 56, 40, 40, 48, 40};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber48) {
  S21Matrix matrix(6, 4);
  double *arr1 = new double[24]{4, 8,  9, 8, 2, 4, 3, 4, 7, 3, 5,  8,
                                3, 10, 5, 8, 5, 2, 5, 5, 7, 1, 10, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 4);
  double *arr2 = new double[24]{20, 40, 45, 40, 10, 20, 15, 20, 35, 15, 25, 40,
                                15, 50, 25, 40, 25, 10, 25, 25, 35, 5,  50, 5};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 5;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber49) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{2, 8, 1, 2, 4, 7, 3, 8, 6, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{4, 16, 2, 4, 8, 14, 6, 16, 12, 18};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber50) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{2, 5, 8, 3, 9, 8, 1, 10, 7, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{18, 45, 72, 27, 81, 72, 9, 90, 63, 36};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber51) {
  S21Matrix matrix(6, 6);
  double *arr1 =
      new double[36]{2, 5, 8, 2,  9, 10, 7, 3, 3, 10, 10, 3, 2, 6, 1, 8,  6, 1,
                     6, 7, 8, 10, 1, 8,  7, 2, 7, 10, 3,  2, 4, 2, 7, 10, 8, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 6);
  double *arr2 = new double[36]{4,  10, 16, 4,  18, 20, 14, 6,  6,  20, 20, 6,
                                4,  12, 2,  16, 12, 2,  12, 14, 16, 20, 2,  16,
                                14, 4,  14, 20, 6,  4,  8,  4,  14, 20, 16, 6};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber52) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{6, 5, 9, 5, 4, 2, 6, 10, 2, 9, 8, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{36, 30, 54, 30, 24, 12, 36, 60, 12, 54, 48, 42};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber53) {
  S21Matrix matrix(3, 6);
  double *arr1 =
      new double[18]{3, 5, 5, 4, 10, 3, 6, 1, 8, 7, 8, 1, 3, 6, 10, 8, 5, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 6);
  double *arr2 = new double[18]{24, 40, 40, 32, 80, 24, 48, 8,  64,
                                56, 64, 8,  24, 48, 80, 64, 40, 8};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber54) {
  S21Matrix matrix(5, 6);
  double *arr1 =
      new double[30]{4, 10, 8, 1, 9, 8, 10, 10, 5, 3,  6, 6,  9, 5, 10,
                     4, 5,  8, 5, 6, 6, 5,  9,  4, 10, 5, 10, 5, 4, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 6);
  double *arr2 = new double[30]{28, 70, 56, 7,  63, 56, 70, 70, 35, 21,
                                42, 42, 63, 35, 70, 28, 35, 56, 35, 42,
                                42, 35, 63, 28, 70, 35, 70, 35, 28, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber55) {
  S21Matrix matrix(2, 3);
  double *arr1 = new double[6]{10, 3, 8, 5, 3, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 3);
  double *arr2 = new double[6]{100, 30, 80, 50, 30, 100};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber56) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{4, 10, 6, 1};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 2);
  double *arr2 = new double[4]{32, 80, 48, 8};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber57) {
  S21Matrix matrix(4, 4);
  double *arr1 =
      new double[16]{6, 9, 4, 8, 7, 3, 7, 8, 9, 7, 1, 1, 1, 10, 10, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 4);
  double *arr2 = new double[16]{60, 90, 40, 80, 70, 30,  70,  80,
                                90, 70, 10, 10, 10, 100, 100, 70};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber58) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{2, 7, 3, 10, 9, 5, 2, 1, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{6, 21, 9, 30, 27, 15, 6, 3, 21};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber59) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{6, 7, 2, 1, 5, 2, 10, 4, 3, 4, 2, 7, 6, 7, 9};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 5);
  double *arr2 =
      new double[15]{24, 28, 8, 4, 20, 8, 40, 16, 12, 16, 8, 28, 24, 28, 36};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber60) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{1, 8, 3, 4, 2, 3, 10, 9, 2, 2, 3, 9, 3, 5, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 5);
  double *arr2 =
      new double[15]{6, 48, 18, 24, 12, 18, 60, 54, 12, 12, 18, 54, 18, 30, 36};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber61) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{7, 2, 2, 2, 7, 3, 1, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{49, 14, 14, 14, 49, 21, 7, 21};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber62) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{10, 9, 9, 9, 4, 8, 4, 8, 7, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{80, 72, 72, 72, 32, 64, 32, 64, 56, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber63) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{7, 9, 8, 2, 9, 6, 10, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{56, 72, 64, 16, 72, 48, 80, 16};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber64) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{4, 4, 4, 4, 6, 6, 9, 9, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{36, 36, 36, 36, 54, 54, 81, 81, 45};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber65) {
  S21Matrix matrix(4, 4);
  double *arr1 =
      new double[16]{4, 8, 4, 3, 9, 2, 5, 10, 3, 7, 4, 8, 1, 8, 1, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 4);
  double *arr2 =
      new double[16]{4, 8, 4, 3, 9, 2, 5, 10, 3, 7, 4, 8, 1, 8, 1, 5};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber66) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{4, 3, 9, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 2);
  double *arr2 = new double[4]{12, 9, 27, 9};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber67) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{10, 10, 3, 1, 10, 5, 2, 5, 6, 6, 8, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 3);
  double *arr2 = new double[12]{20, 20, 6, 2, 20, 10, 4, 10, 12, 12, 16, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber68) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{4, 7, 5, 10, 8, 4, 1, 3, 7, 3, 9, 5, 6, 1, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 5);
  double *arr2 =
      new double[15]{36, 63, 45, 90, 72, 36, 9, 27, 63, 27, 81, 45, 54, 9, 72};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber69) {
  S21Matrix matrix(2, 4);
  double *arr1 = new double[8]{8, 2, 6, 8, 9, 4, 3, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 4);
  double *arr2 = new double[8]{80, 20, 60, 80, 90, 40, 30, 50};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber70) {
  S21Matrix matrix(6, 6);
  double *arr1 =
      new double[36]{7, 2, 8, 10, 4, 9, 8, 2, 5, 9, 10, 3, 6, 2, 1, 7,  9,  10,
                     9, 8, 8, 6,  4, 9, 4, 1, 1, 9, 1,  4, 2, 6, 9, 10, 10, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 6);
  double *arr2 = new double[36]{21, 6, 24, 30, 12, 27, 24, 6,  15, 27, 30, 9,
                                18, 6, 3,  21, 27, 30, 27, 24, 24, 18, 12, 27,
                                12, 3, 3,  27, 3,  12, 6,  18, 27, 30, 30, 24};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber71) {
  S21Matrix matrix(5, 2);
  double *arr1 = new double[10]{2, 6, 3, 2, 3, 4, 10, 9, 7, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 2);
  double *arr2 = new double[10]{18, 54, 27, 18, 27, 36, 90, 81, 63, 63};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber72) {
  S21Matrix matrix(6, 5);
  double *arr1 = new double[30]{2, 8, 8, 2,  6, 1, 2, 10, 3, 7, 2, 6,  3, 5, 1,
                                2, 8, 6, 10, 8, 9, 5, 7,  9, 9, 1, 10, 8, 3, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 5);
  double *arr2 = new double[30]{20, 80, 80, 20, 60, 10, 20,  100, 30,  70,
                                20, 60, 30, 50, 10, 20, 80,  60,  100, 80,
                                90, 50, 70, 90, 90, 10, 100, 80,  30,  70};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber73) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{1, 5, 9, 6, 10, 7, 1, 4, 2, 8, 7, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 4);
  double *arr2 = new double[12]{7, 35, 63, 42, 70, 49, 7, 28, 14, 56, 49, 35};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber74) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{8, 4, 6, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 2);
  double *arr2 = new double[4]{48, 24, 36, 30};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber75) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{9, 2, 3, 3, 10, 4, 3, 8, 10, 4, 2, 3, 2, 1, 6};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 5);
  double *arr2 =
      new double[15]{27, 6, 9, 9, 30, 12, 9, 24, 30, 12, 6, 9, 6, 3, 18};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber76) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{6, 1, 9, 9, 2, 7, 1, 6, 2, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{24, 4, 36, 36, 8, 28, 4, 24, 8, 32};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber77) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{2, 1, 7, 3, 10, 4, 7, 5, 4, 6, 8, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{6, 3, 21, 9, 30, 12, 21, 15, 12, 18, 24, 9};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber78) {
  S21Matrix matrix(5, 4);
  double *arr1 = new double[20]{7, 3, 8, 3, 9,  2, 10, 9, 1, 9,
                                6, 5, 5, 6, 10, 4, 10, 7, 6, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 4);
  double *arr2 = new double[20]{49, 21, 56, 21, 63, 14, 70, 63, 7,  63,
                                42, 35, 35, 42, 70, 28, 70, 49, 42, 70};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber79) {
  S21Matrix matrix(2, 5);
  double *arr1 = new double[10]{9, 8, 1, 9, 7, 10, 4, 1, 3, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 5);
  double *arr2 = new double[10]{9, 8, 1, 9, 7, 10, 4, 1, 3, 7};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber80) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{5, 5, 10, 9, 5, 9, 3, 10, 8, 8, 5, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{35, 35, 70, 63, 35, 63, 21, 70, 56, 56, 35, 35};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber81) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{6, 4, 2,  4, 1, 1, 4, 6, 9, 1, 6, 8, 10, 8, 10,
                                3, 7, 10, 1, 5, 4, 5, 7, 4, 9, 1, 3, 8,  9, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 6);
  double *arr2 = new double[30]{60, 40, 20,  40, 10,  10, 40, 60,  90, 10,
                                60, 80, 100, 80, 100, 30, 70, 100, 10, 50,
                                40, 50, 70,  40, 90,  10, 30, 80,  90, 50};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber82) {
  S21Matrix matrix(4, 2);
  double *arr1 = new double[8]{6, 1, 2, 8, 2, 4, 4, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 2);
  double *arr2 = new double[8]{36, 6, 12, 48, 12, 24, 24, 42};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber83) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{7, 4, 4, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 2);
  double *arr2 = new double[4]{49, 28, 28, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber84) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{6, 1, 6, 2, 6, 4, 1, 5, 4, 5, 7, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 4);
  double *arr2 = new double[12]{42, 7, 42, 14, 42, 28, 7, 35, 28, 35, 49, 21};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber85) {
  S21Matrix matrix(3, 5);
  double *arr1 = new double[15]{7, 5, 8, 5, 1, 2, 10, 2, 1, 10, 3, 3, 5, 10, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 5);
  double *arr2 = new double[15]{70, 50,  80, 50, 10, 20,  100, 20,
                                10, 100, 30, 30, 50, 100, 40};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 10;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber86) {
  S21Matrix matrix(3, 4);
  double *arr1 = new double[12]{8, 4, 4, 4, 4, 9, 2, 4, 2, 8, 2, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 4);
  double *arr2 = new double[12]{56, 28, 28, 28, 28, 63, 14, 28, 14, 56, 14, 49};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 7;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber87) {
  S21Matrix matrix(6, 3);
  double *arr1 =
      new double[18]{4, 4, 6, 7, 1, 10, 3, 5, 4, 10, 7, 8, 7, 6, 7, 9, 8, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 3);
  double *arr2 = new double[18]{36, 36, 54, 63, 9,  90, 27, 45, 36,
                                90, 63, 72, 63, 54, 63, 81, 72, 45};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber88) {
  S21Matrix matrix(2, 2);
  double *arr1 = new double[4]{1, 4, 7, 3};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 2);
  double *arr2 = new double[4]{4, 16, 28, 12};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 4;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber89) {
  S21Matrix matrix(4, 6);
  double *arr1 = new double[24]{6, 8, 10, 7, 6, 2, 10, 3, 7, 3, 4, 4,
                                8, 1, 1,  2, 3, 8, 1,  4, 9, 1, 1, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 6);
  double *arr2 = new double[24]{12, 16, 20, 14, 12, 4,  20, 6, 14, 6, 8, 8,
                                16, 2,  2,  4,  6,  16, 2,  8, 18, 2, 2, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber90) {
  S21Matrix matrix(4, 4);
  double *arr1 = new double[16]{8, 7, 9, 3, 2, 1, 7, 6, 8, 4, 5, 6, 4, 1, 3, 2};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 4);
  double *arr2 = new double[16]{72, 63, 81, 27, 18, 9, 63, 54,
                                72, 36, 45, 54, 36, 9, 27, 18};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber91) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{4, 1, 2, 7, 5, 8, 3, 4, 5, 8, 9, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{8, 2, 4, 14, 10, 16, 6, 8, 10, 16, 18, 14};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 2;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber92) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{4, 1, 6, 4, 2, 8, 8, 8, 2, 8,
                                3, 7, 3, 1, 5, 2, 8, 1, 3, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 5);
  double *arr2 = new double[20]{32, 8,  48, 32, 16, 64, 64, 64, 16, 64,
                                24, 56, 24, 8,  40, 16, 64, 8,  24, 80};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber93) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{3, 2, 2, 4, 7, 2, 4, 1, 6, 6, 4, 4};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 3);
  double *arr2 = new double[12]{9, 6, 6, 12, 21, 6, 12, 3, 18, 18, 12, 12};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 3;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber94) {
  S21Matrix matrix(3, 3);
  double *arr1 = new double[9]{2, 8, 2, 6, 8, 10, 7, 4, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(3, 3);
  double *arr2 = new double[9]{16, 64, 16, 48, 64, 80, 56, 32, 56};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber95) {
  S21Matrix matrix(2, 6);
  double *arr1 = new double[12]{2, 6, 9, 5, 3, 1, 1, 3, 5, 7, 6, 10};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(2, 6);
  double *arr2 = new double[12]{18, 54, 81, 45, 27, 9, 9, 27, 45, 63, 54, 90};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber96) {
  S21Matrix matrix(4, 3);
  double *arr1 = new double[12]{6, 8, 4, 1, 10, 2, 6, 5, 3, 9, 10, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 3);
  double *arr2 = new double[12]{36, 48, 24, 6, 60, 12, 36, 30, 18, 54, 60, 30};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber97) {
  S21Matrix matrix(4, 5);
  double *arr1 = new double[20]{8, 7,  7, 5, 5, 2, 9, 7, 9, 6,
                                5, 10, 8, 1, 9, 2, 9, 4, 8, 5};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(4, 5);
  double *arr2 = new double[20]{72, 63, 63, 45, 45, 18, 81, 63, 81, 54,
                                45, 90, 72, 9,  81, 18, 81, 36, 72, 45};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 9;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber98) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{7, 1, 9, 3, 7, 1, 2, 8, 8, 1, 4, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{42, 6, 54, 18, 42, 6, 12, 48, 48, 6, 24, 48};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 6;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber99) {
  S21Matrix matrix(5, 6);
  double *arr1 = new double[30]{6, 8, 8, 3, 4, 7, 1, 6, 1, 2, 3, 9,  6, 6, 8,
                                3, 3, 7, 7, 8, 5, 5, 7, 9, 4, 4, 10, 2, 1, 8};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(5, 6);
  double *arr2 = new double[30]{48, 64, 64, 24, 32, 56, 8,  48, 8,  16,
                                24, 72, 48, 48, 64, 24, 24, 56, 56, 64,
                                40, 40, 56, 72, 32, 32, 80, 16, 8,  64};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix;
  result *= 8;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulNumberTest, MulNumber100) {
  S21Matrix matrix(6, 2);
  double *arr1 = new double[12]{2, 3, 5, 5, 5, 6, 7, 5, 5, 4, 1, 7};
  matrix.fillMatrixFromArray(arr1);

  S21Matrix expectedMul(6, 2);
  double *arr2 = new double[12]{2, 3, 5, 5, 5, 6, 7, 5, 5, 4, 1, 7};
  expectedMul.fillMatrixFromArray(arr2);

  S21Matrix result = matrix * 1;

  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(result == expectedMul);
}
