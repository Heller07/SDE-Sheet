//1
int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }

//2
// Time Complexity: The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
// Space Complexity: As we are using extra space for the dummy matrix the space complexity will also be O(n*m).
class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};
//3
//Time Complexity: The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.
// Space Complexity: As we are not using any extra space the space complexity of the solution will be  O(1).
class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;//total np. of direction possible(right+down)
            int r = m - 1; //we are finding Nc(m-1) but Nc(n-1) is also correct
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};
