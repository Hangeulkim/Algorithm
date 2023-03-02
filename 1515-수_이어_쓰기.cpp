#include<iostream>

using namespace std;

string input;

void solution(){
    int cnt=1,idx=0,len=input.length();
    while(idx<len){
        string tmp=to_string(cnt++);

        for(int i=0, slen=tmp.length();i<slen&&idx<len;++i){
            if(tmp[i]==input[idx])
                ++idx;
        }
    }
    cout<<cnt-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    solution();

    return 0;
}