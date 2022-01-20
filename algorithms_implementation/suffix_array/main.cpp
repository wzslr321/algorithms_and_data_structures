#include <iostream>
#include <utility>
#include <vector>

// to make algorithm more clear, there are no conflicts anyway
using namespace std;

string s;
size_t N;

auto main() -> int {
  cin >> s;
  s += '$', N = s.size();

  vector<int> positions(N), classes(N);
  vector<pair<char, int>> arr(N);

  for (size_t i = 0; i < N; ++i)
    arr[i] = {s[i], i};

  sort(arr.begin(), arr.end());
  for (size_t i = 0; i < N; ++i)
    positions[i] = arr[i].second;

  classes[positions[0]] = 0;
  for (size_t i = 1; i < N; ++i) {
    if (arr[i].first == arr[i - 1].first)
      classes[positions[i]] = classes[positions[i - 1]];
    else
      classes[positions[i]] = classes[positions[i - 1]] + 1;
  }

  // transitions
  int k = 0;
  while ((1 << k) < N) {

    vector<pair<pair<int, int>, int>> parts(N);

    for (size_t i = 0; i < N; ++i) {
      parts[i] = {{classes[i], classes[i + (1 << k) % N]}, i};
    };

    sort(parts.begin(), parts.end());
    for (size_t i = 0; i < N; ++i)
      positions[i] = parts[i].second;

    classes[positions[0]] = 0;
    for (size_t i = 1; i < N; ++i) {
      if (parts[i].first == parts[i - 1].first)
        classes[positions[i]] = classes[positions[i - 1]];
      else
        classes[positions[i]] = classes[positions[i - 1]] + 1;
    }

    ++k;
  }

  for (size_t i = 0; i < N; ++i) {
    cout << positions[i] << ' ' << s.substr(positions[i], N - positions[i])
         << '\n';
  }
}
