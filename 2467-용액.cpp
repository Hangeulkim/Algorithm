#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
vector<int> water;

void input(){
    cin>>N;

    water.resize(N);
    for(int i=0;i<N;++i)
        cin>>water[i];
}

void solution(){
    int l=0, r=N-1;
    int lans = 0, rans = 0;
    int ans = 2'111'111'111;

    while(l<r){
        int cost = water[l] + water[r];

        if(abs(cost) <= ans){
            lans = l;
            rans = r;
            ans = abs(cost);
        }

        if(cost <= 0)
            ++l;
        else
            --r;
    }

    cout<<water[lans]<<" "<<water[rans]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}