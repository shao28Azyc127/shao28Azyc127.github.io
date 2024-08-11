#include<bits/stdc++.h>
using namespace std;
struct node{
    int p,g;
} u[100010];
bool cmp(node q,node w){
    if(q.g!=w.g) return q.g<w.g;
    else return q.p<w.p;
}
int n,j,nt,mg=100010;
long long d[100010],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&j);
    n--,nt=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        d[i]+=d[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&u[i].g);
        u[i].p=i;
    }
    for(int i=1;i<=n;i++) d[i]=(d[i]+j-1)/j;
    sort(u+1,u+n+1,cmp);
    for(int i=1;i<=n;i++) if(u[i].p<=nt) ans+=1ll*u[i].g*(d[nt]-d[u[i].p-1]),mg=u[i].g,nt=u[i].p-1;
    cout<<ans<<endl;
    return 0;
}
