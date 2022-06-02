class Solution {
public:
    bool checkpar(string p){
        stack<int>s;
        for(auto i:p){
            if(i=='('){
                s.push('(');
            }
            else if(!s.empty()){
                s.pop();
            }
            else{
                return false;
            }
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
    void solve(int open,int close,string s,vector<string>&v,int n){
        
        if(open==n && close==n && checkpar(s)){
            v.push_back(s);
            return;
        }
        if(open<=n) solve(open+1,close,s+'(',v,n);
        if(close<=n)solve(open,close+1,s+')',v,n);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        solve(0,0,s,v,n);
        return v;
    }
};