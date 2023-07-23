#include<iostream>
#include<string>

using namespace std;

int N;
string balls;

void input(){
    cin>>N>>balls;
}

void solution(){
    bool rf = false, bf = false;
    int rc = 0, bc = 0;
    int ans = 987'654'321;

    for(int i=0;i<N;++i){
        if(balls[i] == 'R')
            bf = true;
        else
            rf = true;
        
        if(bf && balls[i] == 'B')
            ++bc;
        if(rf && balls[i] == 'R')
            ++rc;
    }

    ans = min(rc,bc);

    rf = false;
    bf = false;
    rc = 0, bc = 0;

    for(int i=N-1;i>=0;--i){
        if(balls[i] == 'R')
            bf = true;
        else
            rf = true;
        
        if(bf && balls[i] == 'B')
            ++bc;
        if(rf && balls[i] == 'R')
            ++rc;
    }

    ans = min(ans, min(rc, bc));

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}