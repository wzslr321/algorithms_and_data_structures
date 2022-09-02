class Solution {
public:
    bool squareIsWhite(string coordinates) {
        vector<vector<char>> board(8, vector<char>(8));
        auto lc = true;
        for(int i = 0; i < 8; ++i) {
            auto lcc = lc ?  true : false;
            for(int j = 0; j < 8; ++j) {
                board[i][j] = lcc ? 'w' : 'b';
                lcc = !lcc;
            }
            lc = !lc;
        }
        int i = coordinates[0] - 97;
        int j = coordinates[1] - 49;
        i = 7 - i; 
        
        return board[i][j] == 'w' ? true : false;
    }
};