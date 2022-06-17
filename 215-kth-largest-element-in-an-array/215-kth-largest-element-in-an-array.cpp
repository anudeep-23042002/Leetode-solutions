class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>heap;
        for(int i=0;i<nums.size();i++){
            heap.push(nums[i]);
        }
        for(int i=1;i<k && !heap.empty();i++){
            heap.pop();
        }
        if(heap.empty()){
            return -1;
        }
        return heap.top();
    }
};