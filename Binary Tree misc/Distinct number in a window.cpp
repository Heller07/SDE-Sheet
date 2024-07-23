//TC IS O(N)
//O(B)

vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int n = A.size();
    vector<int> ans;
    for(int i = 0;i<n;i++){
        mp[A[i]]++;
        if((i+1) == B){
            ans.push_back(mp.size());
        } 
        if(i >= B ){
            mp[A[i-B]]--;
            if(mp[A[i-B]] == 0){
                mp.erase(A[i-B]);
            }
            ans.push_back(mp.size());
        }
    }
    return ans;
}
