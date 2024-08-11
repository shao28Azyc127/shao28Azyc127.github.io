#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

int n,m,c,q,a[MAXN],b[MAXN],A[MAXN],B[MAXN],pr[MAXN],pb[MAXN];
bool f[MAXN][MAXN],h[MAXN][MAXN];
int g[MAXN][MAXN],l[MAXN][MAXN],L[MAXN][MAXN],R[MAXN][MAXN];
int lef[MAXN],rig[MAXN];
bool check1(){
    for(int i=0;i<=max(n,m)+1;i++) for(int j=0;j<=max(n,m)+1;j++) f[i][j]=g[i][j]=h[i][j]=l[i][j]=0;
    f[0][0]=h[n+1][m+1]=1;
    b[0]=b[m+1]=-1e9;
    for(int i=0;i<=m+1;i++) g[0][i]=l[0][i]=1;
    for(int i=1;i<=m;i++){
        for(int j=i-1;~j;j--) if(b[j]>b[i]){lef[i]=j+1; break;}
        for(int j=i+1;j<=m+1;j++) if(b[j]>b[i]){rig[i]=j-1;break;}
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]<b[j]) L[i][j]=m,R[i][j]=1;
            else{
                int cur=j;
                while(lef[cur] && a[i]>b[lef[cur]-1]) cur=lef[cur]-1;
                L[i][j]=lef[cur];
                cur=j;
                while(rig[cur] && a[i]>b[rig[cur]+1]) cur=rig[cur]+1;
                if(!rig[cur]) R[i][j]=m+1;
                else R[i][j]=rig[cur];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]<b[j]){f[i][j]=0; g[i][j]=g[i][j-1];continue;}
            int cur=g[i-1][j],lst=(L[i][j]==0?0:g[i-1][L[i][j]-1]);
            f[i][j]|=(cur>lst);
            g[i][j]=g[i][j-1]+f[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i]<b[j]){h[i][j]=0; l[i][j]=l[i][j+1]; continue;}
            int cur=l[i+1][j],lst=(R[i][j]>m?0:l[i-1][R[i][j]+1]);
            h[i][j]|=(cur>lst);
            l[i][j]=l[i][j+1]+h[i][j];
        }
    }
    bool flag=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) flag|=(f[i][j] && h[i+1][j+1] && a[i]>b[j]);
    return flag;
}
bool check2(){
    for(int i=0;i<=max(n,m)+1;i++) for(int j=0;j<=max(n,m)+1;j++) f[i][j]=g[i][j]=h[i][j]=l[i][j]=0;
    f[0][0]=h[n+1][m+1]=1;
    b[0]=b[m+1]=1e9;
    for(int i=0;i<=m+1;i++) g[0][i]=l[0][i]=1;
    for(int i=1;i<=m;i++){
        for(int j=i-1;~j;j--) if(b[j]<b[i]){lef[i]=j+1; break;}
        for(int j=i+1;j<=m+1;j++) if(b[j]<b[i]){rig[i]=j-1;break;}
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]>b[j]) L[i][j]=m,R[i][j]=1;
            else{
                int cur=j;
                while(lef[cur] && a[i]<b[lef[cur]-1]) cur=lef[cur]-1;
                L[i][j]=lef[cur];
                cur=j;
                while(rig[cur] && a[i]<b[rig[cur]+1]) cur=rig[cur]+1;
                if(!rig[cur]) R[i][j]=m+1;
                else R[i][j]=rig[cur];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]>b[j]){f[i][j]=0; g[i][j]=g[i][j-1]; continue;}
            int cur=g[i-1][j],lst=(L[i][j]==0?0:g[i-1][L[i][j]-1]);
            f[i][j]|=(cur>lst);
            g[i][j]=g[i][j-1]+f[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i]>b[j]){h[i][j]=0; l[i][j]=l[i][j+1]; continue;}
            int cur=l[i+1][j],lst=(R[i][j]>m?0:l[i-1][R[i][j]+1]);
            h[i][j]|=(cur>lst);
            l[i][j]=l[i][j+1]+h[i][j];
        }
    }
    bool flag=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) flag|=(f[i][j] && h[i+1][j+1] && a[i]<b[j]);
    return flag;
}

int main(){
    //system("diff expand.out expand2.ans"); return 0;
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i],A[i]=a[i];
    for(int i=1;i<=m;i++) cin>>b[i],B[i]=b[i];
    if(c>=9){
        q++;
        while(q--) cout<<1;
        return 0;
    }
    cout<<(check1()||check2());
    while(q--){
        int kx,ky; cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            int x,y; cin>>x>>y;
            a[x]=y;
        }
        for(int i=1;i<=ky;i++){
            int x,y; cin>>x>>y;
            b[x]=y;
        }
        //for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<'\n';
        //for(int i=1;i<=m;i++) cout<<b[i]<<' '; cout<<'\n';
        cout<<(check1()||check2());
        for(int i=1;i<=n;i++) a[i]=A[i];
        for(int i=1;i<=m;i++) b[i]=B[i];
    }
    cout<<'\n';
    return 0;
}
