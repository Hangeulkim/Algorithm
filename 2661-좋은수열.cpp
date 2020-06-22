#include<bits/stdc++.h>

using namespace std;

string result;
int N;
bool eflag=false;

void find(int leng){
    if(leng==N){
        eflag=true;
        return ;
    }
    for(int i=1;i<4;i++){
        result.push_back(i+'0');

        bool fflag=false;
        for(int j=leng;j>leng/2;j--){
            string sub_str=result.substr(j);
            if(j>0&&result.compare(j-sub_str.length(),sub_str.length(),sub_str)==0){
                fflag=true;
            }
            if(fflag) break;
        }

        if(eflag) return ;

        if(!fflag){
            find(leng+1);
            if(eflag) return ;
        }

        result.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    find(0);

    cout<<result<<'\n';

    return 0;
}
