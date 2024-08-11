#include <bits/stdc++.h>
using namespace std;
int dis[100005],price;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)scanf("%d",&dis[i]);
    int x;
    scanf("%d",&price);
    for(int i=1;i<n;i++)scanf("%d",&x);
    for(int i=1;i<n;i++)dis[i]+=dis[i-1];
    printf("%d",ceil(1.0000000*dis[n-1]/d));return 0;
}
