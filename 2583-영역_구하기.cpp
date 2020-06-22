#include<bits/stdc++.h>

using namespace std;

typedef struct Rect{
    int x1;
    int y1;
    int x2;
    int y2;
}rect;

int M,N,K;
int move_y[4]={1,-1,0,0};
int move_x[4]={0,0,1,-1};
vector<rect> rect_in;
vector<int> result;
int chk[101][101];

void check(){
    for(auto it : rect_in){
        for(int i=it.y1+1;i<=it.y2;i++){
            for(int j=it.x1+1;j<=it.x2;j++){
                chk[i][j]=1;
            }
        }
    }
}

void find(int y,int x){
    result[result.size()-1]++;
    chk[y][x]=1;

    for(int i=0;i<4;i++){
        int ny=y+move_y[i];
        int nx=x+move_x[i];

        if(ny>=1&&ny<=M&&nx>=1&&nx<=N&&chk[ny][nx]==0){
            find(ny,nx);
        }
    }
}

bool find_zero(){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(chk[i][j]==0){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N>>K;
    int x1,x2,y1,y2;

    for(int i=0;i<K;i++){
        cin>>x1>>y1>>x2>>y2;
        rect_in.push_back({x1,y1,x2,y2});
    }

    check();

    while(find_zero()){
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(chk[i][j]==0){
                    result.push_back(0);
                    find(i,j);
                }
            }
        }
    }

    sort(result.begin(),result.end(),less<int>());
    cout<<result.size()<<'\n';
    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}
