#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double input=0;
    double pi=3.1415926535897932;
    cin>>input;

    cout<<fixed;
    cout.precision(6);
    cout<<input*input*pi<<'\n';
    cout<<input*input*2<<'\n';





    return 0;
}
