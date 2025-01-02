#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;

int main(){
    int n;
    int target;

    cin>>n>>target;

    vector<int>coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];

    vector<vector<int>>dp(n+1,vector<int>(target+1));
    

    for(int i=0; i<n; i++) dp[i][0]=1;


    for(int i = n - 1; i >= 0; i--){

        for(int sum = 1; sum <= target; sum++){
            int skipping = dp[i + 1][sum];
            int picking = 0;
            
            if(coins[i] <= sum){
                picking = dp[i][sum - coins[i]];
            }

            dp[i][sum] = (skipping + picking) % mod;
        }
    }

    cout<< dp[0][target];
    
}