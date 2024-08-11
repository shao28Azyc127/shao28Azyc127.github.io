#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int c,n,m,q,x[500005],y[500005];
bool judge(){
    int r,lt,minna,minnb;
    r=1; lt=0x7fffffff; minna=-1; minnb=-1;
    for(int i=1;i<=n;i++){
        if(x[i]>=lt) {minna=max(minna,x[i]); continue;}
        if(minna>=minnb&&minna!=-1) return 0;
        minna=-1; lt=x[i];
        while(r<m&&y[r]>x[i]){
                r++;
                minnb=max(minnb,y[r]);
        }
    }
    if(r==m) return 1;
    return 0;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    if(n==1&&m==1){
        for(int i=0;i<=q;i++) cout<<1;
        cout<<endl;
        return 0;
    }
    if(n==1&&m==2){
        cout<<((x[1]-y[1])*(x[1]-y[2])>0);
        int kx,ky,p,v;
        for(int i=0;i<q;i++){
            cin>>kx>>ky;
            for(int j=0;j<kx;j++) {cin>>p>>v; x[p]=v;}
            for(int j=0;j<ky;j++) {cin>>p>>v; y[p]=v;}
            cout<<((x[1]-y[1])*(x[1]-y[2])>0);
        }
        cout<<endl;
        return 0;
    }
    if(n==2&&m==1){
        cout<<((x[1]-y[1])*(x[2]-y[1])>0);
        int kx,ky,p,v;
        for(int i=0;i<q;i++){
            cin>>kx>>ky;
            for(int j=0;j<kx;j++) {cin>>p>>v; x[p]=v;}
            for(int j=0;j<ky;j++) {cin>>p>>v; y[p]=v;}
            cout<<((x[1]-y[1])*(x[2]-y[1])>0);
        }
        cout<<endl;
        return 0;
    }
    if(n==2&&m==2){
        cout<<((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]));
        int kx,ky,p,v;
        for(int i=0;i<q;i++){
            cin>>kx>>ky;
            for(int j=0;j<kx;j++) {cin>>p>>v; x[p]=v;}
            for(int j=0;j<ky;j++) {cin>>p>>v; y[p]=v;}
            cout<<((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]));
        }
        cout<<endl;
        return 0;
    }
    if(c>=8&&c<=14){
            int kx,ky,p,v;
        cout<<judge();
        for(int i=0;i<q;i++){
            cin>>kx>>ky;
            for(int j=0;j<kx;j++) {cin>>p>>v; x[p]=v;}
            for(int j=0;j<ky;j++) {cin>>p>>v; y[p]=v;}
            cout<<judge();
        }
        cout<<endl;
        return 0;
    }

    /*if(a[1]<b[1]){
        for(int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
        swap(n,m);
    }
    if(a[1]==b[1]||a[n]<=b[m]) cout<<0;
    int l,r,k1,k2,lt,minna,minnb;
    r=0; lt=0; minna=0x7fffffff; minnb=0x7fffffff;
    for(int i=1;i<=n;i++){
        if(a[i]<=lt) {minna=min(minna,a[i]); continue;}
        if(minna<=minnb&&minna!=0x7fffffff) {cout<<'?'; break;}
        cout<<minna<<" "<<minnb<<endl;
        minna=0x7fffffff; lt=a[i];
        while(r<m&&b[r]<a[i]){
                r++;
                minnb=min(minnb,b[r]);
        }
        if(r==m) k1=i;
    }
    if(r<m) cout<<0;
    l=m; lt=0; minna=0x7fffffff; minnb=0x7fffffff;
    for(int i=n;i>=1;i--){
        if(a[i]<=lt) {minna=min(minna,a[i]); continue;}
        if(minna<=minnb&&minna!=0x7fffffff) {cout<<0; break;}
        minna=0x7fffffff; lt=a[i];
        while(l>1&&b[l]<a[i]){
                l--;
                minnb=min(minnb,b[l]);
        }
        if(l==1) k1=i;
    }
    cout<<l<<" "<<r<<endl;
    if(l>1) cout<<0;
    if(l>r) cout<<0;*/
    return 0;
}
