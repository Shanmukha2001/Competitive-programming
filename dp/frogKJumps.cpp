#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int> &dp, vector<int> energy, int n, int k)
{
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];
    int currMin = INT_MAX, right = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        if (n >= i)
            right = frogJump(dp, energy, n - k, k) + abs(energy[n - k] - energy[n]);
        currMin = min(currMin, right);
    }
    return dp[n] = min(currMin, right);
}

int main()
{
    vector<int> energy = {10, 20, 30, 10};
    int n = energy.size();
    cout << "Enter k:";
    int k;
    cin >> k;
    vector<int> dp(n + 1, -1);
    // using top down
    cout << frogJump(dp, energy, n - 1, k) << endl;
    // using bottom up
    vector<int> dp2(n + 1, -1);
    dp2[0] = 0;
    int currMin = INT_MAX, left, right;
    for (int i = 1; i < n; i++)
    {
        currMin = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                left = dp2[i - j] + abs(energy[i - j] - energy[i]);
            currMin = min(currMin, left);
        }
        dp2[i] = currMin;
    }
    cout << dp2[n - 1];
    return 0;
}
