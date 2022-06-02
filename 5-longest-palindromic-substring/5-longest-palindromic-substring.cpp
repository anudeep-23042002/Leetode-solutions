class Solution {
public:
    string longestPalindrome(string s) {
        int x=0;
        int y=0;
        int n = s.size();
        bool dp[n+1][n+1];
        memset(dp, false, sizeof(dp));
        for(int len = 0; len<n; len++){
            for(int i=0, j=len; j<n; i++, j++){
               if(len == 0) {
                  dp[i][j] = true;               
            }
            else if(len == 1 and s[i] == s[j]){ 
                    dp[i][j] = true;
                    x=i;
                    y=j;                
            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1]==true){
                    dp[i][j] = true;
                    x=i;
                    y=j;
                }              
            }
        }
    }    
         return s.substr(x, y-x+1);

    }
};