//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int checkmin(vector<bool> visited,int v,vector<int> dist){
        int mi=INT_MAX;
        int index=-1;
        for(int i=0;i<v;i++){
            if(!visited[i] && dist[i]<mi){
                mi=dist[i];
                index=i;
            }
        }
        return index;
    }
    void check(vector<vector<int>> adj[],vector<int> &dist,vector<bool> &visited,int node){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i[0]] && dist[i[0]]>dist[node]+i[1]){
                dist[i[0]]=dist[node]+i[1];
            }
        }
        return;
    }
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(v,INT_MAX);
        vector<int>parent(v,-1);
        vector<bool>visited(v,0);
        dist[S]=0;
        for(int i=0;i<v;i++){
            int k=checkmin(visited,v,dist);
            if(k==-1)
                return dist;
            check(adj,dist,visited,k);
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends