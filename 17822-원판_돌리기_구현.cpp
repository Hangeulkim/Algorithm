#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
deque<int> arr[55];
int N,M,T,sum,sz;

void turn_cw(int x, int k){
    for(int i=1;i*x<=N;i++){
        int t=k,idx=i*x-1;
        while(t--){
            arr[idx].push_front(arr[idx].back());
            arr[idx].pop_back();
        }
    }
}

void turn_ccw(int x, int k){
    for(int i=1;i*x<=N;i++){
        int t=k,idx=i*x-1;
        while(t--){
            arr[idx].push_back(arr[idx].front());
            arr[idx].pop_front();
        }
    }
}

bool same_element(){
    vector<pair<int,int> > s;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==-1)
                continue;
            for(int m=0;m<4;m++){
                int ny=i+my[m];
                int nx=(j+mx[m]+M)%M;

                if(ny<0||ny>=N)
                    continue;

                if(arr[ny][nx]==arr[i][j]){
                    s.push_back({i,j});
                    break;
                }
            }
        }
    }

    int ssz=s.size();
    sz-=ssz;

    for(int i=0;i<ssz;i++){
        int y=s[i].first;
        int x=s[i].second;

        sum-=arr[y][x];
        arr[y][x]=-1;
    }

    return s.empty();
}

void avg(){
    double av=(double)sum/sz;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==-1)
                continue;
            if((double)arr[i][j]>av){
                arr[i][j]--;
                sum--;
            }
            else if((double)arr[i][j]<av){
                arr[i][j]++;
                sum++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>T;

    int tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            arr[i].push_back(tmp);
            sum+=tmp;
        }
    }
    sz=N*M;
        

    int x,d,k;
    while(T--&&sz){
        cin>>x>>d>>k;
        if(d==0)
            turn_cw(x,k);
        else
            turn_ccw(x,k);
        if(same_element())
            avg();
    }

    cout<<sum<<'\n';

    return 0;
}