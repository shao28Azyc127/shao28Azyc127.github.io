#include <bits/stdc++.h>
using namespace std;
int n,d,ans,tot,mini;
int b[100005];
int v[100005];
int ex,ned;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        int a ;
        scanf("%d",&a);
        b[i]=a+b[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    while(ned<b[1]){
        ned+=d;
        ans+=v[1];
    }
    mini=v[1];
    for(int i=2;i<n;i++){
        if(v[i]<mini){
            mini=v[i];
        }
        while(ned<b[i]){
            ned+=d;
            ans+=mini;
        }
    }
    printf("%d",ans);
    return 0;
}

