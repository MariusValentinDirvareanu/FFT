#include <stdio.h>
#include <complex.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>



void even(unsigned n, float R[64], float a[64])
{
	unsigned i = 0;
	while (i < n)
	{
		R[i] = a[2 * i];
		++i;
	}
}



void odd(unsigned n, float R[64], float a[64])
{
	unsigned i = 0;
	while (i < n)
	{
		R[i] = a[2 * i + 1];
		++i;
	}
}

int FFT(unsigned int n, float  r[64], float A[64], float B[64])
{
	float U[64], V[64];
	int k;
	_Dcomplex g;
	// TODO : numar complex de tip float in loc de double 
	g = cexp(2 * M_PI * cimagd(I) / n);
	if (n == 1) {
		return r;
	}
	int m = n / 2;
	even(32, A, r);
	odd(32, B, r);
	A = FFT(m, A, A, B);
	B = FFT(m, B, A, B);
	for (k = 0; k < n; ++k) {
		U[k] = A[k % m];
		V[k] = B[k % m];
	}
}

int main()
{
	unsigned i, n = 64;
	float X[64] = { 0 }, Y[64] = { 0 };
	float v[64] = { 0.8415,    0.9093,    0.1411,   -0.7568,   -0.9589,   -0.2794,    0.6570,    0.9894,    0.4121,   -0.5440,   -1.0000,   -0.5366,    0.4202,    0.9906,    0.6503,   -0.2879,   -0.9614,   -0.7510,    0.1499,  0.9129,    0.8367,   -0.0089,   -0.8462,   -0.9056,   -0.1324,    0.7626,    0.9564,    0.2709,   -0.6636,   -0.9880,   -0.4040,    0.5514,    0.9999,    0.5291,   -0.4282,   -0.9918,   -0.6435,    0.2964,    0.9638,    0.7451,   -0.1586,   -0.9165,   -0.8318,    0.0177,   0.8509,    0.9018,   0.1236,   -0.7683,   -0.9538,   -0.2624,    0.6702,    0.9866,    0.3959,   -0.5588,   -0.9998,   -0.5216,    0.4362,    0.9929,    0.6367,   -0.3048,   -0.9661,  -0.7392,    0.1674, 0.9200 };


	for (i = 0; i < 32; i++)
	{
		printf("%f \n", X[i]);
		printf("%f \n", Y[i]);
	}
	//getchar();
	return 0;
}
