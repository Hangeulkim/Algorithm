#include<bits/stdc++.h>

using namespace std;

int N,L;

int input[102][102];
int cnt=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>L;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin>>input[y][x];
        }
    }

    for(int y=1;y<=N;y++){
        int leng=0;
        bool eflag=false;
        for(int x=1;x<=N;x++){
            leng++;
            if(x==N){
                if(eflag&&leng>=L)
                    eflag=false;
            }
            else if(input[y][x]>input[y][x+1]){
                if(eflag&&leng<L)
                    break;
                eflag=true;
                leng=0;
                if(input[y][x]>input[y][x+1]+1)
                    break;
            }
            else if(input[y][x]<input[y][x+1]){
                if(eflag)
                    leng-=L;
                if(input[y][x]+1<input[y][x+1]||leng<L){
                    eflag=true;
                    break;
                }
                leng=0;
            }
            else{
                if(eflag&&leng>=L){
                    eflag=false;
                    leng-=L;
                }
            }
        }
        if(!eflag){
            cnt++;
        }
    }

    for(int x=1;x<=N;x++){
        int leng=0;
        bool eflag=false;
        for(int y=1;y<=N;y++){
            leng++;
            if(y==N){
                if(eflag&&leng>=L)
                    eflag=false;
            }
            else if(input[y][x]>input[y+1][x]){
                if(eflag&&leng<L)
                    break;
                eflag=true;
                leng=0;
                if(input[y][x]>input[y+1][x]+1)
                    break;
            }
            else if(input[y][x]<input[y+1][x]){
                if(eflag)
                    leng-=L;
                if(input[y][x]+1<input[y+1][x]||leng<L){
                    eflag=true;
                    break;
                }
                leng=0;
            }
            else{
                if(eflag&&leng>=L){
                    eflag=false;
                    leng-=L;
                }
            }
        }
        if(!eflag){
            cnt++;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
