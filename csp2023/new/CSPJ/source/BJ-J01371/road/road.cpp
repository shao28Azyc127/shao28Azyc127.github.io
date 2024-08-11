#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll n,m,cost;
double oil;
ll a[maxn],v[maxn];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%lld%lld",&n,&m);

    a[1]=0;
    for(int i=2;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        //cout<<a[i]<<endl;
    }

    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
    }
    v[n]=0;

    int l=1,r=2;
    while(r<=n){
        while(v[r]>=v[l]) r++;

        double tm=oil;
        //cout<<(a[r]-a[l]+m-1ll-(ll)(oil*m))/m<<endl;
        oil+=(a[r]-a[l]+m-1ll-(ll)(oil*m))/m;
        cost+=(a[r]-a[l]+m-1ll-(ll)(tm*m))/m*v[l];
        int tmp=r+1;
        int mn=v[r];
        //cout<<oil*m<<endl;
        for(tmp;tmp<=n&&a[tmp]-a[l]<=oil*m;tmp++){
               // cout<<tmp<<" "<<l<<" "<<a[tmp]-a[l]<<endl;
            if(v[tmp]<mn){
                r=tmp;
                mn=v[tmp];
            }
        }
       // cout<<l<<" "<<r<<" "<<oil<<" "<<cost<<endl;
        oil-=(a[r]-a[l]*1.0)/(m*1.0);
        l=r;
        r++;
    }
    printf("%lld",cost);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
