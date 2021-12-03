#include <cmath>
#include <iostream>
#include <vector>

void scan(const std::vector<std::string> &data, std::string &filter, bool oxy) {
  for (int i{0}; i <= filter.size(); ++i) {
    int ones = 0;
    int zeros = 0;
    std::vector<std::string> matches;
    for (int j{0}; j < data.size(); ++j) {
      bool invalid = false;
      for (int y = 0; y < filter.size(); ++y) {
        if (data[j][y] != filter[y]) {
          invalid = true;
          break;
        }
      }
      if (invalid) continue;
      matches.push_back(data[j]);
      if (data[j][i] == '1')
        ++ones;
      else
        ++zeros;
    }
    if (matches.size() == 1) {
      filter = matches[0];
      return;
    }
    if (!oxy) {
      if (ones < zeros)
        filter.push_back('1');
      else
        filter.push_back('0');
    } else {
      if (ones >= zeros)
        filter.push_back('1');
      else
        filter.push_back('0');
    }
  }
}

int to_decimal(const std::string &str) {
  int i = 0;
  int num = 0;
  for (size_t j{str.size()}; j > 0; --j) {
    if (str[j - 1] == '1') num += std::pow(2, i);
    ++i;
  }
  return num;
}

auto main() -> int {
  std::vector<std::string> data;
  while (std::cin) {
    std::string s;
    std::cin >> s;
    if (s == "1") break;
    data.push_back(s);
  }

  std::string filter_oxy = "";
  std::string filter_co2 = "";

  scan(data, filter_oxy, true);
  scan(data, filter_co2, false);

  std::cout << "oxygen: " << to_decimal(filter_oxy) << '\n';
  std::cout << "co2: " << to_decimal(filter_co2) << '\n';

  std::cout << "answer: " << (to_decimal(filter_oxy) * to_decimal(filter_co2))
            << '\n';

  return 0;
}
