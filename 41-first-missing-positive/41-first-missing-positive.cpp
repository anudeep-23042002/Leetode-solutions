class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==INT_MIN){
                continue;
            }
            int pos=nums[i]-1;
            while(pos<n && pos>=0 && nums[i]!=nums[pos]){
                swap(nums[i],nums[pos]);
                pos=nums[i]-1;
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};