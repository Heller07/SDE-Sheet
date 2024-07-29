// TC IS O(ELogV) worst case
//we are not using queue to avoid calculation of unnecessary path which will end up consuming more time
//not applicable for negative weights

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        q.push({0,S});
        
        while(!q.empty()){
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it: adj[node]){
                int weight = it[1];
                int adjnode = it[0];
                
                if(distance+weight < dist[adjnode]){
                    dist[adjnode] = distance+weight;
                    q.push({dist[adjnode],adjnode});
                }
            }
            }
            return dist;
    }
};
