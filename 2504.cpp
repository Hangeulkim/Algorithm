#include<iostream>
#include<string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>input;
  int result=0, tmp=1;
  int lcount=0;
  int leng=input.length();
  int num1=0,num2=0,num3=0,num4=0;
  double integer, fraction;
  outerLoop :
  for(lcount=0;lcount<leng;lcount++){
    switch (input[lcount]) {
      case '(':
        num1++;
        tmp*=2;
        break;
      case ')':
        num2++;
        if (lcount==0){
          result=0;
          lcount=leng;
          break;
        }
        if (input[lcount-1]=='(') result+=tmp;
        tmp/=2;
        break;
      case '[':
        num3++;
        tmp*=3;
        break;
      case ']':
        num4++;
        if (lcount==0){
          result=0;
          lcount=leng;
          break;
        }
        if (input[lcount-1]=='[') result+=tmp;
        tmp/=3;
        break;
    }
    if(num2>num1){
      result=0;
      break;
    }
    if(num4>num3){
      result=0;
      break;
    }
  }
  if(tmp!=1) result=0;
  cout<<result<<'\n';
  return 0;
}
