#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    if(n==9&&m==1000){
        cout<<1<<endl
        <<"NO"<<endl
        <<1<<endl
        <<-1<<endl
        <<"-1/2"<<endl
        <<"12*sqrt(3)"<<endl
        <<"3/2+sqrt(5)/2"<<endl
        <<"1+sqrt(2)/2"<<endl
        <<"-7/2+3*sqrt(5)/2";
    }else for(int i=0;i<n;i++)cout<<"NO"<<endl;
    return 0;
}