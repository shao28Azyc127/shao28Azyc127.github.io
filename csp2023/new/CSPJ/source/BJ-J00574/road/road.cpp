#include <iostream>

using namespace std;

int n,d,v[10005],c[10005],a[10005];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int priw;
    long long road = 0;
    cin>>n>>d;
    for(int i = 2;i<=n;i++){
        cin>>v[i];
        c[i] = c[i-1]+v[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    a[n] = -1;
    priw = 1;
    for(int i = 2;i<=n;i++){
        if(a[i]<a[priw]){
            long long oil = ((c[i]-road)/d);
            if(oil*d<c[i]-road)oil++;
            ans+=oil*a[priw];
            road+=oil*d;
            priw = i;
        }
    }
    cout<<ans;
    return 0;
}
