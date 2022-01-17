#include<bits/stdc++.h>

using namespace std;

int T,K,num;
char c;
bool chk[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        priority_queue<pair<int, int>> maxheap;
        priority_queue<pair<int,int>,vector<pair<int, int> >,greater<pair<int, int> > > minheap;
        cin>>K;
        memset(chk,false,sizeof(chk));
        while(K--){
            cin>>c>>num;
            if(c=='I'){
                maxheap.push({num,K});
                minheap.push({num,K});
                chk[K]=true;
            }
            else{
                if(maxheap.empty())
                    continue;
                if(num==1){
                    chk[maxheap.top().second]=false;
                    maxheap.pop();
                }
                else{
                    chk[minheap.top().second]=false;
                    minheap.pop();
                }
            }
            while(!maxheap.empty()&&!chk[maxheap.top().second])
                maxheap.pop();
            while(!minheap.empty()&&!chk[minheap.top().second])
                minheap.pop();
        }
        if(maxheap.empty()){
            cout<<"EMPTY"<<'\n';
        }
        else{
            cout<<maxheap.top().first<<" "<<minheap.top().first<<'\n';
        }
    }

    return 0;
}