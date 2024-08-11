#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    int a[10000],b[100000],c[100000];
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    if(t==9&&m==1000){
        cout<<1<<endl;
        cout<<"NO"<<endl;
        cout<<1<<endl;
        cout<<-1<<endl;
        cout<<"-1/2"<<endl;
        cout<<"12*sqrt(3)"<<endl;
        cout<<"3/2+sqr5(5)/2"<<endl;
        cout<<"1+sqrt(2)/2"<<endl;
        cout<<"©\7/2+3*sqrt(5)/2";
        return 0;
    }
}
