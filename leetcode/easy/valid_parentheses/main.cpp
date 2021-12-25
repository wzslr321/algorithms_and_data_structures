#include <cassert>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, bool> isClosing{
    {'}', true},  {')', true},  {']', true},
    {'{', false}, {'(', false}, {'[', false},
};

unordered_map<char, char> parentheses{
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
};

bool isValid(string s) {
  if ((s.size() % 2) != 0) {
    return false;
  }

  if (!isClosing[s[s.size() - 1]] || isClosing[s[0]]) {
    return false;
  }

  stack<char> p{};

  for (auto i{0}; i < s.size(); i++) {
    if (!isClosing[s[i]]) {
      p.push(s[i]);
    } else {
      if (p.size() > 0) {
        if (s[i] != parentheses[p.top()]) {
          return false;
        }

        p.pop();
      } else {
        return false;
      }
    }
  }

  if (p.size() > 0) {
    return false;
  }

  return true;
};

int main() {
  /*
  assert((isValid("()"), true));
  assert((isValid("()[]{}"), true));
  assert((isValid("(]"), false));
  assert((isValid("([)]"), false));
  assert((isValid("{[]}"), true));
  */

  cout << isValid("()))");

  return 0;
};
