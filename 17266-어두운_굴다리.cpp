#include<iostream>

using namespace std;

int ans=1;
int N,M,C;

void solution(){
    int garo1, garo2;

    cin>>N>>M;
    garo1 = 0;
    for(int i=0;i<M;++i){
        cin>>garo2;
        if(i==0){
            ans = max(ans, garo2);
        }
        if(i==M-1){
            ans = max(ans, N-garo2);
        }
        else{
            ans = max(ans, (garo2-garo1+1)/2);
        }
        garo1=garo2;
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}