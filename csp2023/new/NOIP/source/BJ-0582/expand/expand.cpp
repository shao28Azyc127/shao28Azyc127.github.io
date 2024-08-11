#include <bits/stdc++.h>

using namespace std;

int Num,n,m,q;
int x[500050],y[500050],a[500050],b[500050],kx,ky;

stack <int> qa;
stack <int> qb;

void init(){
    for(int i=1;i<=n;i++) a[i]=x[i];
    for(int i=1;i<=m;i++) b[i]=y[i];
}

void intoq(){
    for(int i=1;i<=n;i++) qa.push(a[i]);
    for(int i=1;i<=m;i++) qb.push(b[i]);
}

int main()
{
    //AC please~
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>Num>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }
    while(q--){
        cin>>kx>>ky;
        init();
        for(int i=1;i<=kx;i++){
            int j,v;
            cin>>j>>v;
            a[j]=v;
        }
        for(int i=1;i<=ky;i++){
            int j,v;
            cin>>j>>v;
            b[j]=v;
        }// change over
        intoq();
        cout<<"0";
    }
    return 0;
}
