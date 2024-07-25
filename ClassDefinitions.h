#ifndef CLASS_DEFINITIONS_H
#define CLASS_DEFINITIONS_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Vector class to optimize code
class Vector {
public:
	vector <double> data;

	Vector(size_t size);

	size_t size() const;

	double &operator[](size_t index);
	const double &operator[](size_t index) const;

	Vector operator+(const Vector &other) const;

	Vector operator*(double scalar) const;
};

// Matrix class
class Matrix {
public:
	vector<vector<double> > data;

	Matrix(size_t rows, size_t cols);

	size_t rows() const;
	size_t cols() const;

	vector <double> &operator[](size_t index);

	const vector <double> &operator[](size_t index) const;

	Matrix transpose() const;

	Matrix operator*(const Matrix &other) const;

	Vector operator*(const Vector &vec) const;
};

#endif
