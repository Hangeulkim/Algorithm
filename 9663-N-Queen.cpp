#include<bits/stdc++.h>

using namespace std;

int cnt=0,N;

void find(int num,bool ch[20][20]){
    for(int i=1;i<=N;i++){
        ch[num][i]=false;

        for(int j=1;j<=num-1;j++){
            if(i-j>=1&&!ch[num-j][i-j]){
                ch[num][i]=true;
            }
            if(i+j<=N&&!ch[num-j][i+j]){
                ch[num][i]=true;
            }
            if(!ch[num-j][i]){
                ch[num][i]=true;
            }
            if(ch[num][i]){
                break;
            }
        }

        if(ch[num][i]){
            continue;
        }

        if(num==N&&!ch[num][i]){
            cnt++;
        }
        find(num+1,ch);

        ch[num][i]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    bool check[20][20];
    memset(check,true,sizeof(check));

    find(1,check);
    cout<<cnt<<'\n';

    return 0;
}
