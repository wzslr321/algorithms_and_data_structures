#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int j = 0;
  int i = 0;
  int count = 0;
  if(n == 0) {
      cout << "0\n";
      return 0;
  }
  if(n < 3) {
      cout << "NIE\n";
      return 0;
  }
  if(n == 3) {
      cout << "2 0 3 1\n";
      return 0;
  }
  while(i <= n/2 && count < n + 1) {
      for(j = i; j <= n; j += 3) {
          ++count;
          cout << j << ' ';
      }
      ++i;
  }
      
  cout << '\n';

  return 0;
}
