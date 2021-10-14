#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

/*
 *
 *      static int inc {2};
 *
 *      static int i  = vector.size() / 2 
 *      
 * Check if target > vector[i-1] and target < vector[i+1]
 *    if 
 *       if target < vector[i]
 *          return i;
 *       else 
 *          return i + 1; 
 *
 *    else 
 *      inc *= 2;
 *      if target < vector [i-1]
 *          i += vector.size() / inc 
 *      else 
 *          i -= vector.size() / inc     
 *      // recursion, with differenc inc and index because it is static 
 *      return func(vector, target); 
 *
 *  example of this thinking:
 *
 *      index -  0 1 2 3 4 5  6  7  8  9
 *
 *               1 3 5 7 9 14 17 20 22 23
 *
 *      i = 9 / 2 = 4
 *      target = 18 --- expected = 7 --> after 17, before 20 
 *      vector[i] = 9
 *
 *      target > vector[i-1] (7) 
 *         i += 9 / 4 = 4 + 2 = 6 
 *       
 *      vector[i] = 17
 *      target > vector[i-1] (14) and target < vector[i+1](20)
 *          target > vector[i]
 *              return i + 1
 *
 *      7 returned here
 *


int searchInsert(vector<int>& nums, int target) {
    if (target == 0) return 0;
    static auto i{nums.size() / 2};
    if (i + 1 >= nums.size()) return i + 1;
    if (target > nums[i - 1] && target < nums[i + 1]) {
        return i;
    } else {
        if (target > nums[i + 1]) {
            i += nums.size() / 4;
        } else {
            i -= nums.size() / 4;
        }
        return searchInsert(nums, target);
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5, 6};
    vector<int> nums2 = {1};

    auto target1{5};
    auto target2{2};
    auto target3{7};
    auto target4{0};
    auto target5{0};

    cout << searchInsert(nums1, target4) << '\n';

    // assert((searchInsert(nums1, target1), 2));
    // assert((searchInsert(nums1, target2), 1));
    // assert((searchInsert(nums1, target3), 4));
    assert((searchInsert(nums1, target4), 0));
    // assert((searchInsert(nums2, target5), 0));

    return 0;
}
