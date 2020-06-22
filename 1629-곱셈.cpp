#include<iostream>
#include<algorithm>

using namespace std;

long long int a=0,b=0,c=0;

long long int result(long long int a,long long int b){
    if(b==1){
        return a%c;
    }

    else{
        if(b%2==0){
            return result(((a%c)*(a%c))%c,b/2);
        }
        else{
            return ((a%c)*result(a%c,b-1))%c;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c;
    a%=c;

    cout<<result(a,b)<<'\n';

    return 0;
}
