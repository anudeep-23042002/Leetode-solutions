class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int l1,r1,l2,r2;
       
        int r=n1;
        
        int mid1,mid2;
        double x=0;
        while(l<=r){
            mid1=l+((r-l)/2);
            mid2=((n1+n2)/2)-mid1;
            l1=mid1<=0?INT_MIN:nums1[mid1-1];
            l2=mid2<=0?INT_MIN:nums2[mid2-1];
            r1=mid1>=n1?INT_MAX:nums1[mid1];
            r2=mid2>=n2?INT_MAX:nums2[mid2];
            if(l1>r2){
                r=mid1-1;
            }
            else if(l2>r1){
                l=mid1+1;
            }
            else{
                if((n1+n2)%2==0){
                    return ((double)(max(l1,l2)+min(r1,r2))/2);
                }
                else{
                    return (double)min(r1,r2);
                }
            }
        }
        return x;
    }
};