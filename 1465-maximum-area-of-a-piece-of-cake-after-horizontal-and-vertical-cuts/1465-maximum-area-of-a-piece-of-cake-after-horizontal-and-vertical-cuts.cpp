class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int ma=horizontalCuts[0];
        int n=horizontalCuts.size();
        for(int i=1;i<n;i++){
            ma=max(ma,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        ma=max(ma,h-horizontalCuts[n-1]);
        int mi=verticalCuts[0];
        int m=verticalCuts.size();
        for(int i=1;i<m;i++){
            mi=max(mi,verticalCuts[i]-verticalCuts[i-1]);
        }
        mi=max(mi,w-verticalCuts[m-1]);
        mi=mi%(1000000007);
        ma=ma%(1000000007);
        return (1ll*mi*ma)%(1000000007);
    }
};