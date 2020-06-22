#include<bits/stdc++.h>

using namespace std;

bool ch[1000001]={false,};
vector<int> sosu;

void aritos(){
    for(int i=2;i<1000001;i++){
        if(!ch[i]){
            sosu.push_back(i);
            for(int j=2;j*i<1000001;j++){
                ch[j*i]=true;
            }
        }
    }
    sosu.erase(sosu.begin());
    ch[2]=true;
}

void result(int N){
    int start=0;

    while(1){
        if(!ch[N-sosu[start]]){
            cout<<N<<" = "<<sosu[start]<<" + "<<N-sosu[start]<<'\n';
            break;
        }
        if(sosu[start]>=N/2){
            cout<<"Goldbach's conjecture is wrong."<<'\n';
            break;
        }
        start++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    aritos();

    int tmp=0;

    while(1){
        cin>>tmp;
        if(tmp==0) break;
        result(tmp);
    }

    return 0;
}
