// https://leetcode.com/problems/set-matrix-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void set_matrix_zeroes(vector<vector<int>> &matrix){

    int col=1, r=matrix.size(), c=matrix[0].size();
    for(int i=0;i<r;i++){
        if(matrix[i][0] == 0){
            col = 0;
        }
        for(int j=1;j<c;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=1;j--){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j] = 0;
            }
        }
        if(col==0){
            matrix[i][0] = 0;
        }
    }
}

void print_updated_matrix(vector<vector<int>> &matrix){
    int r = matrix.size(), c = matrix[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int r,c;
    // cout<<"Enter r and c: ";
    cin>>r>>c;
    vector<vector<int>> matrix(r);
    // cout<<"Enter matrix: \n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int temp;
            cin>>temp;
            matrix[i].push_back(temp);
        }
    }

    set_matrix_zeroes(matrix);
    print_updated_matrix(matrix);

    return 0;
}