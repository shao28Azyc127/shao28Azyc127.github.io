#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,d;
long long v[N],a[N]={LLONG_MAX},f[N]/*f[Õ¾µã]=×îÉÙÇ®*/;
long long minn = INT_MAX;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 2;i <= n;i++){
        scanf("%d",&v[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        a[i]=min(a[i-1],a[i]);
    }
    for(int i = 1; i <= n;i++){
        f[i]=f[i-1]+int((v[i]+d-0.5)/d)*a[i-1];
        v[i+1]-=v[i]%d;
        //cout << v[i] << ' ' << a[i] << ' ' << f[i] << endl;
    }
    cout << f[n];
    return 0;
}
