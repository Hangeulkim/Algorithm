#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct D{
    int y,x,cnt;
}d;

int N;
int arr[131][131];
int dp[131][131];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

int bfs(){
    queue<d> q;
    q.push({0,0,arr[0][0]});
    dp[0][0]=arr[0][0];

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;

        q.pop();

        if(dp[y][x]<cnt)
            continue;
        
        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=N||dp[ny][nx]<=cnt+arr[ny][nx])
                continue;
            
            q.push({ny,nx,cnt+arr[ny][nx]});
            dp[ny][nx]=cnt+arr[ny][nx];
        }
    }


    return dp[N-1][N-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(1){
        cin>>N;
        if(N==0)
            break;

        fill(&dp[0][0],&dp[N][N+1],987654321);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>arr[i][j];
            }
        }

        cout<<"Problem "<<t++<<": "<<bfs()<<'\n';
    }

    return 0;
}