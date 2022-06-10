class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(vector<vector<char>>& board,string word,vector<vector<bool>>&vis,int r,int c,int p,int w,int n,int m){
        if(p>=w){
            return true;
        }
        vis[r][c]=true;
        
        for(int i=0;i<4;i++){
                int x=r+dir[i][0];
                int y=c+dir[i][1];
                if(x<n && y<m && x>=0  && y>=0 && vis[x][y]==false && board[x][y]==word[p]){
                    vis[x][y]=true;
                    if(solve(board,word,vis,x,y,p+1,w,n,m)){
                        return true;
                    }
                    vis[x][y]=false;
                }
            }
        vis[r][c]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int w=word.size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(board,word,vis,i,j,1,w,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};