#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=1e5+5;
int v[N],a[N],s[N],rt[N],st[N];
int newceil(int n,int m){
    if(n%m==0) return n/m;
    return n/m+1;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),d=read();
    for(int i=2;i<=n;i++){
        v[i]=read();
        s[i]=s[i-1]+v[i];
    }
    s[n+1]=s[n];
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int topn=0;
    st[++topn]=n+1;
    a[n+1]=0;
    for(int i=n;i>=1;i--){
        while(a[i]<=a[st[topn]]) topn--;
        rt[i]=st[topn];
        st[++topn]=i;
    }
    int sum=0,lst=0;
    for(int now=1;now<n;now=rt[now]){
        int L=newceil(s[rt[now]]-s[now]-lst,d);
        lst=d*L-(s[rt[now]]-s[now]-lst);
        sum+=L*a[now];
    }
    cout<<sum;
    return 0;
}
