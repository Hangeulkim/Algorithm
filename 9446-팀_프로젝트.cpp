#include<bits/stdc++.h>

using namespace std;

int student[100001],tc=0,testcase=0;
int chk[100001];

void dfs(int start){
    if(chk[start]==1) return;

    if(chk[student[start]]==2||chk[student[start]]==1){
        chk[start]=2;
        return;
    }

    chk[start]=-1;

    if(chk[student[start]]==-1){
        chk[start]=1;
        dfs(student[start]);
        chk[student[start]]=1;
    }

    else if(chk[student[start]]==0){
        dfs(student[start]);
        if(chk[start]==-1){
            chk[start]=2;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;

    while(testcase--){
        cin>>tc;
        for(int i=1;i<=tc;i++){
            cin>>student[i];
            chk[i]=0;
        }
        for(int i=1;i<=tc;i++){
            if(chk[i]==0) dfs(i);
        }

        int cnt=0;
        for(int i=1;i<=tc;i++){
            if(chk[i]==2) cnt++;
        }
        cout<<cnt<<'\n';
    }


    return 0;
}
