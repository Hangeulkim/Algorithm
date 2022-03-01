#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

double san;
vector<int> jung;
int most[8001];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        jung.push_back(tmp);
        most[tmp+4000]++;
        san+=tmp;
    }
    sort(jung.begin(),jung.end());

    cout<<int(round(san/N))<<'\n';
    cout<<jung[N/2]<<'\n';
    tmp=*max_element(most,most+8001);
    int cnt=0,sflag=0;
    for(int i=0;i<8001;i++){
        if(tmp==most[i]){
            if(sflag){
                cnt=i-4000;
                break;
            }
            cnt=i-4000;
            sflag=1;
        }
    }
    cout<<cnt<<'\n';
    cout<<jung[N-1]-jung[0]<<'\n';

    return 0;
}