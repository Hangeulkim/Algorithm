#include<iostream>
#include<map>
#include<string>

using namespace std;

int N;
char G;
int cnt, ret;
string name;
map<string, bool> chk;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>G;
    for(int i=0;i<N;++i){
        cin>>name;

        if(chk.find(name)!=chk.end())
            continue;
        chk[name]=true;
        ++cnt;

        switch (G)
        {
            case 'Y':
                if(cnt==1){
                    cnt=0;
                    ++ret;
                }
                break;
        
            case 'F':
                    if(cnt==2){
                        cnt=0;
                        ++ret;
                    }
                    break;

            case 'O':
                if(cnt==3){
                    cnt=0;
                    ++ret;
                }
                break;
        }
    }
    cout<<ret<<'\n';

    return 0;
}