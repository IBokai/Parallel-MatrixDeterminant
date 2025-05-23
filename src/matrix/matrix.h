#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#define CACHE_LINE 64

// const methods

struct alignas(CACHE_LINE) AlignedDouble {
    double data;
};

class Matrix {
public:
    explicit Matrix(std::vector<std::vector<AlignedDouble>> matrixData);
    explicit Matrix(std::ifstream& inputFILE);
    // noexcept, read about exceptions safety and noexcept relation (the most prominent example is
    // vector push_back())

    // operator=(Matrix&&) is not generated automatically, because move constructor is defined
    // Matrix m1, m2;
    // m1 = std::move(m2); // this will silently copy
    // rule of 5, rule of 6; cppcoreguidelines
    Matrix(Matrix const& other) {
        this->matrixData_ = other.matrixData_;
        this->dim = other.dim;
    }
    Matrix& operator=(Matrix const& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(Matrix&& other) noexcept;
    ~Matrix() = default;

    [[nodiscard]] Matrix Strip(size_t column, size_t row) const;
    void Print() const;
    // should be constructor
    // const-ref return value
    std::vector<std::vector<AlignedDouble>> const& getData() const { return matrixData_; }
    size_t getDim() const { return dim; }

private:
    size_t dim;
    std::vector<std::vector<AlignedDouble>> matrixData_;
};