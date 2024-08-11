#include<bits/stdc++.h>
using namespace std;
const int N=3005,M=26;
int n,m,res[N],ans[N];
struct nd
{
    int cnt[M],id;
    bool operator <(const nd &b)
    {
        for(int i=0;i<M;i++)
            if(cnt[i]!=b.cnt[i]) return cnt[i]>b.cnt[i];
        return false;
    }
}a[N],b[N];
//ax<=by
bool check(nd x,nd y)
{
    int l=0,r=0;
    while(l<M&&r<M)
    {
        if(x.cnt[l]==0){l++;continue;}
        if(y.cnt[r]==0){r++;continue;}
        if(l<M-r-1) return true;
        if(l>M-r-1) return false;
        int mi=min(x.cnt[l],y.cnt[r]);
        x.cnt[l]-=mi,y.cnt[r]-=mi;
    }
    return true;
}
int lb(int x)
{
    int l=1,r=n;
    while(l<r)
    {
        //printf("%d %d\n",l,r);
        int mid=(l+r+1)/2;
        if(check(a[x],b[mid])) l=mid;
        else r=mid-1;
    }
    return l;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        b[i].id=i;
        for(int j=1;j<=m;j++)
        {
            char c;
            scanf(" %c",&c);
            a[i].cnt[c-'a']++;
            b[i].cnt[M-(c-'a')-1]++;
        }
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    //for(int i=1;i<=n;i++) printf("%d ",b[i].id);
    for(int i=1;i<=n;i++)
    {
        int x=lb(i);
        //printf("%d:%d\n",i,x);
        if(x==n) ans[a[i].id]=1;
    }
    for(int i=1;i<=n;i++) printf("%d",ans[i]);
    printf("\n");
    return 0;
}
