#include<iostream>
#include<math.h>

// Suppose we have a function f(x) = x^3 - 4x - 9, and
// we want to find its root using the bisection method.
double f(double x) { return x * x * x - 4 * x - 9; }

// A priori error estimate: Given a tolerance epsilon, 
// we can determine the number of iterations needed to achieve that tolerance.
int steps(double a, double b, double epsilon){
    
}

double seca_epsGiven(int a, int b, double epsilon){
   if(f(a) * f(b) >= 0) {
    printf(
        "The function must have different signs at the endpoints a and b.\n");
    return NAN; // Return NaN to indicate an error

    while(b - a >= epsilon){
        
    }
}
