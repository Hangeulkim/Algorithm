#include<bits/stdc++.h>

using namespace std;

int K,N;
vector<string> pq;

bool cmp(const string &a, const string &b){
    return a+b > b+a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>K>>N;
    string tmp;
    string str_long="0";
    for(int i=0;i<K;i++){
        cin>>tmp;
        pq.push_back(tmp);
        if(tmp.length()>str_long.length())
            str_long=tmp;
        else if(tmp.length()==str_long.length()&&stoi(tmp)>stoi(str_long)) str_long=tmp;
    }

    sort(pq.begin(),pq.end(),cmp);

    bool lflag=true;
    for(int i=0;i<K;i++){
        cout<<pq[i];
        if(lflag&&pq[i]==str_long){
            for(int i=0;i<N-K;i++){
                cout<<str_long;
            }
            lflag=false;
        }

    }

    return 0;
}
