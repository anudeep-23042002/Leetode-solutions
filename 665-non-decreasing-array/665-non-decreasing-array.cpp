class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        int x=nums[0];
        for(int i=0; i<nums.size()-1; ++i) {
            if(x>nums[i+1]) { 
                count++;
                if(count>1) return false;
                if(i>0 && nums[i-1]>nums[i+1]) x=nums[i];
                else x=nums[i+1];
            }
            else x=nums[i+1];
        }
     return true;
    }
};