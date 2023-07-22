#include<iostream>
#include<vector>

using namespace std;

int N,D,K,C;
int arr[30001];
int chk[30001];
int ans = 0;

void input(){
    cin>>N>>D>>K>>C;
    for(int i=0;i<N;++i)
        cin>>arr[i];
}

void solution(){
    int l=0;
    int cnt=0;

    for(int i=0;i<K;++i){
        int idx = l + i;
        int num = arr[idx];
        
        if(!chk[num]){
            ++cnt;
        }

        ++chk[num];
    }

    ans = chk[C] ? cnt : cnt+1;

    while(++l<N){
        int idx = l-1;
        --chk[arr[idx]];
        if(!chk[arr[idx]])
            --cnt;

        idx = (l+K-1)%N;
        ++chk[arr[idx]];
        if(chk[arr[idx]] == 1)
            ++cnt;

        ans = max(ans, chk[C] ? cnt : cnt + 1);
    }

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