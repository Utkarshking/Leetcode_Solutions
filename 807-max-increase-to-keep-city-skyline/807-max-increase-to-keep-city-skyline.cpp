class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
     int res=0;
        int n=grid.size();
        vector<int>rows(n);
        vector<int>col(n);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                rows[i]=max(rows[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res+=min(rows[i],col[j])-grid[i][j];
            }
        }
        return res;
    }
};