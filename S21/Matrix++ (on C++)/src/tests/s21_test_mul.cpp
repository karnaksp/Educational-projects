#include "s21_test.h"

TEST(MatrixMulTest, MulMatrix1) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{3, 5, 4, 9, 3, 5, 9, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{3, 6, 2, 3, 5, 5, 6, 7, 4, 3, 8, 4, 6, 9, 8, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 4);
  double *arr3 = new double[8]{104, 136, 140, 141, 76, 79, 116, 89};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix2) {
  S21Matrix matrix1(3, 3);
  double *arr1 = new double[9]{4, 7, 1, 7, 3, 7, 4, 6, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{6, 1, 2, 8, 3, 4, 4, 8, 2, 5, 1, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 4);
  double *arr3 =
      new double[12]{47, 37, 37, 91, 65, 54, 33, 101, 60, 73, 41, 107};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix3) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{4, 1, 3, 8, 4, 8, 8, 6, 2, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{9, 9, 7, 7, 6, 3, 1, 8, 7, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 =
      new double[25]{39, 37, 36, 35, 30,  51, 35, 85, 77, 66, 60, 44, 92,
                     84, 72, 90, 78, 104, 98, 84, 24, 20, 30, 28, 24};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix4) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{3, 6, 2, 4, 1, 9, 2, 6, 7, 6, 2, 3, 6, 5, 7, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix5) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{3, 7, 3, 7, 7, 5, 6, 9, 9, 1,
                                3, 5, 4, 2, 6, 2, 4, 7, 4, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{6, 5, 7, 7, 4, 7, 4, 3, 2, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 2);
  double *arr3 = new double[8]{121, 148, 146, 163, 89, 120, 86, 105};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix6) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{5, 3, 7, 1, 9, 3, 5, 3, 1, 5, 4, 7, 4, 2, 4, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{7, 1, 5, 3, 5, 6, 7, 9, 4, 6,
                                5, 6, 6, 5, 7, 8, 5, 1, 5, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{96,  73, 95, 67, 96, 130, 75, 105, 79, 110,
                                113, 95, 81, 78, 91, 92,  62, 66,  60, 76};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix7) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{8, 7, 3, 6, 7, 8, 8, 4, 8, 6, 6, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix8) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{7, 5, 7, 9, 8, 8, 3, 2, 7, 7, 8, 7, 7, 2, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{8, 9, 8, 4, 8, 4, 3, 4, 2, 1, 5, 5, 9, 8, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 = new double[25]{111, 113, 139, 94,  103, 144, 145, 176, 116,
                                128, 67,  68,  95,  72,  68,  123, 122, 151,
                                100, 106, 99,  104, 127, 88,  100};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix9) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{2, 7, 6, 1, 2, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix10) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{4, 1, 5, 3, 8, 8, 5, 1, 8, 1, 1, 1, 6,
                                7, 3, 6, 2, 2, 2, 7, 8, 3, 3, 3, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix11) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{7, 3, 9, 1, 1, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{5, 8, 9, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 2);
  double *arr3 = new double[6]{62, 59, 54, 73, 68, 15};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix12) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{6, 3, 8, 9, 2, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{2, 5, 7, 4, 6, 5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{81, 82, 86, 98};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix13) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{3, 8, 9, 5, 6, 7, 7, 1, 1, 2, 2, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{4, 8, 3, 8, 4, 8, 6, 5, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 3);
  double *arr3 =
      new double[12]{130, 101, 91, 110, 99, 77, 42, 65, 31, 54, 49, 32};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix14) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{7, 2, 4, 5, 4, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix15) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{3, 9, 8, 6, 7, 7, 4, 5, 5, 7, 9, 4, 7, 1, 2, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{1, 8, 8, 9, 2, 5, 7, 6, 1, 7, 4, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 3);
  double *arr3 =
      new double[12]{182, 114, 89, 133, 114, 105, 159, 124, 92, 79, 98, 77};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix16) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{1, 9, 2, 2, 5, 3, 7, 3, 5, 8, 4, 3, 3,
                                8, 1, 7, 3, 7, 4, 9, 3, 5, 6, 5, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix17) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{6, 5, 2, 3, 4, 8, 7, 8, 8, 3, 8, 8, 6, 9, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{1, 2, 3, 4, 8, 9, 4, 5, 8, 5, 7, 8, 7, 2, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 3);
  double *arr3 = new double[9]{77, 91, 119, 129, 174, 227, 116, 175, 220};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix18) {
  S21Matrix matrix1(3, 3);
  double *arr1 = new double[9]{7, 6, 1, 2, 5, 8, 3, 1, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix19) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{4, 8, 8, 9, 5, 9, 2, 7, 3, 6, 9, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{2, 7, 5, 7, 1, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 2);
  double *arr3 = new double[8]{56, 92, 52, 107, 42, 66, 59, 107};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix20) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{3, 4, 9, 6, 3, 8, 3, 2, 2, 8,
                                5, 7, 1, 7, 5, 2, 2, 4, 4, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix21) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{7, 9, 8, 9, 6, 8, 8, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{2, 6, 6, 2, 9, 9, 1, 3, 7, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{95, 51, 69, 77, 144, 97, 57, 75, 79, 153,
                                84, 44, 60, 68, 126, 88, 56, 72, 72, 144};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix22) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{7, 1, 4, 1, 3, 6, 1, 5, 1, 1,
                                2, 3, 2, 5, 1, 6, 1, 6, 1, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{9, 1, 9, 2, 3, 6, 6, 3, 8, 5,
                                5, 4, 7, 3, 5, 3, 6, 7, 3, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 =
      new double[25]{92, 35, 101, 37, 52, 83, 73, 87, 72, 74, 34, 33, 47,
                     25, 36, 71,  72, 82, 65, 72, 62, 65, 62, 65, 62};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix23) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{9, 2, 4, 6, 8, 9, 9, 7, 9, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{1, 3, 1, 7, 3, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 3);
  double *arr3 = new double[15]{23, 33, 11, 46, 30, 10, 71, 51,
                                17, 58, 48, 16, 37, 39, 13};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix24) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{4, 4, 9, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{2, 7, 5, 9, 7, 4, 7, 6, 4, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 5);
  double *arr3 = new double[10]{24, 56, 44, 52, 52, 26, 77, 57, 89, 75};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix25) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{2, 2, 4, 7, 7, 6, 1, 4, 5, 6, 4, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{6, 9, 4, 2, 2, 5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 2);
  double *arr3 = new double[8]{28, 42, 82, 107, 32, 42, 54, 67};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix26) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{8, 4, 4, 6, 3, 6, 4, 5, 5, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{7, 7, 1, 3, 8, 6, 3, 5, 2, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 =
      new double[25]{80, 68, 28, 32, 80, 64, 46, 34, 24, 56, 57, 39, 33,
                     21, 48, 58, 43, 29, 22, 52, 89, 62, 50, 33, 76};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix27) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{6, 8, 7, 6, 2, 3, 9, 4, 4, 5, 1, 6, 6, 8, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{8, 8, 4, 6, 4, 9, 8, 8, 1, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 2);
  double *arr3 = new double[6]{158, 225, 113, 191, 129, 243};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix28) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{1, 3, 3, 8, 5, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{3, 3, 4, 1, 4, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{27, 24, 72, 71};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix29) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{2, 3, 4, 6, 4, 8, 9, 7, 5, 2, 4, 2, 4,
                                2, 3, 8, 9, 2, 4, 8, 1, 7, 9, 1, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{7, 1, 1, 6, 7, 1, 4, 3, 1, 2, 3, 3, 7, 5, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 3);
  double *arr3 = new double[15]{88, 73,  55,  162, 117, 53,  81, 51,
                                37, 182, 129, 87,  143, 120, 76};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix30) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{1, 8, 4, 7, 3, 3, 5, 3, 9, 5, 3, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{3, 5, 6, 2, 7, 2, 4, 5, 2, 5,
                                3, 4, 1, 1, 3, 8, 3, 8, 9, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{87, 74, 106, 85, 87,  54, 56, 62,
                                44, 63, 102, 98, 138, 94, 125};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix31) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{1, 8, 3, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 = new double[18]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix32) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{6, 2, 9, 2, 1, 3, 2, 1, 7, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{1, 3, 4, 1, 3, 7, 6, 6, 5, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{58, 98, 66, 66};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix33) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{3, 3, 5, 7, 9, 1, 8, 6, 7, 3, 3, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{9, 9, 4, 2, 5, 3, 9, 3, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 3);
  double *arr3 =
      new double[12]{78, 57, 56, 90, 111, 62, 147, 123, 99, 51, 48, 35};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix34) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{6, 5, 7, 3, 2, 3, 9, 5, 5, 5,
                                8, 2, 1, 5, 3, 1, 6, 2, 2, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{4, 1, 8, 3, 4, 6, 1, 2, 1, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 2);
  double *arr3 = new double[8]{97, 71, 114, 75, 60, 33, 67, 40};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix35) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{2, 8, 1, 2, 8, 2, 9, 4, 4, 8, 7, 8, 8, 6, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix36) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{3, 2, 9, 6, 3, 3, 9, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{1, 4, 5, 2, 7, 5, 2, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 4);
  double *arr3 = new double[16]{17, 22, 19, 20, 51, 66, 57, 60,
                                24, 27, 21, 27, 37, 56, 53, 46};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix37) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{9, 3, 5, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{1, 9, 8, 3, 2, 8, 6, 6, 7, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 5);
  double *arr3 = new double[10]{33, 99, 90, 48, 36, 53, 81, 76, 57, 46};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix38) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{4, 6, 8, 6, 8, 4, 8, 1, 3, 9, 6, 9, 7,
                                4, 8, 5, 6, 7, 3, 4, 9, 4, 3, 5, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{2, 9, 4, 2, 5, 6, 6, 9, 8, 2, 4, 1, 1, 6, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 3);
  double *arr3 = new double[15]{88,  210, 146, 45,  151, 102, 88, 226,
                                162, 74,  174, 127, 55,  154, 92};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix39) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{5, 9, 5, 4, 1, 1, 7, 4, 3, 8,
                                5, 7, 7, 7, 7, 5, 3, 9, 6, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{2, 5, 3, 2, 8, 5, 6, 4, 2, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 2);
  double *arr3 = new double[8]{103, 87, 89, 75, 143, 123, 145, 127};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix40) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{2, 6, 2, 6, 3, 1, 3, 2, 5, 3, 2, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{5, 4, 1, 4, 5, 8, 5, 1, 6, 8, 7, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 3);
  double *arr3 = new double[9]{92, 82, 116, 50, 34, 47, 71, 58, 68};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix41) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{1, 4, 6, 1, 7, 9, 9, 2, 7, 6, 2, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{4, 8, 3, 5, 7, 3, 6, 9, 5, 4,
                                5, 2, 4, 6, 9, 6, 7, 9, 9, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{52,  51,  72, 70,  79,  112, 142, 156,
                                152, 170, 86, 131, 128, 122, 101};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix42) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{6, 7, 4, 5, 9, 9, 7, 1, 4, 5, 5, 1, 2, 2, 9, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{9, 8, 6, 6, 3, 4, 4, 6, 2, 9, 8, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 3);
  double *arr3 =
      new double[12]{157, 133, 102, 172, 149, 110, 95, 85, 60, 129, 132, 80};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix43) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{8, 9, 4, 7, 5, 1, 3, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix44) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{9, 1, 6, 1, 8, 5, 5, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{6, 9, 1, 3, 6, 8, 8, 4, 2, 4, 2, 4, 9, 8, 1, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 4);
  double *arr3 = new double[8]{81, 121, 30, 62, 124, 164, 62, 92};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix45) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{8, 8, 5, 4, 6, 4, 9, 9, 2, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{7, 7, 2, 9, 7, 3, 8, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 4);
  double *arr3 = new double[20]{112, 80, 80,  120, 63, 47,  42, 69, 70, 54,
                                44,  78, 126, 90,  90, 135, 70, 38, 68, 66};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix46) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{9, 3, 8, 3, 2, 9, 6, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix47) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{8, 5, 7, 1, 1, 6, 5, 7, 6, 2, 8, 3, 2, 3, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{1, 8, 1, 4, 1, 1, 5, 6, 5, 6, 3, 3, 8,
                                6, 3, 2, 3, 3, 6, 7, 2, 2, 9, 2, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{38,  115, 106, 107, 67, 48, 116, 128,
                                131, 101, 27,  98,  69, 81, 55};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix48) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{4, 1, 5, 3, 6, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{1, 1, 3, 8, 6, 8, 7, 1, 8};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 3);
  double *arr3 = new double[6]{47, 15, 60, 114, 48, 129};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix49) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{1, 8, 5, 2, 4, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix50) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{6, 2, 1, 3, 3, 4, 4, 6, 6, 3, 8, 7, 3, 1, 4, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix51) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{4, 2, 8, 7, 8, 7, 6, 4, 5, 9, 2, 2, 2, 7, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{3, 3, 6, 2, 8, 4, 5, 1, 1, 7, 9, 9, 7,
                                5, 3, 1, 7, 7, 4, 8, 4, 8, 7, 8, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{131, 207, 187, 142, 198, 122, 194, 174,
                                132, 231, 51,  107, 98,  68,  119};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix52) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{2, 4, 1, 6, 1, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix53) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{7, 1, 9, 6, 5, 6, 7, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{1, 5, 5, 5, 6, 5, 8, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 4);
  double *arr3 = new double[16]{13, 40, 43, 37, 45, 75, 93, 57,
                                41, 55, 73, 37, 43, 65, 83, 47};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix54) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{4, 9, 1, 7, 8, 7, 5, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{7, 2, 5, 2, 2, 6, 1, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 4);
  double *arr3 = new double[16]{46, 62, 29, 17, 21, 44, 12, 9,
                                70, 58, 47, 23, 47, 46, 31, 16};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix55) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{6, 7, 3, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix56) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{6, 4, 2, 4, 5, 1, 7, 3, 9, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{3, 1, 9, 2, 2, 2, 9, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 4);
  double *arr3 = new double[20]{26, 14, 90, 24, 14, 10, 54, 16, 17,  7,
                                54, 13, 27, 13, 90, 23, 43, 25, 153, 42};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix57) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{5, 4, 9, 8, 3, 2, 1, 2, 2, 7, 2, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix58) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{6, 2, 2, 1, 1, 4, 3, 7, 6, 2,
                                1, 9, 1, 8, 6, 3, 7, 7, 1, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix59) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{7, 9, 8, 1, 6, 3, 7, 8, 3, 5, 2, 5, 4, 3, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{5, 1, 5, 2, 4, 5, 6, 8, 2, 1,
                                1, 7, 1, 8, 1, 2, 4, 2, 6, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 4);
  double *arr3 =
      new double[12]{112, 80, 134, 150, 82, 80, 98, 129, 73, 71, 95, 86};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix60) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{5, 7, 6, 1, 5, 9, 9, 9, 5, 7, 2, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix61) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{4, 3, 3, 5, 7, 4, 9, 8, 5, 3,
                                8, 9, 1, 8, 8, 9, 7, 7, 1, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{8, 1, 1, 3, 9, 3, 1, 2, 6, 3, 4, 9, 7, 6, 6, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 4);
  double *arr3 =
      new double[20]{112, 52,  49,  90,  202, 94,  95,  182, 178, 92,
                     94,  174, 191, 103, 95,  172, 153, 55,  42,  80};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix62) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{2, 8, 3, 3, 1, 2, 2, 5, 2, 4, 6, 2, 9, 7, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{5, 8, 6, 7, 8, 2, 8, 3, 7, 5, 2, 6, 5, 7, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 =
      new double[25]{32, 98, 51, 91, 74, 21, 44, 31, 42,  41,  24,  68, 37,
                     63, 53, 36, 92, 52, 84, 74, 77, 182, 120, 175, 161};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix63) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{7, 2, 8, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{9, 8, 7, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{77, 58, 114, 70};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix64) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{6, 1, 1, 4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix65) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{7, 9, 8, 5, 2, 2, 8, 8, 9, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{1, 7, 6, 9, 9, 6, 5, 3, 6, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{170, 207, 173, 168};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix66) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{8, 7, 4, 8, 3, 8, 2, 4, 5, 7, 6, 3, 1, 1, 1, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{7, 8, 7, 7, 3, 6, 3, 2, 1, 2, 4, 5, 8, 1, 5, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 4);
  double *arr3 = new double[16]{145, 122, 133, 122, 79, 80, 73, 63,
                                86,  97,  95,  91,  83, 25, 59, 50};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix67) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{1, 8, 6, 5, 3, 2, 1, 6, 2, 7,
                                7, 3, 6, 4, 9, 6, 1, 5, 5, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{1, 1, 2, 5, 3, 1, 7, 2, 6, 8, 7, 2, 3, 6, 4, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 4);
  double *arr3 = new double[20]{76,  87, 120, 68,  33,  49, 51, 63, 74, 83,
                                114, 59, 90,  118, 127, 98, 64, 82, 96, 67};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix68) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{9, 7, 1, 9, 6, 2, 2, 2, 4, 2, 6, 7, 9, 1, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{6, 1, 5, 4, 7, 5, 3, 7, 4, 2,
                                4, 2, 8, 8, 4, 1, 4, 6, 5, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 4);
  double *arr3 =
      new double[12]{203, 154, 136, 120, 74, 60, 50, 38, 149, 97, 116, 112};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix69) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{8, 3, 6, 5, 4, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{8, 9, 3, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 2);
  double *arr3 = new double[6]{73, 93, 63, 89, 53, 85};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix70) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{8, 8, 5, 1, 7, 4, 2, 6, 5, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{6, 9, 9, 1, 3, 2, 6, 4, 7, 2, 5, 4, 1,
                                8, 2, 1, 8, 8, 2, 3, 1, 8, 9, 8, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 5);
  double *arr3 = new double[10]{97, 204, 180, 162, 74, 69, 160, 144, 124, 61};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix71) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{6, 2, 5, 1, 7, 8, 3, 4, 7, 8,
                                7, 7, 3, 5, 3, 5, 6, 6, 8, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{3, 2, 4, 3, 9, 6, 2, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 2);
  double *arr3 = new double[10]{73, 52, 88, 72, 130, 108, 66, 59, 124, 98};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix72) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{2, 2, 6, 2, 7, 1, 3, 8, 7, 8, 9, 8, 3,
                                7, 4, 5, 7, 1, 8, 3, 5, 1, 5, 7, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{8, 9, 1, 2, 2, 9, 7, 6, 1, 5, 2, 6, 5,
                                7, 8, 9, 6, 8, 9, 8, 2, 7, 2, 4, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 = new double[25]{78,  129, 74,  94,  141, 130, 176, 131, 156,
                                209, 221, 225, 136, 126, 174, 183, 169, 122,
                                108, 144, 138, 180, 108, 141, 183};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix73) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{9, 3, 7, 4, 4, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{5, 8, 6, 3, 7, 6, 8, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 4);
  double *arr3 = new double[12]{66, 90, 78, 39, 63, 80, 74, 37, 62, 68, 72, 36};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix74) {
  S21Matrix matrix1(3, 3);
  double *arr1 = new double[9]{3, 4, 9, 2, 4, 3, 2, 7, 7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{7, 8, 9, 5, 5, 6, 3, 4, 7, 4, 2, 3, 9, 1, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{63, 63, 124, 52, 112, 44, 37, 61,
                                41, 53, 70,  58, 109, 66, 101};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix75) {
  S21Matrix matrix1(3, 3);
  double *arr1 = new double[9]{9, 1, 7, 5, 8, 7, 7, 1, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix76) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{4, 6, 2, 4, 5, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix77) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{8, 6, 3, 3, 3, 1, 7, 6, 1, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{4, 6, 1, 5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 2);
  double *arr3 = new double[10]{38, 78, 15, 33, 13, 23, 34, 72, 12, 46};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix78) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{4, 7, 7, 5, 5, 3, 9, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{8, 8, 4, 2, 4, 1, 6, 8, 7, 4};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{39, 74, 72, 57, 44, 61, 86,  68, 49, 48,
                                43, 58, 44, 31, 32, 77, 102, 76, 53, 56};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix79) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{8, 7, 7, 6, 9, 5, 2, 3, 3, 1, 4, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 = new double[9]{6, 8, 2, 4, 3, 2, 2, 7, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 3);
  double *arr3 =
      new double[12]{90, 134, 51, 82, 110, 45, 30, 46, 19, 32, 55, 25};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix80) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{7, 7, 2, 5, 7, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 = new double[18]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix81) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{2, 9, 6, 9, 8, 5, 7, 9, 9, 8,
                                1, 6, 6, 5, 2, 2, 4, 9, 9, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{1, 7, 5, 4, 7, 2, 3, 8, 1, 1, 5, 4, 6,
                                5, 4, 5, 9, 8, 2, 7, 2, 3, 8, 1, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{111, 170, 254, 73, 182, 125, 197, 271, 98, 213,
                                72,  100, 145, 52, 90,  118, 170, 240, 84, 198};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix82) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{5, 4, 2, 2, 9, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{4, 9, 5, 3, 6, 6, 5, 8};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 4);
  double *arr3 =
      new double[12]{44, 69, 45, 47, 20, 30, 20, 22, 66, 111, 70, 67};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix83) {
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{5, 8, 1, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 = new double[10]{7, 5, 2, 7, 5, 6, 5, 7, 9, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 5);
  double *arr3 = new double[10]{83, 65, 66, 107, 81, 55, 45, 58, 79, 61};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix84) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{4, 6, 8, 9, 5, 4, 3, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{8, 7, 6, 5, 9, 9, 4, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 4);
  double *arr3 = new double[16]{86, 82, 48, 56, 145, 137, 84, 94,
                                76, 71, 46, 49, 33,  30,  22, 21};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix85) {
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{9, 6, 9, 2, 8, 3, 8, 6, 3, 4, 7, 9, 4, 4, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{1, 4, 5, 8, 3, 2, 4, 1, 6, 8, 6, 4, 1,
                                7, 7, 2, 2, 4, 3, 1, 6, 3, 6, 6, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{127, 124, 116, 225, 156, 85,  86, 65,
                                147, 126, 69,  94,  76,  162, 129};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix86) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{1, 7, 9, 2, 8, 4, 3, 6, 7, 6, 5, 8, 6, 3, 2, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{3, 7, 9, 4, 7, 9, 7, 4, 3, 2,
                                7, 9, 9, 2, 4, 6, 1, 1, 6, 8};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{141, 139, 120, 55,  73,  117, 117, 121, 86, 124,
                                158, 144, 140, 104, 145, 65,  82,  85,  43, 64};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix87) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{6, 9, 8, 7, 6, 2, 3, 6, 8, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{9, 2, 6, 8, 7, 7, 2, 4, 9, 2};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{232, 180, 148, 114};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix88) {
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{9, 6, 3, 2, 7, 3, 6, 1, 5, 1,
                                8, 4, 4, 2, 8, 1, 6, 1, 2, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix89) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{6, 2, 2, 2, 7, 8, 9, 4, 1, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{9, 5, 9, 6, 2, 7, 6, 3, 8, 9,
                                4, 9, 8, 3, 6, 1, 8, 5, 7, 6};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 4);
  double *arr3 = new double[8]{146, 103, 135, 104, 170, 167, 183, 142};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix90) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{5, 3, 7, 9, 2, 4, 3, 1, 4, 6, 2, 2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix91) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{4, 3, 4, 1, 1, 6, 8, 1, 2, 8, 2, 6, 8,
                                1, 5, 2, 2, 6, 1, 5, 1, 1, 1, 3, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{7, 6, 5, 2, 5, 2, 2, 8, 1, 8, 7, 8, 9, 9, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 3);
  double *arr3 = new double[15]{59, 87, 39,  148, 170, 71,  95, 158,
                                43, 83, 122, 33,  107, 112, 40};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix92) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{6, 6, 4, 7, 7, 7, 1, 6, 1, 6, 8, 3, 2, 4, 8, 8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{3, 8, 9, 6, 7, 9, 6, 2, 2, 1,
                                8, 1, 4, 5, 3, 1, 2, 8, 1, 1};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(4, 5);
  double *arr3 = new double[20]{111, 102, 138, 75, 67, 98,  111, 129, 67, 65,
                                124, 58,  77,  61, 40, 114, 64,  122, 68, 50};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix93) {
  S21Matrix matrix1(3, 3);
  double *arr1 = new double[9]{8, 2, 9, 9, 4, 7, 6, 5, 9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{5, 3, 8, 6, 8, 1, 5, 1, 7, 4, 7, 5, 7, 1, 5};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 5);
  double *arr3 = new double[15]{105, 79,  129, 71, 117, 98, 82, 125,
                                89,  123, 98,  88, 116, 80, 113};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix94) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{4, 8, 8, 8, 4, 1, 6, 7, 4, 6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{7, 4, 3, 3, 9, 5, 1, 7, 8, 4, 2, 5, 3,
                                7, 6, 8, 2, 8, 9, 2, 7, 2, 8, 7, 8};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 5);
  double *arr3 = new double[10]{176, 88, 188, 232, 164, 125, 65, 146, 178, 131};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix95) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{2, 5, 5, 5, 4, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{6, 8, 3, 7, 3, 9};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 3);
  double *arr3 = new double[9]{47, 31, 51, 65, 55, 60, 45, 41, 39};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix96) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{6, 9, 9, 6, 3, 8, 6, 5, 5, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix97) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{6, 5, 1, 8, 3, 7, 5, 5, 2, 3, 2, 4, 6, 1, 7, 3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{};
  matrix2.fillMatrixFromArray(arr2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);

  delete[] arr1;
  delete[] arr2;
}

TEST(MatrixMulTest, MulMatrix98) {
  S21Matrix matrix1(2, 5);
  double *arr1 = new double[10]{2, 9, 4, 1, 2, 6, 7, 2, 4, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 = new double[10]{5, 1, 8, 8, 2, 8, 3, 5, 4, 7};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(2, 2);
  double *arr3 = new double[4]{101, 125, 106, 105};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix99) {
  S21Matrix matrix1(5, 5);
  double *arr1 = new double[25]{4, 3, 8, 2, 6, 2, 4, 8, 8, 3, 9, 4, 3,
                                5, 7, 2, 2, 2, 3, 8, 8, 8, 6, 7, 5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 = new double[25]{1, 8, 1, 6, 9, 5, 3, 9, 5, 6, 3, 7, 7,
                                3, 1, 6, 4, 9, 3, 9, 9, 3, 7, 8, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(5, 5);
  double *arr3 = new double[25]{109, 123, 147, 117, 98,  121, 125, 187, 104,
                                131, 131, 146, 160, 154, 174, 108, 72,  117,
                                101, 83,  153, 173, 220, 167, 204};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1;
  result *= matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}

TEST(MatrixMulTest, MulMatrix100) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{3, 6, 1, 1, 2, 8, 2, 5, 9, 5, 3, 1};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{4, 6, 9, 6, 1, 2, 3, 3};
  matrix2.fillMatrixFromArray(arr2);

  S21Matrix expectedMul(3, 2);
  double *arr3 = new double[6]{70, 59, 97, 79, 87, 93};
  expectedMul.fillMatrixFromArray(arr3);

  S21Matrix result = matrix1 * matrix2;

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  ASSERT_TRUE(result == expectedMul);
}
