#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n;
int i,j,ans;
int a[N],b[N],c[N],d[N];
int mp[N][N];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int cal(int x,int now){
    int mid,l=1,r=1e9;
    while(l<=r){
        mid=(l+r)>>1;
        if(c[now]>=0){
            if((b[i]*2)+(d[i]*2+l)*((l+1)/2*c[i])*(mid+1)/2 >=a[i]) r=mid-1,ans=mid;
            else l=mid+1;
        }
        if(c[now]<0){
            if((mid+x)*c[now]+b[now]<=0){
                int t=b[now]+abs(c[now]-1)/abs(c[now]);
                if(d[now]>=t){
                    if(mid+1>=a[now])   ans=mid;
                }

            }
            else{
                if((b[now]-d[now]*c[now]+b[now]-(d[now]+mid)*c[now])*(mid+1)/2>=a[now]) r=mid-1,ans=mid;
                else l=mid+1;
            }
        }
    }
}
void DFS(int x){
    if(x==n){
        int q=0;
        for(int i=1;i<=n;i++){
            if(c[i]>=0) {
            }
        }
        return;
    }
    for(i=1;i<=n;i++){
        if(d[i])continue;
        int flag=0;
         if(d[1]==1&&d[2]==2&&i==4&&x==2){
            cout<<d[3]<<endl;
         }
        for(j=1;j<=n;j++){
            if(!mp[i][j])   continue;
            if(d[j]) {
                flag=1;
            }
        }
        if(!flag)   continue;
        d[i]=x+1;
        DFS(x+1);
        d[i]=0;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(i=1;i<=n;i++)   a[i]=read(),b[i]=read(),c[i]=read();
    for(i=1;i<=n;i++){
        int u=read(),v=read();
        mp[u][v]=mp[v][u]=1;
    }
    d[1]=1;
    ans=-1;
    DFS(1);
    printf("%d\n",ans);
    return 0;
}
