#include<bits/stdc++.h>

using namespace std;

int N,M,R;
int a[301][301];
int marr[301][301];

void m1(){
    for(int j=0;j<M;j++){
        for(int i=0;i<N/2;i++){
            swap(a[i][j],a[N-1-i][j]);
        }
    }
}

void m2(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M/2;j++){
            swap(a[i][j],a[i][M-1-j]);
        }
    }
}

void m3(int sr,int sc, int fr, int fc){
    if(sr>fr||sc>fc)
        return ;
    for(int i=sr;i<=fr;i++){
        marr[sc][sr+fr-i]=a[i][sc];
    }
    for(int i=sr;i<=fr;i++){
        marr[fc][sr+fr-i]=a[i][fc];
    }
    for(int i=sc;i<fc;i++){
        marr[i][fr]=a[sr][i];
    }
    for(int i=sc;i<fc;i++){
        marr[i][sr]=a[fr][i];
    }


    m3(sr+1,sc+1,fr-1,fc-1);
}

void m4(int sr,int sc, int fr, int fc){
    if(sr>fr||sc>fc)
        return ;
    for(int i=sr;i<=fr;i++){
        marr[fc][i]=a[i][sc];
    }
    for(int i=sr;i<=fr;i++){
        marr[sc][i]=a[i][fc];
    }
    for(int i=sc;i<fc;i++){
        marr[sc+fc-i][sr]=a[sr][i];
    }
    for(int i=sc;i<fc;i++){
        marr[sc+fc-i][fr]=a[fr][i];
    }


    m4(sr+1,sc+1,fr-1,fc-1);
}

void m5(){
    int sr=0,sc=0,fr=N/2,fc=M/2;

    for(int i=0;i<fr;i++){
        for(int j=0;j<fc;j++){
            marr[i][j]=a[i][j];
            a[i][j]=a[i+fr][j];
        }
    }

    for(int i=fr;i<N;i++){
        for(int j=0;j<fc;j++){
            a[i][j]=a[i][j+fc];
        }
    }

    for(int i=fr;i<N;i++){
        for(int j=fc;j<M;j++){
            a[i][j]=a[i-fr][j];
        }
    }

    for(int i=0;i<fr;i++){
        for(int j=fc;j<M;j++){
            a[i][j]=marr[i][j-fc];
        }
    }
}

void m6(){
    int sr=0,sc=0,fr=N/2,fc=M/2;
    copy(&a[0][0],&a[0][0]+301*301,&marr[0][0]);

    for(int i=0;i<fr;i++){
        for(int j=0;j<fc;j++){
            a[i][j]=marr[i][j+fc];
        }
    }

    for(int i=fr;i<N;i++){
        for(int j=0;j<fc;j++){
            a[i][j]=marr[i-fr][j];
        }
    }

    for(int i=0;i<fr;i++){
        for(int j=fc;j<M;j++){
            a[i][j]=marr[i+fr][j];
        }
    }

    for(int i=fr;i<N;i++){
        for(int j=fc;j<M;j++){
            a[i][j]=marr[i][j-fc];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    
    int num;
    for(int i=0;i<R;i++){
        cin>>num;
        switch(num){
            case 1:
                m1();
                break;
            case 2:
                m2();
                break;
            case 3:
                m3(0,0,N-1,M-1);
                swap(N,M);
                copy(&marr[0][0],&marr[0][0]+301*301,&a[0][0]);
                break;
            case 4:
                m4(0,0,N-1,M-1);
                swap(N,M);
                copy(&marr[0][0],&marr[0][0]+301*301,&a[0][0]);
                break;
            case 5:
                m5();
                break;
            case 6:
                m6();
                break;
        }
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}