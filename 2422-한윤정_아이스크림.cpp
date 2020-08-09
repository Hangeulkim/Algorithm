#include<bits/stdc++.h>

using namespace std;

int N,M;
int y,x;
bool n[201][201];
int cnt=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(n,false,sizeof(n));
    vector<int> c;
    cin>>N>>M;
    while(M--){
        cin>>y>>x;
        n[y][x]=true;
        n[x][y]=true;
    }

    for(int c1=1;c1<=N-2;c1++){
        for(int c2=c1+1;c2<=N-1;c2++){
            for(int c3=c2+1;c3<=N;c3++){
                if(!n[c1][c2]&&!n[c1][c3]&&!n[c2][c3])
                    cnt++;
            }
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
