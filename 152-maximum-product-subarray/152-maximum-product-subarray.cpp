class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int maxproduct=nums[0];
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(product==0){
                product=1;
            }
            product=product*nums[i];
            maxproduct=max(maxproduct,product);
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            if(product==0){
                product=1;
            }
            product=product*nums[i];
            maxproduct=max(maxproduct,product);
        }
        return maxproduct;
    }
};