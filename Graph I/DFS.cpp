// Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],vector<int> &vis,int start,vector<int> &ans){
        vis[start] = 1;
        ans.push_back(start);
        for(auto it: adj[start]){
            if(!vis[it]){
            dfs(adj,vis,it,ans);
        }
            
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,i,ans);
            }
        }
        return ans;
    }
};
