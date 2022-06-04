class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        int n=nums.size();
        if(n==1){
            return true;
        }
        for(int i=0;i<n;i++){
            if(maxreach>=n-1){
                return true;
            }
            if(i==maxreach && nums[i]==0){
                return  false;
            }
            else{
                maxreach=max(maxreach,i+nums[i]);
            }
        }
         if(maxreach>=n){
                return true;
            }
        return false;
    }
};