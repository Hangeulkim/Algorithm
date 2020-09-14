#include<bits/stdc++.h>

using namespace std;

string s,t;

bool find(){
    while(1){
        if(s.length()==t.length()){
            if(!s.compare(t))
                return 1;
            return 0;
        }

        if(t[t.length()-1]=='B'){
            t.pop_back();
            reverse(t.begin(),t.end());
        }
        else{
            t.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;

    cout<<find();

    return 0;
}
