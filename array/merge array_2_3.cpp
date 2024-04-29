class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        for(int j = 0,i = m;j<n;j++){
            nums1[i] = nums2[j];
            i++;
        
        }
        sort(nums1.begin(),nums1.end());;
    }
};
//2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
    vector<int>arr3(m+n);
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < m && right < n) {
        if (nums1[left] <= nums2[right]) {
            arr3[index] = nums1[left];
            left++, index++;
        }
        else {
            arr3[index] = nums2[right];
            right++, index++;
        }
    }
    // If right pointer reaches the end:
    while (left < m) {
        arr3[index++] = nums1[left++];
    }

    // If left pointer reaches the end:
    while (right < n) {
        arr3[index++] = nums2[right++];
    }

    // Fill back the elements from arr3[]
    // to nums1[] and nums2[]:
    for (int i = 0; i < m+n; i++) {
        nums1[i] = arr3[i];
        
    }
}
};
