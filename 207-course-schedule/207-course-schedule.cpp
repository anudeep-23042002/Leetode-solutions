class Solution {
public:
    bool cycle(int i,vector<int>adj[],vector<bool>&vis,vector<bool>&dfs){
        vis[i]=true;
        dfs[i]=true;
        for(auto j:adj[i]){
            if(i==j){
                return true;
            }
            else if(dfs[j] && vis[j]){
                return true;
            }
            else if(!vis[j]){ 
                if(cycle(j,adj,vis,dfs)){
                    return true;
                }
            }
        }
        dfs[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>dfs(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i,adj,dfs,vis)) return false;
            }
        }
        return true;
    }
};