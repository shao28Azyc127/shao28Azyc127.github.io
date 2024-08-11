#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long v[N];
long long a[N];
long long c(long long a,long long b){
    if(a%b==0)return a/b;
    else return (a/b)+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for(long long i=1;i<n;i++)
        cin>>v[i];
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    long long ans=0;
    long long k=a[1];
    long long p=0;
    for(long long i=1;i<n;i++){
        if(a[i]<k)k=a[i];
        ans+=c(v[i]-p,d)*k;
        p+=c(v[i]-p,d)*d-v[i];
    }
    cout<<ans;
    return 0;
}
