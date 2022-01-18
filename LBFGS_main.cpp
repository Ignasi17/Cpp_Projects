#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <array>
#include"Parameters.h"
#include"functional.h"
#include"algebra.h"
#include <fstream>
using namespace std;




int main() {





	for (int i = 0; i < nPixSq; i++) {
		//x[i] =1;
		x[i] = (rand() );
		//cout << x[i]; cout << "\n";
	}
	clipping<vector>(x, nPixSq);

	//STEP 0------------------------------------
	//define grad
	func_grad<vector>(x, grad, nPixSq);

	drt = grad;


	//first new x: x = x - 1*drt
	subs<vector>(x, grad, nPixSq, 1); //new X
	clipping<vector>(x, nPixSq);
	cout << "x = \t";
	func_grad<vector>(x, grad, nPixSq);//new grad
	append<matrix, vector>(s, drt, nPixSq, iter % m);//append s = drt. Wrong sign.
	subs<vector>(grad, drt, nPixSq, 2);
	append<matrix, vector>(y, drt, nPixSq, iter % m);
	//norm<vector>(grad, nPixSq);
	iter++;
	k++;
	q = grad;


	
	while (norm<vector>(grad, nPixSq) >= Epsilon && iter < max_iterations) {



		ys_prod<matrix, vector_m>(y, s, ys, nPixSq, k);
		

		for (int i = k - 1; i > -1; i--) {

			
			alpha[i] = -1 * qs_prod<vector, matrix>(q, s, i, nPixSq) / ys[i];
		
			for (int j = 0; j < nPixSq; j++) q[j] -= alpha[i] * y[i][j];


		}
	

		for (int i = 0; i < k; i++) {

			beta = qs_prod<vector, matrix>(q, y, i, nPixSq) / ys[i];
			for (int j = 0; j < nPixSq; j++) q[j] += (alpha[i] - beta) * (-1 * s[i][j]);

		}

		subs<vector>(x, q, nPixSq, 1);//new X


		drt = grad;
		clipping<vector>(x, nPixSq);
		func_grad<vector>(x, grad, nPixSq);//new grad
		append<matrix, vector>(s, q, nPixSq, iter % m);
		subs<vector>(grad, drt, nPixSq, 2);
		append<matrix, vector>(y, drt, nPixSq, iter % m);
		q = grad;



		if (iter < m) k++;
		
		iter++;

		//cout << norm<vector>(grad, nPixSq); cout << "\n";
	}
	
	cout << "\n"; cout << "iteracions = \t"; cout << iter; cout << "\n";
	
	for (int i = 0; i < nPixSq; i++) {
		cout << x[i]; cout << "\n";
	}
	
	cout << "ready";



};



