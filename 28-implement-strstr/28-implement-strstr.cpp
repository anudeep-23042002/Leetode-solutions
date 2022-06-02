class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==" "){
            return 0;
        }
        int j=0;
        int n=needle.size();
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[j]){
                j+=1;
            }
            else{
                i=i-j;
                j=0;
            }
            if(j==n){
                return i-j+1;
            }
        }
        return -1;
    }
};