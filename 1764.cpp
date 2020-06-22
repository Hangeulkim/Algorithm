#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> answer;
vector<string> input;
int main(){
    string tmp;
    int stmp,ltmp;
    cin>>ltmp>>stmp;
    int calc=ltmp;
    while(ltmp--){
        cin>>tmp;
        input.push_back(tmp);
    }

    while(stmp--){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());
    int leng=input.size();
    for(int i=1;i<leng;i++){
        if(input[i].compare(input[i-1])==0) answer.push_back(input[i]);
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<'\n';
    for(auto it : answer) cout<<it<<'\n';

    return 0;
}
