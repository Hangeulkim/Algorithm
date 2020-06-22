#include<bits/stdc++.h>

using namespace std;

vector<int> part_sum;
int cnt=0,N;
bool ch[4000001]={false,};

void aritos(){
    part_sum.push_back(0);
    for(int i=2;i<4000001;i++){
        if(!ch[i]){
            part_sum.push_back(i+part_sum[part_sum.size()-1]);
            for(int j=2;j*i<4000001;j++){
                ch[j*i]=true;
            }
        }
    }
}

void result(){
    int start=0,end=1;

    while(1){
        if(part_sum[end]-part_sum[start]==N){
            cnt++;
            start++;
        }
        else if(part_sum[end]-part_sum[start]<N){
            end++;
        }
        else{
            start++;
        }
        if(start==end){
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    aritos();

    cin>>N;

    result();

    cout<<cnt<<'\n';

    return 0;
}
