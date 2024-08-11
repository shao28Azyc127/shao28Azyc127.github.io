#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long us;
int n,d;
int u[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&u[i]);
        us+=u[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(us%d==0)us/=d;
    else us=us/d+1;
    cout<<us*a[1];
    return 0;
}
