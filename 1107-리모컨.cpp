#include<cstdio>
#include<cmath>

int main(){
    int N=0,M=0,a[10];
    char innum=0;
    for(int i=0;i<10;i++) a[i]=1;
    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>innum;
        a[innum]=0;
    }

    int ch=abs(N-100),num=0,max=0;
    for(int i=0;i<10;i++)
        if(a[i]&&max<i) max=i;

    while(ch!=0){
        cnt++;

    }
    cout<<cnt<<'\n';

    return 0;
}
