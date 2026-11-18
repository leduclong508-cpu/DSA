#include <math.h>
#include <stdio.h>

// Suppose we have a function f(x) = x^3 - 4x - 9, and
// we want to find its root using the bisection method.
double f(double x) { return x * x * x - 4 * x - 9; }

double bisec_epsGiven(double a, double b, double epsilon) {
  if (f(a) * f(b) >= 0) {
    printf(
        "The function must have different signs at the endpoints a and b.\n");
    return NAN; // Return NaN to indicate an error
  }

  double c;
  int n = 0;
  while ((b - a) >= epsilon) {
    c = (a + b) / 2; // Midpoint
    printf("Buoc %d: Khoang [%.5f, %.5f], c = %.5f\n", n, a, b, c);
    n++;

    if (f(c) == 0.0) {
      break;
    }

    else if (f(a) * f(c) < 0) {
      b = c;
    }

    else {
      a = c;
    }
  }

  return c;
}

double bisec_nGiven(double a, double b, int n) {
  double fa = f(a);
  double fb = f(b);
  if ((fa > 0) == (fb > 0)) {
      printf("Loi: Khoang [%.2f, %.2f] khong dam bao chua nghiem.\n", a, b);
      return NAN;
  }

  double c = a + (b - a) / 2.0;
  for (int i = 0; i < n; i++) {
      c = a + (b - a) / 2.0;
      double fc = f(c);
      printf("Buoc %d: Khoang [%.5f, %.5f], c = %.5f\n", i + 1, a, b, c);

      if (fc == 0.0) break;
      if ((fa > 0) != (fc > 0)) {
          b = c;
          fb = fc;
      } else {
          a = c;
          fa = fc;
      }
  }
  return c;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double epsilon = 1e-4; // Đặt ngưỡng sai số 10^-4

    printf("Bat dau tim nghiem bang phuong phap chia doi...\n");
    double root = bisec_epsGiven(a, b, epsilon);
    printf("\nApproximate root: %.5f\n", root);

    return 0;
}