//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(int dist,vector<int>&v,int C){
        int cows=C-1;
        int N=v.size();
        int d=0;
        int index=0;
        for(int i=1;i<N;i++){
            d=v[i]-v[index];
            if(d>=dist){
                cows--;
                index=i;
            }
            if(cows==0)
                return true;
        }
    return false;
    }
    int solve(int N, int C, vector<int> &v) {
        sort(v.begin(),v.end());
        int l=1;
        int r=v[N-1]-v[0];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            //cout<<mid<<" "<<l<<" "<<r<<endl;
            if(check(mid,v,C)){
                //cout<<"k"<<mid<<endl;
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends