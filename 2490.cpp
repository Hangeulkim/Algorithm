#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int tmp=0;
    for(int i=0;i<3;i++){
        int cnt=0;
        for(int i=0;i<4;i++){
            cin>>tmp;
            if(tmp==0) cnt++;
        }
        if(cnt==1) cout<<"A\n";
        else if(cnt==2) cout<<"B\n";
        else if(cnt==3) cout<<"C\n";
        else if(cnt==4) cout<<"D\n";
        else cout<<"E\n";
    }




    return 0;
}
