class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int p=0,k;
        for(int i=n-1;i>=0;i--){
            k=(columnTitle[i]-'A'+1)*pow(26,n-i-1);
            p=p+k;
        }
        return p;
    }
};