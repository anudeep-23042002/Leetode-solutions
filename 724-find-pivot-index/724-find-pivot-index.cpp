class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size()-1;
        int suml=0,sumr=accumulate(nums.begin()+1,nums.end(),0);
        if(suml==sumr)
            return 0;
        for(int i=1;i<=n;i++)
        {
            suml+=nums[i-1];
            sumr-=nums[i];
            if(suml==sumr)
                return i;
        }
        return -1;
    }
};