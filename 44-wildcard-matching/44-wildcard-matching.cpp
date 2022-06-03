class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(j==0){
                    dp[i][j]=false;
                }
                else if(i==0){
                    bool f=true;
                    for(int z=1;z<=j;z++){
                        if(p[z-1]!='*') f=false;
                    }
                    dp[i][j]=f;
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='?') {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};