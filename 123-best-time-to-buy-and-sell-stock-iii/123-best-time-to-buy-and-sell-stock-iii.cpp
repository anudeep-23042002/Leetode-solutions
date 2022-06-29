class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n=A.size();
    vector<int>left(n,0);
    int ma=0;
    int mi=A[0];
    for(int i=1;i<n;i++){
        mi=min(mi,A[i]);
        ma=max(ma,A[i]-mi);
        left[i]=ma;
    }
    vector<int>right(n,0);
    ma=0;mi=A[n-1];
    for(int i=n-1;i>0;i--){
        mi=max(mi,A[i]);
        ma=max(ma,mi-A[i]);
        right[i]=ma;
        
    }
    ma=0;
    for(int i=0;i<n;i++){
        ma=max(ma,left[i]+right[i]);
    }
    return ma;
    }
};