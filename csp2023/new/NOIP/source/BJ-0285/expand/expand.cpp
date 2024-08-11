#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
    x=x*f;
}
const int N=5e5+5;
const int inf=1e9+5;

int c,n,m,q;
int a[N],b[N];
int a3[N],b3[N],a2[N],b2[N];
int op,k1,k2,x,y;

set<int>sb;
set<int>sa;

signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(c),read(n),read(m),read(q);
    for(int i=1;i<=n;i++)
        read(a[i]),sa.insert(-a[i]);
    for(int i=1;i<=m;i++)
        read(b[i]),sb.insert(b[i]);
    set<int>::iterator it;
    bool f1=0,f2=0;
    it=sb.lower_bound(-1);
    f1=(a[1]<(*it));
    //cout<<(*it)<<" ";
    it=sa.lower_bound(-inf);
    f2=(b[m]>-(*it));
    //cout<<-(*it)<<endl;
    if(f1&&f2) printf("1");
    else printf("0");
    while(q--){
        read(k1),read(k2);
        int v1=a[1],v2=b[m];
        for(int i=1;i<=k1;i++){
            read(x),read(y);
            a2[i]=a[x],a3[i]=y;
            sa.erase(-a[x]);
            sa.insert(-y);
            if(x==1) v1=y;
        }
        for(int i=1;i<=k2;i++){
            read(x),read(y);
            b2[i]=b[x],b3[i]=y;
            sb.erase(b[x]);
            sb.insert(y);
            if(x==m) v2=y;
        }
        it=sb.lower_bound(-1);
        f1=(v1<(*it));
        it=sa.lower_bound(-inf);
        f2=(v2>-(*it));
        if(f1&&f2) printf("1");
        else printf("0");
        for(int i=1;i<=k1;i++){
            sa.erase(-a3[i]);
            sa.insert(-a2[i]);
        }
        for(int i=1;i<=k2;i++){
            sb.erase(b3[i]);
            sa.insert(b2[i]);
        }
    }
    return 0;
}
