#include <iostream>

using namespace std;

int main() {
    int w{};
    cin >> w;

    int a{w / 2};
    if (w % 2 != 0) {
        cout << "NO";
        return 0;
    }
    if (a % 2 == 0) {
        cout << "YES";
        return 0;
    }

    a = 1;
    --w;
    while (a != w) {
        if (a % 2 == 0 && w % 2 == 0) {
            cout << "YES";
            return 0;
        }
        ++a;
        --w;
    }

    cout << "NO";

    return 0;
}

