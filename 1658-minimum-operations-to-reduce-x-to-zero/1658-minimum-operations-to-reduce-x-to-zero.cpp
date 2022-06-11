class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        if(n==1){
            return nums[0]==x?1:-1;
        }
        int l=0;
        int r=1;
         int ma=INT_MAX;
        int target=accumulate(nums.begin(),nums.end(),0)-x;
        if(target==0){
            return n;
        }
        if(target<0){
            return -1;
        }
        if(nums[l]==target){
            ma=n-1;
        }
        int sum=nums[l]+nums[r];
       
        while(l<=r && r<n && l<n){
            
            if(sum<target){
                r++;
                if(r<n && l!=r) sum=sum+nums[r];
            }
            else if(sum>target){
                sum=sum-nums[l];
                l++;
            }
            else{
                ma=min(l+n-r-1,ma);
                r++;
                if(r<n && l!=r) sum=sum+nums[r];
            }
            if(l>r && r!=n-1){
                r++;
                if(r<n && l!=r) sum=sum+nums[r];
            }
        }
        return ma==INT_MAX?-1:ma;
    }
};