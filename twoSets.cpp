#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    //No from 1 to N is forming AP

    //Now use properties of AP

    // Sum of means == Sum of extremes (Jaisa kuch??)

    // Sum/2 find krna hai

    // agar sum/2 set me hai toh utha lo
    // else extremes uthao 
    long long sum=(n*(n+1))/2;

    if(n==(long long)3){
        cout<<"YES"<<"\n";
        cout<<1<<"\n"<<3;
        cout<<"\n"<<2<<"\n";
        cout<<1<<" "<<2;
        return 0;
    }

    if(sum%2==0){
        cout<<"YES"<<"\n";
        long long i=1;
        long long j=n;

        long long tempSum=0;
        long long count=0;



        while((tempSum*2)!=sum){
            if(tempSum+j<=sum/2){
                tempSum+=j;
                count++;
                j--;
            }

            if(tempSum+i<=sum/2){
                tempSum+=i;
                count++;
                i++;
            }
            
            
            
            
        }

        cout<<count<<"\n";

        for(int k=1; k<i; k++){
            cout<<k<<" ";
        }

        for(int k=j+1; k<=n; k++){
            cout<<k<<" ";
        }

        cout<<"\n";
        cout<<n-count;
        cout<<"\n";

        while(i<=j){
            cout<<i<<" ";
            i++;
        }

        

    }
    else cout<<"NO";
    return 0;
}