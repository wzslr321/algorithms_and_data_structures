class Solution {
public:
int findLucky(vector<int>& arr) {
    vector<int> l{};
    // nobody said i cannot sort 
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
};