#include<string>
#include<iostream>
#include<map>

using namespace std;

int T;
int F;
map<string,int> idx;
int par[200002];
int cnt;

void init(){
    for(int i=0;i<200002;i++)
        par[i]=-1;
    idx.clear();
    cnt=0;
}

int find(int x){
    if(par[x] < 0)
        return x;
    return par[x] = find(par[x]);
}

int union_sn(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b)
        return -1*par[a];

    else if(a < b){
        par[a]+=par[b];
        par[b]=a;
        return -1*par[a];
    }

    else{
        par[b]+=par[a];
        par[a]=b;
        return -1*par[b];
    }
}

void solution(){
    init();
    cin>>F;

    string a,b;
    int node1, node2;

    while(F--){
        cin>>a>>b;

        if(idx.find(a)==idx.end())
            idx[a]=cnt++;
            
        if(idx.find(b)==idx.end())
            idx[b]=cnt++;
        
        node1=idx[a];
        node2=idx[b];

        cout<<union_sn(node1,node2)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        solution();
    }

    return 0;
}