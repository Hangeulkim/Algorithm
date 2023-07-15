#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int M, N;
vector<int> snacks;

void input(){
    int snack;

    cin>>M>>N;
    for(int i=0;i<N;++i){
        cin>>snack;
        snacks.push_back(snack);
    }
}

void solution(){
    sort(snacks.begin(), snacks.end(), greater<int>());

    int l=0, r=1'000'000'000;

    while(l<r){
        int mid = (l+r)/2;
        if(l == 0 && r == 0)
            break;

        if(mid == 0){
            mid = 1;
        }

        int cnt = 0;
        for(int i=0;i<N&&cnt<M;++i){
            cnt += snacks[i]/mid;
        }

        if(cnt>=M)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout<<r<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}