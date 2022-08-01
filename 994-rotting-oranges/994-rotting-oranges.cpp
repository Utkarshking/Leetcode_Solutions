struct node{
    int x,y,time;
    node(int _x,int _y,int _time){
    x=_x;
    y=_y;
    time=_time;
}
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // time complexity -->O(N*M)+O(N)*O(N)
        int row=grid.size();
        int col=grid[0].size();
        queue<node>q;
        int cntemptyoranges=0;
        // push the rotten oranges
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push(node(i,j,0));
                }
                if(grid[i][j]!=0)
                    cntemptyoranges++;
            }
        } 
        int ans=0;
        int cnt=0;
        // iterate on the queue
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int time=q.front().time;
             q.pop();
            ans=max(ans,time);
            cnt++;
            int dx[]={-1,0,+1,0};
            int dy[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 and newx<row and newy>=0 and newy<col and grid[newx][newy]==1){
                   grid[newx][newy]=2;
                    q.push(node(newx,newy,time+1));
                }
            }
        }
        if(cntemptyoranges==cnt) return ans;
        return -1;
    }
};