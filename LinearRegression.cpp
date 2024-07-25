#include "LinearRegression.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

Vector solve(const Matrix &A, const Vector &b) {
	Matrix Ab = A;
	Vector x(b.size());

	for (size_t i = 0; i < b.size(); i++) {
		Ab[i].push_back(b[i]);
	}

	// Forward elimination
	for (size_t i = 0; i < b.size(); i++) {
		size_t pivot = i;
		for (size_t j = i + 1; j < b.size(); j++) {
			if (fabs(Ab[j][i]) > fabs(Ab[pivot][i])) {
				pivot = j;
			}
		}
		swap(Ab[i], Ab[pivot]);

		// Eliminate
		for (size_t j = i + 1; j < b.size(); j++) {
			double factor = Ab[j][i] / Ab[i][i];
			for (size_t k = i; k < b.size() + 1; k++) {
				Ab[j][k] -= factor * Ab[i][k];
			}
		}
	}

	// Back substitution
	for (int i = b.size() - 1; i >= 0; i--) {
		x[i] = Ab[i].back() / Ab[i][i];
		for (int j = 0; j < i; j++) {
			Ab[j].back() -= Ab[j][i] * x[i];
		}
	}

	return x;
}

