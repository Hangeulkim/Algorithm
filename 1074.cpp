#include<iostream>
#include<cmath>

using namespace std;

long long int n=0,y=0,x=0;
long long int ans=0;

long long int calc(long long int a,long long int b,long long int c){
    if(a<1) return 0;
    if(b<=(long long)pow(2,a-1)&&c<=(long long)pow(2,a-1)){
        return calc(a-1,b,c);
    }

    else if(b>(long long)pow(2,a-1)&&c>(long long)pow(2,a-1)){
        return (long long)pow(2,(a-1)*2)*3+calc(a-1,b-(long long)pow(2,a-1),c-(long long)pow(2,a-1));
    }

    else if(b>(long long)pow(2,a-1)&&c<=(long long)pow(2,a-1)){
        return (long long)pow(2,(a-1)*2)+calc(a-1,b-(long long)pow(2,a-1),c);
    }

    else{
        return (long long)pow(2,(a-1)*2)*2+calc(a-1,b,c-(long long)pow(2,a-1));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>y>>x;
    y+=1;
    x+=1;
    ans=calc(n,x,y);
    cout<<ans<<'\n';




    return 0;
}
