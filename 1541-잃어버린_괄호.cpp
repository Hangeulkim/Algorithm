#include<bits/stdc++.h>

using namespace std;

string str;
int ret=0;

void parse(){
    int len=str.length();
    int tmp=0;
    bool mflag=false;
    for(int i=0;i<len;i++){
        if(str[i]=='-'||str[i]=='+'){
            if(mflag)
                ret-=tmp;
                
            else
                ret+=tmp;

            if(str[i]=='-')
                mflag=true;
            tmp=0;
        }
        else
            tmp=tmp*10+str[i]-'0';
    }
    if(mflag)
        ret-=tmp;
    else
        ret+=tmp;
    
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    parse();

    return 0;
}