#include<bits/stdc++.h>

using namespace std;

long long s,t;
map<long long, string> visit;

string bfs(){
    queue<long long> q;

    q.push(s);
    if(s==t)
        return "0";
    visit[s]="";

    while(!q.empty()){
        long long num=q.front();

        q.pop();
        if(num==t)
            return visit[num];

        long long next;
        next=num*num;
        if(next<1000000001&&visit.find(next)==visit.end()){
            q.push(next);
            visit[next]=visit[num]+"*";
        }
        next=num+num;
        if(next<1000000001&&visit.find(next)==visit.end()){
            q.push(next);
            visit[next]=visit[num]+"+";
        }
        if(visit.find(0)==visit.end()){
            q.push(0);
            visit[0]=visit[num]+"-";
        }
        if(visit.find(1)==visit.end()){
            q.push(1);
            visit[1]=visit[num]+"/";
        }
    }

    return "-1";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    cout<<bfs();

    return 0;
}
