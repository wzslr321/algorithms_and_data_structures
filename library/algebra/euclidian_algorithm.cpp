#include <bits/stdc++.h>
#include <tuple>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

// extended euclidian algorithm
// find x,y (bezout coefficients) for which ax + by = gcd(a,b) holds
// bezout identity proves that we can always achieve it

// x, y are output values
int gcde(int a, int b, int &x, int &y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    // tie destructures, so x and x1 can be used separately
    // equivalent to:
    // x = x1;
    // x1 = x - q * x1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

// bezout identity can be extended to more than two integers (if)
// https://en.wikipedia.org/wiki/Bézout%27s_identity#For_three_or_more_integers
