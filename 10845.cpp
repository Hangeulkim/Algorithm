#include<iostream>
#include<string>

using namespace std;
int arr[10001];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase=0;
  cin>>testcase;
  string input;
  int front=0,back=0;
  for(int i=0;i<testcase;i++){
    cin>>input;
    int chk=0;
    int pushnum=0;
    if(input=="push"){
      cin>>pushnum;
      arr[back]=pushnum;
      back++;
    }
    else if(input=="pop"){
      if (front==back) cout<<"-1"<<'\n';
      else{
        cout<<arr[front]<<'\n';
        arr[front]=0;
        front++;
      }
    }
    else if(input=="size"){
      cout<<back-front<<'\n';
    }
    else if(input=="empty"){
      if (front==back) cout<<"1"<<'\n';
      else cout<<"0"<<'\n';
    }
    else if(input=="front"){
      if (front==back) cout<<"-1"<<'\n';
      else cout<<arr[front]<<'\n';
    }
    else if(input=="back"){
      if (front==back) cout<<"-1"<<'\n';
      else cout<<arr[back-1]<<'\n';
    }
  }




  return 0;
}
