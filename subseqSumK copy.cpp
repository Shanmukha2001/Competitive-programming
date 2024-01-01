#include<bits/stdc++.h>
using namespace std;

int arrSize = 3;

bool printSeqOfSumK(int i,int k ,int arr[],vector<int> vec,int sum){
    if(sum == k){
        for(int i:vec)
            cout<<i<<" ";
        cout<<endl;
        return true;
    }
    if (i >= arrSize || sum>k) return false;
    vec.push_back(arr[i]);
    if(printSeqOfSumK(i+1,k,arr,vec,sum+arr[i])) return true;
    vec.pop_back();

    if(printSeqOfSumK(i+1,k,arr,vec,sum)) return true;
    return false;
}

int main(){
    int arr[arrSize] = {1,2,1};
    vector<int> temp;
    printSeqOfSumK(0,2,arr,temp,0);
}