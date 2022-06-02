class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ma=0;
        int m=0;
        int area=0;
        while(i<j){
            m=min(height[i],height[j]);
            area=m*(j-i);
            ma=max(area,ma);
            if(height[i]<height[j]){
                i=i+1;
            }
            else{
                j=j-1;
            }
        }
        return ma;
    }
};