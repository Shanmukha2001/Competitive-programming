#include<bits/stdc++.h>
using namespace std;

void printSeq(int i,int arr[],vector<int> temp,int n){
    if(i>=n) {
        for(int j:temp) {
            cout << j << " ";
        }
        cout << endl;
        return;
    }
    temp.push_back(arr[i]);
    printSeq(i+1,arr,temp,n);
    temp.pop_back();
    printSeq(i+1,arr,temp,n);
}

int main(){
    vector<int> temp;
    int arr[3] = {1,2,3};
    printSeq(0,arr,temp,3);
}