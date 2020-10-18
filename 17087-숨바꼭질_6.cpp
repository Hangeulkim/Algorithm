#include<bits/stdc++.h>

using namespace std;

int N,S;
int result=0;
int tmp;

int find(int a, int b){
    if(b>a)
        swap(a,b);

    while(b!=0){
        a=a%b;
        swap(a,b);
    }

    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(!result)
            result=abs(S-tmp);
        else
            result=find(result,abs(S-tmp));
    }
    cout<<result<<'\n';

    return 0;
}
