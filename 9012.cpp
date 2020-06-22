#include<iostream>
#include<string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase=0;
  cin>>testcase;
  string input;
  for(int i=0;i<testcase;i++){
    cin>>input;
    int j=0;
    int num1=0,num2=0;
    for(j=0;j<input.length();j++){
      if(input[j]=='(') num1++;
      else num2++;
      if(num2>num1) {
        cout<<"NO"<<'\n';
        break;
      }
    }
    if(j==input.length()){
      if(num1!=num2) cout<<"NO"<<'\n';
      else cout<<"YES"<<'\n';
    }
  }
  return 0;
}
