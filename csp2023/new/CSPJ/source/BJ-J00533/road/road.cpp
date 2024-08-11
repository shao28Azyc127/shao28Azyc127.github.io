#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,ans;
double d;
int i=1;
double m;
int v[100005],a[100005];
int mabs(double x,double y){
    int k=(x/y*10000);
    if(k%10000>0) k=k/10000+1;
    else k/=10000;
    return k;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    while(i!=n){
        int j;
        double k=0;
        for(j=i+1;j<=n;j++){
            k+=v[j];
            if(a[j]<a[i]){
                break;
            }
        }
        int x=mabs((k-m*d),d);
        ans+=x*a[i];
        m+=x;
        m-=k/d;
        i=j;
    }
    cout<<ans;
    return 0;
}
