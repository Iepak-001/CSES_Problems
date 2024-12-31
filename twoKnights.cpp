//Permu and  Combi ka sawaal hai

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dir[8][2]= {
        {-2, -1}, {-2, 1},  // Up two, left/right one
        {-1, -2}, {-1, 2},  // Up one, left/right two
        {1, -2},  {1, 2},   // Down one, left/right two
        {2, -1},  {2, 1} 
    };

    for(int k=1; k<=n; k++){

        //K x K ka matrix hai
        long long ans=0;
        for(int i=0; i<k; i++){

            for(int j=0; j<k; j++){
                long long count=0;
                for(int l=0; l<8; l++){
                    if(dir[l][0]+i<k && dir[l][0]+i>=0 && dir[l][1]+j<k && dir[l][1]+j>=0) count++;
                }
                ans+=(long long)((long long)k * (long long)k)-1-count;
            }
        }
        // ans*=(long long)((long long)k * (long long)k);
        ans/=2;
        cout<<ans<<"\n";
    }
}