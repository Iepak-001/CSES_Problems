#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n>>x;

    vector<int>weights(n);

    for(int i=0; i<n; i++) cin>>weights[i];

    sort(weights.begin(), weights.end());

    int left=0;
    int right=n-1;

    int counter=0;
    while(left<=right){
        int tempWeight=weights[right];
        right--;
        counter++;

        if(tempWeight<=x){
            if(tempWeight+weights[right] <=x){
                tempWeight+=weights[right];
                right--;
            }
            else if(tempWeight+weights[left] <=x){
                tempWeight+=weights[left];
                left++;
            }
        }
        
    }
    cout<<counter;
}