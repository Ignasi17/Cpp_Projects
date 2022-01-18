#include<math.h>
#include<stdlib.h>#pragma once

using namespace std;


//-----------NORM---------------
//THIS FUNCTION COMPUTES THE NORM OF THE ARARY. IT NEED THE ARRAY, THE DATA TYPE AND
//THE SIZE OF THE ARRAY. EXAMPLE -> j = norm<vector>(x, nPixSq);
template<typename type> 
float norm(type& x, int N) {
	float n = 0;
	for (int i = 0; i < N; i++) {
		n += x[i] * x[i];
	}
	n = sqrt(n);
	return n;
};


//-------------SUBS----------------
//THIS FUNCTION SUBSTRACTS TWO ARRAYS. GIVEN ARRAYS a AND b.
// (1) A - B -> STORES IR IN A
// (2)  A - B -> STORES IT IN B
template<typename type>
void subs(type& a, type& b, int N, int choose) {

	if (choose == 1)
	{
		for (int i = 0; i < N; i++) {

			a[i] -= b[i];
		}
	}
	if (choose == 2)
	{
		for (int i = 0; i < N; i++) {

			b[i] = a[i] - b[i];
		}
	}
}

//-----------APPEND-------

template<typename type1, typename type2>
void append(type1& a, type2& b, int N, int ptr) {

	for (int i = 0; i < N; i++) {
		a[ptr][i] = b[i];
	}
}


//------YS DOT PROD-----
//DO THE DOT PRODUCT OF THE ARRAYS STOREDS INT HTE MATRIX Y AND S AND STORES THE RESULT IN ARRAY YS.

template<typename type, typename type2> //ys_prod<matrix, vector>(y, s, ys, nPixSq, k);
void ys_prod(type& y, type& s, type2& ys, int N, int k) {

	for (int i = 0; i < k ; i++) {

		double sum = 0;
		for (int j = 0; j < N; j++) {

			sum += -1*y[i][j] * s[i][j];
		}
		ys[i] = sum;
	
	}

}

//--------QS DOT PRODUCT------

template<typename type1, typename type2>//qs_prod<vector, matrix>(grad, s, k, nPixSq);
float qs_prod(type1& q, type2& s, int k, int N ) {

	double qs = 0;
	for (int i = 0; i < N; i ++) {
	
			qs += (q[i] * s[k][i]);

	}

	return qs;
}

//-----------CLIPPING-------
//IF SOME VALUE OF THE NEW PIXELS ARE EQUALE T

