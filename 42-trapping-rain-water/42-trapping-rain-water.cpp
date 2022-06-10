class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2){
            return 0;
        }
        int maxleft=height[0];
        int maxright=height[n-1];
        int l=1;
        int r=n-2;
        int water=0;
        while(l<=r){
            if(maxleft<maxright){
                if(height[l]>maxleft) maxleft=height[l];
                else{
                    water=water + maxleft-height[l];
                }
                l++;
            }
            else{
                if(height[r]>maxright) maxright=height[r];
                else{
                    water=water + maxright-height[r];
                }
                r--;
            }
        }
        return water;
    }
};