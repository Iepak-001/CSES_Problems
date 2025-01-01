#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    int count=1;
    
    int i=1;
    while(i<n){
        if(v[i]!=v[i-1]){
             count++;
             i++;
        }

        else{
            while(i<n && v[i]==v[i-1]){
                i++;
            }
        }
    }
    cout<<count;
    return 0;
}