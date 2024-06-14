// Time Complexity: O(2^t * k) where t is the target, k is the average length
// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
// Why not (2^n) but (2^t) (where n is the size of an array)?
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.a
// Space Complexity: O(k*x), k is the average length and x is the no. of combinations
class Solution {
public:
    void solve(vector<int>& candidates,vector < vector < int >> &ans,vector < int > &ds,int target,int index){
        if(index ==candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //include
        if(candidates[index] <= target){
        ds.push_back(candidates[index]);
        solve(candidates,ans,ds,target-candidates[index],index);
        ds.pop_back();
        }

        //exclude
        solve(candidates,ans,ds,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector < vector < int >> ans;
        vector < int > ds;
        int index= 0;
        solve(candidates,ans,ds,target,index);
        return ans;
    }
};
