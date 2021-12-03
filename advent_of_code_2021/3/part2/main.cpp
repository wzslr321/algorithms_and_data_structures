#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

auto scan(const std::vector<std::string> &data, std::string filter)
    -> std::string {
  std::string oxygen = "";

  for (int i{0}; i < data[0].size(); ++i) {
    int ones = 0;
    int zeros = 0;
    for (int j{0}; j < data.size(); ++j) {
      bool invalid = false;
      for (int y{0}; y < filter.size(); ++y) {
        if (data[j][y] != filter[y]) {
          invalid = true;
          break;
        }
      }
      if (invalid) continue;
      if (data[j][i] == '1')
        ++ones;
      else
        ++zeros;
    }
    if (ones >= zeros)
      oxygen.push_back('1');
    else
      oxygen.push_back('0');
    filter = oxygen;
  }
  std::cout << oxygen << '\n';
  return oxygen;
}
auto main() -> int {
  std::vector<std::string> data;
  int ones = 0;
  int zeros = 0;
  while (std::cin) {
    std::string s;
    std::cin >> s;
    if (s[0] == '1')
      ++ones;
    else
      ++zeros;
    if (s == "1") break;
    data.push_back(s);
  }

  std::string filter = "";
  if (ones >= zeros)
    filter = "1";
  else
    filter = "0";

  scan(data, filter);

  return 0;
}
