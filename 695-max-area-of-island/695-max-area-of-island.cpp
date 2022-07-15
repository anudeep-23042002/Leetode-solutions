class Solution {
public:
    int isl(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>m-1 || j>n-1 || grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=2;
        return 1+isl(i-1,j,m,n,grid)+isl(i,j-1,m,n,grid)+isl(i,j+1,m,n,grid)+isl(i+1,j,m,n,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count =0;
        int maxcount=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count=isl(i,j,m,n,grid);
                    maxcount=max(count,maxcount);
                    v.push_back(count);
                }
            }
        }
        sort(v.begin(),v.end());
        int p=v.size();
        for(int i=1;i<p;i+=2){
            count+=v[i];
        }
        cout<<count<<endl;
        return maxcount;
    }
};