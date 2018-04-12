#include "strangeMath.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <io.h>
#include <fcntl.h> 
#include "strangeMath.h"
double rel_error(double x0, double x)
{
	return abs(x0 - x) / abs(x0);
}
double divmult(double x, double d = 3.14, int n = 52)
{
	for (int i = 0; i < n; ++i) {
		x /= d;
	}
	for (int i = 0; i < n; ++i) {
		x *= d;
	}
	return x;
}
double sqrsqrt(double x, int n = 52)
{
	for (int i = 0; i < n; ++i) {
		x = sqrt(x);
	}
	for (int i = 0; i < n; ++i) {
		x *= x;
	}
	return x;
}
double mysqrsqrt(double x, int n = 52)
{
	x = log(x);
	for (int i = 0; i < n; ++i) {
		x *= (1.0/2);
	}
	for (int i = 0; i < n; ++i)
		x *= 2;
	x = exp(x);
	return x;
}
void test(double first, double last, int nsteps)
//calculate relative error from divmul
//Precond: nsteps > 0
//Postcond: return rel_error
{
	double step{ (last - first) / nsteps };
	std::vector<double> x0 = { first };
	double curr{ first };
	for (int i = 0; i < nsteps; ++i) {
		curr += step;
		x0.push_back(curr);
	}
	std::vector<double> x;
	for (int i = 0; i < nsteps; ++i) {
		x.push_back(divmult(x0[i]));
	}
	std::vector<double> rel;
	for (int i = 0; i < nsteps; ++i) {
		rel.push_back(rel_error(x0[i], x[i]));
	}
	for (double x : rel) {
		std::wcout << x << ' ';
	}
	std::wcout << '\n';
}
void tests(double first, double last, int nsteps)
//calculate relative error from divmul
//Precond: nsteps > 0
//Postcond: return rel_error
{
	double step{ (last - first) / nsteps };
	std::vector<double> x0 = { first };
	double curr{ first };
	for (int i = 0; i < nsteps; ++i) {
		curr += step;
		x0.push_back(curr);
	}
	std::vector<double> x;
	for (int i = 0; i < nsteps; ++i) {
		x.push_back(sqrsqrt(x0[i]));
	}
	std::vector<double> rel;
	for (int i = 0; i < nsteps; ++i) {
		double temp = rel_error(x0[i], x[i]);
		rel.push_back(temp);
	}
	for (double x : rel) {
		std::wcout << x << ' ';
	}
	std::wcout << '\n';
}
void testmy(double first, double last, int nsteps)
//calculate relative error from divmul
//Precond: nsteps > 0
//Postcond: return rel_error
{
	double step{ (last - first) / nsteps };
	std::vector<double> x0 = { first };
	double curr{ first };
	for (int i = 0; i < nsteps; ++i) {
		curr += step;
		x0.push_back(curr);
	}
	std::vector<double> x;
	for (int i = 0; i < nsteps; ++i) {
		x.push_back(mysqrsqrt(x0[i]));
	}
	std::vector<double> rel;
	for (int i = 0; i < nsteps; ++i) {
		rel.push_back(rel_error(x0[i], x[i]));
	}
	for (double x : rel) {
		std::wcout << x << ' ';
	}
	std::wcout << '\n';
}