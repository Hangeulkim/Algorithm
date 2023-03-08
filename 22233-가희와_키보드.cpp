#include<iostream>
#include<unordered_set>
#include<sstream>

using namespace std;

int N,M;
unordered_set<string> words;

void input(){
    cin>>N>>M;
    string word;
    while(N--){
        cin>>word;
        words.insert(word);
    }
}

void solution(){
    string used;
    while(M--){
        cin>>used;
        istringstream ss(used);
        string buffer;

        while(getline(ss, buffer, ',')){
            if(words.find(buffer) == words.end())
                continue;

            words.erase(words.find(buffer));
        }
        cout<<words.size()<<'\n';
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