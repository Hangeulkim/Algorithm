#include<bits/stdc++.h>

using namespace std;

int N,num1,num2;
string input;
int my[2]={0,1};
int mx[2]={1,0};

int greed[10][10];
bool chk[10][10],col[10][10],row[10][10],mat[10][10];
bool end_flag=false;

bool find(int pos){
    if(end_flag) return true;
    if(pos==81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<greed[i][j];
            }
            cout<<'\n';
        }
        end_flag=true;
        return true;
    }
    int y=pos/9, x=pos%9;

    if(greed[y][x]!=0)
        return find(pos+1);

    for(int d=0;d<2;d++){
        int ny=y+my[d];
        int nx=x+mx[d];

        if(ny<0||nx<0||ny>8||nx>8||greed[ny][nx]!=0)
            continue;
        for(int i=1;i<=8;i++){
            for(int j=i+1;j<=9;j++){
                if(chk[i][j])
                    continue;
                chk[i][j]=true;

                if(!row[y][i]&&!col[x][i]&&!mat[(y/3)*3+x/3][i]&&!row[ny][j]&&!col[nx][j]&&!mat[(ny/3)*3+nx/3][j]){
                    greed[y][x]=i;
                    greed[ny][nx]=j;
                    row[y][i]=col[x][i]=mat[(y/3)*3+x/3][i]=true;
                    row[ny][j]=col[nx][j]=mat[(ny/3)*3+nx/3][j]=true;
                    if(find(pos+1))
                        return true;
                    row[y][i]=col[x][i]=mat[(y/3)*3+x/3][i]=false;
                    row[ny][j]=col[nx][j]=mat[(ny/3)*3+nx/3][j]=false;
                    greed[y][x]=0;
                    greed[ny][nx]=0;
                }

                if(!row[ny][i]&&!col[nx][i]&&!mat[(ny/3)*3+nx/3][i]&&!row[y][j]&&!col[x][j]&&!mat[(y/3)*3+x/3][j]){
                    greed[y][x]=j;
                    greed[ny][nx]=i;
                    row[ny][i]=col[nx][i]=mat[(ny/3)*3+nx/3][i]=true;
                    row[y][j]=col[x][j]=mat[(y/3)*3+x/3][j]=true;
                    if(find(pos+1))
                        return true;
                    row[ny][i]=col[nx][i]=mat[(ny/3)*3+nx/3][i]=false;
                    row[y][j]=col[x][j]=mat[(y/3)*3+x/3][j]=false;
                    greed[y][x]=0;
                    greed[ny][nx]=0;
                }
                chk[i][j]=false;
            }
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int cnt=1;;cnt++){
        cin>>N;
        if(N==0)
            break;

        end_flag=false;
        memset(greed,0,sizeof(greed));
        memset(chk,false,sizeof(chk));
        memset(col,false,sizeof(col));
        memset(row,false,sizeof(row));
        memset(mat,false,sizeof(mat));
        while(N--){
            cin>>num1>>input;
            int y=input[0]-'A';
            int x=input[1]-'1';
            greed[y][x]=num1;
            row[y][num1]=col[x][num1]=mat[(y/3)*3+x/3][num1]=true;

            cin>>num2>>input;
            y=input[0]-'A';
            x=input[1]-'1';
            greed[y][x]=num2;
            row[y][num2]=col[x][num2]=mat[(y/3)*3+x/3][num2]=true;

            chk[num2][num1]=true;
            chk[num1][num2]=true;
        }
        for(int i=1;i<=9;i++){
            cin>>input;
            int y=input[0]-'A';
            int x=input[1]-'1';
            greed[y][x]=i;
            row[y][i]=col[x][i]=mat[(y/3)*3+x/3][i]=true;
        }

        cout<<"Puzzle "<<cnt<<'\n';
        find(0);
    }

    return 0;
}
