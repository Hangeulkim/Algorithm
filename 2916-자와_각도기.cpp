#include<bits/stdc++.h>

using namespace std;

int N,K,result,tmp;

bool chk[360];
vector<int> gak;

void bfs(){
    queue<int> q;

    for(auto it : gak)
        q.push(it);

    while(!q.empty()){
        int num=q.front();

        q.pop();

        for(auto it : gak){
            int nnum=(it+num)%360;
            if(!chk[nnum]){
                chk[nnum]=true;
                gak.push_back(nnum);
                q.push(nnum);
            }
            if(!chk[360-nnum]){
                chk[360-nnum]=true;
                gak.push_back(360-nnum);
                q.push(360-nnum);
            }

            nnum=abs(num-it);

            if(!chk[nnum]){
                chk[nnum]=true;
                gak.push_back(nnum);
                q.push(nnum);
            }
            if(!chk[360-nnum]){
                chk[360-nnum]=true;
                gak.push_back(360-nnum);
                q.push(360-nnum);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    memset(chk,false,sizeof(chk));
    chk[0]=true;
    gak.push_back(0);
    while(N--){
        cin>>tmp;
        if(tmp==0)
            continue;
        if(!chk[tmp]){
            chk[tmp]=true;
            gak.push_back(tmp);
        }
    }


    bfs();
    for(int i=0;i<K;i++){
        cin>>result;
        if(!chk[result]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }


    return 0;
}
