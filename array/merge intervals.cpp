//1
//TC is O(NlogN)+O(N)
//SC is O(N)+O(N^2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    vector<int> first = intervals[0];
    for(auto i: intervals){
        if(first[1]>=i[0]){
            first[1] = max(first[1],i[1]);
    }
        else{
            ans.push_back(first);
            first = i;
    }

}
    ans.push_back(first);
    return ans;
    }
};
//2
//SC is O(N^2)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
