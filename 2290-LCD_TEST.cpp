#include<bits/stdc++.h>

using namespace std;

string n;
char result[1001][1001];
int s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(result,' ',sizeof(result));
    cin>>s>>n;
    int start=0;
    for(int i=0;i<n.size();i++,start+=s+3){
        switch (n[i]) {
            case '1':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '2':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start]='|';
            }
            break;
            case '3':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '4':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[s+1][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '5':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '6':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+s+2][start+s+1]='|';
                result[cnt+s+2][start]='|';
            }
            break;
            case '7':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '8':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
                result[cnt+s+2][start]='|';
            }
            break;
            case '9':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[s+1][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
            case '0':
            for(int i=start,cnt=0;cnt<s;cnt++,i++){
                result[0][i+1]='-';
                result[2*s+2][i+1]='-';
                result[cnt+1][start]='|';
                result[cnt+1][start+s+1]='|';
                result[cnt+s+2][start]='|';
                result[cnt+s+2][start+s+1]='|';
            }
            break;
        }
    }
    for(int y=0;y<2*s+3;y++){
        for(int x=0;x<(s+3)*n.size();x++){
            cout<<result[y][x];
        }
        cout<<'\n';
    }

    return 0;
}
