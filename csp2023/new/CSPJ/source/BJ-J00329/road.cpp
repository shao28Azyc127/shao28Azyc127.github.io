#include<bits/stdc++.h>
using namespace std;
struct zhan{
    int i,a,d;
}zs[100005],z[100005];
int cmp(zhan a,zhan b){
    return a.a<b.a;
}
int s[100005],d,n,oil=0,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n-1;i++){zs[i].i=i;scanf("%d",&zs[i].d);}
    for(int i=1;i<=n;i++)scanf("%d",&zs[i].a);
    sort(zs+1,zs+n,cmp);
    for(int i=1;i<=n-1;i++){
        z[zs[i].i].a=zs[i].a;
        z[zs[i].i].d=zs[i].d;
        z[zs[i].i].i=i;
    }
    s[1]=0;
    for(int i=2;i<=n;i++)s[i]=s[i-1]+z[i-1].d;
    for(int i=1;i<=n-1;){
        if(z[i].i==1){
            //cout<<oil<<endl;
            cout<<ans+ceil((s[n]-s[i]-oil)/d)*z[i].a;
            break;
        }
        int fm=0;
        for(int j=i;j<=n;j++){
            if(z[j].i<z[i].i){
                fm=j;
                break;
            }
        }

        double cnt=ceil((double)(s[fm]-s[i]-oil)/d)*z[i].a;
        ans+=cnt;
        //cout<<cnt<<i<<endl;
        oil=0;
        oil+=(s[fm]-s[i]-oil)*z[i].a-cnt*d;
        i=fm;
    }
    return 0;
}