#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N],b[N];
ll s[N];
ll x,x1,sum,ans;
int cnt=1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    sum=b[1];
    for(int i=2;i<=n;i++){
        if(sum>b[i]){
            s[i-1]-=x1;
            ans+=ceil(s[i-1]*1.0/d)*sum;
            x1+=ceil(s[i-1]*1.0/d)*d;
            sum=b[i];
        }
    }
    cout<<ans;
    return 0;
}
