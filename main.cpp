#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include <ctime>
#include <ctime>

using namespace std;



int main() {

	
	/*Matrix creation. Matrix must been transposed to improve the velocity************************************************************************************/
	const int m = 20;


	/*double A[m][m] = {12, 6, -4, -51, 167, 24, 4, -68, -41}*/;
	/*double A[m][m] = {2, -2, 18, 2, 1, 0, 1, 2, 0};
	double A[m][m] = { 2, 2, 1, -2, 1, 2, 18, 0, 0 }; */
	double A[m][m];
	double R[m][m] = { {0} };

	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; ++j) {

			A[i][j] = rand() % (100 - 0 + 1) +0;
		
		}
	}
	
	/*
	printf("A = \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {

			printf("%9.6g ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	/****************************************************************************************************/
	std::clock_t c_house1 = std::clock();
	int k, i, cont;

	for (k = 0; k < m; k++) {

		for (i = 0; i < k; i++) {

			for (cont = 0; cont < m; cont++) {
				R[i][k] += A[i][cont] * A[k][cont]; /*R ix bé directament*/

			}
			
			for (cont = 0; cont < m; cont++) {
				A[k][cont] -= R[i][k] * A[i][cont];

			}
		}

		float norm = 0;
		for (cont = 0; cont < m; cont++) {

			norm += A[k][cont] * A[k][cont];


		}

		R[k][k] = sqrt(norm);
		for (cont = 0; cont < m; cont++) {

			A[k][cont] = A[k][cont] / sqrt(norm);

		}
	}
	std::clock_t c_house2 = std::clock();
	
	double time_house_ms = 1000 * (c_house2 - c_house1) / CLOCKS_PER_SEC;
	std::cout << "CPU Schwarz-Rutishauser time used: " << time_house_ms / 1000.0 << " s\n";
	
	/*
	printf("A = \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {

			printf("%9.6g ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("R = \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {

			printf("%9.6g ", R[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	return 0;
}