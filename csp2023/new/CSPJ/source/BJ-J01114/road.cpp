#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005],a[100005];
int ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i < n;i++){
        scanf("%d",&v[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    int wow = a[1];
    for(int i = 1;i <= n;i++){
        wow = min(wow,a[i]);
    }
    if(wow == a[1]){
        int dis = 0;
        for(int i = 1;i <= n;i++){
            dis += v[i];
        }
        dis = dis / d * a[1];
        printf("%d",dis);
    }
    ans += v[1] / d * a[1];
    int lit = a[1];
    for(int i = 2;i <= n;i++){
        if(a[i] >= lit){
            ans += v[i] / d * lit;
        }
        else{
            ans += v[i] / d * lit;
            lit = a[i];
        }
    }
    printf("%d",ans);
    return 0;
}
