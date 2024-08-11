#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int maxn=5e5+10;
int c,n,m,q;
int a[maxn],b[maxn];
int tmp1[maxn],tmp2[maxn];
int premx[maxn],preminn[maxn];
set<pii> s;
bool chk()
{
    if(n==1)
    {
        if(a[1]==b[1]) return 0;
        return 1;
    }
    if(a[1]==b[1]) return 0;
    if(a[n]==b[m]) return 0;
    if(a[1]>b[1]&&a[n]<b[m]) return 0;
    if(a[1]<b[1]&&a[n]>b[m]) return 0;
    if(c>=8&&c<=14)
    {
        if(a[1]<b[1]&&a[n]>b[m]) return 0;
        return 1;
    }
    if(a[1]>b[1])
    {
        if(n<=4e4)
        {
            for(int i=1;i<=m;i++) premx[i]=max(premx[i-1],b[i]);
            preminn[0]=2e9;
            for(int i=1;i<=m;i++) preminn[i]=min(preminn[i-1],b[i]);
            int mx=a[1];
            for(int i=2;i<=n;i++)
            {
                if(a[i]>premx[m])
                {
                    mx=max(a[i],mx);
                    continue;
                }
                int l=1,r=m,pos=0;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(preminn[mid]>=a[i]) l=mid+1;
                    else pos=mid,r=mid-1;
                }
                if(mx<=premx[pos]) return 0;
                mx=max(mx,a[i]);
            }
            return 1;
        }
    }
    if(n<=4e4)
    {
        for(int i=1;i<=n;i++) premx[i]=max(premx[i-1],a[i]);
        preminn[0]=2e9;
        for(int i=1;i<=n;i++) preminn[i]=min(preminn[i-1],a[i]);
        int mx=b[1];
        for(int i=2;i<=m;i++)
        {
            if(b[i]>premx[n])
            {
                mx=max(b[i],mx);
                continue;
            }
            int l=1,r=n,pos=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(preminn[mid]>=b[i]) l=mid+1;
                else pos=mid,r=mid-1;
            }
            //cout<<i<<" "<<pos<<endl;
            if(mx<=premx[pos]) return 0;
            mx=max(mx,b[i]);
        }
        return 1;
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    cout<<chk();
    while(q--)
    {
        int k1,k2;
        cin>>k1>>k2;
        for(int i=1;i<=n;i++) tmp1[i]=a[i];
        for(int i=1;i<=m;i++) tmp2[i]=b[i];
        for(int i=1;i<=k1;i++)
        {
            int p,x;
            cin>>p>>x;
            a[p]=x;
        }
        for(int i=1;i<=k2;i++)
        {
            int p,x;
            cin>>p>>x;
            b[p]=x;
        }
        cout<<chk();
        for(int i=1;i<=n;i++) a[i]=tmp1[i];
        for(int i=1;i<=m;i++) b[i]=tmp2[i];
    }
    cout<<endl;
	return 0;
}
