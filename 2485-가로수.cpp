#include<bits/stdc++.h>

using namespace std;

vector<int> input;
vector<int> dif;
int N=0,tmp=0,num=987654321,cnt=0;

void gcd(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    if(num>a) num=a;
}

void result(){
    for(auto it : dif){
        cnt+=it/num-1;
    }
}

void find(){
    for(int i=1;i<N-1;i++){
        gcd(num,dif[i]);
    }
    result();
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    sort(input.begin(),input.end());
    for(int i=0;i<N-1;i++){
        dif.push_back(input[i+1]-input[i]);
    }

    gcd(dif[0],dif[1]);

    find();
    cout<<cnt<<'\n';

    return 0;
}
