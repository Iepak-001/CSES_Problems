#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;      // No of applicants
    int m;      // No of appartments
    int maxDiff;// Max diff accepted

    cin>>n>>m>>maxDiff;

    vector<int>applicants(n);
    vector<int>apartments(m);

    for(int i=0; i<n; i++){
        cin>>applicants[i];
    }

    for(int i=0; i<m; i++){
        cin>>apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i=0;
    int j=0;

    int ans=0;
    while(i<m && j<n){
        // cout<<apartments[i]<<" "<<applicants[j]<<endl;
        if(apartments[i]>applicants[j]){
            if(abs(apartments[i]-applicants[j])<=maxDiff){
                j++;
                i++;
                ans++;
            }
            else{
                j++;
            }
        }

        else if(apartments[i]<applicants[j]){
            if(abs(apartments[i]-applicants[j])<=maxDiff){
                j++;
                i++;
                ans++;
            }
            else {
                i++;
            }
        }
        else{
            ans++;
            i++;
            j++;
        }
    }
    cout<<ans;


}