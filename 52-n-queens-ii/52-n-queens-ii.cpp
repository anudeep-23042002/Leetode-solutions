class Solution {
public:
    int ans=0;
    bool check(int r,int c,vector<vector<char>>v,int n){
        for(int i=0;i<n;i++){
            if(v[r][i]=='Q'){
                return false;
            }
    }
        for(int i=r, j=c; i>=0 && j>=0; --i, --j){
            if(v[i][j]=='Q')
               return false;
   }
        for(int i=r, j=c; i<n && j>=0; ++i, --j){
            if(v[i][j]=='Q')
               return false;
   }
        return true;
    }
    void solve(int p,vector<vector<char>>&v,int n){
        if(p==n){
            ans+=1;
            return;
        }
        for(int i=0;i<n;i++){
            if(check(i,p,v,n)){
                v[i][p]='Q';
                solve(p+1,v,n);
                v[i][p]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>>v(n,vector<char>(n,'.'));
        ans=0;
        solve(0,v,n);
        return ans;
    }
};