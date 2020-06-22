#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;

int cnt=0;
queue<int> q;
deque<int> dq,dq2,dq3;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,M=0,input=0;
    cin>>N>>M;

    for(int i=1;i<=N;i++) dq.push_back(i);
    for (int i=0;i<M;i++){
        cin>>input;
        q.push(input);
    }

    while (!q.empty()) {
        dq2.resize(dq.size());
        copy(dq.begin(),dq.end(),dq2.begin());
        dq3.resize(dq.size());
        copy(dq.begin(),dq.end(),dq3.begin());

        int result2=0,result3=0;

        while (dq2.front()!=q.front()){
            dq2.push_back(dq2.front());
            dq2.pop_front();
            result2++;
        }
        while (dq3.front()!=q.front()){
            dq3.push_front(dq3.back());
            dq3.pop_back();
            result3++;
        }

        if(result2>result3){
            dq.resize(dq3.size());
            copy(dq3.begin(),dq3.end(),dq.begin());
            cnt+=result3;
        }
        else{
            dq.resize(dq2.size());
            copy(dq2.begin(),dq2.end(),dq.begin());
            cnt+=result2;
        }

        q.pop();
        dq.pop_front();
    }
    cout<<cnt<<'\n';

    return 0;
}
