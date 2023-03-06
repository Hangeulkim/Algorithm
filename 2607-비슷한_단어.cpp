#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int N;
int fcnt[30];
int tcnt[30];
string first;
string tmp;

void input(){
    cin>>N>>first;
    for(int i=0,len=first.length();i<len;++i)
        ++fcnt[first[i]-'A'];
}

bool chkstr(){
    if(abs((int)tmp.length() - (int)first.length()) > 1)
        return false;

    int dcnt=0;
    for(int i=0,len=tmp.length();i<len;++i){
        ++tcnt[tmp[i]-'A'];
    }
    
    for(int i=0;i<='Z'-'A';++i){
        dcnt+=abs(tcnt[i]-fcnt[i]);
    }

    if(dcnt<=1)
        return true;
    
    if(dcnt==2&&tmp.length() == first.length())
        return true;

    return false;
}

void solution(){
    int cnt=0;
    for(int i=0;i<N-1;++i){
        fill(&tcnt[0],&tcnt[30],0);
        cin>>tmp;
        
        if(chkstr())
            ++cnt;
    }
    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}