#include<iostream>

using namespace std;

int N;
int arr[100001];
int chk[100001];
long long ans=0;

void input(){
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
}

void calc(){
    fill(&chk[0], &chk[100001], -1);
    int l=0,r=1;
    ans = 1;

    chk[arr[0]] = 0;
    while(r<N){
        int num = arr[r];
        if(chk[num] >= l){
            l = chk[num]+1;
        }

        ans += r-l+1;
        chk[num] = r;
        ++r;
    }
}

void solution(){
    calc();
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