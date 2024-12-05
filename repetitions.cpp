#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n=str.size();
    int count=1;
    int ans=1;
    for(int i=1; i<n; i++){

        if(str[i]==str[i-1]) {
            count=count+1;
            ans=max(ans,count);
        }
        else count=1;

    }
    cout<< ans;

}