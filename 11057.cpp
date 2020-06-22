#include<iostream>
#include<vector>
using namespace std;
vector<int> result[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<10;i++) result[i].push_back(1);

    int N=0;
    cin>>N;
    for(int i=1;i<N;i++){
        for(int j=0;j<10;j++){
            result[j].push_back(0);
            for(int m=0;m<=j;m++){
                result[j][i]=(result[m][i-1]+result[j][i])%10007;
            }
        }
    }
    int answer=0;
    for(int i=0;i<10;i++) answer+=result[i].back();
    answer=answer%10007;
    cout<<answer<<'\n';
    return 0;
}
