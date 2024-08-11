#include<bits/stdc++.h>
using namespace std;
int n,d,t,l,s,a[100001],b,c[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;++i){
            cin>>b;
            c[i+1]=c[i]+b;
    }
    for(int i=1;i<=n;++i) cin>>a[i];
    t=1;
    for(int i=2;i<=n;++i){
        if(l>=c[i]){
            if(a[i]<a[t]) t=i;
        }
        else if(a[i]<a[t]||i==n){
            int m1=c[i]-l;
            int m2=m1/d;
            if(m1%d>0) ++m2;
            l+=d*m2;
            s+=a[t]*m2;
            t=i;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
