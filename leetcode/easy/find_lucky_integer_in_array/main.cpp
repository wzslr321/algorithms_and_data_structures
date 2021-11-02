#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int findLucky(vector<int>& arr) {
    vector<int> l{};
    // nobody said i cannot sort:
    sort(arr.begin(), arr.end());
    int a{arr[0]}, b{1};
    for (auto i{1}; i < arr.size(); i++) {
        if (arr[i] == a)
            b++;
        else {
            if (b == a) {
                l.push_back(a);
            }
            b = 0;
            a = arr[i];
            b++;
        }
    }
    int s(l.size());

    if (a == b) {
        return a;
    }

    return s > 0 ? l[s - 1] : -1;
}

int main() {
    vector<int> nums{19, 12, 11, 14, 18, 8, 6,  6,  13, 9, 8,
                     3,  10, 10, 1,  10, 5, 12, 13, 13, 9};
    cout << findLucky(nums);

    return 0;
}
