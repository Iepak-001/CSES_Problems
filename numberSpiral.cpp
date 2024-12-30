#include<bits/stdc++.h>
using namespace std;

int main(){
    //This question is of MATHS

    int t; //No of test cases
    cin>>t;

    while(t--){
        long long x, y; // (col , row ) number ==>> 1-Based Indxing
        cin>>x>>y;
        //Identify in which layer the co-ordinates is located
        long long layer=max(x,y);

        //Layer is found => It will be outside (n-1) layer
        long long ans=(layer-1)*(layer-1);

        long long currX=0,currY=0;

        //Odd layer moves right then up
        //even layer moves down then left
        // x-=layer;
        // y-=layer;

        if(layer%2==0){
            currY=layer;
            while(currX<x) {
                ans++;
                currX++;
            }
            while(currY>y){
                ans++;
                currY--;
            }
        }
        else{
            currX=layer;
            
            while(currY<y){
                ans++;
                currY++;
            }
            while(currX>x) {
                ans++;
                currX--;
            }
        }
        cout<<ans<<"\n";
    }
}