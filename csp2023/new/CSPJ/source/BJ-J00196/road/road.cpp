#include <iostream>

using namespace std;
struct node{
    int dis,mon,ys;
}c[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,sum=0,k=100010,ans=0;
    cin>>n>>m;
    for(int i=1;i<=(n-1);i++){
        cin>>c[i].dis;
    }
    for(int i=1;i<=n;i++)cin>>c[i].mon;
    for(int i=1;i<=n-1;i++){
        sum+=c[i].dis;
        if(sum%m==0)c[i].ys=sum/m;
        else c[i].ys=sum/m+1;}
    c[0].ys=0;
    for(int i=1;i<=n-1;i++){
        if(c[i].mon<k){
            k=c[i].mon;}
            ans+=k*(c[i].ys-c[i-1].ys);

    }
    cout<<ans;
    return 0;
}