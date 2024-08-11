#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5e5+10;
int c,n,m,q;
int x[MAXN],y[MAXN];
void Change(){
    int kx,ky;cin>>kx>>ky;
    while(kx--){
        int a,b;cin>>a>>b;
        x[a]=b;
    }
    while(ky--){
        int a,b;cin>>a>>b;
        y[a]=b;
    }
}
void Work1(){
    /*if(x[1]<0&&y[1]<0) cout<<1<<endl;
    else if(x[1]>0&&y[1]>0) cout<<1<<endl;
    else cout<<0<<endl;*/
    if(x[1]==y[1]) cout<<0<<endl;
    else cout<<1<<endl;
}
void Work2(){
    if(n==1&&m==1) Work1();
    else if(n==1&&m==2){
        x[++n]=x[n-1];
    } 
    else if(n==2&&m==1){
        y[++m]=y[m-1];
    }
    for(int i=1;i<=2;i++) if(x[i]==y[i]){
        cout<<0<<endl;
        return;
    }
    int a=x[1]-y[1],b=x[2]-y[2];
    if(a*b>0){
        cout<<1<<endl;
    }
    else cout<<0<<endl;
}
void Work3(){
    for(int i=1;i<=n;i++);
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    if(c==1) Work1();
    else if(c==2) Work2();
    for(int i=1;i<=q;i++){
        Change();
        if(c==1) Work1();
        else if(c==2) Work2();
    }
    return 0;
}