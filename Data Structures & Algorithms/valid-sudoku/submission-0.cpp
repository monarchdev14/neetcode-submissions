class Solution {
public:
    bool row_checker(vector<vector<char>> &board){
        vector<int> checker(10, 0);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!='.'){
                    if(checker[board[i][j]-'0']+1<=1){
                        checker[board[i][j]-'0']++;
                    }else{
                        return false;
                    }
                }
            }
            checker.assign(10,0);
        }
        return true;
    }
    bool col_checker(vector<vector<char>> &board){
        vector<int> checker(10,0);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[j][i]!='.'){
                    if(checker[board[j][i]-'0']+1<=1){
                        checker[board[j][i]-'0']++;
                    }else{
                        return false;
                    }
                }
            }
            checker.assign(10,0);
        }
        return true;
    }
    bool box_checker(vector<vector<char>> &board){
            for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                vector<int> freq(10, 0);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char cell = board[boxRow + i][boxCol + j];
                        if (cell == '.') {
                            continue;
                        }
                        if (cell >= '1' && cell <= '9') {
                            int digit = cell - '0';
                            if (freq[digit] > 0) {
                                return false;
                            }
                            freq[digit]++;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(row_checker(board)==false || col_checker(board)==false || box_checker(board)==false){
            return false;
        }else{
            return true;
        }
    }
};
