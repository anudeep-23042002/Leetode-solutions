class Solution {
public:
    int minDeletions(string s) {
        map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;++i){
            m[s[i]]++;
        }
        map<int,int>mp;
        int ans=0;
        for(auto x:m){
            int a=x.second;
            while(mp.find(a)!=mp.end())
            {
                ans++;
                a--;
            }
        if(a!=0)
           mp[a]++;
        
        }
        return ans;
    }
};