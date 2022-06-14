class Solution {
public:
    int m=0;
    void solve(vector<int>& cookies,vector<int>&child,int c){
        if(c==cookies.size()){
            int p=*max_element(child.begin(),child.end());
            m=min(m,p);
            return;
        }
        for(int i=0;i<child.size();i++){
            child[i]+=cookies[c];
            solve(cookies,child,c+1);
            child[i]-=cookies[c];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>v(k,0);
        m=INT_MAX;
        solve(cookies,v,0);
        return m;
    }
};