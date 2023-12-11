#include <bits/stdc++.h>

using namespace std;

// ax + by = c
//
// we may need to find
// - one solution
// - all solutions
// - solutions in a given interval
// - solution with a minimum value of x + y
//
// base case is when a = b = 0, which may lead
// to infinite or no solutions depending on value of c
//
// if numbers are co-prime ( the only positive integer
// that is a divisor of both of them is 1 ) the solution is:
// x is identical to ca^(-1) mod b, where a^-1 is the modular inverse
// of a modulo b
// note: modular inverse is an integer x, such that ax = 1 mod m
//
// when a and b are not coprime, the solution only exists
// when c is divisible by g, where g = gcd(a,b)
// therefore we can find one of the solutions by:
// (a / g)x is identical to (c / g) (mod b/g)
// {
//  x is identical to (c/g)(a/g)^(-1) (mod b/g)
//  y = (c - ax)/b
// }
//
// assume a,b >= 0
// extended euclidian:
// ax_g + by_g = g
// if(c % g == 0), the equation has a solution
// ax_g * c + by_g * c = c * g
// ax_g * c/g + by_g * c/g = c
//
// one of the solutions:
// x_0 = x_g * c / g
// y_o = y_g * c / g

int gcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1;
  int g = gcd(b, a % b, x1, y1);
  x = y1, y = x1 - y1 * (a / b);
  return g;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  if (a == 0 && b == 0) {
    if (c == 0) {
      x0 = 1, y0 = 1;
      return true;
    }
    return false;
  }
  // abs makes it work for negative values also
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) return false;
  x0 *= c / g;
  y0 *= c / g;
  // adjust values if a,b was negative
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

// after finding one solution it is easy to find all solutions
// as adding b/g to x_0 and a/g from y_0 does not break the equality
// a(x_0 + b/g) + b(y_0 - a/g) = ax_0 + by_0 + a(b/g) - b(a/g) = c
//
// so all the solutions are:
// x = x_0 + k * b / g
// y = y_0 - k * a / g
// without restrictions, there would be an infinite number of them

// problem with intervals
// x is in [min_x; max_x], y is in [min_y, max_y]

