#include <iostream>
using namespace std;
const int N=100005;
const int inf=2e9;
int n,d;
int v[N],a[N],c[N],m[N];
struct node {
    int pre,nex,dist;
} lis[N];
void init(int pre,int ind) {
    lis[ind].pre=pre;
    lis[pre].nex=ind;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int minsta,minpri=inf,distSum=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++) {
        scanf("%d",v+i);
        distSum+=v[i];
        c[i]=(distSum%d==0?distSum/d:distSum/d+1);
    }
    int pre=0,dist=0;
    for(int i=1;i<n;i++) {
        scanf("%d",a+i);
        if(a[i]<minpri) {
            minpri=a[i];
            minsta=i;
            init(pre,i);lis[lis[i].pre].dist=dist;
            dist=0;
            pre=i;
        }
        dist+=v[i];
        m[i]=minpri;
    }
    scanf("%d",a+n);
    int _;
    for(_=1;a[_]!=minpri;_=lis[_].nex) {

    }
    lis[_].nex=n;lis[n].pre=_;lis[_].dist=dist;

    int cost=0,mile=0;
    for(int i=1;i!=0;i=lis[i].nex) {
        //cout<<i<<" "<<lis[i].pre<<" "<<lis[i].nex<<" "<<lis[i].dist<<endl;
        int dis=lis[i].dist-mile;
        cost+=(dis%d==0?dis/d:dis/d+1)*a[i];
        mile=dis%d;
    }
    cout<<cost<<endl;
    return 0;
}
