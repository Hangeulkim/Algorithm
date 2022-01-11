#include<bits/stdc++.h>

using namespace std;

int r,c,t;
int arr[51][51];
int u[2];
int d[2];

int my[4]={0,-1,0,1};
int mx[4]={1,0,-1,0};

void hawk(){
    int tmp[51][51];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                if(arr[i][j]==-1){
                    tmp[i][j]=-1;
                    continue;
                }
                tmp[i][j]+=arr[i][j];
                int num=arr[i][j]/5;
                for(int k=0;k<4;k++){
                    int ny=i+my[k];
                    int nx=j+mx[k];

                    if(nx<0||ny<0||ny>=r||nx>=c||arr[ny][nx]==-1)
                        continue;
                    
                    tmp[ny][nx]+=num;
                    tmp[i][j]-=num;
                }
            }
        }
    }

    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j]=tmp[i][j];
            
        }
    }
}

void gong(){
    int a,b;
    int ny=u[0];
    int nx=u[1]+1;
    
    a=arr[ny][nx];
    arr[ny][nx]=0;
    for(int i=0;i<4;i++){
        while(true){
            b=a;
            ny+=my[i];
            nx+=mx[i];
            
            if(nx<0||ny<0||ny>=r||nx>=c||arr[ny][nx]==-1)
                break;
            
            a=arr[ny][nx];
            arr[ny][nx]=b;
        }
        ny-=my[i];
        nx-=mx[i];
    }

    ny=d[0];
    nx=d[1]+1;
    a=arr[ny][nx];
    arr[ny][nx]=0;
    for(int i=0;i<4;i++){
        while(true){
            b=a;
            ny-=my[i];
            nx+=mx[i];
            
            if(nx<0||ny<0||ny>=r||nx>=c||arr[ny][nx]==-1)
                break;
            
            a=arr[ny][nx];
            arr[ny][nx]=b;
        }
        ny+=my[i];
        nx-=mx[i];
    }
}

void calc(){
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==-1)
                continue;
            cnt+=arr[i][j];
            
            
        }
    }
    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1&&u[0]==0){
                u[0]=i;
                u[1]=0;
                d[0]=i+1;
                d[1]=0;
            }
        } 
    }
    while(t--){
        hawk();
        gong();
    }
    
    calc();

    return 0;
}