#include <bits/stdc++.h>

using namespace std;

void combinationSum(vector<int> &nums, int k, int i, vector<int> &tot,vector<vector<int>> &sol)
{
    if (k == 0) {sol.push_back(tot); return;}
    else if (i==nums.size() || k < 0) return;

    tot.push_back(nums[i]);
    combinationSum(nums, k - nums[i], i + 1, tot,sol);
    tot.pop_back();
    combinationSum(nums, k, i + 1, tot,sol);

    return;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int num = 1;
    vector<int> tot;
    vector<vector<int>> sol;
    combinationSum(arr, num, 0, tot,sol);
    for(auto &x: sol){
        for(int i:x){
            cout<< i<<" ";
        }
        cout<<endl;
    }
}