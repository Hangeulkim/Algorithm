#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<int> calc;
int cnt=0;

int digit(int num){
    int d=0;
    while(num>0){
        d++;
        num/=10;
    }
    return d;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    for(int y=r1;y<=r2;y++){
        for(int x=c1;x<=c2;x++){
            int num=max(abs(x),abs(y));
            int insult=1;
            if(abs(y)==num){
                if(y<=0) insult=pow(num*2-1,2)+(num*2)+(num-x);
                else if(y>=0) insult=pow(num*2+1,2)-(num-x);
            }
            else{
                if(x>0) insult=pow(num*2-1,2)+num-y;
                else if(x<0) insult=pow(num*2+1,2)-(num*2)-(num-y);
            }
            calc.push_back(insult);
        }
    }

    int maxdigit=digit(*max_element(calc.begin(),calc.end()));
    for(int y=r1;y<=r2;y++){
        for(int x=c1;x<=c2;x++){
            for(int i=digit(calc[cnt]);i<maxdigit;i++) cout<<" ";
            cout<<calc[cnt]<<" ";
            cnt++;
        }
        cout<<'\n';
    }


    return 0;
}
