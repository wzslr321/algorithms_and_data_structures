#include <cmath>
#include <iostream>

using namespace std;

int maximum69Number(int num) {
  string s = to_string(num);

  for (auto i{0}; i < s.size(); ++i) {
    if (s[i] == '6') {
      s[i] = '9';
      return stoi(s);
    }
  }
  return num;
}
int main() {
  cout << maximum69Number(9996) << '\n';

  return 0;
}
