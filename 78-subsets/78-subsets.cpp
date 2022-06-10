class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        for(int mask=0;mask<1<<n;mask++){
            vector<int>d;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)) d.push_back(nums[j]);
            }
            v.push_back(d);
        }
        return v;
    }
};