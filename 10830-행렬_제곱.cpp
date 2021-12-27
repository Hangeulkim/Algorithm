#include<bits/stdc++.h>

using namespace std;

int N;
int mat[6][6];
int ans[6][6];
long long int B;

void mat_gop(int one[6][6], int two[6][6]){
    int tmp[6][6];

    memset(tmp,0,sizeof(tmp));


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                tmp[i][j]+=one[i][k]*two[k][j];
            }
            tmp[i][j]%=1000;
        }
        
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            one[i][j]=tmp[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>mat[i][j];
        }
        ans[i][i]=1;
    }
            
    
    while(B>0){
        if(B%2==1)
            mat_gop(ans,mat);
        mat_gop(mat,mat);
        B/=2;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}