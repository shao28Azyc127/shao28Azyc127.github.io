#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,a[N],b[N],f[N];
stack<int> z;
long long s[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);

    for(int i=n;i>=1;i--){
        while(!z.empty()&&b[i]<=b[z.top()])z.pop();
        if(!z.empty())f[i]=z.top();
        else f[i]=n;
        z.push(i);
    }
    long long l=0,ans=0;
    int k=1;
    while(k>0&&k<n){
        long long len=s[f[k]-1]-s[k-1];
        if(l>=len)l-=len;
        else{
            len-=l;
            l=0;
            if(len%d==0){
                ans+=b[k]*(len/d);
            }else{
                ans+=b[k]*(len/d+1);
                l=(len/d+1)*d-len;
            }
        }
        k=f[k];
    }
    printf("%lld",ans);
    return 0;
}
