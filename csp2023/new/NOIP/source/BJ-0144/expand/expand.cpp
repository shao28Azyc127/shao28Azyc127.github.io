#include<iostream>
using namespace std;
struct sss{
    int l,r,mmax,mmin;
}s[2000005];
int c,n,m,q,a[500005],b[500005],dp[500005],ans[500005],flag,a2[500005],b2[500005];
int x[500005],y[500005];
void build(int now,int l,int r){
    s[now].l=l;
    s[now].r=r;
    if(l==r){
        s[now].mmin=s[now].mmax=b[l];
        return;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    s[now].mmin=min(s[now*2].mmin,s[now*2+1].mmin);
    s[now].mmax=max(s[now*2].mmax,s[now*2+1].mmax);
}
void xg(int now,int x,int z){
    if(s[now].l==s[now].r){
        s[now].mmin=s[now].mmax=z;
        return;
    }
    int mid=(s[now].l+s[now].r)/2;
    if(x<=mid){
        xg(now*2,x,z);
    }else{
        xg(now*2+1,x,z);
    }
    s[now].mmin=min(s[now*2].mmin,s[now*2+1].mmin);
    s[now].mmax=max(s[now*2].mmax,s[now*2+1].mmax);
}
int cxmin(int now,int l,int r){
    if(s[now].l>=l&&s[now].r<=r){
        return s[now].mmin;
    }
    int mid=(s[now].l+s[now].r)/2;
    if(r<=mid){
        return cxmin(now*2,l,r);
    }else if(l>mid){
        return cxmin(now*2+1,l,r);
    }else{
        return min(cxmin(now*2,l,r),cxmin(now*2+1,l,r));
    }
}
int cxmax(int now,int l,int r){
    if(s[now].l>=l&&s[now].r<=r){
        return s[now].mmax;
    }
    int mid=(s[now].l+s[now].r)/2;
    if(r<=mid){
        return cxmax(now*2,l,r);
    }else if(l>mid){
        return cxmax(now*2+1,l,r);
    }else{
        return max(cxmax(now*2,l,r),cxmax(now*2+1,l,r));
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        b2[i]=b[i];
    }
    dp[0]=1;
    build(1,1,m);
    int uu=0,vv=0;
    if(a[1]-b[1]>0){
        uu=1;
    }else if(a[1]-b[1]<0){
        uu=-1;
    }
    if(a[n]-b[m]>0){
        vv=1;
    }else if(a[n]-b[m]<0){
        vv=-1;
    }
    if(uu!=vv||uu==0){
        ans[0]=0;
    }else{
        flag=0;
        if(a[1]<b[1]){
            for(int i=1;i<=n;i++){
                int u=dp[i-1];
                while(u<=m&&a[i]<b[u]){
                    u++;
                }
                if(a[i]>=b[dp[i-1]]){
                    int l=1,r=dp[i-1]-1,ans=-1;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(cxmax(1,mid,dp[i-1]-1)>a[i]){
                            l=mid+1;
                            ans=mid;
                        }else{
                            r=mid-1;
                        }
                    }
                    if(ans==-1){
                        flag=1;
                        break;
                    }
                    dp[i]=ans;
                }else{
                    dp[i]=u-1;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                int u=dp[i-1];
                while(u<=m&&a[i]>b[u]){
                    u++;
                }
                if(a[i]<=b[dp[i-1]]){
                    int l=1,r=dp[i-1]-1,ans=-1;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(cxmin(1,mid,dp[i-1]-1)<a[i]){
                            l=mid+1;
                            ans=mid;
                        }else{
                            r=mid-1;
                        }
                    }
                    if(ans==-1){
                        flag=1;
                        break;
                    }
                    dp[i]=ans;
                }else{
                    dp[i]=u-1;
                }
            }
        }
        if(dp[n]<m) flag=1;
        ans[0]=(flag+1)%2;
    }
    for(int t=1;t<=q;t++){
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }
        for(int i=1;i<=ky;i++){
            cin>>x[i]>>y[i];
            b[x[i]]=y[i];
            xg(1,x[i],y[i]);
        }
        int uu=0,vv=0;
        if(a[1]-b[1]>0){
            uu=1;
        }else if(a[1]-b[1]<0){
            uu=-1;
        }
        if(a[n]-b[m]>0){
            vv=1;
        }else if(a[n]-b[m]<0){
            vv=-1;
        }
        if(uu!=vv||uu==0){
            ans[t]=0;
        }else{
            flag=0;
            if(a[1]<b[1]){
                for(int i=1;i<=n;i++){
                    int u=dp[i-1];
                    while(u<=m&&a[i]<b[u]){
                        u++;
                    }
                    if(a[i]>=b[dp[i-1]]){
                        int l=1,r=dp[i-1]-1,ans=-1;
                        while(l<=r){
                            int mid=(l+r)/2;
                            if(cxmax(1,mid,dp[i-1]-1)>a[i]){
                                l=mid+1;
                                ans=mid;
                            }else{
                                r=mid-1;
                            }
                        }
                        if(ans==-1){
                            flag=1;
                            break;
                        }
                        dp[i]=ans;
                    }else{
                        dp[i]=u-1;
                    }
                }
            }else{
                for(int i=1;i<=n;i++){
                    int u=dp[i-1];
                    while(u<=m&&a[i]>b[u]){
                        u++;
                    }
                    if(a[i]<=b[dp[i-1]]){
                        int l=1,r=dp[i-1]-1,ans=-1;
                        while(l<=r){
                            int mid=(l+r)/2;
                            if(cxmin(1,mid,dp[i-1]-1)<a[i]){
                                l=mid+1;
                                ans=mid;
                            }else{
                                r=mid-1;
                            }
                        }
                        if(ans==-1){
                            flag=1;
                            break;
                        }
                        dp[i]=ans;
                    }else{
                        dp[i]=u-1;
                    }
                }
            }
            if(dp[n]<m) flag=1;
            ans[t]=(flag+1)%2;
        }
        for(int i=1;i<=n;i++){
            a[i]=a2[i];
        }
        for(int i=1;i<=m;i++){
            b[i]=b2[i];
        }
        for(int i=1;i<=ky;i++){
            xg(1,x[i],b2[x[i]]);
        }
    }
    for(int i=0;i<=q;i++){
        cout<<ans[i];
    }
    return 0;
}
