#include<bits/stdc++.h>
using namespace std;
long long n,d;
double v[100005];
long long a[100005];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++){
        cin>>v[i];
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    double y=0;
    long long mina=999999;
    for (int i=1;i<n;i++){
        mina=min(a[i],mina);
        v[i]-=y*d;
        y=0;
        double tmp=(double)v[i]/(double)d;
        long long j=tmp;
        if (tmp-j!=0){
            j=tmp+1;
        }
        ans+=j*mina;
        y+=j;
        y-=tmp;

    }
    cout<<ans;
    return 0;
}
