class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int p=nums2.size();
        if(n>p){
            return intersect(nums2,nums1);
        }
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums1[i]]++;
        }
        vector<int>v;
        for(int i=0;i<p;i++){
            if(m[nums2[i]]>0){
                v.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return v;
    }
};