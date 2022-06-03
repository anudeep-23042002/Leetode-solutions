class Solution {
public:
    bool solve(int r,int c,vector<vector<char>>& board){
        map<char,int>m;
        for(int i=0;i<9;i++){
            if(isdigit(board[r][i])){
                if(m.find(board[r][i])!=m.end()){
                    return false;
                }
                m[board[r][i]]=1;
            }
        }
        m.clear();
        for(int i=0;i<9;i++){
            if(isdigit(board[i][c])){
                if(m.find(board[i][c])!=m.end()){
                    return false;
                }
                m[board[i][c]]=1;
            }
        }
        m.clear();
        for(int i=0;i<9;i++){
            if(isdigit(board[3*(r/3)+i/3][3*(c/3)+i%3])){
                if(m.find(board[3*(r/3)+i/3][3*(c/3)+i%3])!=m.end()){
                    return false;
                }
                m[board[3*(r/3)+i/3][3*(c/3)+i%3]]=1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.' && !solve(i,j,board)){
                        return false;
                    }
                }
            }
        
        return true;
    }
};