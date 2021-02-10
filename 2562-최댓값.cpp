#include<bits/stdc++.h>

using namespace std;

int maxnum=0,input;
int idx=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    for(int i=1;i<=9;i++){
        cin>>input;
        if (input>maxnum) {
            idx=i;
            maxnum=input;
        }
    }
    cout<<maxnum<<'\n'<<idx;

    return 0;
}
