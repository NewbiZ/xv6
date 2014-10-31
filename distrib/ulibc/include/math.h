#ifndef ULIBC_MATH_H
#define ULIBC_MATH_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define HUGE_VAL 1e40f

double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double x, double y);
double cos(double x);
double sin(double x);
double tan(double x);
double cosh(double x);
double sinh(double x);
double tanh(double x);
double exp(double x);
double frexp(double value, int* exp);
double ldexp(double x, int exp);
double log(double x);
double log10(double x);
double modf(double value, double* iptr);
double pow(double x, double y);
double sqrt(double x);
double ceil(double x);
double fabs(double x);
double floot(double x);
double fmod(double x, double y);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_MATH_H

