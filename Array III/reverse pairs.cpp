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
//Time Complexity: O(2N*logN), where N = size of the given array.
// Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
// Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp; // temporary numsay
    int left = low;      // starting index of left half of nums
    int right = mid + 1;   // starting index of right half of nums

    //storing elements in the temporary numsay in a sorted manner//

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to nums //
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && 0.5*nums[i] > nums[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(nums, low, mid);  // left half
    cnt += mergeSort(nums, mid + 1, high); // right half
    cnt += countPairs(nums, low, mid, high); //Modification
    merge(nums, low, mid, high);  // merging sorted halves
    return cnt;
}

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
