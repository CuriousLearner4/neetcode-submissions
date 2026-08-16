class Solution {
    bool check(int r,int c, vector<vector<char>>& board){
        int n = board.size();
        bool found = false;
        char toBeSearched = board[r][c];

        for(int i = 0 ; i < n ; ++i ){
            if(i!=r && board[i][c] == toBeSearched) return true;
        }
        
        for(int i = 0 ; i < n ; ++i ){
            if(i!=c && board[r][i] == toBeSearched) return true;
        }

        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i = sr ; i<sr+3; ++i){
            for(int j = sc; j<sc+3; ++j){
                if((i != r || j != c) && board[i][j]==toBeSearched) return true;
            }
        }

        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i = 0 ; i < n; ++i){
            for(int j = 0 ; j < n; ++j){
                if(board[i][j]!='.' && check(i,j,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
