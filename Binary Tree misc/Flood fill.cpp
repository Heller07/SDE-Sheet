// Time Complexity: O(NxM + NxMx4) ~ O(N x M)

// For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

// Space Complexity: O(N x M) + O(N x M)

// O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int color, int delRow[], int delCol[],
             int iniColor) {
        // color with new color
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        // there are exactly 4 neighbours
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            // check for valid coordinate
            // then check for same initial color and unvisited pixel
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, ans, image, color, delRow, delCol, iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
        return ans;
    }
};
//same same but diff
class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);
        dfs(image,i+1,j,val,newColor);
        dfs(image,i,j-1,val,newColor);
        dfs(image,i,j+1,val,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};
