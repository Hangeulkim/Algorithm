#include<bits/stdc++.h>

using namespace std;

string input;
string start;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        getline(cin,input);
        if(cin.eof())
            break;
        vector<string> data(120);
        int cnt=0;
        string tmp="";
        for(int i=0;i<input.size();i++){
            if(cnt==0){
                if(input[i]==' '){
                    cnt++;
                    continue;
                }
                start.push_back(input[i]);
            }
            else{
                if(input[i]==','||input[i]==';'){
                    reverse(data[cnt-1].begin(),data[cnt-1].end());
                    data[cnt-1].push_back(' ');
                    for(int j=0;j<tmp.size();j++)
                        data[cnt-1].push_back(tmp[j]);
                    tmp="";
                    i++;
                    cnt++;
                    continue;
                }
                else if(input[i]=='*'||input[i]=='&')
                    data[cnt-1].push_back(input[i]);
                else if(input[i]=='['||input[i]==']'){
                    data[cnt-1].push_back(input[i]==']'?'[':']');
                }
                else
                    tmp.push_back(input[i]);
            }
        }


        for(int i=0;i<cnt-1;i++){
                cout<<start<<data[i]<<";\n";
        }
    }



    return 0;
}
