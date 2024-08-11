#include<bits/stdc++.h>
using namespace std;
int x[500001],y[500001],tx[500001],ty[500001],n,m,c,q;
void init(){
    if(n==m) return;
    if(n>m){
        for(int i=m+1;i<=n;i++){
            ty[i]=ty[m];
        }
    }else{
        for(int i=n+1;i<=m;i++){
            tx[i]=tx[n];
        }
    }
    return;
}
int solve(){
    init();
    int len=max(n,m),xmax=-2147483648,ymax=-2147483648,xmin=2147483647,ymin=2147483647,pxmax,pymax,pxmin,pymin;
    if(ty[1]>tx[1]){
        for(int i=1;i<=len;i++){
            swap(tx[i],ty[i]);
        }
    }
    if(tx[len]<ty[len]) return 0;
    for(int i=1;i<=len;i++){
        xmax=max(tx[i],xmax);
        ymax=max(ty[i],ymax);
        xmin=min(tx[i],xmax);
        ymin=min(ty[i],ymax);
        if(tx[i]==xmax) pxmax=i;
        if(ty[i]==ymax) pymax=i;
        if(tx[i]==xmin) pxmin=i;
        if(ty[i]==ymin) pymin=i;
        if(xmax<=ymax) return 0;
        //if(xmin<=ymin) return 0;
    }
    cout<<endl<<pxmin<<" "<<pymin<<" "<<pxmax<<" "<<endl;
    if(((pxmin>pxmax) and (pymin<pymax)) or ((pxmin<pxmax) and (pymin>pymax))) return 0;
    return 1;
}
int solve2(int a[],int b[]){
    if(a[0]<b[0]){
        swap(a[0],b[0]);
        swap(a[1],b[1]);
    }
    if(a[0]==b[0]) return 0;
    if(a[1]>b[1]){
        return 1;
    }
    return 0;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>c>>n>>m>>q;
    if(c==1){
        int a,b;
        cin>>a;
        cin>>b;
        if(a!=b) cout<<1;
        else cout<<0;
        while(q--){
            int ta=a,tb=b,ca,cb;
            cin>>ca>>cb;
            for(int i=1;i<=ca;i++){
                int p,v;
                cin>>p>>v;
                ta=v;
            }
            for(int i=1;i<=cb;i++){
                int p,v;
                cin>>p>>v;
                tb=v;
            }
            if(ta!=tb) cout<<1;
            else cout<<0;
        }
    }else if(c==2){
        int a[2],b[2];
        cin>>a[0]>>a[1];
        cin>>b[0]>>b[1];
        cout<<solve2(a,b);
        while(q--){
            int ta[2]={a[0],a[1]},tb[2]={b[0],b[1]},ca,cb;
            cin>>ca>>cb;
            for(int i=1;i<=ca;i++){
                int p,v;
                cin>>p>>v;
                ta[p-1]=v;
            }
            for(int i=1;i<=cb;i++){
                int p,v;
                cin>>p>>v;
                tb[p-1]=v;
            }
            cout<<solve2(ta,tb);
        }
    }
    return 0;
}