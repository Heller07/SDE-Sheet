//1
//https://leetcode.com/problems/reverse-pairs/
// Time Complexity: O(N2), where N = size of the given array.
// Reason: We are using nested loops here and those two loops roughly run for N times.
// Space Complexity: O(1) as we are not using any extra space to solve this proble
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((long long)nums[i]>(long long)2*nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
//2
