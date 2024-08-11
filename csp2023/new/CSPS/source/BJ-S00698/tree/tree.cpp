#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8005,inf=1e9;

//int0-1, short4-7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int n;
int hh[N],nx[N<<1],to[N<<1],idx;
void add(int u,int v){
    idx++;
    to[idx]=v;
    nx[idx]=hh[u];
    hh[u]=idx;
}
int a[N],b[N],c[N];
int fl_B=1;
int grow(int p,int x){
    return b[p]*n+c[p]*(1+x)*x/2;
}
int getday(int p,int day){
    int L=1,R=inf,mid;
    while(L<R){
        mid=L+R>>1;
        if(grow(p,mid)-grow(p,day-1)>=a[p]){
            R=mid;
        }
        else{
            L=mid+1;
        }
    }
    return L;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);


    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",a+i,b+i,c+i);
    }
    for(int i=1,u,v;i<n;i++){
        scanf("%lld%lld",&u,&v);
        if(u!=i||v!=i+1) fl_B=0;
        add(u,v);
        add(v,u);
    }
    if(fl_B){
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,getday(i,i)+i);
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
