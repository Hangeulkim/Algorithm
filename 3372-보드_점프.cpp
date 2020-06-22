#include<bits/stdc++.h>

using namespace std;

int n;
int input[101][101];
int my[2]={1,0};
int mx[2]={0,1};

vector<int> dp[101][101];
vector<int> z;
vector<int> num;

vector<int> hap(vector<int> a, vector<int> b){
    for(int i=0;i<b.size();i++){
        if(a.size()==i){
            a.push_back(0);
        }
        a[i]+=b[i];
        int j=i;
        while(a[j]>=10){
            a[j++]-=10;
            if(a.size()==j){
                a.push_back(0);
            }
            a[j]+=1;
        }
    }
    return a;
}

vector<int> dfs(int y, int x){
    if(y==n&&x==n){
        return num;
    }

    else if(input[y][x]==0){
        return z;
    }

    if(dp[y][x].size()!=0){
        return dp[y][x];
    }

    dp[y][x].push_back(0);
    for(int i=0;i<2;i++){
        int ny=y+input[y][x]*my[i];
        int nx=x+input[y][x]*mx[i];
        if(ny>0&&nx>0&&ny<=n&&nx<=n){
            dp[y][x]=hap(dp[y][x],dfs(ny,nx));
        }
    }
    return dp[y][x];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    num.push_back(1);
    z.push_back(0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>input[i][j];
        }
    }

    dfs(1,1);
    for(int i=dp[1][1].size()-1;i>=0;i--){
        printf("%d",dp[1][1][i]);
    }

    return 0;
}
