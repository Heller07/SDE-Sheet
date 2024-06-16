// Tc = O(2^n)
// SC = O(n)+O(2^n)
#include <bits/stdc++.h> 
void solve(string &s, vector<string> &dictionary,int index,set<string> &st,string str){
    if(index == s.size()){
        st.insert(str);
        return;
    }
    for(int i = index;i<s.size();i++){
        string target = s.substr(index,i-index+1);
        if(find(dictionary.begin(), dictionary.end(), target) != dictionary.end()){
            solve(s,dictionary,i+1,st,str+target+" ");
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    set<string> st;
    string str;
    solve(s,dictionary,0,st,str);
    vector<string>ans;
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
    

}
