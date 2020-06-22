#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
struct tmp{
    int def;
    int start;
    int end;
};

vector<string> input;
string tmps;
string tmpinput;
vector<tmp> result;
bool comp(tmp a,tmp b){
    return a.def < b.def;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        for(int j=1;j<=5;j++){
            cin>>tmps;
            if(j==1){
                input.push_back(tmps);
            }
            else input[i]+=tmps;
        }

        for(int j=0;j<i;j++){
            int cnt=0;
            for(int k=0;k<35;k++){
                if(input[i][k]!=input[j][k]) cnt++;
            }
            result.push_back({cnt,j+1,i+1});
        }
    }

    sort(result.begin(),result.end(),comp);
    cout<<result[0].start<<" "<<result[0].end;
    return 0;
}
