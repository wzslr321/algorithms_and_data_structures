#include <iostream>

using namespace std;

string generateTheString(int n) {
    return n % 2 == 0 ? string(n - 1, 'a') + 'b' : string(n, 'a');
}

int main() {
    cout << generateTheString(9) << '\n';
}
