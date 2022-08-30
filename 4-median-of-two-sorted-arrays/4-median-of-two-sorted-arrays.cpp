class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        if(n>m){
            return findMedianSortedArrays(B,A);
        }
        int l1=0,r1=n;
        int a1,b1,a2,b2;
        int mid1,mid2;
        while(l1<=r1){
            mid1=l1+((r1-l1)/2);
            mid2=((n+m)/2)-mid1;
            a1=mid1>0?A[mid1-1]:INT_MIN;
            a2=mid1<n?A[mid1]:INT_MAX;
            b1=mid2>0?B[mid2-1]:INT_MIN;
            b2=mid2<m?B[mid2]:INT_MAX;
            if(a1>b2){
                r1=mid1-1;
            }
            else if(b1>a2){
                l1=mid1+1;
            }
            else{
                if((n+m)%2!=0){
                    return min(a2,b2);
                }
                else{
                    int w=max(a1,b1);
                    int y=min(a2,b2);
                    return (w+y+0.00)/2;
                }
            }
        }
        return -1;
    }
};