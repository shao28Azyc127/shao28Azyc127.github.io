#include<bits/stdc++.h>
using namespace std;
int c,m,n,q,nx,ny,x,y;
int a[500005],b[500005],ta[500005],tb[500005];
void judge(){
    if(c==1){
        if(ta[1]==tb[1]) cout<<0;
        else cout<<1;
    }
    else if(c>=8&&c<=14){
        if(ta[m]>=tb[n]) cout<<0;
        else cout<<1;
    }

}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c;
    cin>>m>>n>>q;
    for(int i=1;i<=m;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    cin>>b[i];
    for(int j=1;j<=m;j++)
            ta[j]=a[j];
        for(int j=1;j<=n;j++)
            tb[j]=b[j];
    judge();
    for(int i=1;i<=q;i++){
        for(int j=1;j<=m;j++)
            ta[j]=a[j];
        for(int j=1;j<=n;j++)
            tb[j]=b[j];
        cin>>nx>>ny;
        for(int j=1;j<=nx;j++){
            cin>>x>>y;
            ta[x]=y;
        }
        for(int j=1;j<=ny;j++){
            cin>>x>>y;
            tb[x]=y;
        }
        judge();
    }


    return 0;

}
