class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v;
        int temp=0;
        int total=n*m;
        int top=0,left=0,right=m-1,bottom=n-1;
        while(temp<total){
            for(int i=left;i<=right && temp<total;i++){
                v.push_back(matrix[top][i]);
                temp++;
            }
            top++;
            for(int i=top;i<=bottom && temp<total;i++){
                v.push_back(matrix[i][right]);
                temp++;
            }
            right--;
            for(int i=right;i>=left && temp<total;i--){
                v.push_back(matrix[bottom][i]);
                temp++;
            }
            bottom--;
            for(int i=bottom;i>=top && temp<total;i--){
                v.push_back(matrix[i][left]);
                temp++;
            }
            left++;
        }
        return v;
    }
};