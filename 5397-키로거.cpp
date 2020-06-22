#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    cin>>testcase;

    while(testcase--){
        string input;
        cin>>input;
        int leng=input.length();
        list<char> ans;
        auto iter=ans.begin();
        for(int i=0;i<leng;i++){
            switch(input[i]){
                case '<':
                    if(iter!=ans.begin())
                        iter--;
                    break;
                case '>':
                    if(iter!=ans.end())
                        iter++;
                    break;
                case '-':
                    if(iter!=ans.begin()){
                        iter=ans.erase(--iter);
                    }
                    break;
                default :
                    ans.insert(iter,input[i]);
                    break;
            }
        }
        for(auto idx : ans){
            cout<<idx;
        }
        cout<<'\n';
        ans.clear();
    }

    return 0;
}
