#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A,B,C;
    while(1){
        cin>>A>>B>>C;

        if(!A&&!B&&!C)
            break;

        if(A==B && B==C)
            cout<<"Equilateral"<<'\n';
        else if(A >= B+C || B >= A+C || C >= B+A)
            cout<<"Invalid"<<'\n';
        else if(A==B || B==C || A==C)
            cout<<"Isosceles"<<'\n';
        else
            cout<<"Scalene"<<'\n';
    }

    return 0;
}