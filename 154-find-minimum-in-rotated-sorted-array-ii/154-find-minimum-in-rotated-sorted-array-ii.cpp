class Solution {
public:
    int bt(vector<int>arr,int l,int r){
        int n=r-l+1;
        if(n==1){
            return arr[0];
        }
        if(arr[0]<arr[r]){
            return arr[0];
        }
        while(l<=r){
            int mid=l+((r-l)/2);
            
            if(mid==l){
                if(arr[mid]<=arr[r]) return arr[l];
                else{
                    l=mid+1;
                }
            }
            else if(arr[mid]==arr[l] && arr[r]==arr[mid]){
                return min(bt(arr,l,mid),bt(arr,mid+1,r));
            }
            
            else if(arr[mid]>=arr[l] && arr[mid]<=arr[r]){
                return arr[l];
            }
            else if(arr[mid]>=arr[l]){
                l=mid+1;
            }
            else{
                r=mid;
            }
            
        }
        return arr[r];
    }
    int findMin(vector<int>& arr) {
        int l=0;
        int n=arr.size();
        int r=n-1;
        if(n==1){
            return arr[0];
        }
        if(arr[0]<arr[r]){
            return arr[0];
        }
        return bt(arr,0,n-1);
    }
};