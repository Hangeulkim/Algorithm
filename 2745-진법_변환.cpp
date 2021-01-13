#include<bits/stdc++.h>

using namespace std;

int N,B;
string zin;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>zin>>B;
    int k=1;
    for(int i=zin.length()-1;i>=0;i--,k*=B){
        if(zin[i]>='0'&&zin[i]<='9')
            N+=(zin[i]-'0')*k;
        else
            N+=(zin[i]-'A'+10)*k;
    }
    cout<<N;

    return 0;
}
