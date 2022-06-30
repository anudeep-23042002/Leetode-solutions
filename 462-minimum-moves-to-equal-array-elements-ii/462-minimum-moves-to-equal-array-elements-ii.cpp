class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum=0;
        int len=nums.size();
        for(auto x:nums)
            sum+=x;
        sort(nums.begin(),nums.end());
        long long lsum=0;
        long long minmove=INT_MAX;
        for(int i=0;i<len/2;i++)
            lsum+=nums[i]; 
        
        int count=sum-2*lsum;
        if(len&1)
            count+=nums[len/2]*(2*(len/2)-len);
        return count;
    }
};