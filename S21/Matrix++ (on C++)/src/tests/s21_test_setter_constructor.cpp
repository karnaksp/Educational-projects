#include "s21_test.h"

TEST(MatrixSetterConstructorTest, SetterConstructor1) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor2) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor3) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor4) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor5) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor6) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor7) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor8) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor9) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(8);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 8);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor10) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor11) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor12) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(0);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 0);
}

TEST(MatrixSetterConstructorTest, SetterConstructor13) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor14) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor15) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor16) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(0);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 0);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor17) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor18) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor19) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor20) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor21) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor22) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor23) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(8);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 8);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor24) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor25) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor26) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor27) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor28) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor29) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor30) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor31) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor32) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor33) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor34) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor35) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor36) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(0);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 0);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor37) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor38) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor39) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor40) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor41) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor42) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor43) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(8);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 8);
}

TEST(MatrixSetterConstructorTest, SetterConstructor44) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor45) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor46) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor47) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor48) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor49) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor50) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor51) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor52) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor53) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor54) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor55) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor56) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(1);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 1);
}

TEST(MatrixSetterConstructorTest, SetterConstructor57) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor58) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor59) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor60) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor61) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor62) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor63) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(8);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 8);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor64) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(0);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 0);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor65) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor66) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor67) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor68) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(8);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 8);
}

TEST(MatrixSetterConstructorTest, SetterConstructor69) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor70) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(8);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 8);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor71) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor72) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor73) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor74) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor75) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor76) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor77) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor78) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor79) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor80) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor81) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor82) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor83) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor84) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor85) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(8);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 8);
}

TEST(MatrixSetterConstructorTest, SetterConstructor86) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor87) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(6);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 6);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor88) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor89) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor90) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor91) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(2);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 2);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(2);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 2);
}

TEST(MatrixSetterConstructorTest, SetterConstructor92) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor93) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor94) {
  // Создаем матрицу-источник
  S21Matrix matrix(5, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 5);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}

TEST(MatrixSetterConstructorTest, SetterConstructor95) {
  // Создаем матрицу-источник
  S21Matrix matrix(2, 4);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 2);

  matrix.setRows(1);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 1);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 4);

  matrix.setCols(3);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 3);
}

TEST(MatrixSetterConstructorTest, SetterConstructor96) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(7);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 7);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(6);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 6);
}

TEST(MatrixSetterConstructorTest, SetterConstructor97) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 5);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(3);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 3);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 5);

  matrix.setCols(5);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 5);
}

TEST(MatrixSetterConstructorTest, SetterConstructor98) {
  // Создаем матрицу-источник
  S21Matrix matrix(6, 2);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 6);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 2);

  matrix.setCols(0);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 0);
}

TEST(MatrixSetterConstructorTest, SetterConstructor99) {
  // Создаем матрицу-источник
  S21Matrix matrix(3, 6);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 3);

  matrix.setRows(4);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 4);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 6);

  matrix.setCols(7);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 7);
}

TEST(MatrixSetterConstructorTest, SetterConstructor100) {
  // Создаем матрицу-источник
  S21Matrix matrix(4, 3);

  int old_rows = matrix.getRows();
  ASSERT_TRUE(old_rows == 4);

  matrix.setRows(5);

  int new_rows = matrix.getRows();
  ASSERT_TRUE(new_rows == 5);

  int old_cols = matrix.getCols();
  ASSERT_TRUE(old_cols == 3);

  matrix.setCols(4);

  int new_cols = matrix.getCols();
  ASSERT_TRUE(new_cols == 4);
}
