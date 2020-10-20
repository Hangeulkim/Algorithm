#include<bits/stdc++.h>

using namespace std;

string input;
string result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    reverse(input.begin(),input.end());
    int leng=input.length();
    for(int i=0;i<leng;i++){
        input[i]-='0';
        if(i==leng-1){
            if(i==0&&input[i]==0){
                result.push_back('0');
            }
            for(int j=0;j<3&&input[i];j++){
                if(input[i]%2==1){
                    result.push_back('1');
                }
                else{
                    result.push_back('0');
                }
                input[i]/=2;
            }
        }
        else{
            for(int j=0;j<3;j++){
                if(input[i]%2==1){
                    result.push_back('1');
                }
                else{
                    result.push_back('0');
                }
                input[i]/=2;
            }
        }
    }
    reverse(result.begin(),result.end());
    cout<<result<<'\n';

    return 0;
}
