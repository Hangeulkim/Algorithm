#include<bits/stdc++.h>

using namespace std;

int x_check[1001],y_check[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    x_check[x1]++;
    x_check[x2]++;
    x_check[x3]++;

    y_check[y1]++;
    y_check[y2]++;
    y_check[y3]++;

    if(x_check[x1]==1) cout<<x1<<" ";
    else if(x_check[x2]==1) cout<<x2<<" ";
    else cout<<x3<<" ";

    if(y_check[y1]==1) cout<<y1<<" ";
    else if(y_check[y2]==1) cout<<y2<<" ";
    else cout<<y3<<" ";

    return 0;
}
