#include "s21_test.h"

TEST(MatrixEqualityTest, EqualityCheck1) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{1.72, 6.72, 1.24, 4.81, 9.68, 1.3};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{1.72, 6.72, 1.24, 4.81, 9.68, 1.3};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck2) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{8.31, 6.46, 7.41, 2.87, 2.51, 4.85, 4.36,
                                8.46, 5.64, 6.18, 9.14, 1.06, 7.99, 1.45,
                                2.72, 9.94, 4.74, 8.06, 5.12, 4.33};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{8.27, 2.18, 8.27, 4.92, 2.98, 6.0,  9.31, 8.69,
                                1.0,  5.26, 6.63, 6.95, 9.68, 9.88, 2.57, 1.39,
                                9.56, 1.39, 9.06, 9.47, 2.65, 5.09};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck3) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{9.63, 5.75, 3.91, 3.79, 5.54, 7.13, 9.01, 3.41,
                                8.1,  9.27, 8.33, 3.04, 6.11, 8.9,  1.09, 5.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{9.63, 5.75, 3.91, 3.79, 5.54, 7.13, 9.01, 3.41,
                                8.1,  9.27, 8.33, 3.04, 6.11, 8.9,  1.09, 5.5};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck4) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{6.48, 6.39, 5.08, 4.87, 3.87, 4.7, 2.0, 1.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{5.8, 9.9, 8.12, 8.43, 8.46, 2.3, 9.27, 2.57};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck5) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{3.65, 2.03, 4.34, 4.72, 8.9,  9.11,
                                3.95, 3.52, 3.34, 6.87, 9.96, 2.05};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{6.73, 5.49, 5.88, 8.17, 5.15, 4.72, 5.82,
                                9.09, 9.39, 4.25, 1.32, 5.16, 6.26, 8.53};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck6) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{1.58, 7.35, 7.73, 6.7,  5.05, 7.32, 3.4, 9.36,
                                9.24, 7.16, 5.09, 1.55, 3.74, 8.96, 5.6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{1.58, 7.35, 7.73, 6.7,  5.05, 7.32, 3.4, 9.36,
                                9.24, 7.16, 5.09, 1.55, 3.74, 8.96, 5.6};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck7) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{6.12, 7.13, 5.64, 9.91, 7.73, 3.25, 5.79, 1.32};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{6.12, 7.13, 5.64, 9.91, 7.73, 3.25, 5.79, 1.32};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck8) {
  S21Matrix matrix1(5, 2);
  double *arr1 = new double[10]{3.38, 1.95, 7.72, 3.92, 5.11,
                                6.34, 4.02, 2.61, 7.61, 5.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{6.72, 7.46, 2.2, 7.19, 7.8, 3.62, 9.67, 2.6, 2.49, 7.6};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck9) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.78, 6.75, 4.12, 8.74, 2.68, 8.75};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{9.78, 6.75, 4.12, 8.74, 2.68, 8.75};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck10) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{3.29, 4.41, 5.48, 9.42};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{3.29, 4.41, 5.48, 9.42};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck11) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{4.57, 3.32, 3.39, 4.94, 5.03, 3.58, 4.15, 1.85, 8.07};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 =
      new double[9]{4.57, 3.32, 3.39, 4.94, 5.03, 3.58, 4.15, 1.85, 8.07};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck12) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{5.19, 9.68, 2.37, 9.99, 2.54, 1.57, 5.27, 6.16, 6.53,
                     9.48, 2.54, 9.31, 6.95, 5.08, 8.14, 1.92, 6.0,  5.33,
                     9.18, 1.75, 3.36, 2.98, 8.66, 9.51, 3.74};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{9.54, 1.7,  4.96, 8.9,  9.98, 1.81, 4.29, 7.09, 1.95,
                     9.64, 1.48, 6.56, 8.15, 3.34, 3.68, 1.61, 8.68, 1.97,
                     9.67, 2.78, 4.61, 7.76, 6.3,  8.85, 2.72};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck13) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{9.53, 5.23, 8.91, 1.21, 3.15, 8.9,  3.11, 4.32,
                                9.09, 5.96, 4.15, 5.91, 3.85, 9.78, 1.5,  4.11,
                                9.65, 1.22, 1.19, 4.9,  2.43, 4.05, 5.84, 2.12,
                                9.51, 9.19, 1.74, 9.54, 3.58, 4.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{8.14, 8.58, 7.57, 9.59, 8.01, 6.62, 6.46, 5.87,
                                5.35, 2.34, 9.2,  5.77, 1.67, 4.36, 7.08, 6.0,
                                4.78, 8.94, 7.05, 6.75, 1.6,  6.11, 9.42, 5.16,
                                6.19, 4.17, 5.22, 6.76, 6.49, 6.46};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck14) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{9.23, 4.45, 9.78, 2.82, 4.11, 6.63, 2.77, 9.78, 7.68,
                     1.55, 7.2,  6.69, 3.65, 2.53, 2.84, 1.21, 5.26, 8.24,
                     7.2,  5.16, 2.07, 9.64, 1.19, 5.67, 7.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 =
      new double[36]{7.92, 5.97, 2.31, 8.25, 9.87, 7.16, 6.61, 5.98, 3.5,
                     6.08, 2.06, 4.44, 6.84, 1.57, 4.99, 2.14, 4.97, 6.43,
                     2.39, 6.92, 5.92, 7.98, 1.14, 8.34, 7.33, 8.65, 5.01};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck15) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{2.4,  9.27, 1.28, 3.62, 9.74, 3.18,
                                1.04, 7.74, 7.41, 5.69, 2.65, 1.82};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{2.4,  9.27, 1.28, 3.62, 9.74, 3.18,
                                1.04, 7.74, 7.41, 5.69, 2.65, 1.82};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck16) {
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{4.12, 7.23, 8.46, 8.76, 4.41, 1.03,
                                2.37, 6.85, 1.7,  8.45, 2.06, 7.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{2.56, 4.04, 1.18, 5.66, 5.54, 4.41,
                                7.22, 5.59, 7.26, 2.34, 3.16, 6.27};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck17) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{3.26, 8.58, 3.83, 7.45, 9.15, 5.28, 2.13, 6.82, 3.03,
                     2.89, 9.9,  3.04, 6.78, 7.07, 9.48, 7.1,  1.52, 7.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 = new double[28]{7.88, 3.01, 1.63, 9.74, 6.57, 7.5,  5.59,
                                1.5,  3.89, 6.96, 4.08, 8.24, 9.43, 4.45,
                                4.03, 7.38, 6.43, 4.55, 8.29, 4.73};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck18) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{4.71, 8.37, 6.31, 9.3,  9.47, 3.2,  7.29, 1.06, 9.92,
                     6.72, 4.46, 8.09, 8.45, 9.4,  8.23, 8.39, 7.74, 6.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{1.42, 7.02, 2.33, 1.79, 6.89, 4.27, 5.67, 8.79, 6.15,
                     1.51, 9.88, 7.32, 9.32, 7.47, 2.35, 4.79, 6.49, 5.4};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck19) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{2.76, 4.11, 1.5,  7.16, 9.49, 1.34, 3.82, 3.95,
                                2.63, 6.48, 7.89, 6.93, 9.65, 5.52, 7.2};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{2.76, 4.11, 1.5,  7.16, 9.49, 1.34, 3.82, 3.95,
                                2.63, 6.48, 7.89, 6.93, 9.65, 5.52, 7.2};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck20) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{6.85, 9.0,  6.85, 8.25, 1.0,  8.04,
                                4.29, 5.27, 2.55, 5.23, 2.18, 8.29};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{6.01, 6.03, 4.63, 7.68, 1.35, 1.87, 3.3,
                                5.5,  1.47, 2.19, 4.79, 3.14, 1.49, 1.31};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck21) {
  S21Matrix matrix1(5, 4);
  double *arr1 =
      new double[20]{5.42, 5.48, 6.59, 5.42, 8.45, 8.13, 5.92, 9.0, 8.44, 7.98,
                     6.25, 3.36, 1.17, 9.77, 3.66, 5.81, 9.37, 2.7, 8.07, 5.58};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{9.75, 9.11, 4.45, 2.74, 3.0,  4.02, 1.86, 1.61,
                                8.44, 5.48, 2.91, 7.7,  8.25, 7.07, 5.04, 6.59,
                                5.95, 4.34, 3.99, 2.18, 2.42, 2.61};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck22) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{7.82, 9.53, 6.66, 8.27, 3.67, 2.8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{8.65, 5.51, 6.26, 1.68, 1.99, 1.3};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck23) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{5.88, 8.37, 7.66, 7.81, 5.84, 4.04,
                                4.31, 2.86, 5.95, 7.22, 1.18, 3.8};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{5.88, 8.37, 7.66, 7.81, 5.84, 4.04,
                                4.31, 2.86, 5.95, 7.22, 1.18, 3.8};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck24) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 5);
  double *arr1 =
      new double[10]{5.19, 9.9, 1.64, 5.4, 8.71, 9.32, 8.54, 3.96, 2.88, 3.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 =
      new double[10]{5.19, 9.9, 1.64, 5.4, 8.71, 9.32, 8.54, 3.96, 2.88, 3.57};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck25) {
  S21Matrix matrix1(2, 5);
  double *arr1 =
      new double[10]{7.72, 2.71, 7.67, 4.69, 8.69, 9.6, 5.18, 6.96, 7.47, 6.6};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 =
      new double[10]{6.53, 4.7, 6.27, 6.54, 1.55, 1.78, 9.95, 6.77, 6.32, 9.85};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck26) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{1.8,  3.82, 6.18, 2.04, 2.81, 9.26, 7.27, 8.51, 3.01,
                     3.17, 1.68, 1.09, 7.07, 6.8,  4.3,  3.29, 6.25, 3.65,
                     2.87, 4.64, 7.23, 1.33, 8.05, 8.91, 9.96};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 5);
  double *arr2 =
      new double[25]{1.8,  3.82, 6.18, 2.04, 2.81, 9.26, 7.27, 8.51, 3.01,
                     3.17, 1.68, 1.09, 7.07, 6.8,  4.3,  3.29, 6.25, 3.65,
                     2.87, 4.64, 7.23, 1.33, 8.05, 8.91, 9.96};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck27) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 5);
  double *arr1 =
      new double[10]{5.9, 2.43, 3.9, 3.25, 7.75, 9.22, 9.92, 2.11, 5.05, 1.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 =
      new double[10]{5.9, 2.43, 3.9, 3.25, 7.75, 9.22, 9.92, 2.11, 5.05, 1.57};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck28) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{7.09, 1.12, 1.67, 6.47, 2.57, 9.21,
                                5.08, 6.59, 2.01, 4.73, 7.92, 2.53};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{9.51, 4.73, 5.76, 6.68, 3.13, 2.18, 7.22,
                                7.32, 1.18, 9.02, 3.24, 3.52, 3.54, 6.19};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck29) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{8.01, 3.5,  2.54, 7.14, 7.67, 8.63, 6.18, 9.31,
                                9.81, 5.62, 8.54, 7.23, 7.97, 2.13, 5.62};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 =
      new double[24]{1.98, 7.37, 3.7, 4.49, 3.98, 1.57, 4.32, 3.56, 8.17,
                     9.22, 9.15, 6.0, 6.72, 6.44, 2.44, 3.95, 1.74};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck30) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 6);
  double *arr1 = new double[12]{6.48, 5.63, 5.23, 6.36, 7.49, 1.13,
                                5.51, 9.43, 5.53, 4.81, 3.25, 3.69};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 6);
  double *arr2 = new double[12]{6.48, 5.63, 5.23, 6.36, 7.49, 1.13,
                                5.51, 9.43, 5.53, 4.81, 3.25, 3.69};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck31) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{3.58, 6.63, 2.35, 8.92, 3.73, 9.86, 9.57, 2.08,
                                6.24, 5.85, 1.68, 5.15, 3.2,  5.26, 8.87, 5.25,
                                6.46, 9.41, 6.13, 3.29, 2.66, 1.92, 1.51, 2.13};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{3.58, 6.63, 2.35, 8.92, 3.73, 9.86, 9.57, 2.08,
                                6.24, 5.85, 1.68, 5.15, 3.2,  5.26, 8.87, 5.25,
                                6.46, 9.41, 6.13, 3.29, 2.66, 1.92, 1.51, 2.13};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck32) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{8.63, 1.54, 3.15, 6.97, 4.21, 8.74, 7.82, 6.45,
                                8.38, 8.81, 2.06, 5.24, 2.7,  2.88, 7.15, 6.46,
                                7.7,  9.48, 7.24, 4.21, 9.41, 7.39, 9.63, 8.51,
                                1.5,  6.35, 3.66, 6.74, 6.18, 3.06};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{8.63, 1.54, 3.15, 6.97, 4.21, 8.74, 7.82, 6.45,
                                8.38, 8.81, 2.06, 5.24, 2.7,  2.88, 7.15, 6.46,
                                7.7,  9.48, 7.24, 4.21, 9.41, 7.39, 9.63, 8.51,
                                1.5,  6.35, 3.66, 6.74, 6.18, 3.06};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck33) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{7.84, 9.78, 3.03, 7.63, 1.78, 9.17, 6.37, 8.14,
                                1.32, 2.02, 4.5,  2.73, 4.28, 7.88, 1.58, 1.07,
                                2.54, 4.63, 9.35, 3.32, 6.71, 9.79, 6.95, 3.24,
                                6.15, 8.92, 3.37, 6.38, 1.17, 8.26};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{7.84, 9.78, 3.03, 7.63, 1.78, 9.17, 6.37, 8.14,
                                1.32, 2.02, 4.5,  2.73, 4.28, 7.88, 1.58, 1.07,
                                2.54, 4.63, 9.35, 3.32, 6.71, 9.79, 6.95, 3.24,
                                6.15, 8.92, 3.37, 6.38, 1.17, 8.26};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck34) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{8.15, 6.56, 1.09, 8.71};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{8.15, 6.56, 1.09, 8.71};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck35) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{5.37, 8.87, 9.3, 3.48};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{5.37, 8.87, 9.3, 3.48};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck36) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{4.17, 2.91, 4.71, 3.87, 3.46, 3.43,
                                5.91, 4.27, 3.78, 7.45, 3.04, 9.15};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{9.43, 4.41, 3.1,  4.5,  6.26, 4.62,
                                3.31, 9.93, 8.36, 2.33, 4.33, 4.15};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck37) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{6.1,  2.14, 8.15, 6.64, 6.89, 1.16, 7.75, 2.95, 8.47,
                     7.46, 7.07, 6.06, 8.4,  2.81, 2.7,  8.7,  7.63, 3.25};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 = new double[28]{4.17, 2.07, 9.01, 9.98, 6.59, 3.87, 5.03,
                                6.32, 1.48, 3.3,  4.51, 8.13, 3.77, 3.56,
                                4.68, 5.59, 3.51, 4.68, 4.61, 7.15};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck38) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{7.63, 9.24, 2.47, 3.54, 8.14, 8.96, 8.29, 9.51,
                                7.26, 6.26, 9.49, 1.33, 2.77, 7.68, 8.31, 7.34,
                                1.01, 1.44, 9.38, 8.77, 1.96, 8.86, 8.47, 9.22,
                                6.74, 7.21, 2.44, 3.93, 9.79, 3.79};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{7.63, 9.24, 2.47, 3.54, 8.14, 8.96, 8.29, 9.51,
                                7.26, 6.26, 9.49, 1.33, 2.77, 7.68, 8.31, 7.34,
                                1.01, 1.44, 9.38, 8.77, 1.96, 8.86, 8.47, 9.22,
                                6.74, 7.21, 2.44, 3.93, 9.79, 3.79};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck39) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{3.72, 2.96, 6.31, 1.19, 8.97, 4.6, 9.61, 3.82,
                                6.04, 8.48, 6.98, 3.8,  8.41, 1.9, 2.03, 5.37,
                                7.46, 7.3,  7.61, 3.25, 9.61, 8.0, 3.24, 3.43};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 5);
  double *arr2 =
      new double[35]{1.98, 3.17, 4.86, 7.41, 5.22, 1.11, 6.34, 6.8,  9.36,
                     7.16, 7.32, 1.82, 5.32, 9.52, 3.15, 1.71, 1.48, 1.92,
                     8.5,  4.96, 6.97, 2.5,  7.32, 1.76, 8.33, 3.46};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck40) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.04, 6.78, 1.28, 1.51, 1.16, 5.04};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{9.04, 6.78, 1.28, 1.51, 1.16, 5.04};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck41) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{8.09, 4.82, 9.03, 6.15, 1.47, 9.29, 4.95, 4.23};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{8.09, 4.82, 9.03, 6.15, 1.47, 9.29, 4.95, 4.23};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck42) {
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{7.51, 3.07, 8.47, 5.33, 7.74, 4.4,  2.22, 4.68, 3.35,
                     6.75, 4.14, 7.88, 3.14, 5.56, 4.62, 1.01, 8.91, 9.4};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 4);
  double *arr2 = new double[28]{7.49, 3.9,  9.22, 4.37, 3.57, 3.78, 6.59,
                                7.19, 8.18, 1.77, 1.58, 1.27, 5.56, 8.02,
                                2.9,  2.15, 2.43, 1.37, 2.65, 4.08};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck43) {
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{7.23, 5.85, 1.04, 3.44, 9.29, 7.6,
                                1.81, 1.9,  1.99, 9.85, 3.25, 7.72};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 3);
  double *arr2 = new double[21]{8.24, 8.0,  8.83, 8.41, 6.13, 3.56, 4.29,
                                6.03, 8.24, 3.29, 8.03, 2.68, 4.69, 9.18};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck44) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{5.3,  8.91, 1.98, 7.2,  5.24, 4.27, 1.58, 9.86,
                                9.75, 9.5,  8.14, 7.44, 6.32, 1.55, 6.57};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{9.32, 3.92, 2.55, 4.09, 1.79, 3.94, 1.85, 5.99,
                                5.02, 4.39, 9.06, 2.13, 5.32, 6.63, 7.62};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck45) {
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{8.41, 9.93, 2.39, 1.56, 8.2,  7.92, 4.87, 9.18,
                                9.25, 1.17, 5.42, 8.38, 8.07, 7.83, 4.97, 5.62,
                                4.1,  7.22, 6.29, 3.03, 6.63, 1.72, 8.96, 1.16};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{4.49, 7.28, 5.57, 3.69, 6.01, 6.4,  4.18, 8.79,
                                2.92, 7.88, 8.86, 4.24, 4.05, 4.79, 6.15, 1.16,
                                4.26, 2.65, 7.01, 3.71, 2.69, 1.78, 9.61, 1.39};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck46) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 4);
  double *arr1 =
      new double[20]{4.2,  5.61, 1.34, 7.41, 4.9,  9.13, 5.2, 3.51, 2.85, 2.72,
                     7.46, 2.79, 4.09, 3.69, 6.66, 1.7,  6.6, 1.67, 6.21, 6.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 =
      new double[20]{4.2,  5.61, 1.34, 7.41, 4.9,  9.13, 5.2, 3.51, 2.85, 2.72,
                     7.46, 2.79, 4.09, 3.69, 6.66, 1.7,  6.6, 1.67, 6.21, 6.09};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck47) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{3.34, 7.89, 8.66, 8.87, 3.51, 5.89, 9.3,  1.16,
                                9.63, 5.61, 9.73, 4.18, 8.94, 2.1,  1.38, 4.43,
                                4.35, 3.3,  1.17, 3.48, 6.15, 7.69, 2.21, 5.79,
                                7.4,  6.06, 2.08, 6.77, 3.5,  3.88};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 7);
  double *arr2 = new double[42]{7.05, 8.95, 8.98, 4.46, 1.2,  1.83, 1.02, 1.92,
                                7.57, 5.06, 9.45, 1.45, 3.45, 7.75, 8.65, 8.12,
                                8.69, 9.13, 5.52, 3.44, 5.01, 3.77, 8.39, 4.99,
                                3.12, 2.8,  9.27, 9.21, 4.5,  1.37, 7.6,  7.7};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck48) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{3.92, 9.37, 8.72, 7.54, 4.15, 3.14, 3.37, 9.06,
                                7.02, 5.06, 1.95, 9.32, 6.13, 2.12, 2.17, 6.05,
                                6.63, 1.39, 6.93, 7.54, 8.12, 4.85, 4.44, 7.47};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{3.92, 9.37, 8.72, 7.54, 4.15, 3.14, 3.37, 9.06,
                                7.02, 5.06, 1.95, 9.32, 6.13, 2.12, 2.17, 6.05,
                                6.63, 1.39, 6.93, 7.54, 8.12, 4.85, 4.44, 7.47};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck49) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{3.06, 2.41, 5.49, 9.65};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{3.06, 2.41, 5.49, 9.65};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck50) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{1.95, 5.59, 1.92, 5.96, 5.76, 5.96, 2.04, 1.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{3.25, 4.01, 2.0, 5.26, 8.54, 4.58, 6.79, 2.18};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck51) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 4);
  double *arr1 =
      new double[20]{7.25, 5.75, 1.61, 2.06, 7.64, 2.81, 8.37, 1.0,  9.35, 1.52,
                     5.42, 3.82, 9.64, 1.91, 9.26, 7.43, 9.9,  8.32, 3.52, 8.7};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 =
      new double[20]{7.25, 5.75, 1.61, 2.06, 7.64, 2.81, 8.37, 1.0,  9.35, 1.52,
                     5.42, 3.82, 9.64, 1.91, 9.26, 7.43, 9.9,  8.32, 3.52, 8.7};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck52) {
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{3.39, 8.78, 7.65, 8.86, 1.39, 6.01, 3.17, 8.67,
                                4.41, 4.54, 9.3,  6.88, 4.31, 5.75, 1.65};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 =
      new double[24]{5.3,  4.26, 7.22, 3.32, 3.23, 3.01, 5.46, 9.7, 2.79,
                     2.43, 6.3,  9.8,  4.61, 2.99, 4.89, 1.49, 2.98};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck53) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{7.25, 7.41, 7.22, 8.41, 5.76, 8.5,  3.49, 4.08,
                                5.46, 9.13, 6.06, 6.12, 8.7,  6.93, 2.32, 6.51};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{7.25, 7.41, 7.22, 8.41, 5.76, 8.5,  3.49, 4.08,
                                5.46, 9.13, 6.06, 6.12, 8.7,  6.93, 2.32, 6.51};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck54) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{7.67, 4.46, 6.19, 6.38, 7.02, 7.14,
                                4.51, 9.9,  3.48, 9.86, 2.15, 2.84};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{5.43, 9.73, 1.44, 5.98, 3.39, 9.74, 4.81,
                                1.52, 3.74, 2.61, 7.01, 4.12, 5.26, 1.98};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck55) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{5.74, 7.53, 5.77, 8.93, 1.65, 6.32, 4.39, 8.97,
                                9.14, 4.28, 3.2,  6.78, 9.1,  3.76, 8.71, 4.86,
                                1.94, 5.48, 4.46, 5.97, 6.05, 7.28, 6.42, 4.09,
                                7.74, 2.23, 9.5,  1.94, 7.72, 9.53};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 7);
  double *arr2 = new double[42]{3.84, 5.77, 5.16, 8.43, 1.37, 5.98, 7.78, 9.64,
                                6.47, 5.02, 4.3,  7.24, 7.77, 7.56, 8.1,  9.45,
                                3.0,  3.58, 9.94, 5.24, 8.3,  3.13, 7.51, 2.54,
                                6.45, 9.52, 5.59, 6.12, 9.15, 9.87, 7.93, 1.02};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck56) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{7.66, 5.08, 4.65, 8.35, 3.07, 7.84, 9.76, 1.35,
                                6.45, 6.35, 1.64, 1.49, 2.81, 1.19, 4.93, 9.15,
                                4.11, 6.72, 3.21, 4.89, 9.51, 8.88, 6.9,  4.76};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{7.66, 5.08, 4.65, 8.35, 3.07, 7.84, 9.76, 1.35,
                                6.45, 6.35, 1.64, 1.49, 2.81, 1.19, 4.93, 9.15,
                                4.11, 6.72, 3.21, 4.89, 9.51, 8.88, 6.9,  4.76};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck57) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      9.46, 8.94, 5.28, 4.19, 9.2,  5.08, 7.92, 2.23, 2.41, 6.12, 4.08, 1.68,
      6.13, 1.28, 7.62, 1.61, 8.87, 9.15, 6.42, 7.69, 7.56, 4.16, 7.25, 9.47,
      5.03, 9.88, 3.26, 6.33, 2.82, 7.9,  5.45, 6.53, 5.07, 8.62, 2.62, 2.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 7);
  double *arr2 =
      new double[49]{9.71, 8.97, 3.05, 5.89, 7.03, 5.22, 3.84, 2.76, 5.12, 3.91,
                     7.39, 5.03, 3.88, 6.53, 5.83, 4.16, 8.73, 8.08, 6.94, 2.82,
                     1.83, 7.65, 2.98, 1.35, 8.75, 9.13, 8.04, 3.91, 6.28, 5.71,
                     5.2,  8.76, 7.6,  4.24, 5.09, 5.03, 3.26, 3.92};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck58) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{8.78, 8.11, 5.24, 7.03, 5.43, 7.59};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{8.78, 8.11, 5.24, 7.03, 5.43, 7.59};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck59) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{1.96, 6.33, 4.56, 8.73, 5.51, 4.39, 7.43, 5.4,
                                2.64, 6.85, 8.13, 8.37, 6.15, 2.51, 2.89, 2.78,
                                4.02, 2.97, 7.07, 5.1,  4.45, 7.11, 7.57, 1.59,
                                9.95, 8.98, 8.09, 1.98, 2.53, 5.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 6);
  double *arr2 = new double[42]{4.99, 6.6,  7.29, 2.59, 7.35, 2.61, 4.9,  1.76,
                                7.32, 6.94, 2.53, 3.45, 7.49, 6.85, 9.25, 8.33,
                                5.83, 9.81, 7.55, 2.27, 3.15, 6.75, 3.72, 8.81,
                                9.04, 6.63, 5.96, 2.06, 5.14, 4.29, 4.35, 6.49};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck60) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 3);
  double *arr1 =
      new double[18]{2.07, 8.16, 4.91, 7.36, 5.3,  8.5,  8.64, 4.38, 6.19,
                     8.81, 9.34, 2.82, 3.73, 3.29, 7.25, 1.58, 2.73, 8.92};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 3);
  double *arr2 =
      new double[18]{2.07, 8.16, 4.91, 7.36, 5.3,  8.5,  8.64, 4.38, 6.19,
                     8.81, 9.34, 2.82, 3.73, 3.29, 7.25, 1.58, 2.73, 8.92};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck61) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 3);
  double *arr1 =
      new double[9]{7.85, 4.93, 3.21, 6.14, 3.37, 4.71, 7.99, 6.1, 3.26};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 3);
  double *arr2 =
      new double[9]{7.85, 4.93, 3.21, 6.14, 3.37, 4.71, 7.99, 6.1, 3.26};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck62) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{3.14, 4.35, 8.14, 7.18, 5.55, 8.19,
                                3.53, 8.8,  3.25, 4.39, 3.81, 5.44};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{3.14, 4.35, 8.14, 7.18, 5.55, 8.19,
                                3.53, 8.8,  3.25, 4.39, 3.81, 5.44};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck63) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{7.03, 9.63, 5.03, 4.98, 9.53, 9.13, 8.96, 6.73,
                                4.77, 3.14, 8.06, 8.74, 3.73, 9.63, 3.5,  4.15,
                                9.72, 9.41, 7.66, 7.91, 8.6,  3.95, 3.57, 3.04,
                                5.07, 5.92, 2.02, 2.48, 5.08, 2.26};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{1.81, 6.43, 5.01, 2.69, 2.07, 1.61, 8.17, 1.06,
                                5.4,  7.62, 6.51, 8.71, 3.34, 7.33, 7.63, 5.55,
                                1.5,  9.56, 4.85, 5.09, 1.2,  1.63, 9.82, 5.17,
                                3.37, 7.55, 8.35, 6.84, 8.5,  8.11};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck64) {
  S21Matrix matrix1(3, 2);
  double *arr1 = new double[6]{5.85, 5.64, 4.32, 8.37, 5.03, 5.92};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 2);
  double *arr2 = new double[6]{8.04, 3.53, 1.84, 1.21, 6.63, 3.47};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck65) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{1.17, 8.45, 6.23, 4.75, 1.49, 9.93, 1.53, 4.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{1.17, 8.45, 6.23, 4.75, 1.49, 9.93, 1.53, 4.9};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck66) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{1.06, 4.72, 3.64, 4.1,  2.99, 9.18, 1.72,
                                1.41, 6.61, 6.36, 8.58, 3.54, 1.3,  5.01,
                                7.88, 1.37, 4.74, 7.65, 5.41, 3.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 =
      new double[20]{5.62, 3.84, 9.29, 5.89, 5.53, 9.81, 8.82, 1.11, 3.98, 6.57,
                     7.02, 6.36, 1.72, 1.4,  8.9,  4.65, 2.79, 8.12, 3.64, 3.7};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck67) {
  S21Matrix matrix1(3, 4);
  double *arr1 = new double[12]{9.75, 9.21, 6.56, 9.91, 1.53, 1.95,
                                3.89, 9.69, 8.32, 7.94, 3.02, 6.63};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 4);
  double *arr2 = new double[12]{5.98, 8.76, 4.87, 5.68, 5.22, 7.29,
                                6.83, 3.76, 1.76, 3.78, 6.41, 8.22};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck68) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{3.27, 6.13, 3.43, 4.15, 6.17, 5.23,
                                1.37, 6.87, 6.3,  1.72, 9.75, 4.07};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{3.27, 6.13, 3.43, 4.15, 6.17, 5.23,
                                1.37, 6.87, 6.3,  1.72, 9.75, 4.07};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck69) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 6);
  double *arr1 = new double[24]{9.85, 9.35, 1.78, 8.2,  7.4,  8.76, 8.81, 7.29,
                                2.86, 8.81, 4.31, 7.57, 9.96, 4.57, 4.56, 1.79,
                                2.4,  6.02, 5.55, 8.52, 1.96, 8.68, 3.85, 2.97};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 6);
  double *arr2 = new double[24]{9.85, 9.35, 1.78, 8.2,  7.4,  8.76, 8.81, 7.29,
                                2.86, 8.81, 4.31, 7.57, 9.96, 4.57, 4.56, 1.79,
                                2.4,  6.02, 5.55, 8.52, 1.96, 8.68, 3.85, 2.97};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck70) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 2);
  double *arr1 = new double[4]{6.76, 4.26, 1.13, 9.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 2);
  double *arr2 = new double[4]{6.76, 4.26, 1.13, 9.78};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck71) {
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{3.09, 4.44, 9.33, 8.72, 7.44, 9.75, 6.54, 6.24, 9.79, 6.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{4.64, 9.78, 1.83, 9.78, 5.69, 9.94, 7.6, 2.25, 3.65, 8.97};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck72) {
  S21Matrix matrix1(5, 5);
  double *arr1 =
      new double[25]{5.68, 6.57, 6.24, 5.2,  8.13, 8.78, 5.31, 5.48, 4.44,
                     4.65, 8.3,  2.91, 8.7,  4.41, 1.62, 6.7,  1.22, 3.03,
                     5.81, 3.57, 5.02, 9.37, 9.18, 6.85, 1.34};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 =
      new double[36]{8.05, 4.79, 2.18, 1.79, 6.49, 6.3,  1.68, 8.04, 4.11,
                     9.44, 2.67, 9.93, 5.04, 7.38, 9.72, 2.42, 9.78, 2.44,
                     1.16, 9.85, 5.19, 3.39, 9.85, 3.56, 6.58, 8.59, 3.4};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck73) {
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{4.2, 3.09, 9.68, 8.18, 6.82, 7.89};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{2.97, 9.44, 7.74, 1.62, 9.84, 8.16};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck74) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 5);
  double *arr1 = new double[20]{7.81, 1.69, 7.62, 4.56, 9.78, 5.52, 8.03,
                                2.54, 6.22, 3.14, 9.37, 1.99, 6.28, 5.19,
                                9.27, 7.46, 1.39, 2.77, 4.25, 3.37};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 5);
  double *arr2 = new double[20]{7.81, 1.69, 7.62, 4.56, 9.78, 5.52, 8.03,
                                2.54, 6.22, 3.14, 9.37, 1.99, 6.28, 5.19,
                                9.27, 7.46, 1.39, 2.77, 4.25, 3.37};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck75) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      2.67, 8.98, 8.82, 9.26, 2.72, 3.89, 8.57, 3.22, 9.61, 4.14, 3.89, 8.79,
      1.37, 7.48, 2.85, 9.72, 2.9,  9.27, 4.88, 3.54, 9.86, 6.32, 8.01, 1.68,
      9.05, 9.46, 7.31, 9.24, 4.34, 8.61, 9.38, 5.39, 4.36, 5.46, 4.97, 2.78};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      2.67, 8.98, 8.82, 9.26, 2.72, 3.89, 8.57, 3.22, 9.61, 4.14, 3.89, 8.79,
      1.37, 7.48, 2.85, 9.72, 2.9,  9.27, 4.88, 3.54, 9.86, 6.32, 8.01, 1.68,
      9.05, 9.46, 7.31, 9.24, 4.34, 8.61, 9.38, 5.39, 4.36, 5.46, 4.97, 2.78};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck76) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 6);
  double *arr1 =
      new double[18]{4.92, 8.97, 2.8,  3.22, 4.82, 8.44, 7.04, 7.73, 9.11,
                     6.12, 3.59, 9.63, 7.01, 3.86, 2.11, 7.83, 9.23, 7.83};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 6);
  double *arr2 =
      new double[18]{4.92, 8.97, 2.8,  3.22, 4.82, 8.44, 7.04, 7.73, 9.11,
                     6.12, 3.59, 9.63, 7.01, 3.86, 2.11, 7.83, 9.23, 7.83};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck77) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{8.57, 1.16, 9.79, 9.49, 9.53, 6.57, 3.5,  3.54,
                                5.49, 3.89, 1.96, 4.59, 4.29, 4.52, 8.18, 6.68,
                                8.92, 4.58, 1.61, 1.98, 2.15, 3.54, 2.03, 5.66,
                                8.15, 4.91, 1.34, 3.79, 8.3,  8.63};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{8.57, 1.16, 9.79, 9.49, 9.53, 6.57, 3.5,  3.54,
                                5.49, 3.89, 1.96, 4.59, 4.29, 4.52, 8.18, 6.68,
                                8.92, 4.58, 1.61, 1.98, 2.15, 3.54, 2.03, 5.66,
                                8.15, 4.91, 1.34, 3.79, 8.3,  8.63};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck78) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{3.28, 7.34, 5.74, 3.82, 6.33, 7.69, 5.08, 4.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{3.28, 7.34, 5.74, 3.82, 6.33, 7.69, 5.08, 4.09};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck79) {
  S21Matrix matrix1(6, 5);
  double *arr1 = new double[30]{2.26, 7.36, 7.16, 9.05, 4.99, 7.97, 9.47, 9.69,
                                1.18, 5.37, 9.61, 9.86, 5.46, 6.8,  7.54, 2.78,
                                7.23, 5.9,  7.58, 9.54, 3.06, 5.22, 6.32, 7.82,
                                4.14, 5.91, 3.52, 7.26, 9.06, 4.81};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 5);
  double *arr2 = new double[30]{7.56, 9.54, 6.81, 9.68, 7.31, 6.81, 2.05, 3.26,
                                5.48, 8.76, 4.01, 1.41, 2.6,  7.34, 1.38, 1.52,
                                4.33, 6.31, 3.89, 1.06, 6.99, 1.84, 5.55, 6.5,
                                2.21, 9.78, 3.52, 6.7,  9.89, 4.26};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck80) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(2, 3);
  double *arr1 = new double[6]{9.54, 4.07, 3.05, 6.1, 9.28, 8.33};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 3);
  double *arr2 = new double[6]{9.54, 4.07, 3.05, 6.1, 9.28, 8.33};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck81) {
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      1.01, 4.35, 1.08, 8.54, 3.9,  1.37, 3.41, 2.81, 9.15, 1.51, 3.72, 8.85,
      4.72, 1.74, 4.13, 9.67, 4.56, 4.57, 3.56, 5.48, 5.21, 2.58, 4.49, 9.53,
      6.51, 7.64, 5.54, 2.02, 1.1,  2.48, 3.66, 2.28, 1.45, 8.79, 9.83, 8.09};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(7, 7);
  double *arr2 =
      new double[49]{1.99, 4.24, 7.27, 5.53, 9.5,  8.22, 6.31, 7.51, 4.64, 2.1,
                     8.61, 2.02, 1.19, 8.26, 8.97, 2.58, 9.62, 2.05, 8.42, 6.38,
                     7.76, 9.34, 3.74, 4.28, 4.8,  7.89, 4.2,  5.92, 4.78, 7.69,
                     6.12, 9.03, 6.99, 2.1,  5.21, 9.1,  5.96, 6.75};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck82) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(3, 5);
  double *arr1 = new double[15]{1.9,  8.43, 3.73, 2.04, 9.12, 9.81, 2.99, 5.88,
                                3.35, 1.52, 3.93, 4.56, 5.47, 7.26, 7.86};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 = new double[15]{1.9,  8.43, 3.73, 2.04, 9.12, 9.81, 2.99, 5.88,
                                3.35, 1.52, 3.93, 4.56, 5.47, 7.26, 7.86};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck83) {
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{5.27, 1.4, 5.64, 2.06, 9.22, 7.59, 5.23, 4.84};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{1.23, 9.68, 1.87, 2.67, 1.56, 2.53, 6.69, 7.06};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck84) {
  S21Matrix matrix1(5, 4);
  double *arr1 = new double[20]{5.84, 8.26, 2.28, 6.64, 2.51, 7.82, 5.52,
                                2.83, 7.35, 7.09, 5.06, 9.92, 4.38, 4.62,
                                1.21, 7.85, 7.8,  9.59, 4.89, 1.93};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{9.7,  3.4,  5.93, 2.9,  8.37, 7.17, 1.84,
                                2.09, 1.55, 2.24, 6.78, 9.88, 5.89, 4.36,
                                7.38, 5.0,  2.99, 6.93, 1.1,  3.08};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck85) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 2);
  double *arr1 = new double[12]{3.02, 6.4,  2.08, 8.81, 1.12, 3.34,
                                6.64, 4.14, 7.37, 7.84, 1.2,  3.55};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 2);
  double *arr2 = new double[12]{3.02, 6.4,  2.08, 8.81, 1.12, 3.34,
                                6.64, 4.14, 7.37, 7.84, 1.2,  3.55};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck86) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{4.85, 3.52, 6.06, 7.24, 8.48, 5.73, 6.34, 4.14,
                                1.05, 6.58, 6.92, 7.99, 7.51, 2.21, 5.8,  8.25,
                                8.08, 7.07, 3.58, 8.1,  6.0,  4.01, 6.17, 1.99,
                                8.32, 7.51, 5.24, 2.04, 1.37, 9.37};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{4.85, 3.52, 6.06, 7.24, 8.48, 5.73, 6.34, 4.14,
                                1.05, 6.58, 6.92, 7.99, 7.51, 2.21, 5.8,  8.25,
                                8.08, 7.07, 3.58, 8.1,  6.0,  4.01, 6.17, 1.99,
                                8.32, 7.51, 5.24, 2.04, 1.37, 9.37};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck87) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{5.17, 6.99, 2.18, 8.15, 2.23, 2.9, 5.01, 4.18};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(3, 5);
  double *arr2 =
      new double[15]{7.3, 5.74, 4.9, 4.79, 3.79, 5.11, 9.68, 9.08, 2.25, 1.95};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck88) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 2);
  double *arr1 = new double[8]{2.37, 8.47, 1.18, 2.86, 9.84, 8.45, 4.34, 5.72};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 2);
  double *arr2 = new double[8]{2.37, 8.47, 1.18, 2.86, 9.84, 8.45, 4.34, 5.72};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck89) {
  S21Matrix matrix1(2, 5);
  double *arr1 =
      new double[10]{1.04, 7.74, 4.93, 6.04, 2.7, 9.25, 2.25, 7.34, 6.23, 2.9};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 5);
  double *arr2 =
      new double[10]{7.67, 7.1, 9.05, 4.09, 6.67, 6.09, 5.67, 4.36, 7.14, 4.19};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck90) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 3);
  double *arr1 = new double[15]{1.25, 3.3,  7.37, 7.01, 9.61, 1.07, 4.65, 3.87,
                                2.33, 3.23, 2.7,  1.18, 8.7,  4.22, 6.5};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 3);
  double *arr2 = new double[15]{1.25, 3.3,  7.37, 7.01, 9.61, 1.07, 4.65, 3.87,
                                2.33, 3.23, 2.7,  1.18, 8.7,  4.22, 6.5};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck91) {
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{4.25, 6.66, 4.96, 8.86, 2.6,  1.6,  3.8,  5.34,
                                6.61, 2.53, 7.88, 6.79, 8.92, 7.86, 6.88, 7.73,
                                1.46, 2.81, 9.53, 3.14, 6.07, 2.04, 9.69, 9.85};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{2.04, 4.57, 2.09, 2.97, 9.29, 1.02, 8.87, 8.63,
                                3.53, 6.83, 3.77, 1.7,  3.72, 7.96, 8.93, 3.07,
                                9.66, 8.12, 3.25, 5.83, 3.46, 1.1,  6.38, 1.24};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck92) {
  S21Matrix matrix1(4, 4);
  double *arr1 = new double[16]{1.19, 5.27, 2.69, 2.79, 9.81, 1.31, 2.32, 2.15,
                                6.38, 1.62, 4.21, 1.1,  1.01, 6.64, 8.96, 8.53};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 4);
  double *arr2 = new double[16]{8.25, 8.85, 7.5,  7.4,  2.12, 1.12, 5.18, 4.88,
                                3.68, 1.02, 8.53, 3.91, 6.69, 1.4,  4.03, 4.49};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck93) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 6);
  double *arr1 = new double[36]{
      3.92, 6.32, 7.55, 4.69, 4.96, 1.74, 2.06, 7.85, 8.28, 6.32, 2.11, 2.58,
      5.63, 2.04, 3.31, 6.82, 7.97, 6.82, 4.62, 2.89, 9.05, 4.66, 6.73, 5.06,
      1.16, 7.0,  6.38, 7.94, 3.74, 3.94, 7.15, 9.43, 7.5,  3.15, 3.36, 8.29};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 6);
  double *arr2 = new double[36]{
      3.92, 6.32, 7.55, 4.69, 4.96, 1.74, 2.06, 7.85, 8.28, 6.32, 2.11, 2.58,
      5.63, 2.04, 3.31, 6.82, 7.97, 6.82, 4.62, 2.89, 9.05, 4.66, 6.73, 5.06,
      1.16, 7.0,  6.38, 7.94, 3.74, 3.94, 7.15, 9.43, 7.5,  3.15, 3.36, 8.29};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck94) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(6, 4);
  double *arr1 = new double[24]{5.17, 8.57, 4.37, 1.39, 5.57, 4.07, 7.09, 3.64,
                                1.89, 4.69, 6.63, 1.14, 3.79, 7.92, 2.67, 8.47,
                                2.68, 5.17, 2.53, 7.65, 7.83, 9.97, 2.96, 9.0};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 4);
  double *arr2 = new double[24]{5.17, 8.57, 4.37, 1.39, 5.57, 4.07, 7.09, 3.64,
                                1.89, 4.69, 6.63, 1.14, 3.79, 7.92, 2.67, 8.47,
                                2.68, 5.17, 2.53, 7.65, 7.83, 9.97, 2.96, 9.0};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck95) {
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{3.0,  8.01, 3.32, 2.36, 7.17, 3.93,
                                5.12, 3.27, 2.86, 5.17, 3.45, 7.17};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 4);
  double *arr2 = new double[20]{2.1,  6.69, 3.42, 2.28, 1.05, 9.9,  9.23,
                                8.29, 3.37, 3.88, 2.76, 2.28, 3.38, 8.24};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck96) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{6.27, 7.98, 9.08, 1.46, 7.62, 9.03, 4.9,  5.04,
                                9.48, 3.22, 9.76, 7.48, 6.78, 1.77, 6.68, 2.78,
                                6.97, 1.64, 9.66, 7.84, 3.51, 1.92, 3.96, 8.39,
                                4.56, 8.1,  7.57, 8.56, 7.7,  8.86};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 6);
  double *arr2 = new double[30]{6.27, 7.98, 9.08, 1.46, 7.62, 9.03, 4.9,  5.04,
                                9.48, 3.22, 9.76, 7.48, 6.78, 1.77, 6.68, 2.78,
                                6.97, 1.64, 9.66, 7.84, 3.51, 1.92, 3.96, 8.39,
                                4.56, 8.1,  7.57, 8.56, 7.7,  8.86};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck97) {
  S21Matrix matrix1(5, 6);
  double *arr1 = new double[30]{4.41, 9.13, 3.53, 2.62, 2.52, 2.02, 1.53, 7.65,
                                8.65, 3.26, 2.11, 7.82, 6.72, 9.0,  4.53, 3.7,
                                3.77, 1.55, 9.57, 8.28, 7.39, 7.57, 7.38, 8.73,
                                6.88, 9.21, 1.75, 2.95, 9.1,  5.06};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(6, 7);
  double *arr2 = new double[42]{4.35, 1.71, 6.87, 6.68, 1.99, 5.66, 7.52, 6.13,
                                6.98, 8.41, 7.21, 6.67, 6.26, 4.51, 8.5,  4.0,
                                7.66, 4.87, 1.54, 6.71, 5.89, 3.77, 7.54, 9.33,
                                1.56, 8.36, 8.33, 3.53, 8.64, 8.13, 1.29, 5.41};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck98) {
  S21Matrix matrix1(2, 4);
  double *arr1 = new double[8]{3.94, 4.56, 8.91, 2.24, 2.53, 4.65, 7.82, 2.39};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(2, 4);
  double *arr2 = new double[8]{2.58, 2.73, 3.46, 6.02, 5.59, 5.43, 8.59, 1.29};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck99) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(5, 2);
  double *arr1 =
      new double[10]{2.28, 6.5, 7.82, 5.97, 9.7, 7.27, 3.32, 7.62, 7.32, 6.11};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(5, 2);
  double *arr2 =
      new double[10]{2.28, 6.5, 7.82, 5.97, 9.7, 7.27, 3.32, 7.62, 7.32, 6.11};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(MatrixEqualityTest, EqualityCheck100) {
  // Создаем две матрицы с одинаковыми значениями
  S21Matrix matrix1(4, 3);
  double *arr1 = new double[12]{8.66, 8.39, 6.76, 2.91, 3.66, 9.15,
                                1.49, 3.26, 1.83, 6.35, 7.11, 5.25};
  matrix1.fillMatrixFromArray(arr1);

  S21Matrix matrix2(4, 3);
  double *arr2 = new double[12]{8.66, 8.39, 6.76, 2.91, 3.66, 9.15,
                                1.49, 3.26, 1.83, 6.35, 7.11, 5.25};
  matrix2.fillMatrixFromArray(arr2);
  delete[] arr1;
  delete[] arr2;

  ASSERT_TRUE(matrix1 == matrix2);
}
