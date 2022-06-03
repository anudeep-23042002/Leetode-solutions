class Solution {
public:
    void solve(vector<int>&nums,vector<int>&v,vector<vector<int>>&p,vector<bool>&vis,int d,int n){
        if(d==n){
            p.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                v.push_back(nums[i]);
                solve(nums,v,p,vis,d+1,n);
                v.pop_back();
                vis[i]=false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>p;
        vector<bool>vis(n,false);
        vector<int>v;
        solve(nums,v,p,vis,0,n);
        return p;
    }
};