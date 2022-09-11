#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

long long maxdp[11][11];
long long mindp[11][11];
string str;
int N;

long long calc(long long a, long long b, char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>str;

    fill(&mindp[0][0],&mindp[10][11],INT_MAX);
    fill(&maxdp[0][0],&maxdp[10][11],INT_MIN);
    for(int i=0;i<=N/2;i++){
        mindp[i][i]=maxdp[i][i]=str[i*2]-'0';
    }

    for(int cnt=1;cnt<=N/2;cnt++){
        for(int st=0;st<=N/2-cnt;st++){
            for(int i=1;i<=cnt;i++){
                char op = str[(st+i)*2-1];

                long long arr[4]={
                    calc(maxdp[st][st+i-1],maxdp[st+i][st+cnt],op),
                    calc(maxdp[st][st+i-1],mindp[st+i][st+cnt],op),
                    calc(mindp[st][st+i-1],maxdp[st+i][st+cnt],op),
                    calc(mindp[st][st+i-1],mindp[st+i][st+cnt],op)
                };

                sort(arr,arr+4);


                maxdp[st][st+cnt]=max(maxdp[st][st+cnt],arr[3]);
                mindp[st][st+cnt]=min(mindp[st][st+cnt],arr[0]);
            }
        }
    }

    cout<<maxdp[0][N/2]<<'\n';
    return 0;
}