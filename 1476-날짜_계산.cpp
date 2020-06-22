#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int E=0,S=0,M=0;
    cin>>E>>S>>M;
    int cnt=1;
    int tmpE=1,tmpS=1,tmpM=1;
    while(1){
        if(tmpE==E&&tmpS==S&&tmpM==M) break;
        tmpE++;
        tmpS++;
        tmpM++;
        if(tmpE>15) tmpE=1;
        if(tmpS>28) tmpS=1;
        if(tmpM>19) tmpM=1;
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
