class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        int count=0,ma=1;
        for(int i=0;i<n;i++){
            if(m.find(nums[i]+1)==m.end()){
                int k=nums[i]-1;
                count=1;
                while(m.find(k)!=m.end()){
                    count+=1;
                    k-=1;
                }
                ma=max(ma,count);
            }
        }
        return ma;
    }
};