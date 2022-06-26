class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int ans=sum;
        for (int i = 0; i < k; i++) {
            sum+=cardPoints[n-i-1];
            sum-=cardPoints[k-i-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};