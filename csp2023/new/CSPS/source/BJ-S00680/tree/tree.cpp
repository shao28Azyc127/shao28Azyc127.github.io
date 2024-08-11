#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],c[100010];
int u[100010],v[100010],s[100010][100010];
struct node{
    int bs;
    int a,b,c;
    int num;
}d[100010];
bool cmp(node x,node y){
    return x.bs>y.bs;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        d[i].num=i;
        cin>>d[i].a>>d[i].b>>d[i].c;
        d[i].bs=max(d[i].b,1);
        d[i].bs=d[i].a/d[i].bs;
    }
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
    }
    sort(d+1,d+1+n);
    cout<<d[1].bs<<endl;
    return 0;
}
