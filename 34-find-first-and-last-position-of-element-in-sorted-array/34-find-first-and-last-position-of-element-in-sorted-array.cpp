class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int r=n-1;
    while(l<=r){
        int i=l+(r-l)/2;
        if(nums[i]==x){
            int j=i;
            int k=i;
            while(j<n && nums[j]==x){
                j+=1;
            }
            while(k>=0 && nums[k]==x){
                k-=1;
            }
            
            if(j>n){
                j=n;
            }
            return {k+1,j-1};
        }
        else if(nums[i]>x){
            r=i-1;
        }
        else{
            l=i+1;;
        }
    }
    return {-1,-1};
    }
};