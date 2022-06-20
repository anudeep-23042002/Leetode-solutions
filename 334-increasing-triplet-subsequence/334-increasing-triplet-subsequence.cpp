class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        vector<int>w(n,INT_MAX);
        int ma=INT_MIN;
        for(int i=n-1;i>=0;i--){
            ma=max(ma,nums[i]);
            v[i]=ma;
        }
        ma=INT_MAX;
        for(int i=0;i<n;i++){
            ma=min(ma,nums[i]);
            w[i]=ma;
            
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>w[i] && nums[i]<v[i]){
                return true;
            }
        }
        return false;
    }
};