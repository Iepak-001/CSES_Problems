#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;

    if(num==1) {
        cout<<1;
        return 0;
    }

    int lastEven=0;
    if(num%2==0) lastEven=num;
    else lastEven=num-1;

    int firstOdd=1;

    if(lastEven-firstOdd <=1){
        cout<<"NO SOLUTION";
    }
    else{
        
        //Print even 
        for(int i=2; i<=num; i+=2){
            cout<<i<<" ";
        }

        //Print odd 
        for(int i=1; i<=num; i+=2){
            cout<<i<<" ";
        }
    }

    return 0;
}