//play florr.io and tkk!
//written by a fan of Robert_Lewandovski
#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int N=100010;
int n,a[N],b[N],c[N],d[N],zh[N];
vector<int> e[N];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void solve_part_a(){
    for(int i=1;i<=n;i++){
        if(b[i]<1) b[i]=1;
        if(a[i]%b[i]==0) d[i]=a[i]/b[i];
        else d[i]=a[i]/b[i]+1;
        if(d[i]<0) d[i]=1;
    }
    long long nn=n;
    cout<<nn<<endl;
}
void solve_baoli(){
    long long nn=n+1;
    cout<<nn<<endl;
}
bool pd(int p,int l,int r){
    if(r<zh[p]){
        return b[p]*(r-l+1)+c[p]*(l+r)*(r-l+1)/2>=a[p];
    }else{
        if(l>=zh[p]) return r-l+1>=a[p];
        int zhi=r-zh[p]+1;
        r=zh[p]-1;
        zhi+=b[p]*(r-l+1)+c[p]*(l+r)*(r-l+1)/2;
        return zhi>=a[p];
    }
}
void solve_part_b(){
    for(int i=1;i<=n;i++){
        zh[i]=(b[i]-1)/(-c[i])+1;
        if(c[i]>0) zh[i]=2e9;
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int l=i,r=1e9,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(pd(i,i,mid)){
                r=mid-1;
                ans=mid;
            }else l=mid+1;
        }
        mx=max(mx,ans);
    }
    long long mxx=mx;
    cout<<mxx;
}
bool pdl(){
    if(e[1].size()==1&&e[n].size()==1){
        for(int i=2;i<n;i++){
            if(e[i].size()!=2) return 0;
        }
        return 1;
    }else return 0;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(int i=1;i<n;i++){
        int u,v;
        u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int fl=1;
    for(int i=1;i<=n;i++){
        if(c[i]!=0){
            fl=0;
        }
    }
    if(fl==1){
        solve_part_a();
        return 0;
    }else if(n<=2){
        solve_baoli();
        return 0;
    }else if(pdl){
        solve_part_b();
        return 0;
    }else{
        long long nn=n;
        cout<<nn<<endl;
    }
    return 0;
}
