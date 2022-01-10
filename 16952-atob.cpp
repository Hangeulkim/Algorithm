#include<bits/stdc++.h>

using namespace std;

long long int A,B;

int bfs(){
    queue<pair<long long int,int> > q;
    q.push({A,1});

    while(!q.empty()){
        long long num=q.front().first;
        int cnt=q.front().second;

        q.pop();
        if(num == B)
            return cnt;
        long long tmp=num*2;

        if(tmp<=B)
            q.push({tmp,cnt+1});
        
        tmp = num*10+1;
        if(tmp<=B)
            q.push({tmp,cnt+1});
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B;

    cout<<bfs()<<'\n';
    

    return 0;
}