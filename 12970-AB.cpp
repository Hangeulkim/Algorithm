#include<bits/stdc++.h>

using namespace std;

int N,K;
char ans[2500];
bool visit[2500][51];

bool find(int n, int a, int k){
    if(n<0||k>K||visit[k][a]){
        return false;
    }

    if(n==0){
        if(k==K)
            return true;
        return false;
    }

    visit[k][a]=true;
    ans[N-n]='A';
    if(find(n-1,a+1,k)) return true;

    ans[N-n]='B';
    if(find(n-1,a,k+a)) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(ans,'\0',sizeof(ans));
    memset(visit,false,sizeof(visit));
    cin>>N>>K;
    if(find(N,0,0)){
        cout<<ans<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}
