#include<bits/stdc++.h>
using namespace std;
const int NR=5e5+10;
int Tid,n,m,q,a[NR],b[NR];

namespace brute_force{
    int v1[NR],v2[NR];
    const int MR=210;
    int f[MR][MR],g[MR][MR];
    void solve1(){
        memset(f,0,sizeof(f));
        f[1][1]=1;
        for(int i=2;i<=n;i++)
            if(v1[i]>v2[1])f[1][i]=1;
            else break;
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++)
                if(f[i-1][j]&&v1[j]>v2[i])f[i][j]=1;
            for(int j=1;j<=n;j++)
                if((f[i-1][j-1]||f[i][j-1])&&v1[j]>v2[i])f[i][j]=1;
        }
        // puts("----");
        if(f[m][n])putchar('1');
        else putchar('0');
        // puts("-----");
    }
    void solve2(){
        memset(g,0,sizeof(g));
        g[1][1]=1;
        // for(int i=1;i<=n;i++)printf("%d ",v1[i]);puts("");
        // for(int i=1;i<=m;i++)printf("%d ",v2[i]);puts("");
        for(int i=2;i<=m;i++)
            if(v2[i]>v1[1])g[1][i]=1;
            else break;
            // for(int j=1;j<=m;j++)printf("%d",g[1][j]);puts("");
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++)
                if(g[i-1][j]&&v2[j]>v1[i])g[i][j]=1;
            for(int j=1;j<=m;j++)
                if((g[i-1][j-1]||g[i][j-1])&&v2[j]>v1[i])g[i][j]=1;
            // for(int j=1;j<=m;j++)printf("%d",g[i][j]);puts("");
        }
        if(g[n][m])putchar('1');
        else putchar('0');
        // puts("");
    }
    void calc(){
        if(v1[1]>v2[1])solve1();
        else if(v2[1]>v1[1])solve2();
        else putchar('0');
    }
    void solve(){
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++)cin>>b[i];
        for(int i=1;i<=n;i++)v1[i]=a[i];
        for(int i=1;i<=m;i++)v2[i]=b[i];
        calc();
        while(q--){
            int k1,k2;cin>>k1>>k2;
            for(int i=1;i<=n;i++)v1[i]=a[i];
            for(int i=1;i<=m;i++)v2[i]=b[i];
            for(int i=1,x,y;i<=k1;i++)
                cin>>x>>y,v1[x]=y;
            for(int i=1,x,y;i<=k2;i++)
                cin>>x>>y,v2[x]=y;
            calc();
        }
        puts("");
    }
}
namespace special_solve{
    int v1[NR],v2[NR];
    void solve1(){
        int l=1,r=1;
        for(int i=2;i<=n;i++)
            if(v1[i]>v2[1])r=i;
            else break;
        bool ans=1;
        for(int i=2;i<=m;i++){
            while(r<n&&v1[r+1]>v2[i])r++;
            while(r&&v1[r]<=v2[i])r--;
            while(l<n&&v1[l]<=v2[i])l++;
            if(l>r){
                ans=0;
                break;
            }
            // printf("l:%d r:%d\n",l,r);
        }
        if(ans&&r==n)putchar('1');
        else putchar('0');
    }
    void solve2(){
        int l=1,r=1;
        for(int i=2;i<=m;i++)
            if(v2[i]>v1[1])r=i;
            else break;
        bool ans=1;
        for(int i=2;i<=n;i++){
            while(r<m&&v2[r+1]>v1[i])r++;
            while(r&&v2[r]<=v1[i])r--;
            while(l<m&&v2[l]<=v1[i])l++;
            if(l>r){
                ans=0;
                break;
            }
        }
        if(ans&&r==m)putchar('1');
        else putchar('0');
    }
    void calc(){
        if(v1[1]>v2[1])solve1();
        else if(v2[1]>v1[1])solve2();
        else putchar('0');
    }
    void solve(){
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)v1[i]=a[i];
        for(int i=1;i<=m;i++)v2[i]=b[i];
        calc();
        while(q--){
            int k1,k2;cin>>k1>>k2;
            for(int i=1;i<=n;i++)v1[i]=a[i];
            for(int i=1;i<=m;i++)v2[i]=b[i];
            for(int i=1,x,y;i<=k1;i++)
                scanf("%d%d",&x,&y),v1[x]=y;
            for(int i=1,x,y;i<=k2;i++)
                scanf("%d%d",&x,&y),v2[x]=y;
            calc();
        }
        puts("");
    }
}

namespace AC_solve{
    int v1[NR],v2[NR];
        int len,maxv[NR][21],minv[NR][21],lg[NR];
        void init(int n,int *val){
            len=n;
            for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
            for(int i=1;i<=n;i++)minv[i][0]=maxv[i][0]=val[i];
            for(int i=1;i<lg[n];i++)
                for(int j=1;j+(1<<i)<=n+1;j++)
                    maxv[j][i]=max(maxv[j][i-1],maxv[j+(1<<(i-1))][i-1]),
                    minv[j][i]=min(minv[j][i-1],minv[j+(1<<(i-1))][i-1]);
        }
        int get1(int pos,int x){//The biggest k >=pos s.t. v_i>x for all i
            // printf("pos:%d x:%d %d\n",pos,x,minv[pos][0]);
            for(int i=lg[len-pos+1]-1;i>=0;i--)
                if(pos+(1<<i)<=len+1&&minv[pos][i]>x)pos+=(1<<i);
            return pos-1;
        }
        int get2(int pos,int x){//The biggest k <= pos s.t. v_k>x
            for(int i=lg[pos];i>=0;i--)
                if(pos>=(1<<i)&&maxv[pos-(1<<i)+1][i]<=x)pos-=(1<<i);
            return pos;
        }
        int get3(int pos,int x){//The smallest k >=pos s.t. v_k>x
            if(maxv[pos][0]>x)return pos;
            for(int i=lg[len-pos+1];i>=0;i--)
                if(pos+(1<<i)<=len+1&&maxv[pos][i]<=x)pos+=(1<<i);
            return pos;
        }
    void solve1(){
        int l=1,r=1;
        for(int i=2;i<=n;i++)
            if(v1[i]>v2[1])r=i;
            else break;
        bool ans=1;
        init(n,v1);
        for(int i=2;i<=m;i++){
            r=get1(r,v2[i]);
            // printf("l:%d r:%d\n",l,r);
            r=get2(r,v2[i]);
            l=get3(l,v2[i]);
            if(l>r){
                ans=0;
                break;
            }
        }
        if(ans&&r==n)putchar('1');
        else putchar('0');
    }
    void solve2(){
        int l=1,r=1;
        for(int i=2;i<=m;i++)
            if(v2[i]>v1[1])r=i;
            else break;
        bool ans=1;
        init(m,v2);
        for(int i=2;i<=n;i++){
            r=get1(r,v1[i]);
            r=get2(r,v1[i]);
            l=get3(l,v1[i]);
            // printf("l:%d r:%d\n",l,r);
            if(l>r){
                ans=0;
                break;
            }
        }
        if(ans&&r==m)putchar('1');
        else putchar('0');
    }
    void calc(){
        if(v1[1]>v2[1])solve1();
        else if(v2[1]>v1[1])solve2();
        else putchar('0');
    }
    void solve(){
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)v1[i]=a[i];
        for(int i=1;i<=m;i++)v2[i]=b[i];
        calc();
        while(q--){
            int k1,k2;cin>>k1>>k2;
            for(int i=1;i<=n;i++)v1[i]=a[i];
            for(int i=1;i<=m;i++)v2[i]=b[i];
            for(int i=1,x,y;i<=k1;i++)
                scanf("%d%d",&x,&y),v1[x]=y;
            for(int i=1,x,y;i<=k2;i++)
                scanf("%d%d",&x,&y),v2[x]=y;
            calc();
        }
        puts("");
    }
}

signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>Tid>>n>>m>>q;
    if(n<=200){
        brute_force::solve();
        return 0;
    }
    if(n<=2000){
        special_solve::solve();
        return 0;
    }
    AC_solve::solve();
    return 0;
}