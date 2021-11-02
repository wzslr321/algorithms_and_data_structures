#include <iostream>

using namespace std;

string toLowerCase(string s) {
    for (auto &c : s) {
        if (c < 91 && c > 64) {
            c += 32;
        }
    }

    return s;
}

int main() { 
    cout << toLowerCase("HeLoOWorlDz");

    return 0; 
}
