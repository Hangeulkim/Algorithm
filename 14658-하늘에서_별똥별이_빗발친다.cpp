#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;

int N,M,L,K;
vector<pii> stars;

void input(){
    int y, x;
    cin>>M>>N>>L>>K;

    for(int i=0;i<K;++i){
        cin>>x>>y;

        stars.push_back({y,x});
    }
}

bool chk(int sx, int ny, int ty, int tx){
    if(ty >= ny && ty <= ny + L && tx >= sx && tx <= sx + L)
        return true;

    return false;
}

void solution(){
    int ans = 987'654'321;

    for(int i=0;i<K;++i){
        int sx = stars[i].second;

        for(int j=0;j<K;++j){
            int ny = stars[j].first;
                
            int cnt = 0;
            for(int t=0;t<K;++t){
                int ty = stars[t].first;
                int tx = stars[t].second;

                if(!chk(sx, ny, ty, tx))
                    ++cnt;
            }

            ans = min(ans, cnt);
        }
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