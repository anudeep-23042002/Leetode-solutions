class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int,vector<int>>heap;
        int n=nums.size();
        if(n==1){
            return;
        }
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
        }
        for(int i=1;i<n;i+=2){
            nums[i]=heap.top();
            heap.pop();
        }
        for(int i=0;i<n;i+=2){
            nums[i]=heap.top();
            heap.pop();
        }
        return;
    }
};