#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
  if (s.size() < 2) return true;

  int first{0};
  int last(s.size() - 1);

  while (last - first >= 1) {
    if (isdigit(s[first]) || isdigit(s[last])) return false;
    if (!isalpha(s[first])) {
      first++;
      continue;
    }

    if (!isalpha(s[last])) {
      last--;
      continue;
    }
    if (tolower(s[first]) != tolower(s[last])) return false;
    first++;
    last--;
  }

  return true;
}

int main() {
  string s = "a man, a plan, a canal: panama";
  string s2 = "ab";
  string s3 = "a.";
  string s4 = "0P";
  string s5 = "!!!";

  cout << isPalindrome(s);
  cout << isPalindrome(s2);
  cout << isPalindrome(s3);
  cout << isPalindrome(s4);
  cout << isPalindrome(s5);

  return 0;
}
