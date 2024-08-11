#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int tid,n,m,q;
int a[N],b[N];
bool work1(){
    return (a[1]!=b[1]);
}
bool work2(){
    if(n==1)return ((a[1]>b[1] && a[1]>b[2]) || (a[1]<b[1] && a[1]<b[2]));
    if(m==1)return ((a[1]>b[1] && a[2]>b[1]) || (a[1]<b[1] && a[2]<b[1]));
    return ((a[1]>b[1] && a[2]>b[2]) || (a[1]<b[1] && a[2]<b[2]));
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>tid>>n>>m>>q;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    if(tid==1)printf("%d",work1());
    else if(tid==2)printf("%d",work2());
    while(q--){
        int k1,k2,p,x;
        scanf("%d%d",&k1,&k2);
        while(k1--){
            scanf("%d%d",&p,&x);
            a[p]=x;
        }
        while(k2--){
            scanf("%d%d",&p,&x);
            b[p]=x;
        }
        if(tid==1)printf("%d",work1());
        else if(tid==2)printf("%d",work2());
    }
    return 0;
}
