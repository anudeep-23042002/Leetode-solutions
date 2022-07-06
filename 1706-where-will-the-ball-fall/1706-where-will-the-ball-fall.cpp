class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid,int n,int m){
        if(row>=m){
            return col;
        }
        if(col>n){
            return -1;
        }
        if(col<n-1 && grid[row][col]==1 && grid[row][col+1]==1){
            if(row+1==m){
                return col+1;
            }
            return dfs(row+1,col+1,grid,n,m);
        }
        else if(col>0 && grid[row][col]==-1 && grid[row][col-1]==-1){
            if(row+1==m){
                return col-1;
            }
            return  dfs(row+1,col-1,grid,n,m);
        }
        return -1;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<int>v(n,-1);
        for(int i=0;i<n;i++){
            v[i]=dfs(0,i,grid,n,m);
        }
        return v;
    }
};