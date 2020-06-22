#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int hour=0,minute=0;
    cin>>hour>>minute;
    int tmph=hour*12%360;

    if(tmph==minute) cout<<"O"<<'\n';
    else cout<<"X"<<'\n';


    return 0;

}
