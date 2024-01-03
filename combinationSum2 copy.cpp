#include <bits/stdc++.h>

using namespace std;

void combinationSum(vector<int> &nums, int k, int i, vector<int> &tot,set<vector<int>> &sol)
{
    if (k == 0) {sol.insert(tot); return;}
    else if (i==nums.size() || k < 0) return;

    tot.push_back(nums[i]);
    combinationSum(nums, k - nums[i], i + 1, tot,sol);
    tot.pop_back();
    combinationSum(nums, k, i + 1, tot,sol);

    return;
}

int main()
{
    vector<int> arr = {1,1,1, 2};
    int num = 2;
    vector<int> tot;
    set<vector<int>> sol;
    combinationSum(arr, num, 0, tot,sol);
    for(auto &x: sol){
        for(int i:x){
            cout<< i<<" ";
        }
        cout<<endl;
    }
}