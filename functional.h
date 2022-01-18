#include<math.h>
#include<stdlib.h>



using namespace std;

template<size_t N>
double func_value(const std::array<double, N> x) {

	double fx = 0;
	for (int i = 0; i < N; i++) {

		fx += x[i] * log(x[i]);
	};

	return fx;

};


//func_grad<vector>(x, grad, nPixSq);
template<typename type>
void func_grad(type& x, type& grad, int N) {
	for (int i = 0; i < N; i++) {
		grad[i] = 1 + log(x[i]);
	};
};
/*
templat<typename type>
void func_grad2(type& x, type& grad, int N) {


}

//ROSEBROCK


template<size_t N>
double func_value(const std::array<double, N> x) {

	double fx = 0;
	for (int i = 0; i < N; i++) {
		fx += x[i] * log(x[i]);
	};
	return fx;

};

//func_grad<vector>(x, grad, nPixSq);
template<typename type>
void func_grad(type& x, type& grad, int N) {
	grad[0] = 2 * (x[0] - 1) + 400 * (x[0] * x[0] - x[1])*x[0];
	grad[1] = 200 * (x[1] - x[0] * x[0]);
};
*/


//----Clipping-------
template<typename type>
void clipping(type& x, int N) {

	for (int i = 0; i < N; i++) {

		if (x[i] <= 0) x[i] = 0.1;
	}
}
