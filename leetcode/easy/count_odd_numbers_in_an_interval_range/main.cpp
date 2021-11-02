#include <iostream>

using namespace std;

int countOdds(int low, int high) {
    // ik, this could be oneliner, I share my first idea that worked
    if (low % 2 == 0) {
        if (high % 2 == 0) {
            return (high - low) / 2;
        }
        return (high - low) / 2 + 1;
    }
    return (high - low) / 2 + 1;
}

int main() {
    cout << countOdds(8,23) << '\n';
}

