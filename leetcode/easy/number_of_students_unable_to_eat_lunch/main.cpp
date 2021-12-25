#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches) {
  auto unable{0}, i{0}, j{0};

  while (unable != students.size() - j) {
    if (students[j] == sandwiches[i]) {
      ++j;
      ++i;
      unable = 0;
    } else {
      students.push_back(students[j]);
      j++;
      ++unable;
    }
  }
  return unable;
}

int main() {
  vector<int> s{1, 1, 1, 0, 0, 1};
  vector<int> sd{1, 0, 0, 0, 1, 1};
  vector<int> s2{0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1};
  vector<int> sd2{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0};
  cout << countStudents(s, sd);   // 3
  cout << countStudents(s2, sd2); // 5
  return 0;
}
