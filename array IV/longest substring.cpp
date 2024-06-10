//1
// Time Complexity: O( N2 )
// Space Complexity: O(N) where N is the size of HashSet taken for storing the elements
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < s.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < s.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(s[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(s[j]);
    }
  }
  return maxans;
  }
};
//2
//Time Complexity: O( 2*N ) (sometimes left and right both have to travel a complete array)
// Space Complexity: O(N) where N is the size of HashSet taken for storing the elements
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int maxans = INT_MIN;
        unordered_set < char > set;
        int l = 0;
        for (int r = 0; r < s.length(); r++) // outer loop for traversing the sing
    {
            if (set.find(s[r]) != set.end()) //if duplicate element is found
    {
                while (l < r && set.find(s[r]) != set.end()) {
            set.erase(s[l]);
            l++;
         }
    }
            set.insert(s[r]);
    maxans =  max(maxans, r - l + 1);
  }
  return maxans;
  }
};

//3
// Time Complexity: O( N )
// Space Complexity: O(N) where N represents the size of HashSet where we are storing our element
 int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
