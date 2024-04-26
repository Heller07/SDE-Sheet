#1
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
    }
};
#2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int n = nums.size();
    for (int i = 0; i < n; i++) {
            int sum = 0;
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]

            //add all the elements of subarray:
           
                sum += nums[j];
            

            maxi = max(maxi, sum);
        }
#3//optimal
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int n = nums.size();
        int sum = 0;
    for (int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum = 0;
            }
        
    }

    return maxi;
    
}
};
//if we have to print the max sub array
//so we just need the index of start and end
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int start,anstart,ansend;
        int maxi = INT_MIN; // maximum sum
        int n = nums.size();
        int sum = 0;
    for (int i = 0; i < n; i++) {
      if(sum==0) start = i;
            sum += nums[i];
            
            if(sum>maxi){
                maxi = sum;
                anstart = start;
                ansend = i;
            }
            if(sum<0){
                sum = 0;
            }
        
    }

    return maxi;
    
}
};
