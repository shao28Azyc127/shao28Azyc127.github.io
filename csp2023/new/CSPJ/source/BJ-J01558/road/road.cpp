#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
    x=0;char c=getchar();int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename T,typename ...Args>
void read(T &x,Args &...rest){read(x);read(rest...);}

const int N=1e5+5;
typedef long long ll;
int n,d,a[N];
ll v[N],cost;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n,d);
    for(int i=2;i<=n;i++)read(v[i]),v[i]+=v[i-1];
    for(int i=1;i<=n;i++)read(a[i]);
    a[0]=2e9;
    ll pos=0;
    for(int i=1,j=1;i<n;i=j){
        while(j<n&&a[i]<=a[j])++j;
        cost+=1ll*(v[j]-pos+d-1)/d*a[i];
        pos+=1ll*(v[j]-pos+d-1)/d*d;
//        printf("%lld %d %d %lld\n",pos,i,j,cost);
    }
    printf("%lld",cost);
    return 0;
}
