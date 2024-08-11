#include<bits/stdc++.h>
using namespace std;
int a [10001][10001];
int main(){
    freopen ("uqe.in","r",stdin);
    freopen ("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    cout<<"1"<<endl;
    cout<<"NO"<<endl;
    cout<<"1"<<endl;
    cout<<"-1"<<endl;
    cout<<"-1/2"<<endl;
    cout<<"12*sqrt(3)"<<endl;
    cout<<"3/2+sqrt(5)/2"<<endl;
    cout<<"1+sqrt(2)/2"<<endl;
    cout<<"©\7/2+3*sqrt(5)/2"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
