class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n;
        for(int i=1;i<triangle.size();i++){
            n=triangle[i].size();
            for(int j=0;j<n;j++){
                if(j==0){
                    triangle[i][j]=triangle[i][j]+triangle[i-1][j];
                }
                else if(j==n-1){
                    triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
                }
                else{
                    triangle[i][j]=triangle[i][j]+min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        n=triangle.size();
        int mi=triangle[n-1][0];
        for(int i=0;i<n;i++){
            mi=min(mi,triangle[n-1][i]);
        }
        return mi;
    }
};