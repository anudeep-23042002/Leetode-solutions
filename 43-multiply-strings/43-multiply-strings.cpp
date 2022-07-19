class Solution {
public:
    string multiply(string A, string B) {
        if(A=="0" || B=="0"){
            return "0";
        }
        int n=A.size();
        int m=B.size();
    vector<int>v(n+m,0);
    for(int i=n-1;i>=0;i--){
        int carry=0;
        for(int j=m-1;j>=0;j--){
            v[i+j+1]+=carry+(A[i]-'0')*(B[j]-'0');
            v[i+j]+=v[i+j+1]/10;
            v[i+j+1]=v[i+j+1]%10;
        }
    }
    int j=0;
    while(j<v.size() && v[j]==0){
        j++;
    }
    string s="";
    for(int i=j;i<v.size();i++){
        s=s+to_string(v[i]);
    }
    return s;
    }
};