#include "matrix.h"

// initialize dim in member initializer list
Matrix::Matrix(std::vector<std::vector<AlignedDouble>> matrixData)
    : dim(matrixData.size()), matrixData_(std::move(matrixData)) {}

Matrix::Matrix(std::ifstream& inputFile) {
    std::vector<std::vector<AlignedDouble>> input_vector;
    std::string row;
    while (std::getline(inputFile, row)) {
        std::vector<AlignedDouble> row_vector;
        std::istringstream iss(row);
        double value;
        while (iss >> value) {
            row_vector.push_back(AlignedDouble{value});
        }
        input_vector.push_back(row_vector);
    }
    matrixData_ = std::move(input_vector);
    dim = matrixData_.size();
}

Matrix::Matrix(Matrix&& other) noexcept : dim(other.dim) {
    matrixData_ = std::move(other.matrixData_);
    other.dim = 0;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        this->matrixData_ = std::move(other.matrixData_);
        this->dim = other.dim;
        other.dim = 0;
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        this->matrixData_ = other.matrixData_;
        this->dim = other.dim;
    }
    return *this;
}

Matrix Matrix::Strip(size_t column, size_t row) const {
    std::vector<std::vector<AlignedDouble>> stripped_vector;
    for (size_t i = 0; i < dim; i++) {
        if (i == row) {
            continue;
        }
        std::vector<AlignedDouble> row;
        for (size_t j = 0; j < dim; j++) {
            if (j == column) {
                continue;
            }
            row.push_back(matrixData_[i][j]);
        }
        stripped_vector.push_back(std::move(row));
    }
    return Matrix(std::move(stripped_vector));
}

void Matrix::Print() const {
    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            std::cout << matrixData_[i][j].data << ' ';
        }
        std::cout << '\n';
    }
}
