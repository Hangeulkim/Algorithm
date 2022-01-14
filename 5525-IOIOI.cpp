#include<bits/stdc++.h>

using namespace std;

int N,M;
string input;
int ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>input;

    int oi=0;
    for(int i=0;i<M-1;i++){
        if(oi>0&&input[i]=='O'&&input[i+1]=='I'){
            i++;
            oi++;
        }
        else{
            if(oi>=N)
                ret+=oi-N+1;
            oi=0;
        }
        if(oi==0&&i<=M-3&&input[i]=='I'&&input[i+1]=='O'&&input[i+2]=='I'){
            oi++;
            i+=2;
        }
    }
    if(oi>=N)
        ret+=oi-N+1;
    cout<<ret;

    return 0;
}