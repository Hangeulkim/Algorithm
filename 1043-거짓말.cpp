#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<int> gura[51];
vector<int> chk;
int parent[51];
int result=-1;
int tn,tmp;

int Find(int x){
    if(parent[x]==x)
        return x;
    return x=Find(parent[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[x]=y;
}

void ans(){
    for(int pa=1;pa<=M;pa++){
        bool known = false;
        for(auto per : gura[pa]){
            if(known) break;

            for(auto truth : chk){
                if(Find(truth) == Find(per)){
                    known = true;
                    break;
                }
            }
        }
        if(known) result-=1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for (int i=1;i<=N;i++)
        parent[i]=i;

    result=M;

    int prev;
    for(int i=0;i<=M;i++){
        cin>>tn;
        for(int j=0;j<tn;j++){
            prev=tmp;
            cin>>tmp;
            
            if(i==0)
                chk.push_back(tmp);
            else{
                gura[i].push_back(tmp);
                if(j>0){
                    Union(prev,tmp);
                }
            }
                
        }
    }

    ans();
    cout<<result;


    return 0;
}