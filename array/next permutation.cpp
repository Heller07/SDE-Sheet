//approach 1 using STL library of cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            // If next_permutation returns false, it means there is no next permutation
            // So, print the sorted nums vector
            sort(nums.begin(), nums.end());
        }
        // Print the elements of nums
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }

    }
};
