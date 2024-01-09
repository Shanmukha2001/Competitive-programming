#include <bits/stdc++.h>

using namespace std;

void uniqueSubSet(vector<int> arr, vector<int> &sumVec, vector<vector<int>> &sol, int ind)
{
    sol.push_back(sumVec);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        sumVec.push_back(arr[i]);
        uniqueSubSet(arr, sumVec, sol, i + 1);
        sumVec.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 2}, sumVec;
    vector<vector<int>> sol;
    sort(arr.begin(), arr.end());
    uniqueSubSet(arr, sumVec, sol, 0);
    for (auto &x : sol)
    {
        if (x.empty())
            cout << "{}";
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}