#include<iostream>
#include<vector>

using namespace std;

int H,W;
vector<int> world;

void input(){
    cin>>H>>W;

    world.resize(W);
    for(int i=0;i<W;++i)
        cin>>world[i];
}

void solution(){
    int ans = 0;
    int l,r;

    for(int i=1;i<W-1;++i){
        l=0, r=0;

        for(int j=i-1;j>=0;--j){
            l = max(l,world[j]);
        }
        
        for(int j=i+1;j<W;++j){
            r = max(r,world[j]);
        }

        ans += max(0, min(l, r) - world[i]);
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