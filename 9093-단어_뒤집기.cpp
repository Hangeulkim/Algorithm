#include<bits/stdc++.h>

using namespace std;
int T;
string input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    cin.ignore();
    while(T--){
        getline(cin,input);
        vector<string> data;
        data.push_back("");
        int cnt=0;
        for(int i=input.length()-1;i>=0;i--){
            if(input[i]==' '){
                data.push_back("");
                cnt++;
            }
            else
                data[cnt].push_back(input[i]);
        }
        for(int i=data.size()-1;i>=0;i--)
            cout<<data[i]<<" ";
        cout<<'\n';
    }

    return 0;
}
