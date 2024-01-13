#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int> &dp, vector<int> energy, int n)
{
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];
    int left = frogJump(dp, energy, n - 1) + abs(energy[n - 1] - energy[n]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJump(dp, energy, n - 2) + abs(energy[n - 2] - energy[n]);
    return dp[n] = min(left, right);
}

int main()
{
    vector<int> energy = {10, 20, 30, 10};
    int n = energy.size();
    vector<int> dp(n + 1, -1);
    // using top down
    cout << frogJump(dp, energy, n - 1) << endl;
    // using bottom up
    vector<int> dp2(n + 1, -1);
    int x = 0;
    int y = abs(energy[1] - energy[0]);
    int fin, left, right;
    for (int i = 2; i < n; i++)
    {
        left = y + abs(energy[i - 1] - energy[i]);
        right = x + abs(energy[i - 2] - energy[i]);
        fin = min(left, right);
        y = x;
        x = fin;
    }
    cout << fin;
    return 0;
}
