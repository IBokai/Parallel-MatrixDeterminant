#include <gtest/gtest.h>

#include "../src/determinant/determinant.h"

TEST(DeterminantTest, 1x1MatrixTest) {
    std::ifstream file("../matrices/matrix1.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 3);
}

TEST(DeterminantTest, 2x2MatrixTest) {
    std::ifstream file("../matrices/matrix2.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 10);
}

TEST(DeterminantTest, 3x3MatrixTest) {
    std::ifstream file("../matrices/matrix3.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 57);
}

TEST(DeterminantTest, 4x4MatrixTest) {
    std::ifstream file("../matrices/matrix4.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -365);
}

TEST(DeterminantTest, 5x5MatrixTest) {
    std::ifstream file("../matrices/matrix5.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -700);
}

TEST(DeterminantTest, 6x6MatrixTest) {
    std::ifstream file("../matrices/matrix6.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -25588);
}

TEST(DeterminantTest, 7x7MatrixTest) {
    std::ifstream file("../matrices/matrix7.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -52780);
}

TEST(DeterminantTest, 8x8MatrixTest) {
    std::ifstream file("../matrices/matrix8.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 126622);
}

TEST(DeterminantTest, 9x9MatrixTest) {
    std::ifstream file("../matrices/matrix9.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -3716316);
}

TEST(DeterminantTest, 10x10MatrixTest) {
    std::ifstream file("../matrices/matrix10.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), -386883);
}

TEST(DeterminantTest, 11x11MatrixTest) {
    std::ifstream file("../matrices/matrix11.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 4159290);
}

TEST(DeterminantTest, 12x12MatrixTest) {
    std::ifstream file("../matrices/matrix12.txt");
    Matrix matrix = Matrix(file);
    EXPECT_EQ(CalculateDeterminant(std::move(matrix)), 137644155);
}
