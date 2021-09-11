#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

    int it_t_s{3};
    int sum{};
    for (int i{}; i < s.length(); i++) {
        if (m[s[i + 1]] > m[s[i]]) {
            sum += (m[s[i + 1]] - m[s[i]]);
            i++;
        } else {
            sum += m[s[i]];
        }
    }

    return sum;
}

int main() {
    cout << romanToInt("MCMXCIV");

    return 0;
};
