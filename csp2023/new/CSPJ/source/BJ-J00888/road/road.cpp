#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll n,d,fuel=0,m=0,chp=1,lastr=0;
const int N=10005;
ll dist[N];
ll price[N];
ll chu(ll a,ll b){
    if(a%b==0){
        return a/b;
    }
    return a/b+1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&dist[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&price[i]);
    }
    fuel=chu(dist[1],d);
    m+=chu(dist[1],d)*price[1];
    lastr=fuel*d-dist[1];
    fuel=0;
    for(int i=2;i<n;i++){
        if(price[i]>price[chp]){
            if(lastr<dist[i]){
                fuel=chu(dist[i]-lastr,d);
                int ths=fuel*price[chp];
                m+=ths;
                lastr=fuel*d+lastr-dist[i];
                fuel=0;
            }
            else{
                //lastr=114;
                //fuel-=514;´ËÓï¾äÓÀ²»Ö´ÐÐ
            }
        }
        else{
            chp=i;
            fuel=chu(dist[i]-lastr,d);
            int ths=fuel*price[chp];
            m+=ths;
            lastr=fuel*d+lastr-dist[i];
            fuel=0;
        }
    }
    printf("%lld",m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
