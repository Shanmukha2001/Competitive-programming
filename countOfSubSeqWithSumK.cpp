#include<bits/stdc++.h>
using namespace std;

int arrSize = 3;

int printSeqOfSumK(int i,int k ,int arr[],vector<int> vec,int sum){
    if(sum == k){
        return 1;
    }
    if (i >= arrSize || sum>k) return 0;
    int tot =0;
    vec.push_back(arr[i]);
    tot += printSeqOfSumK(i+1,k,arr,vec,sum+arr[i]);
    vec.pop_back();

    tot += printSeqOfSumK(i+1,k,arr,vec,sum);
    return tot;
}

int main(){
    int arr[arrSize] = {1,2,1};
    vector<int> temp;
    cout << printSeqOfSumK(0,2,arr,temp,0);
}