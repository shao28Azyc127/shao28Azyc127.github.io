#include<bits/stdc++.h>
using namespace std;
int a[500050],b[500050];
int p[500050],q[500050];
bool f[2050];
int sub,t,n,m;
void input(){
    scanf("%d%d%d%d",&sub,&n,&m,&t);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),q[i]=b[i];
}void chk(){
    memset(f,0,sizeof(f));
    f[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[j]=(f[j-1]||f[j])&&(a[i]>b[j]);
            //cout<<f[j]<<' '<<a[i]<<' '<<b[j]<<' ';
        }//cout<<endl;
    }if(f[m]){
        putchar('1');
        //puts("-");
        return ;
    }memset(f,0,sizeof(f));
    f[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[j]=(f[j-1]||f[j])&&(a[i]<b[j]);
        }
    }if(f[m])if(f[m]){
        putchar('1');
        //puts("_");
        return ;
    }
    putchar('0');
    //puts("");
}void slv(){
    chk();
    int x,y;
    while(t--){
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++){
            int c,v;
            scanf("%d%d",&c,&v);
            a[c]=v;
        }for(int i=1;i<=y;i++){
            int c,v;
            scanf("%d%d",&c,&v);
            b[c]=v;
        }chk();
        for(int i=1;i<=n;i++) a[i]=p[i];
        for(int i=1;i<=m;i++) b[i]=q[i];
    }
}void chk2(int a1,int a2,int b1,int b2,int al,int bl){
    if(b1>a1&&b2>a2&&(b2>al||a1<bl)) putchar('1');
    else putchar('0');
}void slv2(){
    int ax=0,an=1e9,bx=0,bn=1e9;
    for(int i=1;i<=n;i++) ax=max(ax,a[i]),an=min(an,a[i]);
    for(int i=1;i<=m;i++) bx=max(bx,b[i]),bn=min(bn,b[i]);
    int al=a[1],bl=b[1];
    chk2(ax,an,bx,bn,al,bl);
    while(t--){
        int x,y;
        int qax=0,qan=1e9,qbx=0,qbn=1e9;
        int qal=al,qbl=bl;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++){
            int c,v;
            scanf("%d%d",&c,&v);
            if(c==1) al=v;
            qax=max(qax,v);
            qan=min(qan,v);
        }for(int i=1;i<=y;i++){
            int c,v;
            scanf("%d%d",&c,&v);
            if(c==1) bl=v;
            qbx=max(qbx,v);
            qbn=min(qbn,v);
        }chk2(qax,qan,qbx,qbn,qal,qbl);
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    input();
    if(sub<=7) slv();
    else slv2();
    return 0;
}
