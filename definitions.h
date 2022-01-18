#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

typedef double vector[nPixSq];
typedef double matrix[nPixSq][nPixSq];

//PARÀMETRES DEL LBFGS

template <typename Scalar>
class LBFGSParam {

public:

	int m; //The number of corrections to approximate the inverse Hessian matrix. By default 10.

	Scalar epsilon; //accuracy required to stop the search ( ||grad+ - grad|| < epsilon ). By default 0.0001

	int max_iterations; //max number of iterations. By default 100.

	LBFGSParam() { //initialize the default values every time a LBFGSParam class variable is created

		m = 10;
		epsilon = 0.0001;
		max_iterations = 100;

	}

	inline void check_param() const {

		if (m <= 0)
			throw std::invalid_argument("'m' must be positive");
		if (epsilon < 0)
			throw std::invalid_argument("'epsilon' must be non-negative");
		if (max_iterations < 0)
			throw std::invalid_argument("'max_iterations' must be non-negative");
	};


};

class functional {

private:
	int n;

public:

	functional(int n_) : n(n_) {} //agafa el valor n com la dimensió

	double func_value(const double* x) {
		double fx = 0;
		for (int i = 0; i < n; i++) {

			fx += x[i] * log10(x[i]);

		};

		return fx;
	};

	void grad(const double* x, double* grad) {
		for (int i = 0; i < n; i++) {
			grad[i] = 1 + log10(x[i]);
		};

	}

};

template <typename Scalar, bool LBFGSB = false>
class LBFGSMat {

private:

	matrix m_s;
	matrix m_y;
	vector m_ys;
	vector m_alpha;
	int m_ptr;

public:

	LBFGSMat();

};


/*
class Matrix {

private:
	int rows_, cols_;
	void allocSpace()
	{
		p = new double* [rows_];
		for (int i = 0; i < rows_; ++i) {
			p[i] = new double[cols_];
		}
	};

public:

	double** p;
	Matrix(int rows, int cols) : rows_(rows), cols_(cols)
	{
		allocSpace();
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				p[i][j] = 0;
			}
		}
	}

};

/*
class Vector {

private:
	int rows_;
	void allocSpace()
	{
		vector = new double[rows_];
	}
public:
	double* vector;
	Vector(int rows) : rows_(rows)
	{
		allocSpace();
		for (int i = 0; i < rows_; i++) vector[i] = 0;

	}

};
*/

typedef double vector[nPixSq];
typedef double board[nPixSq][nPixSq]; 



