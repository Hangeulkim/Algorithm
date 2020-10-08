#include<bits/stdc++.h>

using namespace std;

string input;
string result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin,input);
    int leng=input.length();
    bool rflag=true;
    string tmp;
    for(int i=0;i<leng;i++){
        if(input[i]=='<'){
            while(!tmp.empty()){
                result.push_back(tmp.back());
                tmp.pop_back();
            }
            tmp.clear();
            result.push_back(input[i]);
            rflag=false;
        }
        else if(input[i]=='>'){
            result.push_back(input[i]);
            rflag=true;
        }
        else if(input[i]==' '){
            while(!tmp.empty()){
                result.push_back(tmp.back());
                tmp.pop_back();
            }
            tmp.clear();
            result.push_back(input[i]);
        }
        else{
            if(rflag){
                tmp.push_back(input[i]);
            }
            else{
                result.push_back(input[i]);
            }
        }
    }
    while(!tmp.empty()){
        result.push_back(tmp.back());
        tmp.pop_back();
    }
    cout<<result<<'\n';

    return 0;
}
