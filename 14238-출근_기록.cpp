#include<bits/stdc++.h>

using namespace std;

string input;
int num[3];
bool visit[51][51][51][3][3];
char ans[51];
int cnt=0;

bool find(int A, int B, int C, int next, int nnext){
    if(!A&&!B&&!C)
        return true;

    if(A>=1&&!visit[A-1][B][C][0][next]){
        ans[cnt++]='A';
        visit[A-1][B][C][0][next]=true;
        if(find(A-1,B,C,0,next)){
            return true;
        }
        ans[--cnt]=0;
    }
    if(B>=1&&!visit[A][B-1][C][1][next]&&next!=1){
        ans[cnt++]='B';
        visit[A][B-1][C][1][next]=true;
        if(find(A,B-1,C,1,next)){
            return true;
        }
        ans[--cnt]=0;
    }
    if(C>=1&&!visit[A][B][C-1][2][next]&&next!=2&&nnext!=2){
        ans[cnt++]='C';
        visit[A][B][C-1][2][next]=true;
        if(find(A,B,C-1,2,next)){
            return true;
        }
        ans[--cnt]=0;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>input;
    for(int i=0;i<input.size();i++){
        num[input[i]-'A']++;
    }
    if(find(num[0],num[1],num[2],-1,-1)){
        for(int i=input.size()-1;i>=0;i--){
            cout<<ans[i];
        }
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}
