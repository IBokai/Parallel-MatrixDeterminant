#include <chrono>
#include <fstream>

#include "determinant/determinant.h"
#include "matrix/matrix.h"

int main(int argc, char* argv[]) {
    std::ifstream file("../matrices/matrix8.txt");
    Matrix matrix = Matrix(file);
    long double result = 0;
    if (argc == 1) {
        std::cout << "Executing non-parallel version\n";
        auto before = std::chrono::system_clock::now();
        result = CalculateDeterminantNonParallel(std::move(matrix));
        auto after = std::chrono::system_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
        std::cout << "Executing time (microseconds): " << time.count() << '\n';
    } else if (argc == 2) {
        std::string argument = argv[1];
        if (argument == "parallel") {
            std::cout << "Executing parallel version\n";
            // measure time here using std::system_clock::now()
            auto before = std::chrono::system_clock::now();
            result = CalculateDeterminant(std::move(matrix));
            auto after = std::chrono::system_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
            std::cout << "Executing time (microseconds): " << time.count() << '\n';
        } else {
            std::cout << "Wrong arguments\n";
            return -1;
        }
    } else {
        std::cout << "Wrong arguments\n";
        return -1;
    }
    std::cout << result << '\n';
    return 0;
}