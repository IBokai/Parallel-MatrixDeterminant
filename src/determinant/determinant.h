// include what you use only
#pragma once
#include "../matrix/matrix.h"

long double calculateDeterminant(Matrix const& matrix, bool top_level = true);

long double calculateDeterminantNonParallel(Matrix const& matrix);
