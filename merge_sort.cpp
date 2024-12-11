#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>v1, vector<int>v2, vector<int>&v){
    int i=0;
    int j=0;
    int k=0;
    int n=v.size(), n1=v1.size(), n2=v2.size();

    while(i<n1 && j<n2){
        if(v1[i]<v2[j]){
            v[k]=v1[i];
            k++;
            i++;
        }
        else{
            v[k]=v2[j];
            k++;
            j++;
        }
    }
    if(i==n1){
        while(j<n2) v[k++]=v2[j++];
    }
    if(j==n2) while(i<n1) v[k++]=v1[i++];

    return;
}
int count=0;
void count_inversions(vector<int>v1, vector<int>v2){
    int n1=v1.size(), n2=v2.size();

    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(v1[i]>v2[j]){
            count+=n1-i;
            j++;
        }
        else{
            i++;
        }
    }
}

void merge_sort(vector<int>&v){
    int n=v.size();
    if(n==1) return;

    int n1=n/2;
    int n2=n-n1;

    vector<int>v1(n1), v2(n2);

    for(int i=0; i<n1; i++){
        v1[i]=v[i];
    }

    for(int i=0; i<n2; i++){
        v2[i]=v[i+n1];
    }
    // vector<int>res(n);
    merge_sort(v1);
    merge_sort(v2);
    count_inversions(v1,v2);
    merge(v1,v2,v);
    return;
}

int main(){
    vector<int>v={1,4,7,3,2,9,0,34,56,78};
    merge_sort(v);
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<count<<endl;
    return 0;
}