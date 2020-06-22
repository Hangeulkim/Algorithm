#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

list<pair<int, int> > result;
list<pair<int, int> >::iterator iter;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0;
    cin>>N;
    int tmp=0;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        result.push_back(make_pair(i,tmp));
    }
    iter=result.begin();
    while(!result.empty()){
        cout<<(*iter).first<<" ";
        tmp=(*iter).second;
        iter=result.erase(iter);
        if(iter==result.end()) iter=result.begin();
        if(tmp<0){
            for(int i=-1;i>=tmp;i--){
                if(iter==result.begin()) iter=result.end();
                iter--;
            }
        }
        else{
            for(int i=1;i<tmp;i++){
                iter++;
                if(iter==result.end()) iter=result.begin();
            }
        }

    }


    return 0;
}
