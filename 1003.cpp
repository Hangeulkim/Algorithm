#include<iostream>

using namespace std;
int cnt0[44]={1,0};
int cnt1[44]={0,1};

void fibonacci(int n){
  for(int i=2;i<=n;i++){
    cnt0[i]=cnt0[i-1]+cnt0[i-2];
    cnt1[i]=cnt1[i-1]+cnt1[i-2];
  }
}

int main(){
  int testcase=0;
  int inputnum=0;
  scanf("%d",&testcase);
  for(int i=0;i<testcase;i++){
    scanf("%d",&inputnum);
    fibonacci(inputnum);
    printf("%d %d\n",cnt0[inputnum],cnt1[inputnum]);
  }
}
