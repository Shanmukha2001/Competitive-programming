#include <bits/stdc++.h>
using namespace std;

void printPermutations(vector<int> &nums, vector<int> &perm, vector<vector<int>> &sol, int *freq)
{
    if (perm.size() == nums.size()){
        sol.push_back(perm);
        return;
    }

    for (int i = 0; i < nums.size(); i++){
        if (freq[i] == 0){
            freq[i] = 1;
            perm.push_back(nums[i]);
            printPermutations(nums, perm, sol, freq);
            freq[i] = 0;
            perm.pop_back();
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3}, perm;
    vector<vector<int>> sol;
    int freq[nums.size()] = {0};
    printPermutations(nums, perm, sol, freq);
    
    for(auto &x: sol){
        for(int i:x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}