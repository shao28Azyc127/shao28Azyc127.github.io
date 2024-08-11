#include<iostream>
#include<cstdio>
using namespace std;
int a[100005],b[100005],c[100005],w[100005],v[100005],g[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,p=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int tu=0;
    while(tu++){
        for(int j=1;j<=min(tu,n);j++) g[j]+=max(b[j]+tu*c[j],1);
        for(int j=1;j<=min(tu,n);j++) if(g[j]>=a[j]) p++;
        if(p==n){
            cout<<tu;
            return 0;
        }
    }
    return 0;
}
