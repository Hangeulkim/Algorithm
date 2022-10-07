#include<iostream>
#include<vector>

using namespace std;

typedef struct data{
    int ord,a,b;
}d;

int n,m;
int par[1'000'007];
vector<d> orders;

void initialize(){
    for(int i=0;i<1'000'007;i++)
        par[i]=-1;
}

void input(){
    cin>>n>>m;

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        
        orders.push_back({a,b,c});
    }
}

int find(int node){
    if(par[node] < 0) return node;
    return par[node] = find(par[node]);
}

void union_list(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);

    if(node1==node2)
        return;
    
    if(par[node1] < par[node2]){//루트는 음수의 값을 가짐
        par[node1] += par[node2];
        par[node2] = node1;
    }
    else{
        par[node2] += par[node1];
        par[node1] = node2;
    }
}

bool same(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);

    if(node1 == node2)
        return true;
    return false;
}

void solution(){
    int ord,a,b;
    for(int i=0;i<orders.size();i++){
        ord=orders[i].ord;
        a=orders[i].a;
        b=orders[i].b;

        if(ord){
            if(same(a,b))
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
        else{
            union_list(a,b);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    initialize();
    input();
    solution();

    return 0;
}