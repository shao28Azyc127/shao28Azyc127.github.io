#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],b[100001],cnt=0,s=1,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        b[i]=b[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(s<n){
        int i=s+1;
        while(a[s]<a[i]&&i<n){
            i++;
        }
        long long x=0,y=b[s]+cnt;
        while(y<b[i]){
            y+=m;
            x++;
        }
        cnt+=x*m-(b[i]-b[s]);
        ans+=x*a[s];
        s=i;
    }
    cout<<ans;
    return 0;
}
