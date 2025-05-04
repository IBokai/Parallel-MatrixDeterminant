#include <gtest/gtest.h>

#include "../src/determinant/determinant.h"

TEST(DeterminantTest, 1x1MatrixTest) {
    std::ifstream file("../matrices/matrix1.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 3);
}

TEST(DeterminantTest, 2x2MatrixTest) {
    std::ifstream file("../matrices/matrix2.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 10);
}

TEST(DeterminantTest, 3x3MatrixTest) {
    std::ifstream file("../matrices/matrix3.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 57);
}

TEST(DeterminantTest, 4x4MatrixTest) {
    std::ifstream file("../matrices/matrix4.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -365);
}

TEST(DeterminantTest, 5x5MatrixTest) {
    std::ifstream file("../matrices/matrix5.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -700);
}

TEST(DeterminantTest, 6x6MatrixTest) {
    std::ifstream file("../matrices/matrix6.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -25588);
}

TEST(DeterminantTest, 7x7MatrixTest) {
    std::ifstream file("../matrices/matrix7.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -52780);
}

TEST(DeterminantTest, 8x8MatrixTest) {
    std::ifstream file("../matrices/matrix8.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 126622);
}

TEST(DeterminantTest, 9x9MatrixTest) {
    std::ifstream file("../matrices/matrix9.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -3716316);
}

TEST(DeterminantTest, 10x10MatrixTest) {
    std::ifstream file("../matrices/matrix10.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), -386883);
}

TEST(DeterminantTest, 11x11MatrixTest) {
    std::ifstream file("../matrices/matrix11.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 4159290);
}

TEST(DeterminantTest, 12x12MatrixTest) {
    std::ifstream file("../matrices/matrix12.txt");
    EXPECT_EQ(CalculateDeterminant(Matrix(file)), 137644155);
}
