#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > fpq;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase=0;
  cin>>testcase;
  while(testcase--){
    fpq.clear();
    int N=0,M=0;
    cin>>N>>M;
    int imp=0;
    for(int i=0;i<N;i++) cin>>imp, fpq.push_back(make_pair(imp,i));
    int leng=fpq.size();
    for(int i=0;i<leng-1;i++){
      for(int j=i+1;j<leng;j++){
        if(fpq[i].first<fpq[j].first){
          fpq.push_back(make_pair(fpq[i].first,fpq[i].second));
          fpq.erase(fpq.begin()+i);
          i--;
          break;
        }
      }
    }
    for(int i=0;i<leng;i++){
      if(fpq[i].second==M){
        cout<<i+1<<'\n';
        break;
      }
    }
  }
  return 0;
}
