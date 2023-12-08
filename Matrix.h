#include <iostream>

class Matrix {
private:
    unsigned int row;
    unsigned int column;
    int** ptr; // Pointer to a 2D array

public:
    Matrix(unsigned int m, unsigned int n);
    Matrix(const Matrix& mat);
    Matrix(int** array, unsigned int m, unsigned int n);

    unsigned int rows() const;
    unsigned int columns() const;

    int get(unsigned i , unsigned j) const;
    void set(unsigned i , unsigned j , int value);

    Matrix operator+(const Matrix& mat);
    Matrix operator-(const Matrix& mat);
    Matrix operator*(const Matrix& mat);
    Matrix operator~();
    bool operator==(const Matrix& mat);
    std::string toStr();

    ~Matrix();
};

