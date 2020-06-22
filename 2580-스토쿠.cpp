#include<bits/stdc++.h>

using namespace std;

bool finish=false;
int input[10][10];
vector<pair<int, int> > zero;

bool check(int numx,int numy,int num){
    for(int x=0;x<9;x++){
        if(input[numy][x]==num) return false;
    }

    for(int y=0;y<9;y++){
        if(input[y][numx]==num) return false;
    }

    int tmpy=(numy/3)*3;
    int tmpx=(numx/3)*3;

    for(int y=tmpy;y<tmpy+3;y++){
        for(int x=tmpx;x<tmpx+3;x++){
            if(input[y][x]==num){
                return false;
            }
        }
    }
    return true;
}//가능한지 여부

void find(int idx){
    if(idx==zero.size()){
        finish=true;
        return ;
    }
    int tmpy=zero[idx].first;
    int tmpx=zero[idx].second;

    for(int i=1;i<=9;i++){
        if(check(tmpx,tmpy,i)){
            input[tmpy][tmpx]=i;

            find(idx+1);

            if(finish) return ;

            input[tmpy][tmpx]=0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>input[i][j];
            if(input[i][j]==0)
                zero.push_back(make_pair(i,j));
        }
    }


    find(0);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<input[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
