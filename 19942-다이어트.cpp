#include<iostream>
#include<string>

using namespace std;

int N;

int nut[16][5];
int minNut[4];
int ansCost = 987'654'321;
string ansStr;

void input(){
    cin>>N;
    cin>>minNut[0]>>minNut[1]>>minNut[2]>>minNut[3];
    for(int i=0;i<N;++i){
        cin>>nut[i][0]>>nut[i][1]>>nut[i][2]>>nut[i][3]>>nut[i][4];
    }
}

void dfs(int node, int cost, string chk, int mp, int mf, int ms, int mv){
    if(mp >= minNut[0] && mf >= minNut[1] && ms >= minNut[2] && mv >= minNut[3]){
        if(ansCost > cost){
            ansCost = cost;
            ansStr = chk;
        }
        return;
    }

    for(int i=node+1;i<N;++i){
        dfs(i,cost + nut[i][4], chk + to_string(i+1) + " ", mp+nut[i][0], mf+nut[i][1], ms+nut[i][2], mv+nut[i][3]);
    }
}

void solution(){
    for(int i=0;i<N;++i){
        dfs(i,nut[i][4],to_string(i+1) + " ", nut[i][0], nut[i][1], nut[i][2], nut[i][3]);
    }

    if(ansCost == 987'654'321){
        cout<<-1<<'\n';
    }
    else{
        cout<<ansCost<<'\n'<<ansStr<<'\n';
    }

    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}