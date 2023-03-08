#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int p,m,l;
string n;
struct room{
    int sl, el;
    vector<pair<string, int> > party;
    int cnt;
};

void input(){
    cin>>p>>m;
}

void solution(){
    vector<room> rooms;
    while(p--){
        cin>>l>>n;

        bool enter=false;
        for(int i=0,len=rooms.size();i<len;++i){
            if(rooms[i].cnt<m&&rooms[i].sl<=l&&rooms[i].el>=l){
                ++rooms[i].cnt;
                rooms[i].party.push_back({n,l});
                enter=true;
                break;
            }
        }
        if(!enter){
            vector<pair<string, int> > party;
            party.push_back({n,l});
            rooms.push_back({l-10,l+10,party,1});
        }
    }

    for(int i=0,len=rooms.size();i<len;++i){
        if(rooms[i].cnt == m){
            cout<<"Started!"<<'\n';
        }
        else{
            cout<<"Waiting!"<<'\n';
        }

        sort(rooms[i].party.begin(),rooms[i].party.end());
        for(auto it: rooms[i].party){
            cout<<it.second<<" "<<it.first<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}