class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int steps[]={-jug1Capacity,+jug1Capacity,-jug2Capacity,+jug2Capacity};
        int z=jug1Capacity+jug2Capacity;
        vector<int>visited(z+1,0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=1;
            if(node==targetCapacity) return true;
            for(int i=0;i<4;i++){
                int newnode=node+steps[i];
                if(newnode>=0 and newnode<=z and !visited[newnode]){
                q.push(newnode);
              }
            }
        }
        return false;
    }
};