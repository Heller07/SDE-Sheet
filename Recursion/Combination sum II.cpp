
// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.
// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.class Solution {
public:
void solve(vector<int>& candidates,vector < vector < int >> &ans,vector < int > &ds,int target,int index){
    if (target == 0) {
            ans.push_back(ds);
            return;
  }
  for (int i = index; i < candidates.size(); i++) {
    if (i > index && candidates[i] == candidates[i - 1]) continue;
    if (candidates[i] > target) break;
    ds.push_back(candidates[i]);
    solve(candidates, ans,ds, target - candidates[i], i+1);
    ds.pop_back();
  }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector < vector < int >> ans;
        vector < int > ds;
        sort(candidates.begin(), candidates.end());
        int index= 0;
        solve(candidates,ans,ds,target,index);
        
        return ans;
    }
};
