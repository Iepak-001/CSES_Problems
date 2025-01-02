#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<char>>grid(n , vector<char>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>grid[i][j];
    }

    vector<vector<int>>paths(n, vector<int>(n,0));
    int mod=1000000007;

    for(int i=n-1; i>=0; i--) {
        if (grid[i][n-1]=='.') paths[i][n-1]=1;
        else break;
    }

    for(int i=n-1; i>=0; i--) {
        if (grid[n-1][i]=='.') paths[n-1][i]=1;
        else break;
    }

    for(int i=n-2; i>=0; i--){

        for(int j=n-2; j>=0; j--){
            if(grid[i][j]=='*') paths[i][j]=0;
            else paths[i][j]=(paths[i+1][j] %mod +paths[i][j+1]%mod)%mod;
        }
    }
    cout<<paths[0][0];

    return 0;
}