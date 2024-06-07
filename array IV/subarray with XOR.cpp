//1 is using 3 loops

//2
// Time Complexity: O(N*N), where N = size of the array.
// Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).
// Space Complexity: O(1) as we are not using any extra space
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

//3
