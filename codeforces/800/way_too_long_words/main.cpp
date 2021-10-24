#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n{};
    cin >> n;
    vector<string> words{};
    for (auto i{0}; i < n; ++i) {
        string word{};
        cin >> word;
        words.push_back(word);
    }

    for (auto &w : words) {
        if (w.size() > 10) {
            w = w[0] + to_string(w.size() - 2) + w[w.size() - 1];
        }
        cout << w << '\n';
    }

    return 0;
}
