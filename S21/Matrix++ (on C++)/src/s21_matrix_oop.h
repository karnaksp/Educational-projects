#include <cmath>
#include <iostream>
#define EPS 0.00001

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  //  ? accessors == геттеры
  int getRows() const;
  int getCols() const;

  // ? mutators == сеттеры
  void setRows(int newRows);
  void setCols(int newCols);

  // ? methods
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // ? перегрузка операторов
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  S21Matrix operator*(const S21Matrix& other) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double& operator()(int i, int j);

  // ? дополнительные функции
  void fillMatrixFromArray(double* mass);

 private:
  int rows_, cols_;
  double** matrix_;

  void createEmptyMatrix();
  void releaseMatrixMemory();
  void copyMatrix(const double* const* source);
  S21Matrix removeRowAndColumn(int row, int col) const;
  void eliminateZeroInRow(S21Matrix& matrix, int i, int j) const;
  bool eliminateZeros(S21Matrix& copy) const;
};
