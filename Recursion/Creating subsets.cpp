//Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).
// Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
class Solution {
public:
    void makesubset(int index,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = index;i<nums.size();i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            makesubset(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        makesubset(0,nums,ds,ans);
        return ans;
    }
};
//if array has unique element
class Solution {
public:
    void makesubset(int index,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        if(index>=nums.size()){
            ans.push_back(ds);
            return;
        }
        //exclude
        makesubset(index+1,nums,ds,ans);

        //include
        ds.push_back(nums[index]);
        makesubset(index+1,nums,ds,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
    
        makesubset(0,nums,ds,ans);
        return ans;
    }
};
