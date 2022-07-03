class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>ma(n,1);
        vector<int>mi(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]>nums[i]){
                    ma[i]=max(1+mi[j],ma[i]);
                }
                else if(nums[j]<nums[i]){
                     mi[i]=max(1+ma[j],mi[i]);
                }
            }
        }
        int m=1;
        for(int i=0;i<n;i++){
            m=max(m,max(ma[i],mi[i]));
        }
        return m;
    }
};