// TC and SC are same as bottom view,difference is that we can;t overwrite the value like we did in bottom view
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>> q;
        vector<int> ans;
        map<int,int> mp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(!mp.count(line)){
                
                mp[line] = node->data;
            }
            if(node->left){
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};
