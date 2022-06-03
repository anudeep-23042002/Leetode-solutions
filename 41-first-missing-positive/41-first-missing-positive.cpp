class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(auto i:nums){
            if(i>0){
                p.push(i);
            }
        }
        
        if(!p.empty() && p.top()!=1){
            return 1;
        }
        
        int j=1;
        while(!p.empty() && j==p.top()){
            while(!p.empty() && j==p.top()){
                p.pop();
            }
            j+=1;
        }
        return j;
    }
};