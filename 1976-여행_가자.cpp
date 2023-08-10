#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int dist[201][201];
int chk[201];
vector<int> cities;

void input(){
    cin>>N>>M;

    cities.resize(M);
    for(int i=1;i<=N;++i){
        chk[i]=i;
        for(int j=1;j<=N;++j){
            cin>>dist[i][j];
        }
    }
    for(int i=0;i<M;++i){
        cin>>cities[i];
    }
}

int findf(int num){
    if(num != chk[num])
        chk[num] = findf(chk[num]);
    return chk[num];
}

void unionf(int num1, int num2){
    num1 = findf(num1);
    num2 = findf(num2);

    chk[max(num1, num2)] = min(num1,num2);
}

bool calc(){
    int num = chk[cities[0]];
    for(int i=0;i<M;++i){
        if(num != chk[cities[i]])
            return false;
    }
    return true;
}

void solution(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(dist[i][j]){
                unionf(i,j);
            }
        }
    }

    if(calc())
        cout<<"YES"<<'\n';
    else
        cout<<"NO"<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}