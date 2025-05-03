#pragma once
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#define CACHE_LINE 64

// const methods

struct AlignedDouble {
    alignas(CACHE_LINE) double data;
};

class Matrix {
public:
    Matrix(std::vector<std::vector<AlignedDouble>> matrixData);
    Matrix(std::ifstream& inputFILE);
    // noexcept, read about exceptions safety and noexcept relation (the most prominent example is
    // vector push_back())
    Matrix(Matrix&& other) noexcept;
    // operator=(Matrix&&) is not generated automatically, because move constructor is defined
    // Matrix m1, m2;
    // m1 = std::move(m2); // this will silently copy
    // rule of 5, rule of 6; cppcoreguidelines

    Matrix(const Matrix& other) {
        this->matrixData_ = other.matrixData_;
        this->dim = other.dim;
    }
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    ~Matrix() = default;

    Matrix strip(size_t column, size_t row) const;
    void print() const;
    // should be constructor
    // const-ref return value
    std::vector<std::vector<AlignedDouble>> const& getData() const { return matrixData_; }
    size_t getDim() const { return dim; }

private:
    size_t dim;
    std::vector<std::vector<AlignedDouble>> matrixData_;
};