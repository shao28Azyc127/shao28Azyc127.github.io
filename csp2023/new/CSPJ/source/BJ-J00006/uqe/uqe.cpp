#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a[5005],b[5005],c[5005],d[5005],rec[5005],u[5005];
    cin>>t>>m;
    for(int i=0;i<t;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<t;i++){
        rec[i]=b[i]*b[i]-4*a[i]*c[i];
        if(rec[i]<0)cout<<"NO"<<endl;
        int r=sqrt(c[i]/a[i]);
        if(c[i]+r*2*a[i]==0)cout<<u[i]<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
