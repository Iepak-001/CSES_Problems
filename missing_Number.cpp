#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int XOR=0;
    for(int i=0; i<n-1; i++){
        XOR=XOR^v[i];
    }

    int x=n%4;

    if(x==1){
        cout<<(XOR^1);
    }
    else if(x==2){
        cout<<(XOR^(n+1));
    }
    else if(x==3){
        cout<<(XOR^(0));
    }
    else{
        cout<<(XOR^(n));
    }
    cout<<" ";
}