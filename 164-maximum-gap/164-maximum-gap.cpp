class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        if(n==2){
            return abs(nums[0]-nums[1]);
        }
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            ma=max(nums[i],ma);
            mi=min(nums[i],mi);
        }
        int p=ceil((ma-mi+0.0)/(n-1));
        vector<int>bucket_mi(n-1,INT_MAX);
        vector<int>bucket_ma(n-1,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==mi || nums[i]==ma) continue;
            int index=(nums[i]-mi)/p;
            bucket_mi[index]=min(nums[i],bucket_mi[index]);
            bucket_ma[index]=max(nums[i],bucket_ma[index]);
        }
        int a=0;
        int prev=mi;
        for(int i=0;i<bucket_mi.size();i++){
            if(bucket_ma[i]==-1){
                continue;
            }
            a=max(bucket_mi[i]-prev,a);
            prev=bucket_ma[i];
        }
        a=max(ma-prev,a);
        return a;
    }
};