//1
//Time Complexity: O(N2), where N = size of the given array.
// Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.
// Space Complexity: O(1) as we are not using any extra space.
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
//2
// Time Complexity: O(2N), where N = the size of the given array.
// Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).
// Space Complexity: O(N) as we are using a hash array to solve this problem.
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here'
    int n = a.size();
    int arr[n+1] = {0};
    for(int i = 0;i<n;i++){
        arr[a[i]]++;
    }
    int repeat = -1;int missing = -1;
    for(int i =1;i<=n;i++){
        if(arr[i] == 2){
            repeat = i;
        }
        if(arr[i] == 0){
            missing = i;
        }
    }
    return {repeat,missing};
}
//3
//Time Complexity: O(N), where N = the size of the given array.
// Reason: We are using only one loop running for N times. So, the time complexity will be O(N).
// Space Complexity: O(1) as we are not using any extra space to solve this problem.

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    //S-Sn = X-Y:
    long long val1 = S - SN;
    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}
