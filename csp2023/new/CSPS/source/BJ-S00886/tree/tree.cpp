#include<iostream>
#include<fstream>
#include<cstdio>
#include<queue>
using namespace std;
int n;
long long a[114514],b[114514],c[114514];
int link[114514][2];
bool plant[114514],avai[114514];
long long mb,mc;
int main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        link[2*i][0]=link[2*i+1][1]=u;
        link[2*i][1]=link[2*i+1][0]=v;
    }
    plant[1]=1;
    for(int i=1;i<=n;i++) {
        ;
    }
    cout<<a[0]/(b[0]+c[0]);
    return 0;
}
