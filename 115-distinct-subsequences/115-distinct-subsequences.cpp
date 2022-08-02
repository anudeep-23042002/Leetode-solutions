class Solution {
public:
    int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7; 
        int n=s.size();
        int m=t.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=1;
                }
                else if(j==0){
                    dp[i][j]=0;
                }
                else if(t[i-1]==s[j-1]){
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};