#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

using namespace std;

deque<int> dq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=0,N=0,tmp=0;
    cin>>T;
    string input;
    while(T--){
        cin>>input>>N;
        int lend=0,rend=N-1,rvcnt=0,bflag=0,dqsize=0;
        dq.clear();

        cin>>tmp;
        cin.clear();
        cin.ignore(1,'\n');
        while(dqsize!=N){
            cin>>tmp;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1,'\n');
                continue;
            }
            dq.push_back(tmp);
            dqsize++;
        }
        cin>>tmp;
        cin.clear();
        cin.ignore(1,'\n');

        int leng=input.length();
        for(int i=0;i<leng;i++){
            if(input[i]=='R'){
                rvcnt++;
            }
            else{
                if(rvcnt%2==1){
                    rend--;
                }
                else{
                    lend++;
                }
                if(rend-lend<-1){
                    cout<<"error"<<'\n';
                    bflag=1;
                    break;
                }
            }
        }
        if(bflag) continue;

        cout<<"[";
        int lengdq=rend-lend;
        if(rvcnt%2==1) {
            if(lengdq<0){
                cout<<"]"<<'\n';
            }
            else{
                for(int i=rend;i>=lend+1;i--){
                    cout<<dq[i]<<",";
                }
                cout<<dq[lend]<<"]"<<'\n';
            }
        }
        else{
            if(lengdq<0){
                cout<<"]"<<'\n';
            }
            else{
                for(int i=lend;i<=rend-1;i++){
                    cout<<dq[i]<<",";
                }
                cout<<dq[rend]<<"]"<<'\n';
            }
        }
    }



    return 0;
}
