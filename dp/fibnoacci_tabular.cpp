#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 0, second = 1;
    int n, ans;
    cin >> n;
    if (n == 0)
        cout << first;
    else if (n == 1)
        cout << second;
    else
        for (int i = 1; i < n; i++)
        {
            ans = first + second;
            first = second;
            second = ans;
        }
    cout<<ans;
    return 0;
}