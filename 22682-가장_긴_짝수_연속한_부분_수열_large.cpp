#include<iostream>
#include<vector>

using namespace std;

int N, K;
vector<int> S;

void input(){
    int a;

    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>a;
        S.push_back(a);
    }
}

void solution(){
    int l=0, r=0, cnt=0;
    int ans=0;

    while(r<N){
        if(S[r] % 2 == 1){
            ++cnt;
        }

        while(cnt>K && l<r){
            cnt -= S[l++] % 2;
        }

        ans = max(ans, r-l+1-cnt);
        
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