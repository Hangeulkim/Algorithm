#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> input;
string tmp;
int tmpn;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tmpn;
    while(tmpn--){
        cin>>tmp;
        input.push_back(tmp);
    }
    int leng=input.size();
    vector<string> result(input);
    for(int i=0;i<leng;i++){
        for(int j=0;j<leng;j++){
            if(input[i][j]=='.') continue;
            else{
                result[i][j]='*';
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k<0||j+l<0||i+k>=leng||j+l>=leng) continue;
                        else if(result[i+k][j+l]=='*'||result[i+k][j+l]=='M') continue;
                        else{
                            if(result[i+k][j+l]=='.') result[i+k][j+l]='0';
                            if((result[i+k][j+l]+=input[i][j]-'0')>'9') result[i+k][j+l]='M';
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<leng;i++){
        for(int j=0;j<leng;j++){
            if(result[i][j]=='.') result[i][j]='0';
        }
    }
    for(auto it : result) cout<<it<<'\n';
    return 0;
}
