class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> candy(n,1);
        for(int i=1;i<n;i++){
            if(arr[i-1] < arr[i]){
                candy[i] = candy[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                candy[i] = max(candy[i],candy[i+1] + 1);
            }
        }
        int ans = accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};