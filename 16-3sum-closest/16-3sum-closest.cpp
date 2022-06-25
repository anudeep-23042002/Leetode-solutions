class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0,k;
        int s=nums[0]+nums[1]+nums[2];
        int ma=abs(s-target);
        for(int i=0;i<n;i++){
            sum=target-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                k=nums[l]+nums[r];
                if(k==sum){
                    return target;
                }
                else if(k>sum){
                    r--;
                }
                else{
                    l++;
                }
                if(abs(k+nums[i]-target)<ma){
                    s=k+nums[i];
                    ma=abs(k+nums[i]-target);
                }
            }
        }
        return s;
    }
};