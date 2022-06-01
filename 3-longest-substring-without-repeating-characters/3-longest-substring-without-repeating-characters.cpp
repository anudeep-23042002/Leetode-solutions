class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int n=s.size();
        if(n<=1){
            return n;
        }
        int prev=0;
        int ma=0;
        for(int i=0;i<n;i++){
            if(m.count(s[i])>0){
               prev=max(m[s[i]]+1,prev);
               m[s[i]]=i;
            }
            else{
                m[s[i]]=i;
            }
            ma=max(i-prev+1,ma);
        }
        return ma;
    }
};