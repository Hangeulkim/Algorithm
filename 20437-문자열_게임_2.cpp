#include<iostream>
#include<string>
#include<vector>

using namespace std;

int T, K;
string str;

void calc(){
    vector<vector<int> > arr(27);
    int ans1 = 987'654'321, ans2 = 0;

    for(int i=0;i<str.length();++i){
        int num = str[i]-'a';
        arr[num].push_back(i);
    }

    for(int i=0;i<27;++i){
        if(arr[i].size() < K)
            continue;

        int l = 0, r = K-1;
        while(r < arr[i].size()){
            ans1 = min(ans1, arr[i][r] - arr[i][l] + 1);
            ans2 = max(ans2, arr[i][r] - arr[i][l] + 1);

            ++l;
            ++r;
        }
    }

    if(ans1 == 987'654'321)
        cout<<-1<<'\n';
    else
        cout<<ans1<<" "<<ans2<<'\n';
}

void input(){
    cin>>T;
    while(T--){
        cin>>str>>K;

        calc();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    return 0;
}