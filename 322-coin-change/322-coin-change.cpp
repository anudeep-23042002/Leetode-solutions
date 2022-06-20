class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>v(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;++j){
                if(i==0){
                    v[i][j]=INT_MAX-1;
                }
                else if(j==0){
                    v[i][j]=0;
                }
                else if(coins[i-1]>j){
                    v[i][j]=v[i-1][j];
                }
                else{
                    v[i][j]=min(v[i-1][j],1+v[i][j-coins[i-1]]);
                }
            }
        }
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            mi=min(mi,v[i+1][amount]);
        }
        if(mi==INT_MAX-1){
            return -1;
        }
        return mi;
    }
};