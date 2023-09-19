#include<iostream>
#include<string>

using namespace std;

string S;
int q;

int lenArr[200001][26];

void input(){
    cin>>S>>q;

    int leng = S.length();
    ++lenArr[0][S[0]-'a'];
    for(int i=1;i<leng;++i){
        for(int j=0;j<26;++j){
            lenArr[i][j] = lenArr[i-1][j] + (S[i] - 'a' == j);
        }
    }

}

void solution(){
    char alp;
    int s, e;

    while(q--){
        cin>>alp>>s>>e;

        if(s==0){
            cout<<lenArr[e][alp-'a']<<'\n';
        }
        else{
            cout<<lenArr[e][alp-'a']-lenArr[s-1][alp-'a']<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}