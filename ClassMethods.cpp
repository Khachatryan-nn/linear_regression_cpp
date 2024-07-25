#include "ClassDefinitions.h"

// Vector class implementation
Vector::Vector(size_t size) : data(size) {}

size_t Vector::size() const {
	return data.size();
}

double &Vector::operator[](size_t index) {
	return data[index];
}

const double &Vector::operator[](size_t index) const {
	return data[index];
}

Vector Vector::operator+(const Vector &other) const {
	if (size() != other.size())
		throw invalid_argument("Vector sizes do not match.");

	Vector result(size());
	for (size_t i = 0; i < size(); i++) {
		result[i] = data[i] + other[i];
	}

	return result;
}

Vector Vector::operator*(double scalar) const {
	Vector result(size());
	for (size_t i = 0; i < size(); i++) {
		result[i] = data[i] * scalar;
	}

	return result;
}

// Matrix class implementation
Matrix::Matrix(size_t rows, size_t cols) : data(rows, vector<double> (cols)) {}

size_t Matrix::rows() const {
	return data.size();
}

size_t Matrix::cols() const {
	return data[0].size();
}

vector <double> &Matrix::operator[](size_t index) {
	return data[index];
}

const vector <double> &Matrix::operator[](size_t index) const {
	return data[index];
}

Matrix Matrix::transpose() const {
	Matrix result(cols(), rows());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < cols(); j++) {
			result[j][i] = data[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
	if (cols() != other.rows())
		throw invalid_argument("Matrix inner dimensions do not match for matrix multiplication.");

	Matrix result(rows(), other.cols());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < other.cols(); j++) {
			result[i][j] = 0;
			
			for (size_t k = 0; k < cols(); k++) {
				result[i][j] += data[i][k] * other[k][j];
			}
		}
	}

	return result;
}

Vector Matrix::operator*(const Vector &vec) const {
	if (cols() != vec.size())
		throw invalid_argument("Matrix and vector sizes do not match for multiplication.");

	Vector result(rows());
	for (size_t i = 0; i < rows(); i++) {
		result[i] = 0;
		for (size_t j = 0; j < cols(); j++) {
			result[i] += data[i][j] * vec[j];
		}
	}
	return result;
};
