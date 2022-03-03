#include <string>
#include <vector>
#include <queue>
#define mod 1'000'000'007
    
using namespace std;



typedef struct Dat{
    int y,x;
}dat;

int dp[101][101];
bool chk[101][101];
int my[2]={0,1};
int mx[2]={1,0};

void bfs(int m, int n){
    queue<dat> q;
    
    q.push({1,1});
    chk[1][1]=true;
    dp[1][1]=1;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        
        q.pop(); 
        
        if(dp[y-1][x]!=-1)
            dp[y][x]=(dp[y][x]+dp[y-1][x])%mod;
        if(dp[y][x-1]!=-1)
            dp[y][x]=(dp[y][x]+dp[y][x-1])%mod;
            
        for(int i=0;i<2;i++){
            int ny=y+my[i];
            int nx=x+mx[i];
            
            if(ny>n||nx>m||chk[ny][nx]||dp[ny][nx]==-1)
                continue;
            
            q.push({ny,nx});
            chk[ny][nx]=true;
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto it : puddles)
        dp[it[1]][it[0]]=-1;
    
    bfs(m,n);
    
    answer=dp[n][m];
    return answer;
}