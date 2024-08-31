//Tc = O(n3)
//Sc = 1
class Solution {
public:
    string reverse(string s){
        string ans;
        for(long long i = s.size()-1;i>=0;i--){
            ans = ans+s[i];
        }
        return ans;
    }

    string longestPalindrome(string s) {
        long long n = s.size();
        if (n == 0) return "";

        string ans;
        for (long long i = 0; i < n; i++) {
            for (long long j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (sub == reverse(sub) && sub.size() > ans.size()) {
                    ans = sub;
                }
            }
        }
        return ans;
    }

};
// O(n^2)
// O(1)
class Solution {
public:
string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    string longest = "";
    for (int i = 0; i < s.length(); i++) {
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i + 1);
        if (odd.length() > longest.length()) longest = odd;
        if (even.length() > longest.length()) longest = even;
    }
    return longest;
}
};
