class Solution {
public:
    int numDecodings(string A) {
        int n=A.size();
    vector<int>dp(n+1,0);
    dp[0]=1;
    if(A[0]=='0')
        dp[1]=0;
    else {
        dp[1]=1;
    }
    for(int i=2;i<=n;i++){
        int a=0,b=0;
        if(A[i-1]!='0'){
            b=dp[i-1];
        }
        string c="";
        for(int j=i-2;j<i;j++){
            c=c+A[j];
        }
        if(stoi(c)<=26 && stoi(c)>0 && A[i-2]!='0'){
            a=dp[i-2];
        }
        dp[i]=a+b;
    }
    return dp[n];
    }
};