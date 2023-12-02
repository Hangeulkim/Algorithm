#include<iostream>
#include<vector>

using namespace std;

int N;
char obj[7][7];
vector<pair<int, int> > students;
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

void input(){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>obj[i][j];

            if(obj[i][j]=='S')
                students.push_back({i,j});
        }
    }
}

bool chk(){
    for(int i=0;i<students.size();++i){
        int y = students[i].first;
        int x = students[i].second;
        for(int m=0;m<4;++m){
            int ny = y+my[m];
            int nx = x+mx[m];

            while(ny>0&&nx>0&&ny<=N&&nx<=N){
                
                if(obj[ny][nx]=='T')
                    return false;

                else if(obj[ny][nx]!='X')
                    break;

                ny+=my[m];
                nx+=mx[m];
            }
        }
    }
    return true;
}

bool dfs(int y, int x, int cnt){
    if(cnt == 3){
        return chk();
    }

    for(int i=y;i<=N;++i){
        for(int j=i==y?x:1;j<=N;++j){
            if(obj[i][j]=='X'){
                obj[i][j]='O';
                if(dfs(i,j,cnt+1)){
                    return true;
                }
                obj[i][j]='X';
            }
        }
    }
    return false;
}

void solution(){
    if(dfs(1,1,0))
        cout<<"YES"<<'\n';
    else
        cout<<"NO"<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}