#include<bits/stdc++.h>

using namespace std;

string input[5][5];

int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

vector<string> result;

bool chk(string d){
    int sz=result.size();
    for(int i=0;i<sz;i++){
        if(d.compare(result[i])==0)
            return true;
    }
    return false;
}

void dfs(int y, int x, string d, int cnt){
    if(cnt==6){
        if(!chk(d))
            result.push_back(d);
        return;
    }

    for(int i=0;i<4;i++){
        int ny=y+my[i];
        int nx=x+mx[i];

        if(ny<0||nx<0||ny>4||nx>4)
            continue;

        dfs(ny,nx,d+input[ny][nx],cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            cin>>input[y][x];
        }
    }

    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            dfs(y,x,input[y][x],1);
        }
    }
    cout<<result.size()<<'\n';

    return 0;
}
