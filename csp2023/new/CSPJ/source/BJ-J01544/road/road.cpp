#include <bits/stdc++.h>
using namespace std;
long long v[100010],a[100010],st[100010];
long long c=0,ans=0;double now=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;cin>>n>>d;int mn=0x3f;
    for(int i=1;i<=n-1;i++)cin>>v[i];
    for(int i=0;i<n;i++){
            cin>>a[i];
            if((i==0||a[i]<a[0])||i==n-1){st[c]=i;c++;}
            if(mn<a[i]&&i!=n-1)mn=a[i];
    }for(int i=1;i<c;i++){
        long long len=0;
        for(int j=st[i-1];j<st[i];j++)len+=v[j+1];
        if(a[st[i]]>mn||i==c-1)len-=(now*d);
        long long x=len;
        len/=d;if(len*d!=x)len++;
        now+=((len*(double)d)-x)/(double)d;
        len*=a[st[i-1]];ans+=len;
    }cout<<ans<<endl;
}
