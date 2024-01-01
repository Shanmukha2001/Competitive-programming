#include<iostream>
using namespace std;

void rev(int arr[],int i){
    if(i >= (5/2)){
        return;
    }
    swap(arr[i] ,arr[5 - i]);
    rev(arr,i+1);
}

int main(){
 int arr[6] ={1,2,3,4,2,6}; 
 rev(arr,0);
 for(int i:arr)
    cout<<i<<endl; 
}
