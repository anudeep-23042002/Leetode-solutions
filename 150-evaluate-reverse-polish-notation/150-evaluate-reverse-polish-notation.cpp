class Solution {
public:
    bool isop(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            return true;
        }
        return false;
    }
    int operation(int a,int b,string s){
        if(s=="+"){
            return a+b;
        }
        else if(s=="-"){
            return a-b;
        }
        else if(s=="*"){
            return a*b;
        }
        return a/b;
    }
    int evalRPN(vector<string>&v) {
        stack<int>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(isop(v[i])){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(operation(b,a,v[i]));
            }
            else{
                s.push(stoi(v[i]));
            }
        }
        return s.top();
    }
};