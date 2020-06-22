#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        long long int x1,x2,x3,maxnum=0,sum=0;

        cin>>x1>>x2>>x3;
        if(x1==0&&x2==0&&x3==0) break;

        if(x1>maxnum) maxnum=x1;
        if(x2>maxnum) maxnum=x2;
        if(x3>maxnum) maxnum=x3;

        if(x1!=maxnum) sum+=x1*x1;
        if(x2!=maxnum) sum+=x2*x2;
        if(x3!=maxnum) sum+=x3*x3;

        if(sum==maxnum*maxnum) cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';
    }




    return 0;
}
