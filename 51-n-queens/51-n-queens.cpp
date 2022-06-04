class Solution {
public:
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
    void solve(int p,vector<vector<char>>&v,int n,vector<vector<string>>&ans){
        if(p==n){
            vector<string>k;
            for(int i=0;i<n;i++){
                string s="";
                for(int j=0;j<n;j++){
                    s=s+v[i][j];
                }
                k.push_back(s);
            }
            ans.push_back(k);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(i,p,v,n)){
                v[i][p]='Q';
                solve(p+1,v,n,ans);
                v[i][p]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>v(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        solve(0,v,n,ans);
        return ans;
    }
};