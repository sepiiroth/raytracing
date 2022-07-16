#include "../include/Matrix.h"
#include "HPoint.cpp"
#include "HVector.cpp"

#define EPS 1e-10


Matrix::Matrix() {
    this->rows = 4;
    this->cols = 4;
    allocSpace();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->p[i][j] = 0;
        }
    }
}

Matrix::Matrix(int x, int y) {
    this->rows = x;
    this->cols = y;
    allocSpace();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->p[i][j] = 0;
        }
    }
}
Matrix::Matrix(const Matrix& m) {
    this->rows = m.rows;
    this->cols = m.cols;
    allocSpace();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->p[i][j] = m.p[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] this->p[i];
    }
    delete[] this->p;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) {
        return *this;
    }

    if (rows != m.rows || cols != m.cols) {
        for (int i = 0; i < rows; ++i) {
            delete[] this->p[i];
        }
        delete[] this->p;

        rows = m.rows;
        cols = m.cols;
        allocSpace();
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*(const Matrix& m) {
    Matrix temp(rows, m.cols);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * m.p[k][j]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*=(const Matrix& m) {
    Matrix temp(rows, m.cols);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * m.p[k][j]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*(HPoint& point) {
    Matrix temp(rows, 4);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * point[k]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*=(HPoint& point) {
    Matrix temp(rows, 4);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * point[k]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*(HVector& v) {
    Matrix temp(rows, 4);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * v[k]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*=(HVector& v) {
    Matrix temp(rows, 4);
    for(int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                temp.p[i][j] += (this->p[i][k] * v[k]);
            }
        }
    }
    return (*this = temp);
}

void Matrix::swapRows(int r1, int r2) {
    float *temp = p[r1];
    p[r1] = p[r2];
    p[r2] = temp;
}

Matrix Matrix::createIdentity(int size) {
    Matrix temp(size, size);
    for (int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols; ++j) {
            if (i == j) {
                temp.p[i][j] = 1;
            } else {
                temp.p[i][j] = 0;
            }
        }
    }
    return temp;
}

Matrix Matrix::augment(Matrix A, Matrix B) {
    Matrix AB(A.rows, A.cols + B.cols);
    for (int i = 0; i < AB.rows; ++i) {
        for (int j = 0; j < AB.cols; ++j) {
            if (j < A.cols) {
                AB(i, j) = A(i, j);
            } else {
                AB(i, j) = B(i, j - B.cols);
            }
        }
    }
    return AB;
}

Matrix Matrix::gaussianEliminate() {
    Matrix Ab(*this);
    int rowsG = Ab.rows;
    int colsG = Ab.cols;
    int Acols = cols - 1;

    int i = 0; // row tracker
    int j = 0; // column tracker

    // iterate through the rows
    while (i < rowsG) {
        // find a pivot for the row
        bool pivot_found = false;
        while (j < Acols && !pivot_found) {
            if (Ab(i, j) != 0) { // pivot not equal to 0
                pivot_found = true;
            } else { // check for a possible swap
                int max_row = i;
                double max_val = 0;
                for (int k = i + 1; k < rowsG; ++k) {
                    double cur_abs = Ab(k, j) >= 0 ? Ab(k, j) : -1 * Ab(k, j);
                    if (cur_abs > max_val) {
                        max_row = k;
                        max_val = cur_abs;
                    }
                }
                if (max_row != i) {
                    Ab.swapRows(max_row, i);
                    pivot_found = true;
                } else {
                    j++;
                }
            }
        }

        // perform elimination as normal if pivot was found
        if (pivot_found) {
            for (int t = i + 1; t < rowsG; ++t) {
                for (int s = j + 1; s < colsG; ++s) {
                    Ab(t, s) = Ab(t, s) - Ab(i, s) * (Ab(t, j) / Ab(i, j));
                    if (Ab(t, s) < EPS && Ab(t, s) > -1*EPS)
                        Ab(t, s) = 0;
                }
                Ab(t, j) = 0;
            }
        }

        i++;
        j++;
    }

    return Ab;
}

Matrix Matrix::rowReduceFromGaussian() {
    Matrix R(*this);
    int rowsG = R.rows;
    int colsG = R.cols;

    int i = rowsG - 1; // row tracker
    int j = colsG - 2; // column tracker

    // iterate through every row
    while (i >= 0) {
        // find the pivot column
        int k = j - 1;
        while (k >= 0) {
            if (R(i, k) != 0)
                j = k;
            k--;
        }

        // zero out elements above pivots if pivot not 0
        if (R(i, j) != 0) {
            for (int t = i - 1; t >= 0; --t) {
                for (int s = 0; s < colsG; ++s) {
                    if (s != j) {
                        R(t, s) = R(t, s) - R(i, s) * (R(t, j) / R(i, j));
                        if (R(t, s) < EPS && R(t, s) > -1*EPS)
                            R(t, s) = 0;
                    }
                }
                R(t, j) = 0;
            }

            // divide row by pivot
            for (int k = j + 1; k < colsG; ++k) {
                R(i, k) = R(i, k) / R(i, j);
                if (R(i, k) < EPS && R(i, k) > -1*EPS)
                    R(i, k) = 0;
            }
            R(i, j) = 1;

        }

        i--;
        j--;
    }

    return R;
}

Matrix Matrix::inverse() {
    Matrix I = Matrix::createIdentity(this->rows);
    Matrix AI = Matrix::augment(*this, I);
    Matrix U = AI.gaussianEliminate();
    Matrix IAInverse = U.rowReduceFromGaussian();
    Matrix AInverse(this->rows, this->cols);
    for (int i = 0; i < AInverse.rows; ++i) {
        for (int j = 0; j < AInverse.cols; ++j) {
            AInverse(i, j) = IAInverse(i, j + cols);
        }
    }
    return AInverse;
}

void Matrix::allocSpace() {
    this->p = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        this->p[i] = new float[cols];
    }
}
