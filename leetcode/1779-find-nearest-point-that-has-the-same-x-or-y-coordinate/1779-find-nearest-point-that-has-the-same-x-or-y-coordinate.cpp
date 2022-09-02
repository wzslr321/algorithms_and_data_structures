class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        auto best = make_pair(INT_MAX, INT_MAX);
        for(size_t i = 0; i < points.size(); ++i) {
           if(points[i][0] == x || points[i][1] == y)  {
               auto mh = abs(x - points[i][0]) + abs(y - points[i][1]);
               if(mh < best.second) 
                   best = {i, mh};
           }
        }
        
        if(best.first != INT_MAX) return best.first;
        return -1;
    }
};