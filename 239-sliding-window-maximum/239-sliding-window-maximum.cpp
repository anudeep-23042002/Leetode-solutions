class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>heap;
        for(int i=0;i<k;i++){
            heap.push({nums[i],i});
        }
        int n=nums.size();
        vector<int>v(n-k+1,0);
        v[0]=heap.top().first;
        for(int i=1;i+k-1<n;i++){
            heap.push({nums[i+k-1],i+k-1});
            auto p=heap.top();
            while(heap.top().second<i){
                heap.pop();
            }
            v[i]=heap.top().first;
        }
        return v;              
    }
};