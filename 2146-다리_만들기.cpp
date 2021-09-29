#include<bits/stdc++.h>

using namespace std;

int N;

int arr[101][101];
int chk[101][101];
int sd[101][101];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

typedef struct Dat{
    int y,x,cnt,dae;
}dat;

queue<dat> st;


void dfs(int y, int x, int num){
    sd[y][x]=num;

    for(int m=0;m<4;m++){
        int ny=y+my[m];
        int nx=x+mx[m];

        if(ny<0||nx<0||ny>=N||nx>=N||!arr[ny][nx]||sd[ny][nx]!=-1)
            continue;

        dfs(ny,nx,num);
    }

}

int bfs(){
    while(!st.empty()){
        int y=st.front().y;
        int x=st.front().x;
        int cnt=st.front().cnt;
        int dae=st.front().dae;

        st.pop();
        
        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=N)
                continue;
            
            if(chk[ny][nx]!=-1){
                continue;
            }
                
            st.push({ny,nx,cnt+1,dae});
            chk[ny][nx]=cnt+1;
            sd[ny][nx]=dae;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            chk[i][j]=-1;
            sd[i][j]=-1;
        }
    }

    int num=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]){
                if(sd[i][j]==-1)
                    dfs(i,j,num++);
                st.push({i,j,0,sd[i][j]});
                chk[i][j]=0;
            }
        }
    }

    bfs();

    int ret=987654321;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int m=0;m<4;m++){
                int ny=i+my[m];
                int nx=j+mx[m];

                if(ny<0||nx<0||ny>=N||nx>=N)
                    continue;
                
                if(sd[i][j]!=sd[ny][nx])
                    ret=min(ret,chk[i][j]+chk[ny][nx]);
            }
        }
    }
    cout<<ret;

    return 0;
}