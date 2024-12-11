#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent, int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}
void Union(vector<int>&parent, vector<int>&rank, int a, int b){
    a=find(parent,a);
    b=find(parent,b);

    if(rank[a]>rank[b]){
        parent[b]=a;
        rank[a]++;
    }
    else{
        parent[a]=b;
        rank[b]++;
    }
}
struct Edge{
    int src;
    int dest;
    int wt;
};
static bool cmp(Edge e1, Edge e2){
    if(e1.wt==e2.wt)
    return e1.wt+e1.src+e1.dest<e2.wt+e2.dest+e2.src;

    else return e1.wt<e2.wt;
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    vector<int>parent(nodes+1),rank(nodes+1,1);

    for(int i=0; i<parent.size(); i++) parent[i]=i;

    vector<Edge>v;
    for(int i=0; i<edges; i++){
        Edge temp;
        cin>>temp.src>>temp.dest>>temp.wt;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);

    int i=0;
    int edgeCount=0;

    int ans=0;
    while(i<edges && edgeCount<nodes-1){
        Edge curr=v[i];
        cout<<curr.src<<"->"<<curr.dest<<" "<<curr.wt<<endl;
        int srcPar=find(parent,curr.src);
        int destPar=find(parent,curr.dest);

        //NOW If cycle not exists proceed

        if(srcPar!=destPar){
            Union(parent,rank,srcPar,destPar);
            ans+=curr.wt;
            edgeCount++;
        }
        i++;
    }
    cout<<ans;

    return 0;
}   
