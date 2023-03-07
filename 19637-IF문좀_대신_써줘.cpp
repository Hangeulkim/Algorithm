#include<iostream>
#include<map>

using namespace std;

map<int, string> titles;

int N,M;
void input(){
    string name;
    int power;

    cin>>N>>M;
    while(N--){
        cin>>name>>power;

        if(titles.find(power) != titles.end())
            continue;

        titles[power]=name;
    }
}

void solution(){
    int power;
    while(M--){
        cin>>power;

        auto it = titles.lower_bound(power);
        cout<<(*it).second<<'\n';
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