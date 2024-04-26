//1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MIN;
        int sub = 0;
        for(int i = 0;i<prices.size();i++){
            for(int j = i;j<prices.size();j++){//we can start it by i+1
                if(prices[j]>prices[i]){
                sub = prices[j]-prices[i];
            }
                maxi = max(maxi,sub);
            }
        }
        return maxi;
    }
};
//2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            mini = min(mini,prices[i]);//minimising the buying stock
            maxi = max(maxi,prices[i]-mini);//maximizing the profit
        }
        return maxi;
    }
};
