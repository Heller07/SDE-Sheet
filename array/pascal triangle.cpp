//TC is of the order of O(n3)or O(n2r)
long long int ncr(int n,int r){
    int res = 1;
    for(int i = 0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans(N);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<=i;j++){
            ans[i].push_back(ncr(i,j));
        }
    }
    return ans;
}
//MORE optimised
//TC is O(n2) or to be more precise it is O(n*r)
vector<int> generateRow(int row){
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }  
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}
