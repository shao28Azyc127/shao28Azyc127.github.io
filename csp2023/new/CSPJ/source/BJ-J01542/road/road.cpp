#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, d;
    scanf("%d%d",&n,&d);
    int gas = 0;
    int dis = 0;
    for(int i=1; i<=n-1; i++){
        int k;
        scanf("%d",&k);
        dis += k;
    }
    int low;
    scanf("%d",&low);
    printf("%.0lf",ceil(dis/1.0/d)*low);
    return 0;
}