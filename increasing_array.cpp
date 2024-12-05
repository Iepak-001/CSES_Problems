#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int maxi=arr[0];
    long long movesCount=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=maxi){
            movesCount+=(long long)(maxi-arr[i]);
        }
        else if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    cout<<movesCount;
}