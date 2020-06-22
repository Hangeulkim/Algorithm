#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<string> result;
bool comp(string a,string b){
    if(a.length()!=b.length()) return a.length()<b.length();
    return a.compare(b)<0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0;
    cin>>testcase;
    string tmp;
    for(int i=0;i<testcase;i++){
        cin>>tmp;
        int size=result.size();
        int flag=0;
        for(auto it=result.begin();it!=result.end();it++){
            if(tmp.compare(*it)==0) {
                flag=1;
                break;
            }
        }
        if(flag==1) continue;
        result.push_back(tmp);
    }
    sort(result.begin(),result.end(),comp);
    for(auto it : result){
        cout<<it<<'\n';
    }

    return 0;
}
