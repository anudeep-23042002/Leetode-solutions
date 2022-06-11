// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        int i=1,count=0;
        int index=1;
        while(n!=0){
            if(n&1){
                count+=1;
                index=i;
            }
            if(count>2) return -1;
            i+=1;
            n=n>>1;
        }
        return count==1?index:-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends