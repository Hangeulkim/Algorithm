#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> state;
int T;
int s,n;

void input(){
    cin>>N;
    state.resize(N+2);
    for(int i=1;i<=N;++i){
        cin>>state[i];
    }
}

void solution(){
    cin>>T;
    while(T--){
        cin>>s>>n;

        if(s==1){
            int idx=1;
            while(n*idx<=N){
                state[n*idx]=state[n*idx]?0:1;
                ++idx;
            }
                
        }
        else{
            int idx=1;
            state[n]=state[n]?0:1;
            while(n-idx>0&&n+idx<=N&&state[n-idx]==state[n+idx]){
                state[n-idx]=state[n-idx]?0:1;
                state[n+idx]=state[n+idx]?0:1;
                ++idx;
            }
        }
    }
    for(int i=1;i<=N;++i){
        cout<<state[i]<<" ";
        if(i%20==0)
            cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}