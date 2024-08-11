#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='0') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=1e5+5,MOD=1e9;
int a[N],b[N],c[N];
vector<int> g[N];
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(time(NULL));
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<(rand()*32768ll+rand()*1ll)%MOD;
    //CSP-S AK ME!!
    return 0;
}
