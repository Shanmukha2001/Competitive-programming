#include<bits/stdc++.h>

using namespace std;

void subSetSum(vector<int> arr,int i,int sum,vector<int> &sol){
    if(i>=arr.size()) {sol.push_back(sum); return;}
    subSetSum(arr,i+1,sum+arr[i],sol);
    subSetSum(arr,i+1,sum,sol);
}

int main(){
    vector<int> arr = {3,1,4},sol;
    subSetSum(arr,0,0,sol);
    sort(sol.begin(),sol.end());
    for(int i : sol) cout<<i<<endl;
}