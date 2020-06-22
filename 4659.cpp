#include<iostream>
#include<vector>
#include<string>

using namespace std;
string tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin>>tmp;
        if(tmp=="end") break;
        int leng=tmp.length(),bflag=0;

        int allae=0;
        int ae=0,bc=0;
        for(int i=0;i<leng;i++){
            if(i<leng-1){
                if(tmp[i]==tmp[i+1]){
                    if(tmp[i]!='e'&&tmp[i]!='o'){
                        bflag++;
                        break;
                    }
                }
            }
            if(tmp[i]=='a'||tmp[i]=='e'||tmp[i]=='i'||tmp[i]=='o'||tmp[i]=='u'){
                allae++;
                ae++;
                bc=0;
            }
            else{
                ae=0;
                bc++;
            }
            if(ae>=3||bc>=3){
                bflag++;
                break;
            }
        }
        if(bflag!=0||allae==0){
            cout<<"<"<<tmp<<"> is not acceptable."<<'\n';
        }
        else cout<<"<"<<tmp<<"> is acceptable."<<'\n';
    }





    return 0;
}
