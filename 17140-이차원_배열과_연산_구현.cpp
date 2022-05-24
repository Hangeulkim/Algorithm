#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int arr[101][101];
int R=3,C=3;
int r,c,k;

void R_func(){
    int tmp[101][101];
    fill(&tmp[0][0],&tmp[100][101],0);

    int tc=0;
    for(int i=1;i<=R;i++){
        map<int, int> m;
        for(int j=1;j<=C;j++){
            if(!arr[i][j])
                continue;
            m[arr[i][j]]++;
        }
        vector<pair<int,int> > vp(m.begin(),m.end());
        sort(vp.begin(),vp.end(),cmp);
        for(int c=0;c<vp.size() && c<50;c++){
            tmp[i][c*2+1] = vp[c].first;
            tmp[i][c*2+2] = vp[c].second;
        }
        tc=max(tc,(int)vp.size()*2);
    }

    C=tc;
    for(int i=1;i<101;i++)
        for(int j=1;j<101;j++)
            arr[i][j]=tmp[i][j];
}

void C_func(){
    int tmp[101][101];
    fill(&tmp[0][0],&tmp[100][101],0);

    int tr=0;
    for(int i=1;i<=C;i++){
        map<int, int> m;
        for(int j=1;j<=R;j++){
            if(!arr[j][i])
                continue;
            m[arr[j][i]]++;
        }
        vector<pair<int,int> > vp(m.begin(),m.end());
        sort(vp.begin(),vp.end(),cmp);
        for(int c=0;c<vp.size() && c<50;c++){
            tmp[c*2+1][i] = vp[c].first;
            tmp[c*2+2][i] = vp[c].second;
        }
        tr=max(tr,(int)vp.size()*2);
    }

    R=tr;
    for(int i=1;i<101;i++)
        for(int j=1;j<101;j++)
            arr[i][j]=tmp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c>>k;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>arr[i][j];

    int t=0;
    while(arr[r][c]!=k && t<=100){
        if(R>=C)
            R_func();
        else
            C_func();

        t++;
    }

    if(t>100)
        cout<<-1<<'\n';
    else
        cout<<t<<'\n';
    return 0;
}