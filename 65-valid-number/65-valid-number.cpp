class Solution {
public:
    bool inte(string s){
        int n=s.size();
        int i=0;
        int j=0;
        if(n>1 && (s[i]=='+' || s[i]=='-') && (s[i+1]=='+' || s[i+1]=='-')){
            return false;
        }
        if(s[i]=='+' || s[i]=='-'){
            s=s.substr(1);
        }
        bool dig=false;
        for(i=0;i<s.size();i++){
            if(!isdigit(s[i])){
                return false;
            }
            else{
                dig=true;
            }
        }
        return dig;
    }
    bool dec(string s){
        int n=s.size();
        int i=0;
        if(n>1 && (s[i]=='+' || s[i]=='-') && (s[i+1]=='+' || s[i+1]=='-')){
            return false;
        }
        if(s[i]=='+' || s[i]=='-'){
            s=s.substr(1);
        }
        bool dig=false;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                if(i==n-1){
                    return true;
                }
                else if(!isdigit(s[i+1])){
                    return false;
                }
            }
            else if(isdigit(s[i])){
                dig=true;
            }
            else if(!isdigit(s[i])){
                return false;
            }
        }
        return dig;
    }
    bool uy(string s){
        bool dot=false;
        bool t=false,dig=false;
        int n=s.size();
        if(n>1 && (s[0]=='e' || s[0]=='E')){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                if(i==n-1 || ! s[i+1]=='+' || s[i+1]=='-'){
                    return false;
                }
                string h=s.substr(i+1);
                
                if((inte(h) || dec(h)) && i!=n-1){
                    return true;
                }
                
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(!dig){
                    return false;
                }
                if(inte(s.substr(i+1)) && i!=n-1){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(isdigit(s[i])){
                dig=true;
            }
            else{
                return false;
            }
        }
        if(!dig) return false;
        return true;
    }
    bool isNumber(string s) {
        int i=0;
        int n=s.size();
        string p=s;
        if(n==1 && !isdigit(s[0])){
            return false;
        } 
        if(n>1 && (s[i]=='+' || s[i]=='-') && (s[i+1]=='+' || s[i+1]=='-')){
            return false;
        }
        if(s[i]=='+' || s[i]=='-'){
            p=s.substr(1);
        }
        bool dot=false;
        bool t=false;
        bool dig=false;
        for(int i=0;i<n;i++){
            if(p[i]=='.'){
                if(dot) return false;
                else{
                    dot=true;
                }
            }
            if(p[i]=='e' || p[i]=='E'){
                if(t) return false;
                else{
                    t=true;
                }
            }
            if(isdigit(s[i])){
                dig=true;
            }
        }
        if(!dig) return false;
        if(dec(p) || inte(p)){
            return true;
        }
        for(int i=0;i<p.size();i++){
            if(p[i]=='e' || p[i]=='E'){
                return uy(p);
            }
        }
        return false;
    }
};