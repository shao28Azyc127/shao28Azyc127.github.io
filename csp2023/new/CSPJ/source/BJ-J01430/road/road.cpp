#include<bits/stdc++.h>
using namespace std;
long long a[100005],v[100005],S[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    long long d;
    scanf("%d%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        S[i+1]=S[i]+a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
    }
    long long now=1,sum=0,ans=0;
    while(now!=n){
        int nxpos=n;
        for(int i=now+1;i<=n;i++){
            if(v[i]<v[now]){
                nxpos=i;
                break;
            }
        }

        long long dis=S[nxpos]-S[now];
        //cout<<now<<"->"<<nxpos<<" "<<dis<<endl;
        long long need=(dis-sum);
        if(need%d==0){
            need/=d;
        }else{
            need=need/d+1;
        }
        sum+=need*d;
        sum-=dis;
        ans+=need*v[now];
        //cout<<need<<" "<<v[now]<<endl;
        now=nxpos;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
