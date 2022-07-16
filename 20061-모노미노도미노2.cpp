#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gboard[10][10];
int bboard[10][10];
int N,b=1;
int t,x,y;
int ret=0;

int move(vector<pair<int,int> > v, int c, int arr[10][10]){
    int m=1;
    bool bflag=false;
    while(1){
        for(int i=0;i<v.size();i++){
            int y=v[i].first;
            int x=v[i].second;

            if(y+m==5||(arr[y+m+1][x]&&arr[y+m+1][x]!=c)){
                bflag=true;
                break;
            }
        }

        if(bflag)
            break;
        m++;
    }

    return m;
}

void under(int arr[10][10]){
    for(int i=1;i>=0;i--){
        for(int j=0;j<4;j++){
            if(arr[i][j]){
                vector<pair<int, int> > v;

                if(arr[i+1][j]||(arr[i][j+1]==arr[i][j]&&arr[i+1][j+1])||(j>0&&arr[i][j-1]==arr[i][j]&&arr[i+1][j-1]))
                    continue;

                v.push_back({i,j});

                if(arr[i-1][j]==arr[i][j])
                    v.push_back({i-1,j});
                    
                if(arr[i][j+1]==arr[i][j]){
                    if(arr[i+1][j+1])
                        continue;
                    v.push_back({i,j+1});
                }

                int c=arr[i][j];
                int m=move(v,c,arr);

                for(int k=0;k<v.size();k++){
                    int ty=v[k].first;
                    int tx=v[k].second;

                    arr[ty][tx]=0;
                    arr[ty+m][tx]=c;
                }
            }
        }
    }
}

bool chk_over(int arr[10][10]){
    for(int i=1;i>=0;i--){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=0)
                return true;
        }
    }
    return false;
}

void del_last(int arr[10][10]){
    for(int i=4;i>=0;i--){
        for(int j=0;j<4;j++){
            arr[i+1][j]=arr[i][j];
            arr[i][j]=0;
        } 
    }
}

int chk(int arr[10][10]){
    for(int i=5;i>=2;i--){
        if(arr[i][0]&&arr[i][1]&&arr[i][2]&&arr[i][3]){
            ret++;
            for(int k=i;k>=1;k--)
                for(int j=0;j<4;j++)
                    arr[k][j]=arr[k-1][j];
            return true;
        }
    }
    return false;
}

void show(int arr[10][10]){
    cout<<b<<'\n';
    for(int i=0;i<=5;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void func(int arr[10][10]){
    under(arr);
    while(chk(arr)) ;

    while(chk_over(arr)){
        del_last(arr);
    }

    while(chk(arr)) ;
}

int cnt(int arr[10][10]){
    int res=0;

    for(int i=0;i<=5;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j])
                res++;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    while(N--){
        cin>>t>>x>>y;
        gboard[1][x]=b;
        bboard[1][y]=b;
        switch (t)
        {
        case 2:
            gboard[0][x]=b;
            bboard[1][y+1]=b;
            break;
        case 3:
            gboard[1][x+1]=b;
            bboard[0][y]=b;
            break;
        }
        func(gboard);

        func(bboard);

        b++;
    }

    cout<<ret<<'\n';
    cout<<cnt(bboard)+cnt(gboard)<<'\n';

    return 0;
}