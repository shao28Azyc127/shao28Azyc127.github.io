#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,v[100005],a[100005],s[100005],minn=1000000,x,c=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    s[1]=0;
    for(int i=2;i<=n-1;i++){
        s[i]=s[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]<minn){
            minn=a[i];
            x=i;
        }
    }
    c=c+(s[x]/d)*a[1];
    c=c+((s[n-1]-s[x])/d)*a[x];
    cout<<c;
    return 0;
}
