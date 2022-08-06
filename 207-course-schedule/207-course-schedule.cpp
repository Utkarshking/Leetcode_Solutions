class Solution {
private:
    bool iscyclepresent( int node, vector<int>&vis, vector<int>&path, vector<int>adj[] ){
        vis[node]=1;
        path[node]=1;
        
    
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(iscyclepresent(it,vis,path,adj)==true) return true;
            }
            else if(path[it]==1) {    
                return true;
            }
        }
        
        path[node]=0;
        return false;
    }
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(iscyclepresent(i,visited,path,adj)==true){
                  return false;  
                } 
            }
        }
        return true;
    }
};