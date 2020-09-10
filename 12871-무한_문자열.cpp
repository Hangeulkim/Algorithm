#include<bits/stdc++.h>

using namespace std;

string s,t;

int gcd(int a, int b){
    while(b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    int sleng=s.length();
    int tleng=t.length();

    int guak=lcm(sleng,tleng);
    string sr,tr;
    while(guak>sr.length())
        sr+=s;

    while(guak>tr.length())
        tr+=t;

    if(!sr.compare(tr))
        cout<<1<<'\n';
    else
        cout<<0<<'\n';


    return 0;
}
