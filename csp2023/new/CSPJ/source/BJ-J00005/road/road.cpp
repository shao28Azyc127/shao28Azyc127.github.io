#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<stack>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=100005;
int n,d;
int v[N],a[N];
int l[N];
int ans;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
        l[i]=l[i-1]+v[i];
    }
    l[n]=l[n-1];
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    int tmplen=0;
    for(int i=1;i<n;i++){
       // cout<<"i:"<<i<<endl;
        int tp=i,minn=a[i];
        while(minn<=a[i+1]&&i!=n)i++;
        ans+=ceil((l[i]-l[tp-1]-tmplen)*1.0/d)*a[tp];
      //  cout<<"len:"<<ceil((l[i]-l[tp-1]-tmplen)*1.0/d)*d<<' '<<ans<<endl;
        tmplen=ceil((l[i]-l[tp-1]-tmplen)*1.0/d)*d-(l[i]-l[tp-1]-tmplen);
       // cout<<"tmplen:"<<tmplen<<endl;
        i++;
        while(tmplen>=v[i])tmplen-=v[i],i++;
        i--;
    }
    printf("%lld\n",ans);
    return 0;
}
