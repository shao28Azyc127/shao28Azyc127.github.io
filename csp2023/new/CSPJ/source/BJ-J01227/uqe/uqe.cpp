#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,minn=1e18;
struct node{
    int a,v=0,l=0;
    double k=0;
    int f=0;
}p[100010];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<=n-1;i++)cin>>p[i].v;
    for (int i=1;i<=n-1;i++) cin>>p[i].a;
    int last; cin>>last;
    for (int i=n-1;i>=1;i--){
        p[i].l=p[i].v+p[i+1].l;
        p[i].k=1.0*p[i].l/d;
        if (p[i].l%d==0)p[i].f=p[i].k;
        else p[i].f=p[i].k+1;
    }
    if (n==1) {
        cout<<0<<endl;
    }
    if (n==2){
        cout<<p[1].f*p[1].a;
    }
    cout<<p[1].f*p[1].a;
    return 0;
}
