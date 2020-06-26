#include<bits/stdc++.h>

using namespace std;
int result[21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        string a;
        cin>>a;
        if(!a.compare("add")){
            cin>>tmp;
            result[tmp]=1;
        }
        else if(!a.compare("remove")){
            cin>>tmp;
            result[tmp]=0;
        }
        else if(!a.compare("check")){
            cin>>tmp;
            cout<<result[tmp]<<'\n';
        }
        else if(!a.compare("toggle")){
            cin>>tmp;
            if(result[tmp]==1)
                result[tmp]=0;
            else
                result[tmp]=1;
        }
        else if(!a.compare("all")){
            for(int i=1;i<=20;i++)
                result[i]=1;
        }
        else if(!a.compare("empty")){
            for(int i=1;i<=20;i++)
                result[i]=0;
        }
    }

    return 0;
}
