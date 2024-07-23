//nlogn
//O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
//O(n)+O(k)
//O(N)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int ans;
        for(int i = 0;i<nums.size();i++){
            q.push(nums[i]);
        }
        for(int i = 0;i<k;i++){
            ans = q.top();
            q.pop();
        }
        return ans;
    }
};
// Time Complexity: O(nlogk)
// Each of the n elements is processed once. However, heap operations take O(logk) time, leading to an overall complexity of O(nlogk).

// Space Complexity: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
