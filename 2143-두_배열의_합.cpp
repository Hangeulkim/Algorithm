#include<bits/stdc++.h>

using namespace std;

int T,A,B,tmp;
int ain[1001];
int bin[1001];
map<int, int> a;
map<int, int> b;
long long cnt=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    cin>>A;
    for(int i=1;i<=A;i++){
        cin>>ain[i];
        ain[i]+=ain[i-1];
    }
    cin>>B;
    for(int i=1;i<=B;i++){
        cin>>bin[i];
        bin[i]+=bin[i-1];
    }

    for(int i=1;i<=A;i++){
        for(int j=i;j<=A;j++){
            a[ain[j]-ain[i-1]]++;
        }
    }

    for(int i=1;i<=B;i++){
        for(int j=i;j<=B;j++){
            b[bin[j]-bin[i-1]]++;
        }
    }

    for(auto it : a){
        if(b.count(T-it.first)>0)
            cnt+=(long long)b[T-it.first]*it.second;
    }

    cout<<cnt<<'\n';

    return 0;
}
