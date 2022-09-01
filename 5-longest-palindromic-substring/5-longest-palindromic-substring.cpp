class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ma=1;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int l=0;
        int r=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(ma==1){
                    l=i;
                    r=i+1;
                    ma=2;
                }
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0,j=k-1;j<n;i++,j++){
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(ma<k){
                        l=i;
                        r=j;
                        ma=k;
                    }
                }
            }
        }
        return s.substr(l,r-l+1);

    }
};