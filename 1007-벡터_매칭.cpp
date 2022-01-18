#include<bits/stdc++.h>

using namespace std;

int T;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(12);
    cout << fixed;

    cin>>T;
    while(T--){
        cin>>N;
        vector<pair<double,double> > P;
        double tmp1,tmp2;
        vector<int> arr;
        for(int i=0;i<N;i++){
            cin>>tmp1>>tmp2;
            P.push_back({tmp1,tmp2});
            if(i<N/2)
                arr.push_back(0);
            else
                arr.push_back(1);
            
        }

        double ret=987654321;
        do
        {
            double val[2][2];
            memset(val,0,sizeof(val));
            double tmp=0;
            for(int i=0;i<N;i++){
                if(arr[i]){
                    val[0][0]+=P[i].first;
                    val[0][1]+=P[i].second;
                    val[1][0]-=P[i].first;
                    val[1][1]-=P[i].second;
                    
                    
                }
                else{
                    val[0][0]-=P[i].first;
                    val[0][1]-=P[i].second;
                    val[1][0]+=P[i].first;
                    val[1][1]+=P[i].second;
                }
                    
            }

            tmp=min(sqrt(pow(val[0][0],2)+pow(val[0][1],2)),sqrt(pow(val[1][0],2)+pow(val[1][1],2)));
            ret=min(ret,tmp);
        } while (next_permutation(arr.begin(),arr.end()));
        cout<<ret<<'\n';
    }

    return 0;
}