class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i <target; i++) {
            if (!dp[i]) continue;
            for (int num : nums)
                if (num + i <= target) dp[i+num] += dp[i];
        }
        return dp[target];
    }
};