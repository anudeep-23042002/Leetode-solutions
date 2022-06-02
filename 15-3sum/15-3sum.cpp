class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n=nums.size();
        int l,r,sum;
        for(int i=0;i<n;i++){
            l=i+1;
            r=n-1;
            while(l<r){
                sum=nums[l]+nums[r]+nums[i];
                if(sum==0){
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};