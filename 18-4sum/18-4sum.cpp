class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long int k;
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int sum=target-nums[i];
                sum=sum-nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    k=nums[l]+nums[r];
                    if(k>sum){
                        r--;
                    }
                    else if(k<sum){
                        l++;
                    }
                    else{
                        int p=nums[l];
                        int q=nums[r];
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l<r && nums[l] == p)
                            ++l;
                        while (l<r && nums[r] ==q)
                            --r;
                    }   
                }
                while (j<n-1 && nums[j]==nums[j+1])
                    ++j;
            }
            while (i<n-1 && nums[i+1]==nums[i])
                ++i;
        }
        return ans;
    }
};