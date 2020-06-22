#include<iostream>
#include<queue>

using namespace std;

queue<int> p;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cnt=1;
  int M=0,N=0;
  cin>>N>>M;

  for(int i=1;i<=N;i++) p.push(i);

  cout<<"<";
  for(int i=0;!p.empty();i++){
    for(int j=0;j<M-1;j++){
      p.push(p.front());
      p.pop();
    }
    if(p.size()==1) cout<<p.front();
    else cout<<p.front()<<", ";
    p.pop();
  }
  cout<<">"<<'\n';

  return 0;
}
