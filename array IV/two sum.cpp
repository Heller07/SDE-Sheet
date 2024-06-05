//TC  = O(n*n)
//SC = O(1)
class Solution {
private:
vector<int> index(vector<int>& nums, int target){
int sum;
vector<int>ans;
for(int i=0;i<nums.size();i++){
    for(int j = i+1;j<nums.size();j++){
        sum = nums[i]+nums[j];
        if(sum==target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
 return ans;
}


public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        return index(nums,target);
    }
};
//TC = O(n)//in best case of unordered map
//SC = O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.count(moreNeeded)) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
    }
};

//TC == O(N)+O(nlogn)
//SC == O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
    
        vector<pair<int,int>> mp;
        for(int i = 0;i<nums.size();i++){
            mp.push_back(make_pair(nums[i],i));
        }
        sort(mp.begin(),mp.end());
        int left = 0;
        int right = nums.size()-1;
    while(left<right) {
        
        if(mp[left].first+mp[right].first == target){
            return {mp[left].second,mp[right].second};
        }
        if(mp[left].first+mp[right].first>target){
            right--;
        }
        if(mp[left].first+mp[right].first<target){
            left++;
        }
    }
    return {-1,-1};
    }
};
