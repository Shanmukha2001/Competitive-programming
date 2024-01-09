#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int inv_count = 0;
    vector<int> temp;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            inv_count += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= right){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = left; i <= right; i++){
        arr[i] = temp[i - left];
    }

    return inv_count;
}

int solve(vector<int> &arr, int left, int right){
    int inv_count = 0;
    if(right > left){
        int mid = left + (right - left) / 2;
        inv_count += solve(arr, left, mid);
        inv_count += solve(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main(){
    vector<int> arr ={5,3,2,1,4};
    int n = arr.size();
    cout << "Number of inversions are " << solve(arr, 0, n-1);
    return 0;
}
