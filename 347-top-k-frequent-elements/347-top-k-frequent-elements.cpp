class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>heap;
        for(auto i:m){
            heap.push({i.second,i.first});
        }
        for(int i=0;i<k;i++){
            v.push_back(heap.top().second);
            heap.pop();
        }
        return v;
    }
};