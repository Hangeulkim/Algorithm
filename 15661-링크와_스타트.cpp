#include<bits/stdc++.h>

using namespace std;

int input[21][21];
int N;

int result=987654321;
vector<int> chk;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<N/2;i++){
        chk.push_back(0);
    }
    for(int i=N/2;i<N;i++){
        chk.push_back(1);
    }

    do {
        int link=0,start=0;
        for(int i=0;i<N;i++){
            if(chk[i]==1){
                for(int j=i+1;j<N;j++){
                    if(chk[j]==1){
                        link+=input[i][j]+input[j][i];
                    }
                }
            }
            else{
                for(int j=i+1;j<N;j++){
                    if(chk[j]==0){
                        start+=input[i][j]+input[j][i];
                    }
                }
            }
        }
        result=min(abs(link-start),result);
    } while(next_permutation(chk.begin(),chk.end()));

    cout<<result<<'\n';
    return 0;
}
