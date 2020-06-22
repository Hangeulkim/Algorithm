#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#define FALSE  0
#define TRUE   1

using namespace std;

queue<int> bfsroot;
stack<int> dfsroot;
vector<int> a[1001];
int outdfs[1001];
int outbfs[1001];

void bfs(int cur){
  fill(outbfs,outbfs+1001,0);
  bool c[1001];
  fill(c+0,c+1001,FALSE);
  int cnt=0;
  bfsroot.push(cur);
  c[cur]=TRUE;
  outbfs[cnt]=cur;
  cnt++;
  while(!bfsroot.empty()){
    for(int j=0;j<a[cur].size();j++){
      int next=a[cur][j];
      if(!c[next]){
        bfsroot.push(next);
        outbfs[cnt]=next;
        c[next]=TRUE;
        cnt++;
      }
    }
    bfsroot.pop();
    if(!bfsroot.empty()) cur=bfsroot.front();
  }
  for(int j=0;outbfs[j]!=0;j++){
    cout<<outbfs[j]<<" ";
  }
  cout<<'\n';
}

void dfs(int cur){
  fill(outdfs,outdfs+1001,0);
  bool c[1001];
  fill(c+0,c+1001,FALSE);
  int cnt=0;
  dfsroot.push(cur);
  outdfs[cnt]=cur;
  c[cur]=TRUE;
  cnt++;
  while(!dfsroot.empty()){
    for(int j=0;j<a[cur].size();j++){
      int next=a[cur][j];
      if(c[next]){
        if(j==a[cur].size()-1) {
          dfsroot.pop();
          if(!dfsroot.empty()) cur=dfsroot.top();
        }
        continue;
      }
      else{
        outdfs[cnt]=next;
        dfsroot.push(next);
        cnt++;
        c[next]=TRUE;
        cur=next;
        break;
      }
    }
  }
  for(int j=0;outdfs[j]!=0;j++){
    cout<<outdfs[j]<<" ";
  }
  cout<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N=0,M=0,V=0;
  cin>>N>>M>>V;
  int start=0,end=0;
  for(int i=0;i<M;i++){
    cin>>start>>end;
    a[start].push_back(end);
    a[end].push_back(start);
  }
  for(int i=1;i<=N;i++)
    sort(a[i].begin(), a[i].end());
  dfs(V);
  bfs(V);

  return 0;
}
