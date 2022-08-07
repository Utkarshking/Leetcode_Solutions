class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        int visited[1001][1001]={0};
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if((newx>=0 and newx<row and newy>=0 and newy<col)and(image[newx][newy]==image[x][y] and !visited[newx][newy])){
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
             image[x][y]=color;
        }
        return image;
    }
};