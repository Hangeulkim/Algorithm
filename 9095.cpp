#include<iostream>
using namespace std;
int num[11]={1,2,4,};
int main()
{
  int a=0;
  cin >> a;
  int numbering[a];
  for(int i=0;i<a;i++)
    cin >> numbering[i];
  for(int i=3;i<10;i++)
    num[i]=num[i-3]+num[i-2]+num[i-1];
  for(int i=0;i<a;i++)
    cout << num[numbering[i]-1] << '\n';
  return 0;
}
