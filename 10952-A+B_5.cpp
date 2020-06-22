#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a=0,b=0;
    while(1){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        cout<<a+b<<'\n';
    }

    return 0;
}
