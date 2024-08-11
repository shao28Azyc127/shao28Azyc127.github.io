#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

long long s[100005];
int price[100005];
int vis[100005];
long long km,ans;

int dis(int l,int r){
    return s[r-1] - s[l-1];
}


int main (){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,-1,sizeof(vis));
    for (int i = 1;i <= n-1;i++){
        scanf("%lld",&s[i]);
        s[i] += s[i-1];
    }
    for (int i = 1;i <= n;i++){
        scanf("%d",&price[i]);
    }
    for (int i = 1;i < n;i++){
        for (int j = i+1;j <= n;j++){
            if (price[j] < price[i]){
                vis[i] = j;
                break;
            }
        }
    }
    //for(int i = 1;i <= n;i++){
    //    cout <<vis[i] <<" ";
    //}
    for (int i = 1;i < n;i=vis[i]){
        //cout << i <<endl;
        if (vis[i] == -1) vis[i] = n;
        ans += (ceil(max(0ll,dis(i,vis[i]) - km) * 1.0 / m)) * price[i];
        km += (ceil(max(0ll,dis(i,vis[i]) - km) * 1.0 / m)) * m;
        km -= dis(i,vis[i]);
        //cout <<vis[i]<<" "<<ans << " " << km << endl;
    }
    printf("%lld",ans);
    return 0;
}
