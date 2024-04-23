#1
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
    }
};
