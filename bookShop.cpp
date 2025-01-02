#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int priceCap;

    cin>>n>>priceCap;

    vector<pair<int, int>>books(n, pair<int,int>());

    for(int i=0;i<n; i++) cin>>books[i].first;
    for(int i=0;i<n; i++) cin>>books[i].second;

    // (price, Pages) ka PAIR hai

    vector<vector<int>>maxPages(n+1, vector<int>(priceCap+1,0));

    // [Index][Target] ka DP hai

    for(int i=0; i<n; i++){
        if(priceCap>=books[i].first) maxPages[i][priceCap-books[i].first]=books[i].second;
        else maxPages[i][priceCap]=-1;
    }

    for(int i=n-1; i>=0; i--){

        for(int j=0; j<=priceCap; j++){
            // Take/ Not Take
            int ans=0;
            //Not take
            ans=maxPages[i+1][j];

            //Take
            if(j-books[i].first>=0)
            ans=max(ans, books[i].second + maxPages[i+1][j-books[i].first]);

            maxPages[i][j]=ans;
        }
    }
    cout<<maxPages[0][priceCap];
}