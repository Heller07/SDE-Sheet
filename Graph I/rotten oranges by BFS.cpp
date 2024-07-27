// Time Complexity: O ( n x n ) x 4    

// Reason: Worst-case - We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions

// Space Complexity: O ( n x n )

// Reason: worst-case -  If all oranges are Rotten, we will end up pushing all rotten oranges into the Queue data structure
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int i = 0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
