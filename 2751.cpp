#include<bits/stdc++.h>
using namespace std;
vector<int> dat;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int input,test;
  cin>>input;
  for(int i=0;i<input;i++){
      cin>>test;
      dat.push_back(test);
  }

  sort(dat.begin(),dat.end());

  for(auto it : dat)
    cout<<it<<'\n';
  return 0;
}
