#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int input=0;
    cin>>input;
    long long int result[10]={0};
    long long int mod=1000000000;
    long long int tmp[10]={0};
    for(int i=1;i<=input;i++){
        if(i==1){
            for(int j=1;j<=9;j++){
                result[j]=1;
            }
        }
        else{
            for(int j=0;j<=9;j++){
                tmp[j]=result[j];
            }
            for(int j=0;j<=9;j++){
                if(j==0) result[0]=tmp[1]%mod;
                else if(j==9) result[9]=tmp[8]%mod;
                else result[j]=(tmp[j-1]+tmp[j+1])%mod;
            }
        }
    }
    long long int sum=0;
    for(int i=0;i<=9;i++){
        sum=(sum+result[i])%mod;
    }
    cout<<sum<<'\n';


    return 0;
}
