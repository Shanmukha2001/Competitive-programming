#include<bits/stdc++.h>

using namespace std;

bool isPalindrom(string s,int i,int j){
    while(i<=j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

void solve(string s,vector<vector<string>> &sol,vector<string> &sub,int i){
    if(i == s.length()) {sol.push_back(sub); return;}
    for(int j=i;j<s.length();j++){
        if(isPalindrom(s,i,j)){
            sub.push_back(s.substr(i,j-i+1));
            solve(s,sol,sub,j+1);
            sub.pop_back();
        }
    }
}

int main(){
    string s = "aabb";
    vector<vector<string>> sol;
    vector<string> substring;
    solve(s,sol,substring,0);
    for(auto &x:sol){
        for(auto &st:x){
            cout<<st<<" ";
        }
        cout<<endl;
    }
}