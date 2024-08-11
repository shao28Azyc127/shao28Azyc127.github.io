#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int n,d,a[N],v[N],ans,l[N],f=1,qz[N];
struct nd{
    int len;
    int z;
}c[N];
int chk(int i,int j){
     return qz[j]-qz[i];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        qz[i]=qz[i-1]+v[i];
    }
    int mi=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(a[i],mi);
    }
    if(mi==a[1]){
        cout<<(qz[n-1]/d)*a[1];
        return 0;
    }
    mi=0;
    for(int i=1;i<n;){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                c[f].z=a[i];
                c[f++].len=chk(i-1,j-1);
                mi=j-i;
                break;
            }
        }
        i+=mi;
    }
    f--;
    l[1]=c[1].len%d;
    if(l[1])
    ans+=(c[1].len/d+1)*c[1].z;
    else
    ans+=(c[1].len/d)*c[1].z;
    for(int i=2;i<=f;i++){
        l[i]=(l[i-1]+c[i].len)%d;
        if((c[i].len-l[i-1])%d){
            ans+=((l[i-1]+c[i].len)/d)*c[i].z;
        }
        else{
            ans+=((c[i].len-l[i-1])/d)*c[i].z;
        }
    }
    cout<<ans;
    return 0;
}
