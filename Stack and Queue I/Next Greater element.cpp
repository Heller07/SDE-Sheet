//Brute
class Solution {
public:
    vector<int> bruteforce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int counter=0;
        for(int i=0; i<nums2.size(); i++){
            
            for(int j=i+1; j<nums2.size(); j++){
                if(nums2[i]<nums2[j]){
                    ans.push_back(nums2[j]);
                    counter++;
                    break;
                }
            }
            if(counter==0) ans.push_back(-1);
            counter=0;
        }
        
        vector<int> ans2;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    ans2.push_back(ans[j]);
                    break;
                }
            }
        }
        return ans2;

    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        return bruteforce(nums1, nums2);
    }
    

//TC-O(n2)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int num = -1;
            int p = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (p == 0) {
                    if (nums1[i] == nums2[j])
                        p++;
                    continue;
                }
                if (nums2[j] > nums1[i]) {
                    num = nums2[j];
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};
// Time complexity: O(N+M)
// Space complexity: O(N+M
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; //for storing next greater element
        stack<int> st;

        for(int num:nums2){
            while(!st.empty() and st.top() < num){
                mp[st.top()] = num;  // storing parent of smaller element
                st.pop();  // pop the smaller element
            }

            st.push(num); // push the current element
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp.count(nums1[i]) ? mp[nums1[i]] : -1;  //if greater element present the update the greater element else update it with -1
        }

        return nums1;
    }
};




