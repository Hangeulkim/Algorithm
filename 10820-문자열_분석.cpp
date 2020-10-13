#include<bits/stdc++.h>

using namespace std;

string input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(getline(cin,input)){
        int big=0,small=0,space=0,num=0;
        for(int i=0;i<input.length();i++){
            if(input[i]==' ')
                space++;
            else if(input[i]>='a'&&input[i]<='z')
                small++;
            else if(input[i]>='A'&&input[i]<='Z')
                big++;
            else
                num++;
        }
        cout<<small<<" "<<big<<" "<<num<<" "<<space<<'\n';
    }

    return 0;
}
