#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

map<string, bool> chk;
string S,T;

int bfs(){
    int len=S.length();
    queue<string> q;

    chk[T]=true;
    q.push(T);

    while(!q.empty()){
        string n=q.front();

        q.pop();

        if(n.compare(S)==0)
            return 1;
        
        string tmp=n;
        if(tmp.back()=='A'){
            tmp.pop_back();
            if(chk.find(tmp)==chk.end()&&n.length()>len){
                q.push(tmp);
                chk[tmp]=true;
            }
        }
        

        if(n.front()=='B'){
            tmp.assign(n.begin()+1,n.end());
            reverse(tmp.begin(),tmp.end());
            if(chk.find(tmp)==chk.end()&&n.length()>len){
                q.push(tmp);
                chk[tmp]=true;
            }
        }
        
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>S>>T;
    cout<<bfs()<<'\n';

    return 0;
}