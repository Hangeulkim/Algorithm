#include<bits/stdc++.h>

using namespace std;

int N,M;
int col[1001];
int row[1001];
int result;
int max_row=987654321,min_row;
int max_col=987654321,min_col;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            if(i==0||i==N-1){
                col[j]+=tmp*2;
                if(j==0||j==M-1)
                    row[i]+=tmp*2;
                else
                    row[i]+=tmp*4;
            }
            else if(j==0||j==M-1){
                if(i==0||i==N-1)
                    col[j]+=tmp*2;
                else
                    col[j]+=tmp*4;
                row[i]+=tmp*2;
            }
            else{
                col[j]+=tmp*4;
                row[i]+=tmp*4;
            }
        }
        if(i==0||i==N-1)
            result+=row[i]/2;              
        
        else
            result+=row[i];
    }
        
    min_row=max(row[0],row[N-1]);
    min_col=max(col[0],col[M-1]);

    for(int i=1;i<N-1;i++){
        max_row=min(row[i],max_row);
    }
    for(int i=1;i<M-1;i++){
        max_col=min(col[i],max_col);
    }
    if(min_row-max_row > min_col-max_col && min_row-max_row > 0){
        result=result-max_row/2+min_row/2;
    }
    else if(min_row-max_row <= min_col-max_col && min_col-max_col > 0){
        result=result-max_col/2+min_col/2;
    }


    cout<<result;


    return 0;
}