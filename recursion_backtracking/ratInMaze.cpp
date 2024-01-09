#include<bits/stdc++.h>

using namespace std;

void solve(int i,int j,vector<vector<int>> graph,vector<string> &ans,vector<vector<bool>> &visited,string s){
    if(i == graph.size() -1 && j == graph[0].size() -1){
        ans.push_back(s);
        cout<<s<<endl;
        return;
    }
    if((i+1)<graph.size() && graph[i+1][j] == 1 && !visited[i+1][j]){
        visited[i+1][j] = true;
        solve(i+1,j,graph,ans,visited,s+"D");
        visited[i+1][j] = false;
    }
    if((j+1)<graph[0].size() && graph[i][j+1] == 1 && !visited[i][j+1]){
        visited[i][j+1] = true;
        solve(i,j+1,graph,ans,visited,s+"R");
        visited[i][j+1] = false;
    }
    if((i-1)>=0 && graph[i-1][j] == 1 && !visited[i-1][j]){
        visited[i-1][j] = true;
        solve(i-1,j,graph,ans,visited,s+"U");
        visited[i-1][j] = false;
    }
    if((j-1)>=0 && graph[i][j-1] == 1 && !visited[i][j-1]){
        visited[i][j-1] = true;
        solve(i,j-1,graph,ans,visited,s+"L");
        visited[i][j-1] = false;
    }
}


int main(){
    int n = 4;
    vector<string> ans;
    vector<vector<int>> graph ={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    if(graph[0][0] == 1) solve(0,0,graph,ans,visited,"");
}