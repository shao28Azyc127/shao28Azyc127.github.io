#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,d,v[maxn],a[maxn],s[maxn];
int fd(int pos){
    for(int i=pos;i<=n;i++){
        if(a[i]<a[pos])return i;
    }
    return n+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)s[i]=s[i-1]+v[i];
    int pos=1,lst=0,ans=0;
    while(pos<n){
        int nps=fd(pos);
        int c=(s[nps-1]-s[pos-1]-lst+d-1)/d;
        ans+=c*a[pos];
        c*=d;
        c-=s[nps-1]-s[pos-1]-lst;
        lst=c;
        pos=nps;
    }
    cout<<ans;
    return 0;
}
