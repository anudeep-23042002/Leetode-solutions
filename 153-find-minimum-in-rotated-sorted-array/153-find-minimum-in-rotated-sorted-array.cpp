class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0;
        int n=arr.size();
        if(arr[0]<=arr[n-1]){
            return arr[0];
        }
        int r=n-1;
        while(l<=r){
            int mid=l+((r-l)/2);
           
            if(arr[mid]>=arr[l] && arr[mid]<=arr[r]){
                return arr[l];
            }
            else if(arr[mid]>=arr[l]){
                l=mid+1;
            }
            else{
                r=mid;
            }
            
        }
        return arr[l];
    }
};