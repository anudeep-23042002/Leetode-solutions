class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>v;
        map<string,vector<string>>m;
        for(auto i:strs){
            string s=i;
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        for(auto i:m){
            v.push_back(i.second);
        }
        return v;
    }
};