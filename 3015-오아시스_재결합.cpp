#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int N;
long long ans=0;
vector<int> people;

void input(){
    cin>>N;

    people.resize(N);
    for(int i=0;i<N;++i){
        cin>>people[i];
    }
}

void solution(){
    stack<pair<int, int> > s;

    for(int i=0;i<N;++i){
        int cnt = 1;
        while(!s.empty() && s.top().first <= people[i]){
            ans+=s.top().second;

            if(s.top().first == people[i]){
                cnt = s.top().second + 1;
            }
            
            s.pop();
        }

        //값이 여러 개 있더라도 가장 붙어 있는 친구 하나만 고려 된다.
        //6 5 1이며 6 5가 스택에 있으면 6과 1사이에 5가 있으므로 서로 보지 못하기 때문이다.
        //5 5 1또한 동일하다.
        if(!s.empty())
            ++ans;

        s.push({people[i], cnt});
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}