#include<iostream>
#include<vector>

using namespace std;

int N,T,P;
vector<int> ranks;

void input(){
    cin>>N>>T>>P;
    ranks.resize(N+1);
    for(int i=0;i<N;++i){
        cin>>ranks[i];
    }
}

void solution(){
    int cnt=1;
    for(int i=0;i<N&&i<P;++i){
        if(ranks[i]<T){
            if(i>0&&ranks[i-1]>T)
                cnt=i+1;
            cout<<cnt<<'\n';
            return;
        }
        if(i>0&&ranks[i-1]>ranks[i])
            cnt=i+1;
    }
    
    if(N<P){
        if(ranks[N-1]==T)
            cout<<cnt<<'\n';
        else
            cout<<N+1<<'\n';
    } 
    else
        cout<<-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}