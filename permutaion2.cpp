#include <bits/stdc++.h>
using namespace std;

void printPermutations(vector<int> &nums, vector<vector<int>> &sol, int ind)
{
    if (ind == nums.size())
    {
        sol.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[i], nums[ind]);
        printPermutations(nums, sol, ind + 1);
        swap(nums[i], nums[ind]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sol;
    printPermutations(nums, sol, 0);

    for (auto &x : sol)
    {
        for (int i : x)
            cout << i << " ";
        cout << endl;
    }
}