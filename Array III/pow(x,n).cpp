//brute
class Solution {
public:
    double myPow(double x, int n) {
         if (n == 0) return 1.0;

        // Handle the case where n is negative
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double mul = 1.0;
        for (int i = 0; i < n; i++) {
            mul *= x;
        }

        return mul;
    }
    
};
//2
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
    } 
            else {
                x = x * x;
                nn = nn / 2;
    }
  }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;

    }
    
};
