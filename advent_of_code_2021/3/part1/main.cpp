#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> data;
  while (std::cin) {
    std::string s;
    std::cin >> s;
    if (s == "1") break;
    data.push_back(s);
  }

  std::string gamma = "";
  for (int j = 0; j < data[0].size(); ++j) {
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < data.size(); ++i) {
      if (data[i][j] == '1')
        ++ones;
      else
        ++zeros;
    }
    if (ones > zeros)
      gamma.push_back('1');
    else
      gamma.push_back('0');
  }

  uint32_t gamma_num = 0;
  uint32_t epilson = 0;
  for (int i = gamma.size() - 1; i >= 0; --i) {
    if (gamma[i] == '1')
      gamma_num += std::pow(2, (gamma.size() - i - 1));
    else
      epilson += std::pow(2, (gamma.size() - i - 1));
  }

  std::cout << "answer: " << (epilson * gamma_num);
}
