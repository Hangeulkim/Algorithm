#include<iostream>
#include<algorithm>

using namespace std;

int people[6];
int arr[21][21];
bool chk[21][21];
int sum=0;
int N;
int ret=987654321;

int calc(int x, int y, int d1, int d2){
    fill(&people[0],&people[6],0);
    fill(&chk[0][0],&chk[20][21],false);

    for(int i=0;i<=d1;i++){
        chk[x+i][y-i]=true;
        chk[x+d2+i][y+d2-i]=true;
    }

    for(int i=1;i<=d2;i++){
        chk[x+i][y+i]=true;
        chk[x+d1+i][y-d1+i]=true;
    }

    for(int r=1;r<x+d1;r++){
        for(int c=1;c<=y;c++){
            if(chk[r][c])
                break;
            people[1]+=arr[r][c];
        }
    }

    for(int r=1;r<=x+d2;r++){
        for(int c=N;c>y;c--){
            if(chk[r][c])
                break;
            people[2]+=arr[r][c];
        }
    }

    for(int r=x+d1;r<=N;r++){
        for(int c=1;c<y-d1+d2;c++){
            if(chk[r][c])
                break;
            people[3]+=arr[r][c];
        }
    }
    
    for(int r=x+d2+1;r<=N;r++){
        for(int c=N;c>=y-d1+d2;c--){
            if(chk[r][c])
                break;
            people[4]+=arr[r][c];
        }
    }

    people[5]=sum-people[1]-people[2]-people[3]-people[4];
    if(*min_element(&people[1],&people[6])==0)
        return 987654321;
    
    return *max_element(&people[1], &people[6]) - *min_element(&people[1], &people[6]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
    }
        
        
    for(int d1=1;d1<N;d1++){
        for(int d2=1;d2<N;d2++){
            for(int x=1;x+d1+d2<=N;x++){
                for(int y=2;y<N;y++){
                    if(1>y-d1||y+d2>N)
                        continue;
                    ret=min(ret,calc(x,y,d1,d2));
                }
            }
        }
    }
    cout<<ret<<'\n';

    return 0;
}