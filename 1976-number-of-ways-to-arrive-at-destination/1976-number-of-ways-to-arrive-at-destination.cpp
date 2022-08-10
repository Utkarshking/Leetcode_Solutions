class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(1e9+7);
        vector<long>ways(n,0);
        vector<long>distance(n,LONG_MAX);
        
//         creating the adjacency list
        vector<pair<long,long>>adj[n];
       for(auto it:roads){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
        distance[0]=0;
        ways[0]=1;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long node=pq.top().second;
            long long dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
               int wt=it.second;
               int adjnode=it.first;
                if(dis+wt<distance[adjnode]){
                    distance[adjnode]=dis+wt;
                    ways[adjnode]=ways[node];
                    pq.push({dis+wt,adjnode});
                }
//                 special condition
//                 in which the ways will be increased
                else if(dis+wt==distance[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
                
            }
            
        }
        return ways[n-1];
    }
};