#include<bits/stdc++.h>
#define ll __int128
using namespace std;
inline ll read(){
    ll x=0,f=1; char c=getchar();
    while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x*f;
}
void write(ll x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+10;
int n;
ll a[N],b[N],c[N],zr[N],lim[N],dp[N];
vector<int> v[N];
void dfs(int x,int fa){
    dp[x]=lim[x];
    for(int u:v[x]){
        if(u==fa) continue;
        dfs(u,x);
        dp[x]=min(dp[x],dp[u]-1);
    }
}
bool check(ll mid){
    for(int i=1;i<=n;i++){
        ll tmp=a[i],md=mid;
        if(c[i]==0){
            if(mid*b[i]<a[i]) return 0;
            lim[i]=mid-(a[i]+b[i]-1)/b[i]+1;
            continue;
        }
        if(c[i]<0&&mid>=zr[i]){
            if(mid-a[i]+1>=zr[i]){
                lim[i]=mid-a[i]+1;
                continue;
            }
            a[i]-=mid-zr[i]+1,mid=zr[i];
        }
        ll vn=b[i]+c[i]*mid;
        ll A=c[i],B=b[i]+vn-c[i]*mid-c[i],C=2*a[i]-(b[i]+vn)*(mid+1);
        ll dt=B*B-4*A*C;
        a[i]=tmp,mid=md;
        if(dt<0&&A>0) return 0;
        lim[i]=(sqrt(dt)-B)/(2*A);
    }
    dfs(1,0);
    return dp[1]>=1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
        if(c[i]<0) zr[i]=(b[i]-c[i]-1)/(-c[i]);
    }
    for(int i=1;i<n;i++){
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y),v[y].push_back(x);
    }
    ll l=1,r=1e9,res=-1;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    write(res);
    return 0;
}

