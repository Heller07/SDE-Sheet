//https://leetcode.com/problems/majority-element/
//1
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}
//2
// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity: O(N) as we are using a map data structure.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second>n/2){
                return it.first;
            }
        }
        return 0;
    }
};
//3
//Moore's Voting Algorithm //for/more than 50%
//Time Complexity: O(N) + O(N), where N = size of the given array.
// Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
// Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).
// Space Complexity: O(1) as we are not using any extra space.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
    }
};
