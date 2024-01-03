#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum(vector<int> &nums, int k, int i, vector<int> &tot, vector<vector<int>> &sol)
{
    if (k == 0)
    {
        sol.push_back(tot);
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        if (nums[j] == nums[j - 1] && j > i)
            continue;
        if (nums[j] > k)
            break;
        tot.push_back(nums[j]);
        combinationSum(nums, k - nums[j], j + 1, tot, sol);
        tot.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 1, 2};
    int num = 2;
    vector<int> tot;
    vector<vector<int>> sol;
    sort(arr.begin(), arr.end());
    combinationSum(arr, num, 0, tot, sol);
    for (auto &x : sol)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}