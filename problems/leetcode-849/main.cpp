// https://leetcode.com/problems/maximize-distance-to-closest-person/description/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
       size_t N = seats.size();
       bool canBeOnLeft = seats[0] == 0;
       bool canBeOnRight = seats[N - 1] == 0;
       auto maxl = 0, maxr = 0, maxm = 0;
       if(canBeOnLeft) {
           for(size_t i = 0; i < N; ++i) {
              if(seats[i] != 0)  break;
               ++maxl;
           }
       }
       if(canBeOnRight) {
           for(int i = N - 1; i  >= 0; --i) {
              if(seats[i] != 0)  break;
              ++maxr;
           }
       }
       for(size_t i = 0; i < N; ++i)  {
           auto curr = 0;
           while(i < N && seats[i] == 0) {
               ++curr;
               ++i;
           }
           maxm = max(curr, maxm);
       }
       maxm += 2;
       if(!(maxm & 1)) --maxm;
       return max(maxl, max((maxm / 2), maxr));
    }
};