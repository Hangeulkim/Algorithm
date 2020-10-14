#include<bits/stdc++.h>

using namespace std;

string input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin,input);
    for(int i=0;i<input.length();i++){
        int tmp=input[i];
        if(tmp>='a'&&tmp<='z'){
            tmp+=13;
            if(tmp>'z')
                tmp-=26;
        }
        else if(tmp>='A'&&tmp<='Z'){
            tmp+=13;
            if(tmp>'Z')
                tmp-=26;
        }
        input[i]=tmp;
    }
    cout<<input;

    return 0;
}
