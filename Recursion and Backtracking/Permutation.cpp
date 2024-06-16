//Time Complexity:  N! x N
// Space Complexity:  O(N)
class Solution {
  private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};
//Time Complexity: O(N! X N)
// Space Complexity: O(1)
class Solution {
private:
void permutation(int index,vector<int> &nums,vector<vector<int>>&ans){
    if(index ==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index;i<nums.size();i++){
       swap(nums[index],nums[i]);
       permutation(index+1,nums,ans);
       swap(nums[index],nums[i]);
    }

    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(0,nums,ans);
        return ans;
    }
};
