#include <bits/stdc++.h>
using namespace std;

int hops(vector<int> &dp, int n)
{
    if (n == 0) return dp[0] =1;
    if (n == 1) return dp[1] = 1;
    else if (dp[n] != -1) return dp[n];
    else
    {
        return dp[n] = hops(dp,n-1)+hops(dp,n-2);
    }
}

int main()
{
    int stairs;
    cin >> stairs;
    vector<int> dp(stairs + 1, -1);
    // using memoziation
    hops(dp, stairs);
    cout << dp[stairs];
    return 0;
}