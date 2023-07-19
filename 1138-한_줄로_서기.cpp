#include<iostream>

using namespace std;

int N;
int jul[11];
int arr[11];

void input(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
}

bool dfs(int now){
    if(now == N){
        for(int i=0;i<N;++i){
            int cnt = 0;
            int node = i+1;

            for(int j=0;jul[j]!=node;++j)
                if(jul[j] > node)
                    ++cnt;

            if(cnt != arr[node-1])
                return false;
        }

        return true;
    }
        
    for(int i=arr[now];i<N;++i){
        if(jul[i]==0){
            jul[i] = now+1;
            if(dfs(now+1))
                return true;
            jul[i] = 0;
        }
    }


    return false;
}

void solution(){
    dfs(0);
    
    for(int i=0;i<N;++i)
        cout<<jul[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}