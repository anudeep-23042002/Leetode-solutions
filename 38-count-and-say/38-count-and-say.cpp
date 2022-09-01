class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s="";
        string b=countAndSay(n-1);
        int y=b.size();
        char r=b[0];
        int count=1;
        for(int i=1;i<y;i++){
            if(b[i]==r){
                count+=1;
            }
            else{
                s=s+to_string(count)+r;
                r=b[i];
                count=1;
            }
        }
        if(count>0){
            s=s+to_string(count)+r;
        }
        return s;
    }
};