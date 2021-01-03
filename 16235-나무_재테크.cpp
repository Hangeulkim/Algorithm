#include<bits/stdc++.h>

using namespace std;

int N,M,K;
int x,y,z;
int yang[12][12];
int now[12][12];
deque<int> tree[1001][12][12];
int my[8]={-1,-1,-1,0,0,1,1,1};
int mx[8]={-1,0,1,-1,1,-1,0,1};

int dfs(int year){
    if(year==0){
        int result=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                result+=tree[year][i][j].size();
            }
        }
        return result;
    }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int boom=0;
            int len=tree[year][i][j].size();

            for(int z=0;z<len;z++){
                int age=tree[year][i][j].front();
                tree[year][i][j].pop_front();

                if(now[i][j]>=age){
                    now[i][j]-=age;
                    tree[year-1][i][j].push_back(age+1);

                    if((age+1)%5==0){
                        for(int m=0;m<8;m++){
                            int ny=i+my[m];
                            int nx=j+mx[m];
                            if(ny<1||nx<1||ny>N||nx>N)
                                continue;

                            tree[year-1][ny][nx].push_front(1);
                        }
                    }
                }

                else{
                    boom+=age/2;
                }
            }
            now[i][j]+=boom+yang[i][j];
        }
    }

    return dfs(year-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>yang[i][j];
            now[i][j]=5;
        }
    }
    for(int i=0;i<M;i++){
        cin>>y>>x>>z;
        tree[K][y][x].push_back(z);
    }

    cout<<dfs(K);

    return 0;
}
