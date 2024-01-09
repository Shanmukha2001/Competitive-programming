#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
    int i=0,j=0;
    for (const auto &row : matrix)
    {
        if(j%3 ==0) {cout <<"-------------------"<<endl;}
        for (const auto &elem : row)
        {
            if(i/3 != ((i-1)/3)) { cout<<"|"; }
            cout << elem << ' ';
            i++;
        }
        cout << '\n';
        i%=9;
        j++;
    }
    cout << '\n';
}

bool isValid(vector<vector<int>> &puzz, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (puzz[row][i] == num)
            return false;
        if (puzz[i][col] == num)
            return false;
        if (puzz[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &puzz)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (puzz[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(puzz, i, j, k))
                    {
                        puzz[i][j] = k;
                        if (solve(puzz))
                            return true;
                        else
                            puzz[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> puzz = {{5, 3, 0, 6, 7, 8, 9, 0, 2},
                                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                {0, 9, 8, 3, 4, 2, 5, 6, 7},

                                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                {7, 1, 3, 9, 0, 4, 8, 5, 6},

                                {9, 6, 0, 5, 3, 7, 2, 8, 4},
                                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    solve(puzz);
    printMatrix(puzz);
}