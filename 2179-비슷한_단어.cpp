#include<iostream>
#include<map>
#include<string>

using namespace std;

int N;
map<string, int> m;

void solution(){
    string input;
    pair<int, int> cnt = {0, 987'654'321};
    pair<string, string> ans;

    cin>>N;
    for(int idx = 0; idx < N; ++idx){
        cin>>input;

        if(m.find(input) != m.end())
            continue;

        for(int i=cnt.first;i<=input.length();++i){
            string str = input.substr(0,i);

            auto it = m.lower_bound(str);

            if(it != m.end()){
                string findStr = it->first;

                if(findStr.substr(0,i).compare(str) == 0 ){
                    if((i == cnt.first && m[findStr] < cnt.second) || i > cnt.first){
                        ans = {findStr, input};
                        cnt = {i, m[findStr]};
                    }
                }
            }
        }

        m[input] = idx;
    }

    cout<<ans.first<<'\n'<<ans.second<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();    

    return 0;
}