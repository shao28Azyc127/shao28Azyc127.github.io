#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
template<typename T>
inline void write(T x){
    if(x>=10) write(x/10);
    putchar(x%10+48);
}
const int N=1e5+10;
ll n,d,v[N],a[N],path[N],rest,k,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n);read(d);
    for(int i=1;i<n;++i) read(v[i]),v[i]+=v[i-1];
    for(int i=1;i<=n;++i) read(a[i]);
    int pos=1;
    path[++k]=1;
    while(pos!=n){
        bool f=0;
        for(int i=pos+1;i<=n;++i){
            if(a[i]<a[pos]){
                path[++k]=i;
                pos=i;
                f=1;
                break;
            }
        }
        if(!f) break;
    }
    if(pos!=n) path[++k]=n;
    for(int i=1;i<k;++i){
        int dis=v[path[i+1]-1]-v[path[i]-1];
        int need=(dis-rest)/d;
        if((dis-rest)%d!=0) need++;
        ans+=need*a[path[i]];
        rest+=need*d-dis;
    }
    write(ans);
    return 0;
}
