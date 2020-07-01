#include<bits/stdc++.h>

using namespace std;
int N;
int M;
bool gojang[11];
int min_num=987654321;

void dfs(string input){
    for (int i = 0; i < 10; i++) {
        if(!gojang[i]){
            string tmp=input+to_string(i);

            min_num=min(min_num,abs(N-stoi(tmp))+(int)tmp.length());

            if(tmp.length()<=6){
                dfs(tmp);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>N>>M;
    min_num=min(min_num,abs(100-N));

    for(int i=0;i<M;i++){
        cin>>tmp;
        gojang[tmp]=true;
    }

    if(M<10)
        dfs("");
    cout<<min_num;

    return 0;
}
