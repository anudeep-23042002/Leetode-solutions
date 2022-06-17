class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>v;
        vector<int>adj[numCourses];
        int n=prerequisites.size();
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]+=1;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        if(q.empty()) return v;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;++i){
                auto p=q.front();
                q.pop();
                v.push_back(p);
                count+=1;
                for(auto j:adj[p]){
                    indegree[j]-=1;
                    if(indegree[j]==0) q.push(j);
                }
            }
        }
        if(count<numCourses){
            v.clear();
        }
        return v;
    }
};