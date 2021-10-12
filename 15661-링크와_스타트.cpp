#include<bits/stdc++.h>

using namespace std;

int result=987654321;
int input[21][21];
int chk[21];
int N;

void dfs(int start, int link, int cnt){
    if(cnt==N+1){
        if(start == 0 || link == 0)
            return;

        int st=0,lk=0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(chk[i]!=chk[j])
                    continue;
                if(chk[i]==1){
                    st+=input[i][j]+input[j][i];
                }

                else if(chk[i]==-1){
                    lk+=input[i][j]+input[j][i];
                }
            }
        }

        result=min(result,abs(st-lk));
        return;
    }

    chk[cnt]=1;
    dfs(start+1,link,cnt+1);
    chk[cnt]=-1;
    dfs(start,link+1,cnt+1);
    chk[cnt]=0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
    }
    dfs(0,0,1);
    cout<<result;

    return 0;
}