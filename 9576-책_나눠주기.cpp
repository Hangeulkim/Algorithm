#include<bits/stdc++.h>

using namespace std;

int testcase;
int N,M;
int a,b;
bool chk[1001];
int A[1001],B[1001];
vector<int> input[1001];

bool dfs(int i){
    chk[i]=true;
    for(int j : input[i]){
        if(B[j] == -1 || !chk[B[j]]&&dfs(B[j])){
            B[j]=i;
            A[i]=j;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;
    while(testcase--){
        cin>>N>>M;

        for(int i=1;i<=M;i++){
            cin>>a>>b;
            input[i].clear();
            for(int j=a;j<=b;j++)
                input[i].push_back(j);
        }

        int cnt=0;
        fill(A,A+1001,-1);
        fill(B,B+1001,-1);
        for(int i=1;i<=M;i++){
            if(A[i]==-1){
                fill(chk,chk+1001,false);
                if(dfs(i)) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
