class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,1);
        int product=1;
        for(int i=0;i<n-1;i++){
            v[i]=product;
            product=product*nums[i];
     
        }
        v[n-1]=product;
        product=nums[n-1];
        for(int i=n-2;i>=1;i--){
            v[i]=product*v[i];
            product=product*nums[i];
        }
        v[0]=product;
        return v;
    }
};