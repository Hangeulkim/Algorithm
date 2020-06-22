#include<bits/stdc++.h>

using namespace std;

int min_num=987654321,tmp,N;
int input[20][20];

void calc(bool ch[20]){
    int link_sum=0,start_sum=0;

    for(int i=0;i<N;i++){
        if(ch[i]){
            for(int j=i+1;j<N;j++){
                if(ch[j]){
                    link_sum+=input[i][j]+input[j][i];
                }
            }
        }
        else{
            for(int j=i+1;j<N;j++){
                if(!ch[j]){
                    start_sum+=input[i][j]+input[j][i];
                }
            }
        }
    }

    if(min_num>abs(start_sum-link_sum))
        min_num=abs(start_sum-link_sum);
}

void find(int num, bool ch[20],int link){
    for(int i=num;i<N/2+link;i++){
        ch[i]=true;
        link++;
        if(link==N/2){
            calc(ch);
        }
        else{
            find(i+1,ch,link);
        }
        link--;
        ch[i]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            input[i][j]=tmp;
        }
    }
    bool check[20];
    memset(check,false,sizeof(check));

    find(0,check,0);
    cout<<min_num<<'\n';

    return 0;
}
