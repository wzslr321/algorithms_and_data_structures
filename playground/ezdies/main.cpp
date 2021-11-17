#include <climits>
#include <iostream>
#include <sstream>
#include <string>

int countAverage(std::string &s) {
  std::istringstream ss(s);
  std::string number;

  // int sum = 0;
  int size = 0;

  while (std::getline(ss, number, ';')) {
    std::cout << number << std::endl;
    // sum += std::stoi(number);
    ++size;
  }
  return size;
}

int main() {
  std::string s = ";5;6;6;13;12;22;27;22;11;14;11;5";
  std::cout << countAverage(s);

  return 0;
}
