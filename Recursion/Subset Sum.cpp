// Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
class Solution {
  public:
    void makesubset(int index,vector<int> &arr,int n,vector<int> &ans,int sum){
        if(index == n){
            ans.push_back(sum);
            return ;
        }
        makesubset(index+1,arr,n,ans,sum);
        makesubset(index+1,arr,n,ans,sum+arr[index]);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        makesubset(0,arr,n,ans,0);
        return ans;
    }
};
