#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int> > box;
int N;

bool cussort(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void input(){
    cin>>N;
    
    int L,H;
    while(N--){
        cin>>L>>H;
        box.push_back({L,H});
    }
    sort(box.begin(),box.end(),cussort);
}

void solution(){
    int ret=box[0].second;
    int l=box[0].first;
    int mid=box[0].first;
    int r=box[0].first+1;

    for(int i=1, len=box.size();i<len;++i){
        int L=box[i].first;
        int H=box[i].second;

        if(L<mid){
            if(L > l)
                continue;
            ret+=(l-L)*H;
            l=L;
        }
        else{
            if(L < r)
                continue;
            ret+=(L-r+1)*H;
            r=L+1;
        }
    }
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}