#include<bits/stdc++.h>
using namespace std;

int main(){
    // For No of trailing zeros
    //calculate exponent of 2 && 5
    //Power of 5 determines answer
    //power of 2 is abundant and very large

    // EASY Task

    //Memoisation=>  n! == (n-1)! * n

    int n;
    cin>>n;

    int powerOf2=0, powerOf5=0;

    vector<pair<int,int>>vis;

    for(int i=5; i<=n; i*=5){

        powerOf5+=n/i;

    }
    cout<<(powerOf5);
    return 0;
}