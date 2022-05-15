class Solution {
public:
    string toLowerCase(string s) {
        for(auto &c : s){
            if(c < 91 && c > 64){
                c += 32;
            }
        }
        
        return s;
    }
};