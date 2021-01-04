//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
#include<bits/stdc++.h>
#define MAX 5
using namespace std;

bool isSafe(int m[MAX][MAX], int n, int row, int col){
    if(row<0 || row>=n || col<0 || col>=n || !m[row][col])
        return false;
    return true;    
}


void printPathUtil(int m[MAX][MAX], int n, int row, int col, vector<string>& paths, string &curr_path){
    if(row == n-1 && col == n-1){
        paths.push_back(curr_path);
        return;
    }
    
    int i;
    int row_change[] = { 1, -1, 0, 0};
    int col_change[] = { 0, 0, -1, 1};
    char move[] = {'D', 'U', 'L', 'R'};
    
    for(i=0;i<4;i++){
        if(isSafe(m, n, row + row_change[i], col + col_change[i])){
            curr_path.push_back(move[i]);
            m[row][col] = 0;
            printPathUtil(m, n, row + row_change[i], col + col_change[i], paths, curr_path);
            m[row][col] = 1;
            curr_path.pop_back();
        }
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    vector<string> paths;
    if(m[n-1][n-1] == 0 || m[0][0] == 0)
        return paths;
        
    int row = 0, col = 0;
    string curr_path = "";
    printPathUtil(m, n, row, col, paths, curr_path);
    sort(paths.begin(),paths.end());
    return paths;
}