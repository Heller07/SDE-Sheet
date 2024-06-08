// Time Complexity: O(NM), where N = given row number, M = given column number.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

//2
// Time Complexity: O(N + logM), where N = given row number, M = given column number.
// Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).
// Space Complexity: O(1) as we are not using any extra space.
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

//3
//by flattening the 2d into 1d(not really)
//Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
// Reason: We are applying binary search on the imaginary 1D array of size NxM.
// Space Complexity: O(1) as we are not using any extra space.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;//mid is mid index of assumed 1d array,row col are index of 2d mat,this is how we convert 1d index into 2d row and cols
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    //by for loop
    //     bool searchMatrix(vector<vector<int>>& mat, int target) {
    //     int n=mat.size();

    // int m=mat[0].size();

    // for(int i=0;i<n*m;i++){

    //     if(mat[i/m][i%m]==target){

    //         return true;

    //     }

    // }

    // return false;


}
       
    }
};
//4
//proper binary search for 2D mat
//TC is O(N+M)
//SC is 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;int col = m-1;
    while(row<n&&col>=0){
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            col--;
        }
        else{
            row++;        }
    }
       return false;
    }
};
