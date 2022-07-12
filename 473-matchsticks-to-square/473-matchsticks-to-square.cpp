class Solution {
public:
    bool solve(vector<int>& matchsticks,vector<int>&vis,int sum,int p,int n,int j,int k){
        if(j==0){
            return true;
        }
        if(sum==k){
            return solve(matchsticks,vis,0,0,n,j-1,k);
        }
        for(int i=p;i<n;i++){
            if(vis[i] || matchsticks[i]+sum>k){
                continue;
            }
            vis[i]=true;
            if(solve(matchsticks,vis,sum+matchsticks[i],i+1,n,j,k)){
                return true;
            }
            vis[i]=false;
            
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
         int n=matchsticks.size();
        if(sum%4!=0 || n<4){
            return false;
        }
        sum=sum/4;
       
        vector<int>vis(n,false);
        return solve(matchsticks,vis,sum,0,n,4,sum);
    }
};