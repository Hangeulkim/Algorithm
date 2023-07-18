#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string input;

void solution(){
    cin>>input;
    int acnt = count(input.begin(), input.end(), 'a');

    int ans = 987'654'321;
    for(int i=0;i<input.length();++i){
        int cnt = 0;
        for(int j=0;j<acnt;++j){
            int idx = (i+j)%input.length();

            cnt += input[idx] == 'b';
        }
        ans = min(ans, cnt);
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    
    solution();

    return 0;
}