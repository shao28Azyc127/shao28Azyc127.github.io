#include<bits/stdc++.h>
using namespace std;
int n,d,y=0,a[100005],b[100005],c[100005],sum=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    int tmp;
    c[0]=114514;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        c[i]=min(b[i],c[i-1]);
    }
    for(int i=1;i<=n-1;i++){
        //while(a[i]>y){
        //    y+=d;
       //     sum+=c[i];
        //}
        int tmp;
        //tmp=(a[i]-y)/d;
        tmp=((d-(a[i]-y)%d)%d+(a[i]-y))/d;
        sum+=tmp*c[i];
        y+=tmp*d;
        y-=a[i];
        //cout<<sum<<" "<<y<<" ";
    }
    cout<<sum;
}
