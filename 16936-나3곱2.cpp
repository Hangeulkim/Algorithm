#include<bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int N;
vector<ull> arr;

bool cmp(ull a,ull b){
    int ta=0,tb=0;
    ull na,nb;
    na=a;
    nb=b;
    while(na%3==0){
        na/=3;
        ta++;
    }
    while(nb%3==0){
        nb/=3;
        tb++;
    }
    if(ta==tb){
        while(na%2==0){
            na/=2;
            ta++;
        }
        while(nb%2==0){
            nb/=2;
            tb++;
        }
        return ta<tb;
    }
    return ta>tb;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    ull input;
    for(int i=0;i<N;i++){
        cin>>input;
        arr.push_back(input);
    }
        
    sort(arr.begin(),arr.end(),cmp);
    

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";

    return 0;
}