#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    private:
        int rows, cols;
        float **p;

        void allocSpace();
    public:
        Matrix();
        Matrix(int x, int y);
        Matrix(const Matrix& m);
        Matrix& operator=(const Matrix& m);
        ~Matrix();

        inline float& operator()(int x, int y) { return this->p[x][y]; }

        Matrix& operator*(const Matrix& m);
        Matrix& operator*=(const Matrix& m);

        void swapRows(int r1, int r2);
        static Matrix createIdentity(int size);
        static Matrix augment(Matrix, Matrix);
        Matrix gaussianEliminate();
        Matrix rowReduceFromGaussian();
        Matrix inverse();
};

#endif
