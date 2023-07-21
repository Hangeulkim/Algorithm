#include<iostream>
#include<deque>
#include<cmath>

using namespace std;

int N;
int tower[100001];
int minn[100001][2];
deque<pair<int, int> > s;


void input(){
    cin>>N;
    for(int i=1;i<=N;++i)
        cin>>tower[i];
}

void calcFront(){
    s.clear();

    for(int i=1;i<=N;++i){
        while(!s.empty() && s.back().second <= tower[i])
            s.pop_back();

        minn[i][1] += s.size();

        if(!s.empty() && (abs(i - s.back().first) <= abs(minn[i][0] - i) || !minn[i][0]))
            minn[i][0] = s.back().first;

        s.push_back({i,tower[i]});
    }
}

void calcBack(){
    s.clear();

    for(int i=N;i>0;--i){
        while(!s.empty() && s.front().second <= tower[i])
            s.pop_front();

        minn[i][1] += s.size();

        if(!s.empty() && (abs(s.front().first - i) <= abs(minn[i][0] - i) || !minn[i][0]))
            minn[i][0] = s.front().first;

        s.push_front({i,tower[i]});
    }
}

void solution(){
    calcBack();
    calcFront();

    for(int i=1;i<=N;++i){
        if(minn[i][1] == 0)
            cout<<0<<'\n';
        else
            cout<<minn[i][1]<<" "<<minn[i][0]<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}