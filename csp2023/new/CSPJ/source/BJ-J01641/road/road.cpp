#include<bits/stdc++.h>
using namespace std;
int n,d,a[100007],u[100007],ans;
void dfs(int x,int xx){
    if(x==n)return;
    int va=0,vx=0,vu;
    for(int i=x+1;i<=n;i++){
        va+=a[i],vx=i;
        if(u[i]<u[x])break;
    }
    va-=xx;
    vu=va/d;
    if(va%d)vu++;
    ans+=vu*u[x];
    //cout<<vx<<" "<<va<<endl;
    dfs(vx,vu*d-va);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&u[i]);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
