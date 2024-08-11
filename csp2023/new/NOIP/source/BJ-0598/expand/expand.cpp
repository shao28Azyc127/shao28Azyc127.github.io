#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
int cc,n,m,q,t,kx,ky,u,v;
int a[N],b[N],aa[N],bb[N];
struct node{
    int v,id;
}c[N<<2];
int tr[5000005];
void add(int x){
    while(x){
        tr[x]=1;
        x-=x&-x;
    }
}
ll query(ll x){
    ll res=0;
    while(x<=1e6){
        res=res|tr[x];
     //   cout<<res<<endl;
        x+=x&-x;
    }
    return res;
}
bool cmp(node x,node y){
    return x.v<y.v;
}
int main(){
    freopen("expand.in","r",stdin);
   freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&cc,&n,&m,&q);
    t=q+1;
    while(t--){
        if(t<q){
            scanf("%d%d",&kx,&ky);
            for(int i = 1;i<=kx;i++){
                scanf("%d%d",&u,&v);
                a[u]=v;
            }
            for(int i = 1;i<=ky;i++){
                scanf("%d%d",&u,&v);
          //      cout<<u<<" "<<v;
                b[u]=v;
            }
            for(int i = 1;i<=n;i++){
                c[i].v=a[i];
                c[i].id=i;
            }
            for(int i = 1;i<=m;i++){
                c[i+n].v=b[i];
                c[i+n].id=i+n;
             //   cout<<i+n<<" "<<c[i+n].v<<endl;
            }
        }
        else{
            for(int i = 1;i<=n;i++){
                scanf("%d",&a[i]);
                c[i].v=a[i];
                c[i].id=i;
            }
            for(int i = 1;i<=m;i++){
                scanf("%d",&b[i]);
                c[i+n].v=b[i];
                c[i+n].id=i+n;
            }
        }
        if(n==1&&m==1){
            if(a[i]==b[i]) cout<<0;
            else cout<<1;
            continue;
        }
        if(n==2&&m==2){
            if(a[1]<b[1]){
                if(a[2]<b[2]) cout<<1;
                else if(a[2]<b[1]) cout<<1;
                else cout<<0;
            }
            else if(a[1]>b[1]){
                if(a[2]>b[2]) cout<<1;
                else if(a[2]>b[1]) cout<<1;
                else cout<<0;
            }
            else cout<<0;
            continue;
        }
        sort(c+1,c+1+n+m,cmp);
        int cnt=0;
        for(int i = 1;i<=n+m;i++){
            if(c[i].v>c[i-1].v) cnt++;
            if(c[i].id>n) bb[c[i].id-n]=cnt;
            else aa[c[i].id]=cnt;
        }
            int flag=1;
            memset(tr,0,sizeof tr);
            for(int i = 1;i<=n;i++){
                if(i<=m){
                    add(bb[i]);
                }
                int x;
                x=query(aa[i]);
                if(x<=0){
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                printf("0");
                continue;
            }
            memset(tr,0,sizeof tr);
            for(int i = 1;i<=m;i++){
                if(i<=n){
                    add(1e6-aa[i]);
                }
                int x=query(1e6-bb[i]);
                if(x<=0){
                      //  cout<<2<<" "<<i<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag) printf("1");
            else printf("0");
    }
    return 0;
}
