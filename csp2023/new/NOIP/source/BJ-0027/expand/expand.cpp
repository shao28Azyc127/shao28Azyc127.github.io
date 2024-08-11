#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=1000000+5;
int A[n_MAX],B[n_MAX],p[n_MAX],q[n_MAX],cur;
bool check(const int n,const int m,const int a[],const int b[])
{
    // process 1.1
    A[1]=a[1]; For(i,2,n) A[i]=min(A[i-1],a[i]);
    B[1]=b[1]; For(i,2,m) B[i]=min(B[i-1],b[i]);
    cur=1;
    For(i,1,n)
    {
        while((cur<=m)&&!(A[i]>B[cur])) ++cur;
        if(cur==(m+1)) return false;
        p[i]=cur;
    }

    // process 1.2
    A[1]=a[1]; For(i,2,n) A[i]=max(A[i-1],a[i]);
    B[1]=b[1]; For(i,2,m) B[i]=max(B[i-1],b[i]);
    cur=1;
    For(i,1,m)
    {
        while((cur<=n)&&!(A[cur]>B[i])) ++cur;
        if(cur==(n+1)) return false;
        q[i]=cur;
    }

    // process 1.3
    For(i,1,n) if(q[p[i]-1]>i) return false;

    // process 2.1
    A[n]=a[n]; For_down(i,n-1,1) A[i]=min(A[i+1],a[i]);
    B[m]=b[m]; For_down(i,m-1,1) B[i]=min(B[i+1],b[i]);
    cur=m;
    For_down(i,n,1)
    {
        while(cur&&!(A[i]>B[cur])) --cur;
        if(!cur) return false;
        p[i]=cur;
    }

    // process 2.2
    A[n]=a[n]; For_down(i,n-1,1) A[i]=max(A[i+1],a[i]);
    B[m]=b[m]; For_down(i,m-1,1) B[i]=max(B[i+1],b[i]);
    cur=n;
    For_down(i,m,1)
    {
        while(cur&&!(A[cur]>B[i])) --cur;
        if(!cur) return false;
        q[i]=cur;
    }

    // process 2.3
    For(i,1,n) if((p[i]<=(m-1))&&(q[p[i]+1]<i)) return false;

    // return true
    return true;
}
int sub,n,m,T,a[n_MAX],b[n_MAX],ma[n_MAX],mb[n_MAX];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>sub>>n>>m>>T;
    For(i,1,n) cin>>a[i],ma[i]=a[i];
    For(i,1,m) cin>>b[i],mb[i]=b[i];
    const int max_a=(*max_element(a+1,a+n+1));
    const int max_b=(*max_element(b+1,b+m+1));
    cout<<((max_a>=max_b)?check(n,m,a,b):check(m,n,b,a));
    while(T--)
    {
        int k1,k2; cin>>k1>>k2;
        For(i,1,n) a[i]=ma[i];
        For(i,1,m) b[i]=mb[i];
        while(k1--){int p,w; cin>>p>>w,a[p]=w;}
        while(k2--){int p,w; cin>>p>>w,b[p]=w;}
        const int max_a=(*max_element(a+1,a+n+1));
        const int max_b=(*max_element(b+1,b+m+1));
        cout<<((max_a>=max_b)?check(n,m,a,b):check(m,n,b,a));
    }
    cout<<'\n'; return 0;
}