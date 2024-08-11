#include <bits/stdc++.h>
using namespace std;
int n,d,xy[100005],jq[100005],ans,now;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=0; i<n-1; i++){
        scanf("%d",&xy[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d",&jq[i]);
    }
    for(int i=0; i<n-1; i++){
        if(now>xy[i]){
            now-=xy[i];
        }else{
            while(now<xy[i]){
                now+=d;
                ans+=jq[i];
            }
            now-=xy[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
