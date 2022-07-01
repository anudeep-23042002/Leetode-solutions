class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int cnt=0;
        int dis=0,lastjump=0;
        for(int i=0;i<=dis;i++){
            dis=max(i+nums[i],dis);
            if(i==lastjump){
                cnt++;
                lastjump=dis;
            }    
            if(lastjump>=nums.size()-1)break;
        }
        return cnt;
    }
};