struct node{
    int x;
    int y;
    int steps;
    node(int _x,int _y,int _steps){
        x=_x;
        y=_y;
        steps=_steps;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // time complexity -->O(n*m);
        // space complexity -->O(n*m)+O(n*m)
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        // we have took the other matrix which takes the dis 
        // and will not disrupt the data 
        vector<vector<int>>dis(row,vector<int>(col,0));
        queue<node>q;
        // queue<pair<pair<int,int>,int>>q;
            int dx[]={-1,0,+1,0};
            int dy[]={0,+1,0,-1};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push(node(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        // O(n*m*4)
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int steps=q.front().steps;
            q.pop();
            dis[x][y]=steps;
            for(int cor=0;cor<4;cor++){
                int newx=x+dx[cor];
                int newy=y+dy[cor];
                // validity check for the boundries
                if(newx>=0 and newx<row and newy>=0 and newy<col and !vis[newx][newy]){
                    vis[newx][newy]=1;
                    q.push(node(newx,newy,steps+1));
                }
            } 
        }
        return dis;
    }
};