#include "s21_matrix_oop.h"

//----------Конструкторы----------//

S21Matrix::S21Matrix() : S21Matrix(0, 0) {}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  createEmptyMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  createEmptyMatrix();
  copyMatrix(other.matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = nullptr;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

//----------Деструкторы----------//

S21Matrix::~S21Matrix() { releaseMatrixMemory(); }

//----------Геттеры----------//

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

//----------Сеттеры----------//

void S21Matrix::setCols(int newCols) {
  if (newCols >= 0) {
    int min_val = 0;
    if (cols_ > newCols)
      min_val = newCols;
    else
      min_val = cols_;

    double** newMatrix = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      newMatrix[i] = new double[newCols]{};
      for (int j = 0; j < min_val; j++) {
        newMatrix[i][j] = matrix_[i][j];
      }
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = newMatrix;

    for (int i = 0; i < rows_; i++) {
      for (int j = cols_; j < newCols; j++) {
        matrix_[i][j] = 0.0;
      }
    }
    cols_ = newCols;
  }
}

void S21Matrix::setRows(int newRows) {
  if (newRows >= 0) {
    if (newRows > rows_) {
      double** newMatrix = new double*[newRows];
      for (int i = 0; i < rows_; i++) {
        newMatrix[i] = matrix_[i];
      }
      for (int i = rows_; i < newRows; i++) {
        newMatrix[i] = new double[cols_]{};
      }

      delete[] matrix_;

      matrix_ = newMatrix;
    } else if (newRows < rows_) {
      for (int i = newRows; i < rows_; i++) {
        delete[] matrix_[i];
      }
    }
    rows_ = newRows;
  }
}

/**
 * Creates an empty matrix with the specified number of rows and columns.
 *
 * @throws None
 */
void S21Matrix::createEmptyMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{};
  }
}

/**
 * Releases memory allocated for the matrix.
 */
void S21Matrix::releaseMatrixMemory() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

/**
 * Copies a 2D matrix from a source array to the matrix object.
 *
 * @param source The 2D array to copy data from.
 *
 * @return void
 *
 * @throws None
 */
void S21Matrix::copyMatrix(const double* const* source) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = source[i][j];
    }
  }
}

/**
 * Check if the current S21Matrix object is equal to another S21Matrix object.
 *
 * @param other The S21Matrix object to compare against
 *
 * @return true if the matrices are equal, false otherwise
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool res = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    res = false;
  }

  if (res != false)
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
          res = false;
          break;
        }
      }
      if (res == false) break;
    }

  return res;
}

/**
 * Sums the elements of the current matrix with the corresponding elements of
 * another matrix. Throws an exception if the matrices have different
 * dimensions.
 *
 * @param other the matrix to be added to the current matrix
 *
 * @throws matrices have different dimensions
 */
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "Matrices have different dimensions for the operation");
  }

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
}

/**
 * Subtracts the elements of the given matrix from the elements of the current
 * matrix.
 *
 * @param other The matrix to subtract from the current matrix.
 *
 * @throws dimensions of the matrices are different.
 */
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "Matrices have different dimensions for the operation");
  }

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
}

/**
 * Multiplies each element of the matrix by a given number.
 *
 * @param num the number to multiply each element by
 *
 * @return void
 *
 * @throws None
 */
void S21Matrix::MulNumber(const double number) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = matrix_[i][j] * number;
}

/**
 * Multiplies this matrix with another matrix.
 *
 * @param other The matrix to multiply with.
 *
 * @throws number of columns in this matrix is not equal to the number of rows
 * in the other matrix.
 */
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incompatible dimensions for matrix multiplication");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      double sum = 0.0;
      for (int k = 0; k < cols_; k++) {
        sum += matrix_[i][k] * other.matrix_[k][j];
      }
      result.matrix_[i][j] = sum;
    }
  }

  *this = std::move(result);
}

/**
 * Transposes the current matrix and returns the transposed matrix.
 *
 * @return The transposed matrix.
 *
 * @throws None
 */
S21Matrix S21Matrix::Transpose() {
  S21Matrix transposed_matrix(cols_, rows_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      transposed_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }
  return transposed_matrix;
}

/**
 * Removes a specified row and column from the matrix and returns a new matrix
 * with the removed elements.
 *
 * @param row The index of the row to be removed.
 * @param col The index of the column to be removed.
 *
 * @return A new matrix with the specified row and column removed.
 *
 * @throws If the matrix is too small to remove a row
 *         or column.
 */
S21Matrix S21Matrix::removeRowAndColumn(int row, int col) const {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int newRow = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == row) {
      continue;
    }
    int newCol = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == col) {
        continue;
      }
      minor.matrix_[newRow][newCol] = matrix_[i][j];
      ++newCol;
    }
    ++newRow;
  }
  return minor;
}

/**
 * Calculates the complements of the current S21Matrix object.
 *
 * @return S21Matrix with complements calculated
 *
 * @throws if the matrix is not square
 */
S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square");
  }

  S21Matrix calc_complements_matrix(rows_, cols_);

  if (rows_ == 1 && cols_ == 1) {
    calc_complements_matrix.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = removeRowAndColumn(i, j);
        double determinant = minor.Determinant();
        double complement = determinant * pow(-1, i + j);
        calc_complements_matrix.matrix_[i][j] = complement;
      }
    }
  }
  return calc_complements_matrix;
}

/**
 * Calculate the determinant of the square matrix.
 *
 * @return the determinant of the matrix
 *
 * @throws if the matrix is not square
 */
double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square");
  }

  S21Matrix copy(*this);
  double det = 1.0;

  eliminateZeros(copy);

  for (int i = 0; i < rows_; ++i) {
    det *= copy.matrix_[i][i];
  }

  return det;
}

/**
 * Eliminates zeros in the given S21Matrix by performing row reduction.
 *
 * @param copy The S21Matrix object to be modified.
 *
 * @return Returns false.
 *
 * @throws None.
 */
bool S21Matrix::eliminateZeros(S21Matrix& copy) const {
  for (int i = 0; i < rows_ - 1; ++i) {
    for (int j = i + 1; j < rows_; ++j) {
      eliminateZeroInRow(copy, i, j);
    }
  }

  return false;
}

/**
 * Eliminates zero in a specific row of the matrix by performing row operations.
 *
 * @param matrix The matrix on which the operation is performed.
 * @param row The row index of the matrix to be modified.
 * @param col The column index of the matrix to be used for elimination.
 *
 * @throws None
 */
void S21Matrix::eliminateZeroInRow(S21Matrix& matrix, int row, int col) const {
  double temp1, temp2;
  double* array = new double[matrix.cols_];
  if (matrix.matrix_[col][row] != 0) {
    temp1 = matrix.matrix_[row][row];
    temp2 = matrix.matrix_[col][row];
    for (int k = 0; k < matrix.cols_; ++k) {
      array[k] = matrix.matrix_[row][k] / temp1 * temp2;
    }
    for (int k = 0; k < matrix.cols_; ++k) {
      matrix.matrix_[col][k] -= array[k];
    }
  }
  delete[] array;
}

/**
 * Calculates the inverse matrix of the current S21Matrix object.
 *
 * @return The inverse matrix of the current S21Matrix object
 *
 * @throws std::invalid_argument if the determinant is equal to zero
 */
S21Matrix S21Matrix::InverseMatrix() const {
  double det = Determinant();
  if (abs(det) < EPS) {
    throw std::invalid_argument("Determinant is equal to zero");
  }
  S21Matrix calc_complements = CalcComplements();
  S21Matrix calc_complements_T = calc_complements.Transpose();
  calc_complements_T.MulNumber(1.0 / det);

  return calc_complements_T;
}

//-----Перегрузка опреаторов-----//

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result;
  result = *this;
  result.MulMatrix(other);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    releaseMatrixMemory();
    rows_ = other.rows_;
    cols_ = other.cols_;
    createEmptyMatrix();
    copyMatrix(other.matrix_);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Index out of bounds");
  }

  return matrix_[i][j];
}

/**
 * Fills the matrix with values from the given array for testing.
 *
 * @param array the array of values to fill the matrix with
 *
 * @throws None
 */
void S21Matrix::fillMatrixFromArray(double* array) {
  int index = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = array[index];
      index++;
    }
  }
}
