class Solution {
public:
    unordered_map<string,bool> m; 
    bool isScramble(string s1, string s2) {
        string key=s1;
        key.push_back(' ');
        key.append(s2);
        if(m.find(key)!=m.end()){
            return m[key];
        }
       if(s1.size() != s2.size())   
            return false;
        if(s1.size()==0 && s2.size()==0)   
            return true;
        if(s1.compare(s2)==0)               
            return true;
        if(s1.size()<=1)                
            return false;
        bool flag=false;
        int n=s1.size();
        for(int i=1;i<n;i++){
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i))) || 
          (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))){
                flag=true;
                break;
        }
        }
        m[key]=flag;
        return flag;
    }
};