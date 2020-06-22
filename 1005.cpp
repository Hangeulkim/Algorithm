#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int ti[1001];
int result[1001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int, int> > > pq;
int last=0;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase=0;
  cin>>testcase;
  for(int i=0;i<testcase;i++){
    int buildnum=0, seq=0;
    int start=0,end=0;
    cin>>buildnum>>seq;
    memset(ti,0,1001);
    memset(result,0,1001);
    for(int j=0;j<buildnum;j++){
      cin>>ti[j+1];
    }
    for(int j=0;j<seq;j++){
      cin>>start>>end;
      pq.push(make_pair(end,start));
    }
    cin>>last;

    int leng=pq.size();
    for(int j=0;j<leng;j++){
      result[pq.top().first]=max(result[pq.top().first],result[pq.top().second]+ti[pq.top().first]);
      pq.pop();
    }
    cout<<result[last]+ti[last]<<'\n';
  }



  return 0;
}
