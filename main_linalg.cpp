#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <cmath>
#include <algorithm>
#include "LinearRegression.h"
#include "graphs.hpp"

Vector linearRegression(const Matrix &X, const Vector &y) {
	// Add a column of ones to X
	Matrix X_b(X.rows(), X.cols() + 1);
	for (size_t i = 0; i < X.rows(); i++) {
		X_b[i][0] = 1.0;
		for (size_t j = 0; j < X.cols(); j++) {
			X_b[i][j + 1] = X[i][j];
		}
	}

	Matrix Xt = X_b.transpose();
	Matrix XtX = Xt * X_b;
	Vector Xty = Xt * y;

	return solve(XtX, Xty);
}

int main() {
	int n_samples = 20;
	Matrix X(n_samples, 1); // 4 samples, 1 feature
	Vector y(n_samples); // 4 targets
	float w = 2.0;
	float b = 3.5;
	// Creating arrays and essential variables for further plotting the data
	vector <vector <double> > orig_data(n_samples, vector<double>(2));
	vector <vector <double> > pred_data(n_samples, vector<double>(2));
	size_t height = 80;
	size_t width = 80;
	long double xmin = 0;
	long double xmax = 20;
	long double ymin = 0;
	long double ymax = 20;
	graphs::options aoptions;
	aoptions.type = graphs::type_block;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	
	for (size_t i = 0; i < X.rows(); i++) {
		X[i][0] = dis(gen) * 10.0;
	}

	for (size_t i = 0; i < X.rows(); i++) {
		y[i] = X[i][0] * w + b + dis(gen) * 2;
	}

	Vector beta = linearRegression(X, y);

	cout << "Coefficients: ";
	for (size_t i = 0; i < beta.size(); i++) {
		cout << beta[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < X.rows(); i++) {
		orig_data[i][0] = X[i][0];
		pred_data[i][0] = X[i][0];
		orig_data[i][1] = y[i];
		pred_data[i][1] = X[i][0] * beta[1] + beta[0];
	}

	cout << "X | Y | Pred: " << endl;
	for (size_t i = 0; i < X.rows(); i++) {
		cout << orig_data[i][0] << " = " << orig_data[i][1] << " | " << pred_data[i][1] << endl;
	}
	cout << endl;

	vector <vector <vector <double> > > arrays(2);
	arrays[0] = orig_data;
	arrays[1] = pred_data;
	graphs::plots(height, width, xmin, xmax, ymin, ymax, arrays, aoptions);

	return 0;
}
