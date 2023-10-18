#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int N,K;
vector<int> number;
vector<int> dist;

void input(){
    cin>>N>>K;

    int tmp;
    while(N--){
        cin>>tmp;

        number.push_back(tmp);
    }

    sort(number.begin(), number.end());
    number.erase(unique(number.begin(), number.end()), number.end());
    for(int i=1;i<number.size();++i){
        dist.push_back(number[i]-number[i-1]);
    }
}

void solution(){
    int sum = 0;

    sort(dist.begin(),dist.end(),greater<int>());

    for(int i=K-1;i<dist.size();++i){
        sum+=dist[i];
    }

    cout<<sum<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}