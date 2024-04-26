////just normal sorting you can use any sorting algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for ( int i = 0 ; i < nums.size() -1 ; i++ ){

            for ( int j = i ; j < nums.size() ; j++ ) {
                if ( nums[i] > nums[j] ) {
                    swap(nums[i],nums[j]) ;
                }
            }
        }
    }
};
//insertion sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            int current = nums[i];
            int j = i-1;
            while(j>=0 && nums[j]>current )
            {
                nums[j+1]= nums[j];
                j--;
            }
            nums[j+1]=current;
        }
    }
};
//2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0,one = 0,two = 0;
        int n = nums.size();
        for ( int i = 0 ; i < nums.size() ; i++ ){
            if(nums[i]==0){
                zero++;
            }
            if(nums[i]==1){
                one++;
            }
            if(nums[i]==2){
                two++;
            }
            
        }
        for(int i = 0;i<zero;i++){
            nums[i] = 0;
        }
        for(int i = zero;i<zero+one;i++){
            nums[i] = 1;
        }
        for(int i = zero+one;i<n;i++){
            nums[i] = 2;
        }
    }
};
//By dutch national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0,mid = 0,high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]== 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

