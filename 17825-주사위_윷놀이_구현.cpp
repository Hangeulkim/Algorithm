#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[10];
int ret=0;

bool chks(vector<int> v){
    for(int i=0;i<4;i++){
        if(v[i]==9999||v[i]==0)
            continue;
        for(int j=i+1;j<4;j++){
            if(v[i]==v[j])
                return false;
        }
    }
    return true;
}

pair<int,int> calc(int f, int d){
    int s=0;
    if(f>=100){
        while(d--){
            if(f==100||f==130||f==160)
                f+=30;
            else if(f==190||f==260||f==240)
                f=2500;
            else if(f==200||f==220)
                f+=20;
            else if(f==300)
                f=280;
            else if(f==280||f==270)
                f-=10;
            else if(f==2500||f==3000||f==3500)
                f+=500;
            else{
                f=9999;  
                break;
            }                  
        }
    }
    else{
        f+=2*d;
    }

    if(f==10||f==20||f==30)
        f*=10;
    else if(f==40)
        f=4000;

    if(f<100&&f>40)
        f=9999;
    
    if(f==9999)
        s=0;
    else if(f<100)
        s=f;
    else if(f<1000)
        s=f/10;
    else
        s=f/100;

    
    return {f,s};
}   

void dfs(vector<int> v, int d, int s){
    if(d==10){
        /*
        if(ret<s){
            cout<<'\n'<<s<<'\n';
            for(int i=0;i<4;i++)
                cout<<v[i]<<" ";
            cout<<'\n';
        }*/
        ret=max(ret,s);
        return;
    }

    for(int idx=0;idx<4;idx++){
        if(v[idx]==9999)
            continue;
        pair<int,int> p = calc(v[idx],arr[d]);
        vector<int> t = {v.begin(),v.end()};
        t[idx]=p.first;

        if(chks(t))
            dfs(t,d+1,s+p.second);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<10;i++)
        cin>>arr[i];

    vector<int> v(5,0);
    
    dfs(v,0,0);
    cout<<ret<<'\n';

    return 0;
}