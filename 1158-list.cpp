#include<iostream>
#include<list>

using namespace std;
list<int> result;
list<int>::iterator iter;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N=0,M=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++) result.push_back(i);

    iter=result.begin();
    cout<<"<";
    while(!result.empty()){
        for(int i=1;i<M;i++){
            iter++;
            if(iter==result.end()) iter=result.begin();
        }
        if(result.size()==1){
            cout<<*iter;
            break;
        }
        else{
            cout<<*iter<<", ";
            iter=result.erase(iter);
            if(iter==result.end()) iter=result.begin();
        }
    }
    cout<<">\n";


    return 0;
}
