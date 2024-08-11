#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 100005
#define MAXM 1000000005
ll n,d,s,z;
ll v[MAXN];
ll a[MAXN];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>n>>d;
    for(int i=2;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    ll sum=0,lst=a[1];
    z=1;
    for(ll i=2;i<=n;i++){
        sum+=v[i];
        if(lst>a[i]){
            if(sum<=0){
                lst=a[i];
                continue;
            }
            ll k=sum/d;
            if(sum%d!=0)k++;
            s+=k*lst;
            z=i;
            sum-=k*d;
            lst=a[i];
        }
    }
    if(sum>0){
        ll k=sum/d;
        if(sum%d!=0)k++;
        s+=k*lst;
        sum-=k*d;
    }
    cout<<s<<endl;
    return 0;
}