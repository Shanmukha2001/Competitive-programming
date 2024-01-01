#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r)
{
    vector<int> temp;
    int left = l, right = mid + 1;
    while (l <= mid && right <= r)
    {
        if (a[l] <= a[right])
            temp.push_back(a[l++]);
        else
            temp.push_back(a[right++]);
    }

    while (l <= mid)
        temp.push_back(a[l++]);

    while (right <= r)
        temp.push_back(a[right++]);

    for (int i = left; i <= r; i++)
        a[i] = temp[i - left];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    mergeSort(a, 0, a.size() - 1);
    for (int i : a)
    {
        cout << i << " ";
    }
}