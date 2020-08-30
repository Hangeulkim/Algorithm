#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    string a,b,c;
    int cnt;
}dat;

string A,B,C;
char tmp;
int num;
map<string, bool> visit;

bool chk(string a, string b, string c){
    if(a.find("B")!=string::npos||a.find("C")!=string::npos)
        return false;
    if(b.find("A")!=string::npos||b.find("C")!=string::npos)
        return false;
    if(c.find("A")!=string::npos||c.find("B")!=string::npos)
        return false;
    return true;
}

string chg(string a, string b, string c){
    return a+"/"+b+"/"+c;
}

int bfs(){
    string tmpstr=chg(A,B,C);
    queue<dat> q;
    q.push({A,B,C,0});
    visit[tmpstr]=true;

    while(!q.empty()){
        string a=q.front().a;
        string b=q.front().b;
        string c=q.front().c;
        int cnt=q.front().cnt;

        q.pop();

        if(chk(a,b,c)){
            return cnt;
        }


        if(a.length()>0){
            string tmpa=a;
            tmpa.pop_back();

            tmpstr=chg(tmpa,b+a[a.length()-1],c);
            if(visit.count(tmpstr)==0){
                q.push({tmpa,b+a[a.length()-1],c,cnt+1});
                visit[tmpstr]=true;
            }

            tmpstr=chg(tmpa,b,c+a[a.length()-1]);
            if(visit.count(tmpstr)==0){
                q.push({tmpa,b,c+a[a.length()-1],cnt+1});
                visit[tmpstr]=true;
            }
        }
        if(b.length()>0){
            string tmpb=b;
            tmpb.pop_back();

            tmpstr=chg(a+b[b.length()-1],tmpb,c);
            if(visit.count(tmpstr)==0){
                q.push({a+b[b.length()-1],tmpb,c,cnt+1});
                visit[tmpstr]=true;
            }

            tmpstr=chg(a,tmpb,c+b[b.length()-1]);
            if(visit.count(tmpstr)==0){
                q.push({a,tmpb,c+b[b.length()-1],cnt+1});
                visit[tmpstr]=true;
            }
        }
        if(c.length()>0){
            string tmpc=c;
            tmpc.pop_back();

            tmpstr=chg(a+c[c.length()-1],b,tmpc);
            if(visit.count(tmpstr)==0){
                q.push({a+c[c.length()-1],b,tmpc,cnt+1});
                visit[tmpstr]=true;
            }

            tmpstr=chg(a,b+c[c.length()-1],tmpc);
            if(visit.count(tmpstr)==0){
                q.push({a,b+c[c.length()-1],tmpc,cnt+1});
                visit[tmpstr]=true;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>num;
    while(num--){
        cin>>tmp;
        A.push_back(tmp);
    }
    cin>>num;
    while(num--){
        cin>>tmp;
        B.push_back(tmp);
    }
    cin>>num;
    while(num--){
        cin>>tmp;
        C.push_back(tmp);
    }
    cout<<bfs();
    return 0;
}
