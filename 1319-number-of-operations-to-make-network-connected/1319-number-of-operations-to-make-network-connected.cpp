class Solution {
    private:
    bool dfssolve(int node,vector<int>&visited,vector<int>adj[]){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfssolve(it,visited,adj)) return true;
            }
        }
        return false;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        // adjacency list 
        vector<int>adj[n];
        int connected=0;
        vector<int>visited(n+1,0);
//         making the adjacency list
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
//         counting components by bfs 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                 connected++;
                dfssolve(i,visited,adj);
            }
        }
        // if there are n nodes so we simply need m-1 minimum wires to connect to the network
        return connected-1;
    }
};