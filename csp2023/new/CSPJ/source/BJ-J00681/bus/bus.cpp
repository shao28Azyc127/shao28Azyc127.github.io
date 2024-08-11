#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m,q,p,ans,a,b,c,derta;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&t,&m);

    while(t--){
        scanf("%lld%lld%lld",&a,&b,&c);
        derta=-4.0*a*c;
        if(b==0&&c==0){
            printf("0\n");
        }else if(b==0){
            if(-c>0){

                ans=sqrt(derta)/2.0;
                printf("%lld\n",ans);

            }else{
                printf("NO\n");
            }
        }else{
            if(derta>=0) printf("%lld+sqrt(%lld)/2\n",b,derta);
            else printf("NO\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
