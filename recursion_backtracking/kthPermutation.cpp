#include<bits/stdc++.h>

using namespace std;

void kPermutation(int num,int k){
    vector<int> nums;
    int factorial =1;
    for(int i=1;i<num;i++){
        nums.push_back(i);
        factorial = factorial *i;
    }
    nums.push_back(num);
    string s ="";
    while(true){
        s+=to_string(nums[k/factorial]);
        nums.erase(nums.begin()+k/factorial);
        if(nums.size() == 1){
            s+=to_string(nums[k/factorial]);
            cout<<s;
            return;
        }
        k%=factorial;
        factorial/=nums.size();
    }
}                      

int main(){
    kPermutation(4,16);
}