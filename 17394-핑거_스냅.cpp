#include<bits/stdc++.h>

using namespace std;

int testcase;
int N,A,B;

bool sosu[1000001];
queue<pair<int,int> > bfs_arr;
bool chk[1000001];

void aritos(){
    for(int i=2;i<1000001;i++){
        if(!sosu[i]){
            for(int j=2;i*j<1000001;j++){
                sosu[i*j]=true;
            }
        }
    }
}

int bfs(){
    bfs_arr.push(make_pair(N,0));
    chk[N]=true;
    while(!bfs_arr.empty()){
        int num=bfs_arr.front().first;
        int cnt=bfs_arr.front().second;

        if(num<=B&&num>=A&&!sosu[num]){
            return cnt;
        }

        if(!chk[num+1]){
            bfs_arr.push(make_pair(num+1,cnt+1));
            chk[num+1]=true;
        }
        if(!chk[num/2]){
            bfs_arr.push(make_pair(num/2,cnt+1));
            chk[num/2]=true;
        }
        if(!chk[num/3]){
            bfs_arr.push(make_pair(num/3,cnt+1));
            chk[num/3]=true;
        }
        if(!chk[num-1]&&num>0){
            bfs_arr.push(make_pair(num-1,cnt+1));
            chk[num-1]=true;
        }

    bfs_arr.pop();
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;
    aritos();
    while(testcase--){
        cin>>N>>A>>B;
        fill(chk,chk+1000001,false);
        cout<<bfs()<<'\n';
        while(!bfs_arr.empty()) bfs_arr.pop();
    }

    return 0;
}
