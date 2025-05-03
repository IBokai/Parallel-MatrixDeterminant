// include what you use only
#pragma once
#include "../matrix/matrix.h"

long double CalculateDeterminant(Matrix const& matrix, bool top_level = true);

long double CalculateDeterminantNonParallel(Matrix const& matrix);
