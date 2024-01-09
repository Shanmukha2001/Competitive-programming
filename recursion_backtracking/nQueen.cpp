#include <bits/stdc++.h>
using namespace std;

int n=8;
vector<int> upperDiag(2*n-1, 0), row(n, 0), lowerDiag(2*n-1, 0);

bool check(vector<vector<int>>& matrix, int i, int j){
    int lowerDiagNum = n-(i-j)-1;
    if(upperDiag[i+j] || lowerDiag[lowerDiagNum] || row[i]) return false;
    upperDiag[i+j] = 1;
    row[i] = 1;
    lowerDiag[lowerDiagNum] = 1;
    return true;
}

void uncheck(int i, int j){
    int lowerDiagNum = n-(i-j)-1;
    upperDiag[i+j] = 0;
    row[i] = 0;
    lowerDiag[lowerDiagNum] = 0;
}

void printMatrix(vector<vector<int>>& matrix){
    for(const auto& row : matrix) {
        for(const auto& elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void NQueen(vector<vector<int>>& matrix, int j){
    if(j == matrix.size()) {
        printMatrix(matrix);
        return;
    }
    for(int i=0; i<matrix.size(); i++){
        if(check(matrix, i, j)) {
            matrix[i][j] = 1;
            NQueen(matrix, j+1);
            matrix[i][j] = 0;
            uncheck(i, j);
        }
    }
}

int main(){
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    NQueen(matrix, 0);
}
