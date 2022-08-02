class Solution {
public:
    int hist(vector<int>A){
    int n=A.size();
    if(n==1){
        return A[0];
    }
    vector<int>v(n,1);
    stack<int>s;
    int ma=0;
    s.push(0);
    for(int i=0;i<n;i++){
        ma=max(A[i],ma);
            while(!s.empty() && A[s.top()]>=A[i]){
                    s.pop();
                }
            v[i]=s.empty()?0:s.top()+1;
            s.push(i);
        
    }
    while(!s.empty()){
        s.pop();
    }
    vector<int>w(n,1);
    for(int i=n-1;i>=0;i--){
        
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            w[i]=s.empty()?n-1:s.top()-1;
            s.push(i);
        
    }
    ma=0;
    for(int i=0;i<n;i++){
        ma=max(abs(w[i]-v[i]+1)*A[i],ma);
    }
    return ma;
    }
    int maximalRectangle(vector<vector<char>>& A) {
        int n=A.size();
    int m=A[0].size();
    int ma=INT_MIN;
        vector<int>v(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='1'){
                v[j]+=1;
            }
            else{
                v[j]=0;
            }
        }
        ma=max(ma,hist(v));
    }
    return ma;
    }
};