#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double n,m;
int s[N],a[N];
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //freopen("road.in","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    int i=1,minn=a[1];
    double tot=0;
    int k=i;
    for(int i=1;i<n;i++)s[i]+=s[i-1];
    while(i<n){
        i++;
        if(a[i]<minn||i==n){
            double x=s[i-1]-s[k-1]-tot*m;
            double t=x/m;
            if(t!=int(t))t=int(t)+1;
            x=(s[i-1]-s[k-1])/m;
            tot+=t-x;
            ans+=t*a[k];
            k=i;
        }
    }
    cout<<ans;
    return 0;
}
