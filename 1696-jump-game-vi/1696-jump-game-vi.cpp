class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        int mi;
        dp[0]=nums[0];
        priority_queue<pair<int,int>,vector<pair<int,int>>>heap;
        heap.push({dp[0],0});
        for(int i=1;i<n;i++){
            while(heap.top().second<max(0,i-k)){
                heap.pop();
            }
            dp[i]=nums[i]+heap.top().first;
            heap.push({dp[i],i});
        }
        return dp[n-1];
    }
};