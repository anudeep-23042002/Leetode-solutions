class Solution {
public:
    vector<int>v,k;
    int n=0;
    Solution(vector<int>& nums) {
        n=nums.size();
        for(auto i:nums){
            v.push_back(i);
            k.push_back(i);
        }
    }
    
    vector<int> reset() {
        return k;
    }
    
    vector<int> shuffle() {
        int k=rand() % n;
        int s=k;
        while(s==k){
            s=rand()%n;
        }
         cout<<k<<" "<<s<<endl;
        swap(v[k],v[s]);
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */