#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int d1,d2,d3,d4;
    string how;
}dat;

int T;
int A[5],B;

void chgd(int tmp, int &d1, int &d2, int &d3, int &d4){
    d1=tmp/1000;
    d2=tmp%1000/100;
    d3=tmp%100/10;
    d4=tmp%10;
}

int chg(int d1, int d2, int d3, int d4){
    int tmp=d1;
    tmp=tmp*10+d2;
    tmp=tmp*10+d3;
    tmp=tmp*10+d4;
    return tmp;
}

string bfs(){
    bool visit[10001]={false,};
    visit[chg(A[1],A[2],A[3],A[4])]=true;

    queue<dat> q;
    q.push({A[1],A[2],A[3],A[4],""});

    while(!q.empty()){
        int d1=q.front().d1;
        int d2=q.front().d2;
        int d3=q.front().d3;
        int d4=q.front().d4;
        string how=q.front().how;

        q.pop();
        if(chg(d1,d2,d3,d4)==B)
            return how;

        int tmp=chg(d1,d2,d3,d4);
        int d=tmp*2%10000;
        int s=tmp<1?9999:tmp-1;
        int l=chg(d2,d3,d4,d1);
        int r=chg(d4,d1,d2,d3);

        if(!visit[d]){
            visit[d]=true;
            chgd(d,d1,d2,d3,d4);
            q.push({d1,d2,d3,d4,how+"D"});
        }

        if(!visit[s]){
            visit[s]=true;
            chgd(s,d1,d2,d3,d4);
            q.push({d1,d2,d3,d4,how+"S"});
        }

        if(!visit[l]){
            visit[l]=true;
            chgd(l,d1,d2,d3,d4);
            q.push({d1,d2,d3,d4,how+"L"});
        }

        if(!visit[r]){
            visit[r]=true;
            chgd(r,d1,d2,d3,d4);
            q.push({d1,d2,d3,d4,how+"R"});
        }
    }
    return "";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    int tmp;
    while(T--){
        cin>>tmp>>B;
        chgd(tmp,A[1],A[2],A[3],A[4]);
        cout<<bfs()<<'\n';
    }

    return 0;
}
