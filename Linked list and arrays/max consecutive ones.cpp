// Time Complexity: O(N) since the solution involves only a single pass.
// Space Complexity: O(1) because no extra space is used.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        if(n == 0) return 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
                maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
