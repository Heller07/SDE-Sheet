//brute is to apply 2 loops and find sum by regular boring method



//2
//O(n) for best case
//for postives and negatives

class Solution{//for sum k
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        unordered_map<int,int> mp;
        int sum = 0;
        int maxlen = 0;
        for(int i=0;i<A.size();i++){
            sum += A[i];
            if(sum == n){
                maxlen = max(maxlen,i+1);
            }
            int rem = sum-n;
            if(mp.count(rem)){
                int len = i-mp[rem];
                maxlen = max(maxlen,len);
            }
            if(!mp.count(sum)){//sum was not in map previously
                mp[sum] = i;
            }
        }
        return maxlen;
    }
};

//3
//for postives and 0 this is optimal
//but if we include negatives then 2 is optimal
//TC is O(2N) in worst case
//SC is 

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        int left = 0;
        int maxlen = 0;
        int right = 0;
        int sum = A[0];
        while(right<n){
            while(left<=right&&sum>0){
                sum = sum-A[left];
                left++;
            }
            if(sum==0){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
            if(right<n){
                sum = sum+A[right];
            }
        }
        return maxlen;
    }
};
