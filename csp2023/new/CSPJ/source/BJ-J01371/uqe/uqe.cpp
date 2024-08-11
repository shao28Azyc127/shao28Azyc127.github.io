#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m;
int a[maxn];

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    scanf("%d%d",&n,&m);

    while(n--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);

        ll derta=b*b-4ll*a*c;
        //cout<<derta<<endl;
        //cout<<derta<<endl;
        if(derta<0){
            printf("NO\n");
            continue;
        }
        ll dn=a*2;
        ll ul=-b;
        ll ur=derta;
            //if(ul<0) printf("-"),ul=-ul;
        ll tm=sqrt(ur);

        if(tm*tm==ur){
            if(dn<0) ul=-ul,dn=-dn;
            ul+=tm;
            if(ul%dn==0) printf("%lld\n",ul/dn);
            else{
                ll g=__gcd(dn,abs(ul));
                dn/=g;
                ul/=g;
                printf("%lld/%lld\n",ul,dn);
            }
            continue;
        }
        if(b==0);
        else if(ul%dn==0) printf("%lld",ul/dn);
        else{
            if(dn<0) ul=-ul,dn=-dn;
            ll g=__gcd(dn,abs(ul));
            dn/=g;
            ul/=g;
            printf("%lld/%lld",ul,dn);
            dn*=g;
        }
        if(!derta) printf("\n");
        else{
            dn=abs(dn);
            ll url=0;
            if(b!=0) printf("+");
            ll tmp=sqrt(ur);
            while(tmp>1){
                if(ur%(tmp*tmp)==0){
                    //cout<<tmp<<endl;
                    url=tmp,ur/=(tmp*tmp);
                    break;
                }
                tmp--;
            }

            if(ur==1) printf("1/%lld\n",dn);
            else if(!url) printf("sqrt(%lld)/%lld\n",ur,dn);
            else if(url%dn==0){
                url/=dn;
                if(url==1) printf("sqrt(%lld)\n",ur);
                else printf("%lld*sqrt(%lld)\n",url,ur);
            }
            else{
                ll g=__gcd(url,dn);
                dn/=g;
                url/=g;
                if(url==1) printf("sqrt(%lld)/%lld\n",ur,dn);
                else printf("%lld*sqrt(%lld)/%lld\n",url,ur,dn);
            }
        }


    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
