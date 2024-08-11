#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int del=b*b-4*a*c;
        if(del<0){
            printf("NO");
            printf("\n");
            continue;
        }
        int w=sqrt(del);
        int ans=max((w-b)/(2*a),(-w-b)/(2*a));
        printf("%d\n",ans);
    }
    return 0;
}