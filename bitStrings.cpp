#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    long long mod=1000000007;
    long long ans=1;

    for(int i=0; i<n; i++){
        ans=(ans%mod)*2;
        ans%=mod;
    }
    cout<<ans;
}