#include<bits/stdc++.h>

using namespace std;

string input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin>>input;
        if(input.compare("0")==0)
            break;

        bool lflag=false;
        int len=input.length();
        for(int i=0;i<len/2;i++){
            if(input[i]!=input[len-1-i]){
                cout<<"no\n";
                lflag=true;
                break;
            }
        }
        if(lflag)
            continue;
        cout<<"yes\n";
    }

    return 0;
}
