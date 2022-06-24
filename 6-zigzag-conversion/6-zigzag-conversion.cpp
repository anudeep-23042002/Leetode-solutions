class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        string str[numRows];
        for(int i=0;i<numRows;i++)
        {
            str[i]="";
        }
        int n = s.length();
        int idx = 0;
        int flag= 0;
        for(auto i: s){
            str[idx] += i;
            if(idx<numRows-1 && flag==0)
            {
                idx++;
            }
            else{
                idx--;
            }
            if(idx == numRows-1 && flag==0){
                flag=1;
            }
            if(idx==0 && flag==1){
                flag=0;
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=str[i];
        }
        return ans;
    }
};