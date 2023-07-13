#include<iostream>

using namespace std;

int dap[10];
int ans = 0;

void input(){
    for(int i=0;i<10;++i){
        cin>>dap[i];
    }
}

void dfs(int num, int collect, int prev, int dupcnt){
    if(num == 10){
        if(collect >= 5)
            ++ans;

        return ;
    }

    for(int i=1;i<=5;++i){
        int ncol = collect + (i == dap[num]);

        if(prev == i){
            if(dupcnt == 2)
                continue;

            dfs(num + 1, ncol, i, dupcnt + 1);
        }
        else{
            dfs(num + 1, ncol, i, 1);
        }
    }
}

void solution(){
    dfs(0, 0, 0, 0);

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