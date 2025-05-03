#include "determinant.h"

#include <mutex>
#include <thread>

long double calculateDeterminant(Matrix const& matrix, bool top_level) {
    std::vector<std::thread> threads;
    std::mutex det_mutex;
    long double det = 0;
    if (matrix.getDim() == 1) {
        return matrix.getData()[0][0].data;
    }
    if (matrix.getDim() == 2) {
        return matrix.getData()[0][0].data * matrix.getData()[1][1].data -
               matrix.getData()[0][1].data * matrix.getData()[1][0].data;
    }
    for (size_t column = 0; column < matrix.getDim(); column++) {
        if (top_level) {
            threads.emplace_back([&, column]() {
                long double term = (column % 2 == 0 ? 1 : -1) * matrix.getData()[0][column].data *
                                   calculateDeterminantNonParallel(matrix.strip(column, 0));
                std::lock_guard<std::mutex> lock(det_mutex);
                // false sharing
                det += term;
            });
        } else {
            det += (column % 2 == 0 ? 1 : -1) * matrix.getData()[0][column].data *
                   calculateDeterminantNonParallel(matrix.strip(column, 0));
        }
    }
    if (top_level) {
        for (auto& thread : threads) {
            thread.join();
        }
    }
    return det;
}

long double calculateDeterminantNonParallel(Matrix const& matrix) {
    long double det = 0;
    if (matrix.getDim() == 1) {
        return matrix.getData()[0][0].data;
    }
    if (matrix.getDim() == 2) {
        return matrix.getData()[0][0].data * matrix.getData()[1][1].data -
               matrix.getData()[0][1].data * matrix.getData()[1][0].data;
    }
    for (size_t column = 0; column < matrix.getDim(); column++) {
        det += (column % 2 == 0 ? 1 : -1) * matrix.getData()[0][column].data *
               calculateDeterminantNonParallel(matrix.strip(column, 0));
    }
    return det;
}