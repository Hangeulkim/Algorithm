#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct Data{
    int sy,sx,ey,ex;
    int dm;
}d;

int L,N;
vector<d> vst;
vector<pair<int, char> > moving;

int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};
long long ret=0;
int y=0,x=0;
int m=0;

bool chk(int ny, int nx){//이동 가능한 칸수를 반환 
    int ty1,tx1,ty2,tx2,cnt;
    bool r=true;

    switch (m)
    {
        case 0:
            ty1=ty2=y;
            tx1=x;
            tx2=nx;
            cnt=nx-x;
            break;
    
        case 2:
            ty1=ty2=y;
            tx1=nx;
            tx2=x;
            cnt=x-nx;
            break;
        
        case 1:
            tx1=tx2=x;
            ty1=y;
            ty2=ny;
            cnt=ny-y;
            break;

        case 3:
            tx1=tx2=x;
            ty1=ny;
            ty2=y;
            cnt=y-ny;
            break;
    }

    for(int i=vst.size()-2;i>=0;i--){//이전 몸통의 경우 이어서 늘어나므로 부딪힐 일이 없음
        int sy=vst[i].sy;
        int sx=vst[i].sx;
        int ey=vst[i].ey;
        int ex=vst[i].ex;
        

        if(sy==ey){//몸통이 가로로 있음
            if(m==0||m==2){//가로 가로
                if(sy==ty1){
                    if((tx1<=ex)&&(tx2>=sx)){
                        if(m==0)
                            cnt=min(cnt,sx-tx1);
                        else
                            cnt=min(cnt,tx2-ex);
                        r=false;
                    }
                }
            }
            else{//가로 세로
                if(tx1>=sx&&tx1<=ex){
                    if(ty1<=sy&&ty2>=sy){
                        if(m==1)
                            cnt=min(cnt,sy-ty1);
                        else
                            cnt=min(cnt,ty2-sy);
                        r=false;
                    }
                }
            }
        }
        else{
            if(m==1||m==3){//세로 세로
                if(sx==tx1){
                    if((ty1<=ey)&&(ty2>=sy)){
                        if(m==1)
                            cnt=min(cnt,sy-ty1);
                        else
                            cnt=min(cnt,ty2-ey);
                        r=false;
                    }
                }
            }
            else{//세로 가로
                if(ty1>=sy&&ty1<=ey){
                    if(tx1<=sx&&tx2>=sx){
                        if(m==0)
                            cnt=min(cnt,sx-tx1);
                        else
                            cnt=min(cnt,tx2-sx);
                        r=false;
                    }
                }
            }
        }
    }
    

    if(ty1<-L||tx1<-L||ty2>L||tx2>L){//그리드를 벗어낫는지 체크
        switch (m)
        {
            case 0:
                cnt = min(cnt,L+1-tx1);
                break;
             case 1:
                cnt = min(cnt,L+1-ty1);
                break;
             case 2:
                cnt = min(cnt,L+1+tx2);
                break;
             case 3:
                cnt = min(cnt,L+1+ty2);
                break;
        }
        r=false;
    }
    vst.push_back({ty1,tx1,ty2,tx2});

    ret+=cnt;
    return r;
}

bool chgmove(int t, char dir){
    int ny = y+my[m]*t;
    int nx = x+mx[m]*t;

    bool tmp = chk(ny,nx);

    if(!tmp){
        return false;
    }

    if(dir=='L'){
        --m;
        if(m<0)
            m=3;
    }
    else{
        ++m;
        m%=4;
    }
    y=ny;
    x=nx;

    return true;
}

void Input(){
    cin>>L>>N;

    int a;
    char b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        moving.push_back({a,b});
    }

    moving.push_back({200'000'007,0});
}

void Solution(){
    for(int i=0;i<moving.size()+1;i++){
        int t = moving[i].first;
        char dir = moving[i].second;

        if(!chgmove(t,dir))
            break;
    }

    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}