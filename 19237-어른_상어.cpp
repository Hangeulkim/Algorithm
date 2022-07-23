#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int sangm[401][4][4];
int sangdat[401][3];
int arr[21][21][2];
int N, M, K;
int ret=1001;

bool none_move(int i){
    int y=sangdat[i][0];
    int x=sangdat[i][1];
    int nowm=sangdat[i][2];

    for(int f=0;f<4;f++){
        int nm=sangm[i][nowm][f];
        int ny=y+m[nm][0];
        int nx=x+m[nm][1];

        if(ny<0||nx<0||ny>=N||nx>=N||arr[ny][nx][1]>0)
            continue;
    
        if(arr[ny][nx][1]==-1){
            sangdat[i][2]=-1;
            return true;
        }
        
        arr[ny][nx][0]=i;
        arr[ny][nx][1]=-1;
        sangdat[i][0]=ny;
        sangdat[i][1]=nx;
        sangdat[i][2]=nm;
        return true;
    }
    return false;
}

void smell_move(int i){
    int y=sangdat[i][0];
    int x=sangdat[i][1];
    int nowm=sangdat[i][2];

    for(int f=0;f<4;f++){
        int nm=sangm[i][nowm][f];
        int ny=y+m[nm][0];
        int nx=x+m[nm][1];

        if(ny<0||nx<0||ny>=N||nx>=N||arr[ny][nx][0]!=i)
            continue;
        
        arr[ny][nx][1]=1001;
        sangdat[i][0]=ny;
        sangdat[i][1]=nx;
        sangdat[i][2]=nm;

        return ;
    }
}

void move_fish(){
    for(int i=1;i<=M;i++){
        if(sangdat[i][2]==-1)
            continue;

        if(!none_move(i))
            smell_move(i);
    }
}

void spray_fish(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j][1]==-1||arr[i][j][1]==1001)
                arr[i][j][1]=K;

            else if(arr[i][j][1]>0){
                --arr[i][j][1];

                if(!arr[i][j][1])
                    arr[i][j][0]=0;
            }
        }
    }
}

bool chka(){
    for(int i=2;i<=M;i++){
        if(sangdat[i][2]!=-1)
            return false;
    }
    return true;
}

void show(int t){
    cout<<t<<'\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j][0]<<" ";
        }
        cout<<'\t';
        for(int j=0;j<N;j++){
            cout<<arr[i][j][0]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=0;i<N;i++){
        cout<<i<<" "<<sangdat[i][0]<<" "<<sangdat[i][1]<<" "<<sangdat[i][2]<<'\n';
    }
    cout<<'\n';
}

void dfs(int t){
    if(t>1000){
        ret=t;
        return;
    }

    move_fish();
    spray_fish();

    if(chka()){
        ret=t;
        return ;
    }
    
    dfs(t+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j][0];
            if(!arr[i][j][0])
                continue;
            arr[i][j][1] = K;
            sangdat[arr[i][j][0]][0]=i;
            sangdat[arr[i][j][0]][1]=j;
        }
    }

    for (int i = 1; i <= M; i++){
        cin >> sangdat[i][2];
        --sangdat[i][2];
    }
        

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> sangm[i][j][0] >> sangm[i][j][1] >> sangm[i][j][2] >> sangm[i][j][3];
            --sangm[i][j][0];
            --sangm[i][j][1];
            --sangm[i][j][2];
            --sangm[i][j][3];
        }
    }

    dfs(1);

    if(ret>1000)
        cout<<-1<<'\n';
    else
        cout<<ret<<'\n';

    return 0;
}