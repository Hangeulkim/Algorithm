#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,cnt=0,num=0,check=0;
    cin>>N;

    for(num=666;cnt<N;num++){
        int digit=1;
        int cnt6=0;
        while(num/digit!=0&&cnt6<3){
            check=num%(digit*10)/digit;
            if(check==6) cnt6++;
            else cnt6=0;
            digit*=10;
        }
        if(cnt6>=3) cnt++;
    }
    cout<<num-1<<'\n';
    return 0;
}
