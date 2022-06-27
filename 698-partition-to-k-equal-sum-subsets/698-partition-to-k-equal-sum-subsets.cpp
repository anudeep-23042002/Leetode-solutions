class Solution {
public:
    int maxi;
    bool solve(vector<int>& nums,int sum,int a,vector<bool>&vis,int k,int j){
        if(k==1){
            return true;
        }
        if(a==sum){
            if(solve(nums,sum,0,vis,k-1,0)){
                return true;
            }
            else{
                return false;
            }
        }
        else if(a>sum ){
            return false;
        }
        for(int i=j;i<nums.size();i++){
            if(!vis[i] && a+nums[i]<=sum){
                vis[i]=true;
                if(solve(nums,sum,a+nums[i],vis,k,i+1)){
                    return true;
                }
                vis[i]=false;
                if(a==0) {
                    return false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        maxi=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0){
            return false;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<bool>vis(n,false);
        return solve(nums,sum/k,0,vis,k,0);
    }
};