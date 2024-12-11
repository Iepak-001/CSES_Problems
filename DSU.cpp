#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent, int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent, parent[x]);
}
void Union(vector<int>&parent, vector<int>&rank,vector<int>&maxi, vector<int>&mini, vector<int>&sze, int a, int b){

    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return;
    if(rank[a]>rank[b]){
        rank[a]++;
        parent[b]=a;
        sze[a]+=sze[b];
        maxi[a]=max(maxi[a],maxi[b]);
        mini[a]=min(mini[a],mini[b]);
    }
    else{
        rank[b]++;
        parent[a]=b;
        sze[b]+=sze[a];
        maxi[b]=max(maxi[a],maxi[b]);
        mini[b]=min(mini[a],mini[b]);
    }
}
void get(vector<vector<int>>&ans, vector<int>&parent, vector<int>&rank,vector<int>&maxi, vector<int>&mini,vector<int>&sze, int x){
    ans.push_back({mini[x],maxi[x],sze[x]});
}
int main(){
    int n,m;
    cin>>n>>m;

    
    vector<int>maxi(n+1),mini(n+1),parent(n+1),rank(n+1,1),sze(n+1,1);

    for(int i=0; i<=n; i++) {
        maxi[i]=mini[i]=parent[i]=i;
    }

    vector<vector<int>>ans;
    for(int i=0; i<m; i++){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,maxi,mini,sze,x,y);
        }
        else{
            int x;
            cin>>x;
            x=find(parent,x);
            get(ans,parent,rank,maxi,mini,sze,x);
            cout<<"\n";
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
    }

    return 0;
}