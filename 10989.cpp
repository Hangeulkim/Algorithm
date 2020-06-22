#include<iostream>

using namespace std;
int result[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<10001;i++){
        result[i]=0;
    }
    int tmp=0,testcase=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>tmp;
        result[tmp]++;
    }
    for(int i=1;i<10001;i++){
        while((result[i]--)!=0) cout<<i<<'\n';
    }



    return 0;
}
