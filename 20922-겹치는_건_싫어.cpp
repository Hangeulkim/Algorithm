#include<iostream>

using namespace std;

int N,K;
int arr[200001];
int chk[100001];

void input(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
}

void solution(){
    int ans = 0;
    int l=0, r=0;

    while(r<N){
        ++chk[arr[r]];

        while(chk[arr[r]] > K){
            --chk[arr[l++]];
        }

        ans = max(ans, r-l+1);
        ++r;
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