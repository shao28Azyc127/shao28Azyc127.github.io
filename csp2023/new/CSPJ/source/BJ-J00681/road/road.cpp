#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int upp(int x,int y){
    if(x%y==0) return x/y;
    else return x/y+1;
}
int n,d,v[N],a[N],cnt,cur;
bool flag=1,flag2=1;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    cnt=0;
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
        if(v[i]%d!=0) flag2=0;
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i!=1&&a[i]>a[i-1]) a[i]=a[i-1],flag=0;
    }
    a[n]=0;
    cur=0;
    if(flag){
        cnt=upp(v[n-1],d)*a[1];
    }else if(flag2){
        for(int i=1;i<n;i++){
            cnt+=a[i]*(v[i]-v[i-1])/d;
        }
    }else{
        for(int i=1;i<n;i++){
            if(v[i]>cur&&a[i]!=a[i+1]){
                cnt+=upp(v[i]-cur,d)*a[i];
                cur=v[i]+upp(v[i]-cur,d);
            }

        }
    }
    printf("%lld",cnt);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
