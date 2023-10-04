// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

       int bb = prices[0];
       int bs = prices[0];

       int ans = 0;
       int bp = 0;

       for(int i = 1; i < n; ++i) {
            if(prices[i] < bb) {
                if(bp > 0) {
                    ans += bp;
                    bp = 0;
                }
                bb = prices[i];
                bs = prices[i];
            }

            if(prices[i] > bs) {
                bs = prices[i];
                bp = max(bp, bs - bb);
            } 

            if(prices[i] < bs && bp > 0) {
                ans += bp;
                bb = prices[i], bs = prices[i], bp = 0;
            }

       }

       bp = max(bp, bs - bb);
       return ans + bp;
    }
};