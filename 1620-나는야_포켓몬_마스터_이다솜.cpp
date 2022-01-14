#include<bits/stdc++.h>

using namespace std;

int N,M;
map<int,string> dogam1;
map<string,int> dogam2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    string input;
    for(int i=1;i<=N;i++){
        cin>>input;
        dogam1[i]=input;
        dogam2[input]=i;
    }
    while(M--){
        cin>>input;
        if(input[0]>='0'&&input[0]<='9'){
            cout<<dogam1[stoi(input)]<<'\n';
        }
        else{
            cout<<dogam2[input]<<'\n';
        }
    }

    return 0;
}