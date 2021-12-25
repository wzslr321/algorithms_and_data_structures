#include <cstdlib>
#include <iostream>
#include <vector>

struct suffix_array {
 private:
  int N;
  std::vector<int> Text;
  std::vector<int> Sa;
  std::vector<int> Lcp;
  bool IsSaConsturcted = false;
  bool IsLcpConstructed = false;

 public:
  explicit suffix_array(std::vector<int> text) {
    if (text.empty()) return;
    Text = text;
    N = text.size();
  }

  auto buildSuffixArray() -> void {
    if (IsSaConsturcted) return;
    construct();
    IsSaConsturcted = true;
  }

  auto buildLcpArray() -> void {
    if (IsLcpConstructed) return;
    buildSuffixArray();
    kasai();
    IsLcpConstructed = true;
  }

  auto construct() -> void {}

  auto kasai() -> void {
    auto lcp = std::vector<int>(N);
    auto inv = std::vector<int>(N);

    for (int i = 0; i < N; ++i)
      inv[Sa[i]] = i;

    for (int i = 0, len = 0; i < N; ++i) {
      if (inv[i] > 0) {
        int k = Sa[inv[i] - 1];
        while ((i + len < N) && (k + len < N) && Text[i + len] == Text[k + len])
          ++len;

        lcp[inv[i]] = len;
        if (len > 0) --len;
      }
    }
  }
};

auto main() -> int { return EXIT_SUCCESS; }
