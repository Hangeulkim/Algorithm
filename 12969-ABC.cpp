#include<bits/stdc++.h>

using namespace std;

int N,K;
bool visit[501][31][31][31];
char ans[31];

bool find(int n, int a, int b, int c, int gap){
    if(visit[gap][a][b][c]||gap>K){
        return false;
    }
    visit[gap][a][b][c]=true;
    if(n==N){
        if(gap==K)
            return true;
        return false;
    }

    ans[n]='A';
    if(find(n+1,a+1,b,c,gap)) return true;

    ans[n]='B';
    if(find(n+1,a,b+1,c,gap+a)) return true;

    ans[n]='C';
    if(find(n+1,a,b,c+1,gap+a+b)) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>N>>K;
    if(find(0,0,0,0,0)){
            cout<<ans;
    }
    else{
        cout<<-1<<'\n';
    }


    return 0;
}
