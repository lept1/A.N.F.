#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

// ROOT FINDER METHODS
// fun	target function
// dfun	derivative of target function
// a	inferior limit
// b	superior limit
// eps	desired tolerance
// N	number of interval where to search zeros

double Bisection(double(*fun)(double),double a, double b,double eps);
double Falsi(double(*fun)(double), double a, double b, double eps);
double Secant(double (*fun)(double), double a, double b, double eps);
double Newton(double (*fun)(double),double (*dfun)(double), double a, double eps);
vector<double> BracketBisection(double(*fun)(double),double a, double b,double eps, int N);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

// NUMERICAL INTEGRATION METHODS
// fun	integrand
// a	inferior limit of the definite integral
// b	superior limit of the definite integral
// N	number of intervals to divide (b-a)
// ord	degree of Legendre polynomials for Gauss-Legendre Quadrature

double Trapezoidal(double (*fun)(double), double a, double b, int N);
double Rectangular(double (*fun)(double), double a, double b, int N);
double Simpson (double (*fun)(double), double a, double b, int N);
double GaussLegendre(double (*fun)(double), double a, double b, int N, int ord, double eps);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//DERIVATION METHODS
// fun	function to derivate
// x	point where derivate
// h	desired tolerance

double ForwardD(double(*fun)(double),double x, double h);	
double BackwardD(double(*fun)(double),double x,double h);
double CentralD(double(*fun)(double),double x, double h);
double HighD(double(*fun)(double),double x,double h);
double CentralD2(double(*fun)(double),double x, double h);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//DIFFERENTIAL EQUATION METHODS WITH INITIAL CONDITION
// fun ydot Rhs acc		right hand side of ode
// x0					starting point of integration
// y0					initial conditions
// h					desired tolerance
// neq					number of equation in first order differential equation system

vector<double> Euler(double(*fun)(double),double x0, double y0, double h, double xf);
void EulerStep(double x, double *Y, void (*ydot)(double, double *, double *), double h, int neq);
void RK2(double x, double *Y, void(*Rhs)(double, double *, double *), double  h, int neq);
void RK4(double x, double *Y, void(*ydot)(double, double *, double *), double  h, int neq);
void PV(double *x, double *v, void(*acc)(double *, double *, double *),double  h, int N);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//ALGEBRA METHODS
// **a			matrix
// n			number of unknowns, assuming only square matrix
// i j			number of a row
// a b c r		assuming tridiagonal matrix with the following form
//  			|b0	c0	0 	0  ||x0| |r0|
//  			|a1	b1	c1	0  ||x1|=|r1|
//  			|0	a2	b2	c2 ||x2| |r2|
//  			|0	0	a3	b3 ||x3| |r3|

void GaussElimination(double **a, int n);
void SwapRow(double **a, int i, int j, int n);
void PartialPivot(double **a, int n);
void TridiagonalSolver(double *a, double *b, double *c, double *r, int n);
void PrintMat(double **a,int n);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

// SOME USEFUL MATHEMATICAL FUNCTION
double LegendrePol(double x, int n);
double Polynom(double x, int n, double *coeff);
double DLegendrePol(double x, int n);
double Parabola(double x);
double Sic(double x);
double Gaussian(double x);
double PL(double x);
