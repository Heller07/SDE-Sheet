// Time complexity: O(n*log(n))+O(n)

// Space Complexity: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int k = st.size();
        int i = 0;
        for(auto it:  st){
            nums[i] = it;
            i++;
        }
        return k;
    }
};

//2
//Time Complexity: O(N)
// Space Complexity: O(1)
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
