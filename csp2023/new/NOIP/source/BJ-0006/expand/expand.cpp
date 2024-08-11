/*
    author: honglan0301

    2023-11-18 10:32:35
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

int c,n,m,q,ka,kb,u,v,a[500005],b[500005],la[500005],lb[500005],ans;
int qma[500005],qna[500005],qmb[500005],qnb[500005],hma[500005],hna[500005],hmb[500005],hnb[500005];

int getma(int x,int y) {return a[x]>a[y]?x:y;}
int getmb(int x,int y) {return b[x]>b[y]?x:y;}
int getna(int x,int y) {return a[x]<a[y]?x:y;}
int getnb(int x,int y) {return b[x]<b[y]?x:y;}

void init()
{
    qma[1]=1; for(int i=2;i<=n;i++) qma[i]=getma(qma[i-1],i);
    qna[1]=1; for(int i=2;i<=n;i++) qna[i]=getna(qna[i-1],i);
    qmb[1]=1; for(int i=2;i<=m;i++) qmb[i]=getmb(qmb[i-1],i);
    qnb[1]=1; for(int i=2;i<=m;i++) qnb[i]=getnb(qnb[i-1],i);
    hma[n]=n; for(int i=n-1;i>=1;i--) hma[i]=getma(hma[i+1],i);
    hna[n]=n; for(int i=n-1;i>=1;i--) hna[i]=getna(hna[i+1],i);
    hmb[m]=m; for(int i=m-1;i>=1;i--) hmb[i]=getmb(hmb[i+1],i);
    hnb[m]=m; for(int i=m-1;i>=1;i--) hnb[i]=getnb(hnb[i+1],i);
}

int solve3(int ra,int rb)
{
    if(ra<=1||rb<=1) return 1;
    int ma=qma[ra],na=qna[ra],mb=qmb[rb],nb=qnb[rb];
    if(a[ma]>b[mb]) return solve3(ma-1,rb); else if(a[na]>b[nb]) return solve3(ra,nb-1); else return 0;
}
int solve4(int la,int lb)
{
    if(la>=n||lb>=m) return 1;
    int ma=hma[la],na=hna[la],mb=hmb[lb],nb=hnb[lb];
    if(a[ma]>b[mb]) return solve4(ma+1,lb); else if(a[na]>b[nb]) return solve4(la,nb+1); else return 0;
}
int solve1()
{
    int ma=qma[n],na=qna[n],mb=qmb[m],nb=qnb[m];
    if(a[ma]>b[mb]&&a[na]>b[nb]) return solve3(ma-1,nb-1)&solve4(ma+1,nb+1);
    else return 0;
}

int solve5(int ra,int rb)
{
    if(ra<=1||rb<=1) return 1;
    int ma=qma[ra],na=qna[ra],mb=qmb[rb],nb=qnb[rb];
    if(a[ma]<b[mb]) return solve5(ra,mb-1); else if(a[na]<b[nb]) return solve5(na-1,rb); else return 0;
}
int solve6(int la,int lb)
{
    if(la>=n||lb>=m) return 1;
    int ma=hma[la],na=hna[la],mb=hmb[lb],nb=hnb[lb];
    if(a[ma]<b[mb]) return solve6(la,mb+1); else if(a[na]<b[nb]) return solve6(na+1,lb); else return 0;
}
int solve2()
{
    int ma=qma[n],na=qna[n],mb=qmb[m],nb=qnb[m];
    if(a[ma]<b[mb]&&a[na]<b[nb]) return solve5(na-1,mb-1)&solve6(na+1,mb+1);
    else return 0;
}
void solve()
{
    init(); ans=0; //cout<<solve1()<<" "<<solve2()<<endl;
    if(a[1]>b[1]&&a[n]>b[m]) ans|=solve1();
    if(a[1]<b[1]&&a[n]<b[m]) ans|=solve2();
    cout<<ans;
}

signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>c>>n>>m>>q; for(int i=1;i<=n;i++) cin>>a[i]; for(int i=1;i<=m;i++) cin>>b[i];
    memcpy(la,a,sizeof(la)); memcpy(lb,b,sizeof(lb)); solve();
    for(int tt=1;tt<=q;tt++)
    {
        cin>>ka>>kb;
        for(int i=1;i<=ka;i++) cin>>u>>v,a[u]=v;
        for(int i=1;i<=kb;i++) cin>>u>>v,b[u]=v;
        solve();
        /*if(tt==17)
        {
            cout<<endl;
            for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
            for(int i=1;i<=m;i++) cout<<b[i]<<" "; cout<<endl;
            cout<<solve1()<<endl;
        }*/
        memcpy(a,la,sizeof(a)); memcpy(b,lb,sizeof(b));
    }
    cout<<endl;
}
