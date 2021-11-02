#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // comments are values on iterations

    // 0 --> 0
    int first{0};

    //  6 --> 3
    int last{n + m};

    // 3 --> 1 ( nums1[in] >= nums2[mid]) - insert and pop last, in++
    //
    int mid{(first + last) / 2};

    int in{0};

    while (in != n) {
        if (nums1[in] > nums2[mid]) {
            first = mid;
            mid = (first + last) / 2;
        } else if (nums1[in] < nums2[mid]) {
            last = mid;
            mid = (first + last) / 2;
        }

        if (nums1[in] >= nums2[mid] && nums1[in] <= nums2[mid]) {
            nums1.insert(nums1.begin() + mid, nums2[in]);
            nums1.pop_back();
            in++;
        }
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m{3}, n{3};

    merge(nums1, m, nums2, n);

    for (auto i{0}; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
