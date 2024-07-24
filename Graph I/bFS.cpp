// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int start,vector<int> adj[],vector<int> &vis,vector<int> &ans){
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto it: adj[front]){
                if(!vis[it])
                {
                    q.push(it);
                   
                    vis[it]=1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        
        
                bfs(i,adj,vis,ans);
            
        
        return ans;
    }
};
