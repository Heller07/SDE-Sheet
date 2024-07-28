// Time Complexity: O(N+E) 
// N = Number of node , E = Number of Edges
// Space Complexity: O(N) + O(N)
// Visited Array and Stack data structure. Both will be using O(N).
// Auxiliary Space Complexity:  O(N)
// Recursion call of DFS
class Solution
{
    private:
    void dfs(vector<int> adj[],stack<int> &st,vector<int> &vis,int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj,st,vis,node);
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> vis(V,0);
	    vector<int> ans;
	    for(int i = 0;i< V;i++){
	        if(!vis[i]){
	            dfs(adj,st,vis,i);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
