#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int u[131072] = {0};
    int a[131072] = {0};
    int w[131072] = {0},top = 0;
    scanf("%d %d",&n,&d);
    int ans = 0;
    int st[131072] = {INT_MAX};
    long long ar[131072] = {0};
    for(int i = 1;i < n;i++){
        scanf("%d",&u[i]);
        ar[i] = ar[i-1] + u[i];
    }
    for(int i = 1;i < n;i++){
        scanf("%d",&a[i]);
        if(st[i-1] > a[i]){
            st[i] = a[i];
            w[top++] = i;
        }else{
            st[i] = st[i-1];
        }
    }

    int o = 0,z = 0;
    for(int i = 1;i < n;i++){
//printf("%d ",z);
        double f = d;
        ans += st[i]*ceil((ar[w[i]-1] - o - z) / f);
        o = d - ar[w[i]-1] % d;
        //z = ar[w[i]-1];

    }
    printf("%d",ans);
    return 0;
}
