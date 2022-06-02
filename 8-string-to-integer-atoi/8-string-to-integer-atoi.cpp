class Solution {
public:
    
    int myAtoi(string s) {
        int i=0;
        bool f=false;
        bool g=false;
        int n=s.size();
        while(i<n && (s[i]==' ')){
            i+=1;
        }
        if(i<n && s[i]=='-'){
            f=true;
            i+=1;
        }
        else if(i<n && s[i]=='+'){
            f=false;
            i+=1;
        }
        int num=0;
        while(i<n && isdigit(s[i])){
            int k=s[i]-'0';
            if(num>(INT_MAX/10) || (num==INT_MAX/10 && k>7 )){
                if(f){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
            num=10*num+k;
            i+=1;
        }
        if(f){
            num=-1*num;
        } 
        
        return num;
    }
};