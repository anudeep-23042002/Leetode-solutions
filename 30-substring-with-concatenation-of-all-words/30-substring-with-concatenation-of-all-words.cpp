class Solution {
public:
    bool check(string s,map<string,int>words,int n,int w){
        auto m=words;
        string p;
        for(int i=0;i<n;i+=w){
            p=s.substr(i,w);
            if(m[p]>0){
                m[p]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        vector<int>v;
        int w=words[0].size();
        int k=n*w;
        
        map<string,int>m;
        for(auto i:words){
            m[i]++;
        }
        int y=s.size()-k;
        for(int i=0;i<=y;i++){
            if(check(s.substr(i,k),m,k,w)){
                v.push_back(i);
            }
        }
        return v;
    }
};