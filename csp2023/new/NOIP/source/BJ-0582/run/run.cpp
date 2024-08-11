#include <bits/stdc++.h>

using namespace std;



int num,T,n,m,k,kk,d,ans=0,en=0;
int vis[10000300];

struct run{
    int x,y,v;
    int start;
    int w;
}a[10000500];

bool cmp(run n,run m){
    if(n.w==m.w){
        return n.start<m.start;
    }
    return n.w>m.w;
}

int main()
{
    //neverTLE;
    //foreverAC
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>num>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        kk=k;
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y>>a[i].v;
            a[i].start=a[i].x-a[i].y+1;
            a[i].w=a[i].v/a[i].y;
        }

        sort(a+1,a+m+1,cmp);

        for(int i=1;i<=n;i++){
            int l=a[i].start,r=a[i].x;

            if(a[i].y>kk){
                kk=k;
                continue;
            }

            for(int j=l;j<=r;j++){
                if(vis[i]==0){
                    en-=d;
                }

                kk--;
            }
            en+=a[i].v;
            if(en>ans){
                ans=en;
                for(int j=l;j<=r;j++){
                    vis[j]=1;
                }
            }
            else en=ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
