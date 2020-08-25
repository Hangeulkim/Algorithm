#include<bits/stdc++.h>

using namespace std;

int input[502][1002];
int blk[502][1002];
int chk[255002];
int N;
int ans=-1;
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
vector<int> path[255002];

void graph() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N*2; j++) {
            int now = blk[i][j];
            for (int k=0; k<4; k++) {
                int ny = i+my[k];
                int nx = j+mx[k];
                if (ny < 1 || ny > N || nx < 1 || nx > N*2+1) continue;
                int next = blk[ny][nx];
                if (now != next && input[i][j] == input[ny][nx]) {
                    path[now].push_back(next);
                }
            }
        }
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    chk[1]=0;
    while(!q.empty()){
        int num=q.front();

        q.pop();

        for(auto nnum : path[num]){
            if(chk[nnum]!=-1) continue;
            ans=max(ans,nnum);
            chk[nnum]=num;
            q.push(nnum);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,-1,sizeof(input));
    memset(blk,-1,sizeof(blk));
    memset(chk,-1,sizeof(chk));
    int blknum=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        if(i%2==1){
            for(int j=1;j<=N*2;j++){
                if(j%2==1)
                    blknum++;
                cin>>input[i][j];
                blk[i][j]=blknum;
            }

        }
        else{
            for(int j=2;j<=N*2-1;j++){
                if(j%2==0)
                    blknum++;
                cin>>input[i][j];
                blk[i][j]=blknum;
            }

        }
    }
    graph();
    bfs();

    vector<int> result;
    int num=ans;
    result.push_back(num);
    while(chk[num]){
        num=chk[num];
        result.push_back(num);
    }
    cout<<result.size()<<'\n';
    for(int i=result.size()-1;i>=0;i--)
        cout<<result[i]<<" ";

    return 0;
}
