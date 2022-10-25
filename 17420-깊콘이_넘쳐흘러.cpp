#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct dat{
    int A,B;
}d;

struct cmp{
    bool operator()(d &a, d &b){
        if(a.B == b.B)
            return a.A<b.A;
        return a.B<b.B;
    }
};

int N;

vector<d> C;

long long ans=0;
void input(){
    int num;

    cin>>N;

    C.resize(N);
    for(int i=0;i<N;i++)
        cin>>C[i].A;

    for(int i=0;i<N;i++)
        cin>>C[i].B;
}

void solution(){
    sort(C.begin(),C.end(),cmp());

    int pmax=C[0].B;
    int cmax=-1;
    for(int i=0;i<N;i++){
        int A=C[i].A;
        int B=C[i].B;
        if(pmax > A){
            int num=(pmax - A + 29)/30;
            ans += num;
            
            A += num*30;
        }
        

        cmax = max(cmax, A);
        if(i<N-1 && B != C[i+1].B){
            pmax = max(cmax,C[i+1].B);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}