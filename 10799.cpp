#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;
vector<int> cnt;
vector<int> num;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    int tmpn=0,result=0;
    cin>>input;
    int leng=input.length();
    for(int i=0;i<leng;i++){
        if(input[i]=='(') cnt.push_back(1);
        else cnt.push_back(2);
    }
    leng=cnt.size();
    for(int i=0;i<leng;i++){
        if(cnt[leng-i-1]==2&&cnt[leng-i-2]==1){
            if(num.empty());
            else{
                for(auto it= num.begin();it!=num.end();it++)
                    (*it)++;
                }
                i++;
        }
        else if(cnt[leng-i-1]==1){
            if(num.empty()) continue;
            result+=num.back();
            num.pop_back();
        }
        else{
            num.push_back(1);
        }
    }

    cout<<result<<'\n';
    return 0;
}
