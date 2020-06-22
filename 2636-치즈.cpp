#include<bits/stdc++.h>

using namespace std;

int cheese[105][105];
int N,M,cnt=0,take_time=0;
int y[4]={0,0,1,-1};
int x[4]={1,-1,0,0};

void air_check();
void find();
bool all_check();
bool all_air_check();

void air_check(){
    vector<pair<int, int> > change_cheese;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<4;k++){
                if(cheese[i+y[k]][j+x[k]]==2&&cheese[i][j]==0){
                    change_cheese.push_back(make_pair(i,j));
                    break;
                }
            }
        }
    }

    for(auto it : change_cheese){
        cheese[it.first][it.second]=2;
    }

    if(all_air_check()) air_check();
}

bool all_air_check(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<4;k++){
                if(cheese[i+y[k]][j+x[k]]==2&&cheese[i][j]==0){
                    return true;
                }
            }
        }
    }
    return false;
}

bool all_check(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(cheese[i][j]==1){
                return true;
            }
        }
    }
    return false;
}

void find(){
    air_check();

    vector<pair<int, int> > bye;
    cnt=0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(cheese[i][j]==1) cnt++;
            for(int k=0;k<4;k++){
                if(cheese[i+y[k]][j+x[k]]==2&&cheese[i][j]==1){
                    bye.push_back(make_pair(i,j));
                    break;
                }
            }
        }
    }
    for(auto it : bye){
        cheese[it.first][it.second]=2;
    }
    take_time++;
    if(all_check()){
        find();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;

    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if(i==0||i==N+1||j==0||j==M+1){
                cheese[i][j]=2;
            }
            else{
                cin>>cheese[i][j];
            }
        }
    }

    find();

    cout<<take_time<<'\n'<<cnt<<'\n';

    return 0;
}
