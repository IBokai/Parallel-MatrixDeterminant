#include <chrono>
#include <fstream>

#include "determinant/determinant.h"
#include "matrix/matrix.h"

int main(int argc, char* argv[]) {
    long double result = 0;
    if (argc != 3) {
        std::cout << "Wrong arguments\n";
        return -1;
    } else if (std::string(argv[1]) == "parallel") {
        std::string filename = argv[2];
        std::string filepath = "../matrices/" + filename;
        std::ifstream file(filepath);
        if (!file) {
            std::cout << "Wrong file name\n";
            return -1;
        }
        std::cout << "Executing parallel version\n";
        // measure time here using std::system_clock::now()
        auto before = std::chrono::system_clock::now();
        result = CalculateDeterminant(Matrix(file));
        auto after = std::chrono::system_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
        std::cout << "Executing time (microseconds): " << time.count() << '\n';
    } else if (std::string(argv[1]) == "non-parallel") {
        std::string filename = argv[2];
        std::string filepath = "../matrices/" + filename;
        std::ifstream file(filepath);
        if (!file) {
            std::cout << "Wrong file name\n";
            return -1;
        }
        std::cout << "Executing non-parallel version\n";
        auto before = std::chrono::system_clock::now();
        result = CalculateDeterminantNonParallel(Matrix(file));
        auto after = std::chrono::system_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
        std::cout << "Executing time (microseconds): " << time.count() << '\n';
    } else {
        std::cout << "Wrong arguments\n";
        return -1;
    }
    std::cout << "Determinant: " << result << '\n';
    return 0;
}