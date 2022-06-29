// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&A){
    //Write your code here..
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

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends