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
    int cnt=1;
    for(int i=0;i<leng;i++){
        if(i%3==0){
            cnt=1;
            result.push_back(0);
        }
        if(input[i]=='1'){
            result.back()+=cnt;
        }
        cnt*=2;
    }
    for(int i=0;i<result.length();i++){
        result[i]+='0';
    }
    reverse(result.begin(),result.end());
    cout<<result<<'\n';

    return 0;
}
