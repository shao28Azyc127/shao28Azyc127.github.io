#include <bits/stdc++.h>
#define ll long long
#define mid (l+r>>1)
using namespace std;
const int N=1e5+5;
int n,m,k,s,t;
ll a[N],b[N],c[N],ans;
vector<int> e[N];
ll ok(ll p,ll x,ll i){
    ll xx=a[i];
    if (c[i]>=0) {
        if ((xx-=(p-x+1)*b[i])<=0) return 1;
        else if (c[i]==0) return 0;
        else return (x+p)*(p-x+1)/2>=xx/c[i];
    }
    else {
        ll o=(1-b[i])/c[i]+1;
        if (o<=p && o>=x) {
            xx-=p-o+1;
            p=o-1;
        }
        if (xx<=0) return 1;
        if (p>=x){
        if ((xx-=(p-x+1)*b[i])<=0) return 1;
        else return (x+p)*(p-x+1)/2>=xx/c[i];
        }
        else return 0;
    }
}
ll calc(int x,int i){
    ll l,r;
    l=x;r=1e9;
    while (l<=r){
        if (ok(mid,x,i)) r=mid-1;
        else l=mid+1;
    }
    return l;
}
struct node{
    int d[22],f[22];
    void init(){
        for (int i=1;i<=n;++i) d[i]=i;
        do{
            memset(f,0,sizeof(f));
            f[1]=1;int bo=1;ll tmp=0;
            for (int i=1;i<=n;++i){
                int x=d[i];
                if (!f[x]) {bo=0;break;}
                for (int &v:e[x]) f[v]=1;
                tmp=max(tmp,calc(i,x));
            }
            if (bo) ans=min(ans,tmp);
        }while (next_permutation(d+2,d+1+n));
        cout<<ans;
    }
}A;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i];
    for (int i=1;i<n;++i){
        cin>>s>>t;
        e[s].push_back(t);
        e[t].push_back(s);
    }
    ans=0x3f3f3f3f3f3f3f3f;
    if (n<=20) A.init();
}
