#include<iostream>
#include<map>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int T,n,k,t,m;

typedef struct Data{
    int idx,last,num,score;
}d;

bool cmpsort(const d &a, const d &b){
    if(a.score == b.score){
        if(a.num == b.num)
            return a.last < b.last;
        return a.num < b.num;
    }
    return a.score > b.score;
}

void input(){
    cin>>n>>k>>t>>m;
}


void calc(){
    map<pair<int,int>, int> data;
    vector<d> arr(n);

    for(int i=0;i<n;++i)
        arr[i].idx=i+1;

    int i,j,s;
    for(int idx=0;idx<m;++idx){
        cin>>i>>j>>s;

        if(data.find({i,j})!=data.end())
            data[{i,j}]=max(data[{i,j}],s);
        else
            data[{i,j}]=s;
        ++arr[i-1].num;
        arr[i-1].last=idx+1;
    }

    int idx=0;
    for(auto it : data){
        int team = it.first.first;
        int num = it.first.second;
        int score = it.second;

        arr[team-1].score+=score;

        ++idx;
    }
    
    sort(arr.begin(),arr.end(),cmpsort);

    for(int i=0;i<n;++i){
        if(arr[i].idx == t){
            cout<<i+1<<'\n';
            break;
        }
    }
}

void solution(){
    calc();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        input();
        solution();
    }
    

    return 0;
}