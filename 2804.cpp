#include<iostream>
#include<string>

using namespace std;

string input1,input2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input1>>input2;
    int leng1=input1.length();
    int leng2=input2.length();
    int n1=0,n2=0;
    int bflag=0;
    for(int i=0;i<leng1;i++){
        for(int j=0;j<leng2;j++){
            if(input1[i]==input2[j]){
                n1=i;
                n2=j;
                bflag++;
                break;
            }
        }
        if(bflag!=0) break;
    }

    for(int i=0;i<leng2;i++){
        if(i==n2){
            cout<<input1<<'\n';
        }
        else{
            for(int j=0;j<leng1;j++){
                if(j==n1) cout<<input2[i];
                else cout<<".";
            }
            cout<<'\n';
        }
    }

    return 0;
}
