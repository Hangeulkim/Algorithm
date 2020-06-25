#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> op;
vector<int> num;

int val(){
    long long result=num[0];
    for(int i=0;i<N-1;i++){
        switch (op[i]) {
            case 1:
                result+=num[i+1];
                break;
            case 2:
                result-=num[i+1];
                break;
            case 3:
                result*=num[i+1];
                break;
            case 4:
                result/=num[i+1];
                break;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long maxnum=-9876543210,minnum=9876543210,tmp;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        num.push_back(tmp);
    }
    for(int i=1;i<=4;i++){
        cin>>tmp;
        for(int j=0;j<tmp;j++){
            op.push_back(i);
        }
    }
    do {
        tmp=val();
        maxnum=max(maxnum,tmp);
        minnum=min(minnum,tmp);
    } while(next_permutation(op.begin(),op.end()));
    cout<<maxnum<<'\n'<<minnum<<'\n';


    return 0;
}
