class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
        vector<int>ans;
        vector<int>indegree(numCourses,0);
            queue<int>q;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnttoposort=0;
        while(!q.empty()){
           ans.push_back(q.front());
            cnttoposort++;
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                // node-->it
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
                }
            }
        if(cnttoposort!=numCourses) return {};
        return ans;
    }
};