#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;


int N,K;
deque<pair<int, bool> > A;
int ret;

void fi(){
    A.push_front({A.back().first,A.back().second});
    A.pop_back();
    A[N-1].second=false;
}

void se(){
    for(int i=N-2;i>=0;i--){
        if(!A[i+1].second&&A[i+1].first&&A[i].second){
            A[i].second=false;
            A[i+1].second=true;
            A[i+1].first--;
        }
    }
    A[N-1].second=false;
}

void th(){
    if(!A[0].second&&A[0].first){
        A[0].first--;
        A[0].second=true;
    }
}

bool fo(){
    int cnt=0;
    for(int i=0;i<2*N;i++)
        if(!A[i].first)
            cnt++;
    return cnt>=K;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    int tmp;
    for(int i=0;i<2*N;i++){
        cin>>tmp;
        A.push_back({tmp,false});
    }

    while(true){
        ret++;
        fi();
        se();
        th();
        if(fo())
            break;
    }
    cout<<ret<<'\n';

    return 0;
}