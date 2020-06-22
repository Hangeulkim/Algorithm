#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int input[100001];
stack<int> stk;
vector<char> ans;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase=0;
  cin>>testcase;
  int cnt=0;
  for(int total=0;total<testcase;total++) cin>>input[total];

  for(int i=1;i<=testcase;i++){
    stk.push(i);
    ans.push_back('+');
    while (!stk.empty()&&stk.top()==input[cnt]) {
      stk.pop();
      ans.push_back('-');
      cnt++;
    }
  }
  if(!stk.empty()) cout<<"NO"<<'\n';
  else
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<'\n';
    }
  return 0;
}
