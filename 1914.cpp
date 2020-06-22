#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int num=0,input=0;
string result;

void hanoi(int num, int pil1, int pil2, int pil3){
    if(num==1) cout<<pil1<<" "<<pil3<<'\n';
    else{
        hanoi(num-1,pil1,pil3,pil2);
        cout<<pil1<<" "<<pil3<<'\n';
        hanoi(num-1,pil2,pil1,pil3);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    result.push_back('0');
    for(int i=1;i<=input;i++){
        for(int j=0;result[j]!='\0';j++){
            result[j]=(result[j]-'0')*2+'0';
        }
        result[0]+=1;

        for(int j=0;result[j]!='\0';j++){
            if(result[j]-'0'>=10){
                if(j+1==result.length()) result.push_back('1');
                else result[j+1]+=1;
            }
            result[j]=(result[j]-'0')%10+'0';
        }
    }
    reverse(result.begin(),result.end());
    cout<<result<<'\n';
    if(input<=20) hanoi(input,1,2,3);

    return 0;
}
