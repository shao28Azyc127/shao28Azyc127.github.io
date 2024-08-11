#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,d,now,need;
long long p[N];
long long a[N];
long long nxt[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++) cin>>p[i],p[i]+=p[i-1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j=1;i<n;){
        while(a[i]<=a[j]) j++;
        while(i<j) nxt[i++]=min((long long)j,n);
    }
    for(int i=1;i<=n;i++) cout<<p[i]<<" "; cout<<endl;
    for(int j=1;j<=n;j++) cout<<nxt[j]<<" "; cout<<endl;
    for(int i=1;i<n;i++){
        now-=p[i]-p[i-1];
        if(now>=(p[nxt[i]]-p[i])) continue;
        long long  dis=p[nxt[i]]-p[i];
        long long use=ceil((dis-now)*1.0/d);
        now+=(long long)(use*d);
        need+=(long long)(use*a[i]);
    }
    cout<<need<<endl;
    return 0;
}
