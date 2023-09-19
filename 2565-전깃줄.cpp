#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<pair<int, int> > arr;
int lis[101];

void input(){
    int a,b;
    cin>>N;

    for(int i=0;i<N;++i){
        cin>>a>>b;
        arr.push_back({a,b});
    }
}

void solution(){
    int leng = 0;

    sort(arr.begin(), arr.end());
    for(int i=0;i<N;++i){
        lis[i]=1;

        for(int j=0;j<i;++j){
            if(arr[i].second > arr[j].second){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }

        leng = max(leng, lis[i]);
    }

    cout<<N-leng<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}