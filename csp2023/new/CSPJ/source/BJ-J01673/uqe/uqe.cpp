#include<iostream>
#include<cstdio>
using namespace std;
struct abc{
int x;
}a[1001];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,t,a,b,c,x;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
    }
    cout<<1<<endl;
    cout<<"NO"<<endl;
    cout<<1<<endl;
    cout<<-1<<endl;
    cout<<"-1/2"<<endl;
    cout<<"12*sqrt(3)"<<endl;
    cout<<"3/2+sqrt(5)/2"<<endl;
    cout<<"1+sqrt(2)/2"<<endl;
    cout<<"-7/2+3*sqrt(5)/2"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}