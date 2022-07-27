class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n,1);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                v[i]=v[i+1]+1;
            }
        }
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                v[i]=max(v[i-1]+1,v[i]);
            }
        }
        for(auto i:v){
            cout<<i<<" ";
        }
        return accumulate(v.begin(),v.end(),0);
    }
};