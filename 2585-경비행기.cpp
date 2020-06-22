#include<bits/stdc++.h>

using namespace std;

typedef struct POS{
    int x;
    int y;
}pos;

int n,k,x,y;
int btm=1,top;
vector<pos> input;
bool chk[10001];
pos S={0,0};
pos T={10000,10000};

int dis(pos a, pos b){
    return ceil(sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2))/10);
}

bool bfs(int mid){
      fill(chk,chk+10001,false);
      queue<pos> q;
      q.push(S);
      chk[0]=true;

      while(!q.empty()){
          int start=q.front().x;
          int cnt=q.front().y;
          q.pop();

          if(start==input.size()-1){
              if(cnt<=k+1) return true;
              return false;
          }

          for(int i=1;i<input.size();i++){
              if(!chk[i]&&dis(input[i],input[start])<=mid){
                  chk[i]=true;
                  q.push({i,cnt+1});
              }
          }
      }
      return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    input.push_back(S);
    for(int i=0;i<n;i++){
        cin>>x>>y;
        input.push_back({x,y});
    }
    input.push_back(T);

    top=dis(S,T);
    int result=top;

    while(btm<=top){
        int mid=(btm+top)/2;

        if(bfs(mid)){
            top=mid-1;
            result=mid;
        }
        else
            btm=mid+1;
    }
    cout<<result<<'\n';

    return 0;
}
