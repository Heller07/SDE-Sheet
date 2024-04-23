#1
class Solution {
private:
void permutation(vector<int> &nums,vector<int> &array,vector<vector<int>>&ans,int freq[]){
    if(array.size()==nums.size()){
        ans.push_back(array);
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(!freq[i]){
        array.push_back(nums[i]);
        freq[i] = 1;
        permutation(nums,array,ans,freq);
        freq[i] = 0;
        array.pop_back();
    }
}
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> array;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i = 0;i<nums.size();i++) freq[i]=0;
        permutation(nums,array,ans,freq);
        return ans;
    }
};
#2
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
