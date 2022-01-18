#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <array>

using namespace std;




const float Epsilon = 0.000001;
const int m = 10;
const int max_iterations = 1000;
const int t = 1; //newton step.

const int nPixSq = 20000;
int k = 0; //iterator
int iter = 0;

typedef double matrix[m][nPixSq];
typedef std::array<double, nPixSq> vector;
typedef std::array<double, m> vector_m;

double* b = new  double[nPixSq];
double beta;
matrix s;
matrix y; 
vector x;
vector q;
vector grad;
vector gradp;
vector drt;
vector aux1;

vector_m ys;
vector_m alpha;
