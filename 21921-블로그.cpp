#include<iostream>
#include<vector>

using namespace std;

int N,X,tmp;
vector<int> partsum;

void input(){
    cin>>N>>X>>tmp;

    partsum.push_back(tmp);
    for(int i=1;i<N;++i){
        cin>>tmp;
        partsum.push_back(partsum[i-1]+tmp);
    }
}

void solution(){
    int mnum=partsum[X-1], cnt=1;


    for(int i=X;i<N;++i){
        int now = partsum[i]-partsum[i-X];
        if(mnum==now)
            ++cnt;
        else if(mnum<now){
            mnum=now;
            cnt=1;
        }
    }
    if(mnum==0)
        cout<<"SAD"<<'\n';
    else
        cout<<mnum<<'\n'<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    
    input();
    solution();

    return 0;
}