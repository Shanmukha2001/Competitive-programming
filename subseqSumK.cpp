#include<bits/stdc++.h>
using namespace std;

int arrSize = 3;

void printSeqOfSumK(int i,int k ,int arr[],vector<int> vec,int sum){
    if(sum == k){
        for(int i:vec)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    if (i >= arrSize || sum>k) return;
    vec.push_back(arr[i]);
    printSeqOfSumK(i+1,k,arr,vec,sum+arr[i]);
    vec.pop_back();

    printSeqOfSumK(i+1,k,arr,vec,sum);
}

int main(){
    int arr[arrSize] = {1,2,1};
    vector<int> temp;
    printSeqOfSumK(0,2,arr,temp,0);
}