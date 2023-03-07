#include<iostream>

using namespace std;

string s;
int zero=0,one=0;
bool arr[501];
void input(){
    cin>>s;
    fill(&arr[0],&arr[500],true);
    for(int i=0,len=s.length();i<len;++i){
        if(s[i]=='0')
            ++zero;
        else
            ++one;
    }
}

void solution(){
    for(int i=0,cnt=0;cnt<one/2;++i){
        if(s[i]=='1'){
            ++cnt;
            arr[i]=false;
        }
    }

    for(int i=s.length()-1,cnt=0;cnt<zero/2;--i){
        if(s[i]=='0'){
            ++cnt;
            arr[i]=false;
        }
    }

    for(int i=0,len=s.length();i<len;++i){
        if(arr[i])
            cout<<s[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}