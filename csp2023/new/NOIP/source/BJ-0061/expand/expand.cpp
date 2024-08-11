#include<bits/stdc++.h>
using namespace std;
int sta[500005];
int stb[500005];
int cc,n,m,q;
int a[500005];
int b[500005];
int st1[500005][20];
int st2[500005][20];
inline int nxt(int x,const int &y){
    for(int k=19;k>=0;k--){
//            cout<<x<<" "<<y<<endl;
        if(x+(1<<k)<=n&&st1[x][k]>y){
            x+=(1<<k);
        }
    }
    if(st1[x][0]<=y)x--;
    return x;
}
inline int lst(int x,const int &y){
    for(int k=19;k>=0;k--){
        if(x-(1<<k)>=1&&st2[x][k]<=y){
            x-=(1<<k);
        }
    }
    if(st2[x][0]<=y)x=0;
    return x;
}
inline bool solve(){
    memset(st1,39999,sizeof(st1));
    memset(st2,-39999,sizeof(st2));
    int pa=1;
    int pb=1;
    int cs=1;
//    a[n+1]=-2e9;
//    b[m+1]=2e9;
    a[0]=-2e9;
//    b[0]=2e9;
    if(a[1]<b[1])cs=-1;
    a[0]*=cs;
//    b[m+1]*=cs;
    for(int i=1;i<=n;i++){
        st1[i][0]=cs*a[i];
        st2[i][0]=cs*a[i];
    }
    for(int k=1;k<=19;k++){
        int nn=n-(1<<k)+1;
        for(int i=1;i<=nn;i++){
            st1[i][k]=min(st1[i][k-1],st1[i+(1<<(k-1))][k-1]);
        }
    }
    for(int k=1;k<=19;k++){
        for(int i=(1<<k);i<=n;i++){
            st2[i][k]=max(st2[i][k-1],st2[i-(1<<(k-1))][k-1]);
        }
    }
    int aa=0;
    for(int i=1;i<=m;i++){
//            cout<<i<<" "<<aa<<endl;
        if(aa<n&&a[aa+1]*cs>b[i]*cs){
//            cout<<1<<endl;
            aa=nxt(aa+1,b[i]*cs);
        }else if(a[aa]*cs<=b[i]*cs){
            aa=lst(aa,b[i]*cs);
            if(aa==0)return 0;
        }
    }
    return aa==n;
}
int main(){
//    cout<<sizeof(st)/1024.0/1024.0<<endl;
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>cc>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>sta[i];
    }
    for(int i=1;i<=m;i++){
        cin>>stb[i];
    }
    for(int i=1;i<=n;i++)a[i]=sta[i];
    for(int i=1;i<=m;i++)b[i]=stb[i];
    cout<<solve();
    for(int i=1;i<=q;i++){
        for(int i=1;i<=n;i++)a[i]=sta[i];
        for(int i=1;i<=m;i++)b[i]=stb[i];
        int na,nb;
        cin>>na>>nb;
        for(int i=1;i<=na;i++){
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }
        for(int i=1;i<=nb;i++){
            int x,y;
            cin>>x>>y;
            b[x]=y;
        }
        cout<<solve();
    }
    return 0;
}
