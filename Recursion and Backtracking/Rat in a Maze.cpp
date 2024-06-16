//1
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).
class Solution{
    public:
    void solve(vector<vector<int>> &m,vector<vector<bool>> &visited,vector<string>& ans,string s,int row,int col,int n){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        //RIGHt
        visited[row][col] = true;
        
        if(col<n-1 && m[row][col+1] == 1 && !visited[row][col+1]){
            s = s+'R';
            solve(m,visited,ans,s,row,col+1,n);
             s.pop_back();
        }
        //LEFT
        if(col-1>=0 && m[row][col-1] == 1 && !visited[row][col-1]){
            s = s+'L';
            solve(m,visited,ans,s,row,col-1,n);
             s.pop_back();
        }
        //DOWM
        if(row<n-1 && m[row+1][col] == 1 && !visited[row+1][col]){
            s = s+'D';
            solve(m,visited,ans,s,row+1,col,n);
            s.pop_back();
        }
         // UP
        if (row - 1 >= 0 && m[row - 1][col] == 1 && !visited[row - 1][col]) {
            s = s+'U';
            solve(m,visited, ans, s, row - 1, col, n);
            s.pop_back();
        }
        visited[row][col] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s;
        if (m[0][0] == 1) {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            solve(m,visited, ans, s, 0, 0, n);
        }
        return ans;
    }
};
//SAME SOLUTION AS ABOVE ITS JUST truncate form of 4 if statement 
class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};
