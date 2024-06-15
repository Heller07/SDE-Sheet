// Time Complexity: O( (2^n) *k*(n/2) )
// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.
// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
class Solution {
public:

bool isPalindrome(string &s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }

    void partitioning(string &s,int index,vector<string> &st,vector<vector<string>> &ans){
        if(index == s.size()){
            ans.push_back(st);
            return;
        }
        for(int i = index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                st.push_back(s.substr(index,i-index+1));
                partitioning(s,i+1,st,ans);
                st.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> st;
        partitioning(s,0,st,ans);
        return ans;
    }
};
