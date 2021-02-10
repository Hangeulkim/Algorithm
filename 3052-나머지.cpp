#include<bits/stdc++.h>

using namespace std;

int num=42,input;
bool chk[42];
int ret=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(chk,false,sizeof(chk));


    for(int i=1;i<=10;i++){
        cin>>input;
        if (chk[input%42]) {
            continue;
        }

        chk[input%42]=true;
        ret++;
    }
    cout<<ret;

    return 0;
}
