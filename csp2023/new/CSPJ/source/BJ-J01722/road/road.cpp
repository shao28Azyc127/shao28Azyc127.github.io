#include <bits/stdc++.h>
using namespace std;
struct node{
    int cost,dis;
}node[100005];
int n,d,now,a[100005],v[100005],r,ans,f2;
double elsee=0;
int get_number(int x,int y){
    double z=(double)(x/y);
    elsee+=z-x/y;
    return x/y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=0;i<n-1;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    node[0].cost=a[0],node[0].dis=0;
    for(int i=1;i<n;i++){
        node[i].cost=a[i];
        node[i].dis=get_number(v[i-1],d);
    }now=node[0].cost;
    for(int i=1;i<n;i++){
        now=min(now,node[i].cost);
        ans+=node[i].dis*now;
    }printf("%d\n",ans+int(elsee*now)+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}