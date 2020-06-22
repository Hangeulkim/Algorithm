#include<iostream>
#include<string>

using namespace std;

string ans,input,bomb;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input>>bomb;
    int inleng=input.length(),bleng=bomb.length();

    for(int i=0;i<inleng;i++){
        ans.push_back(input[i]);
        int aleng=ans.length();
        if(input[i]==bomb[bleng-1]&&aleng>=bleng){
            int bcnt=0;
            for(int j=0;j<bleng;j++){
                if(ans[aleng-j-1]==bomb[bleng-j-1]) bcnt++;
            }
            if(bcnt==bleng){
                for(int j=0;j<bleng;j++) ans.pop_back();
            }
        }
    }

    if(ans.length()==0) cout<<"FRULA"<<'\n';
    else cout<<ans<<'\n';

    return 0;
}
