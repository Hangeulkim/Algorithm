#include<bits/stdc++.h>

using namespace std;

int N;
long long num[10];

void chk(int n, int digit){
    while(n>0){
        num[n%10]+=digit;
        n/=10;
    }
}

void find(int start, int end, int digit){
    while(start%10!=0 && start<=end){
        chk(start,digit);
        start++;
    }
    if(start>end) return ;
    while(end%10!=9 && start<=end){
        chk(end,digit);
        end--;
    }

    int cnt=end/10-start/10+1;
    for(int i=0;i<10;i++)
        num[i]+=cnt*digit;

    find(start/10,end/10,digit*10);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    find(1,N,1);
    for(int i=0;i<10;i++)
        cout<<num[i]<<" ";
    cout<<'\n';


    return 0;
}
