class Solution {
public:
int maxProfit(vector<int>& prices) {
    int min{prices[0]}, max{0}, inmin{0};
    int cr_pr{};
    for (auto i{1}; i < prices.size(); i++) {
        if (prices[i] < min) {
            min = prices[i];
            inmin = i;
            max = 0;
        }
        if (prices[i] > max && i > inmin) max = prices[i];
        if (max - min > cr_pr) {
            cr_pr = max - min;
        }
    }
    return cr_pr > 0 ? cr_pr : 0;
}
};