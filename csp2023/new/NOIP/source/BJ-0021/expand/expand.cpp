#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int INF=1e9+9;
int a[N],b[N];
int ay[N],by[N];
int c,n,m,q;
//int qamin[N],hamin[N],qamax[N],hamax[N],qbmin[N],hbmin[N],qbmax[N],hbmax[N];
bool check(int div1,int div2,bool flag1,bool flag2){//flag1=0:a>b flag2=0:qian
    if(!flag2&&(div1<=0||div2<=0))return 1;
    if(flag2&&(div1>=n||div2>=m))return 1;
    if(!flag1){
        if(!flag2){
            int l=1,r=1;
            int pre_min=INF;
            int maxb=0;
            int maxa=0;
            while(l<=div1){
                maxa=max(maxa,a[l]);
                if(a[l]<pre_min){
                    while(r<=div2&&b[r]>=a[l]){
                        maxb=max(maxb,b[r]);
                        r++;
                    }
                    //if(r>div2)
                    if(maxa<=maxb)return 0;
                    pre_min=a[l];
                }
                l++;
            }
            return 1;
        }
        else{
            int l=n,r=m;
            int pre_min=INF;
            int maxb=0;
            int maxa=0;
            while(l>=div1){
                maxa=max(maxa,a[l]);
                if(a[l]<pre_min){
                    while(r>=div2&&b[r]>=a[l]){
                        maxb=max(maxb,b[r]);
                        r--;
                    }
                    //if(r>div2)
                    if(maxa<=maxb)return 0;
                    pre_min=a[l];
                }
                l--;
            }
            return 1;
        }
    }
    else{
        if(!flag2){
            int l=1,r=1;
            int pre_min=INF;
            int maxa=0;
            int maxb=0;
            while(r<=div2){
                maxb=max(maxb,b[r]);
                if(b[r]<pre_min){
                    while(l<=div1&&a[l]>=b[r]){
                        maxa=max(maxa,a[l]);
                        l++;
                    }
                    //if(r>div2)
                    if(maxa>=maxb)return 0;
                    pre_min=b[r];
                }
                r++;
            }
            return 1;
        }
        else{
            int l=n,r=m;
            int pre_min=INF;
            int maxa=0;
            int maxb=0;
            while(r>=div2){
                maxb=max(maxb,b[r]);
                if(b[r]<pre_min){
                    while(l>=div1&&a[l]>=b[r]){
                        maxa=max(maxa,a[l]);
                        l--;
                    }
                    //if(r>div2)
                    if(maxa>=maxb)return 0;
                    pre_min=b[r];
                }
                r--;
            }
            return 1;
        }
    }
}
bool fun(){
    if((a[1]-b[1])*(a[n]-b[m])<=0)return 0;
    if(a[1]>b[1]){
        int max_xa=0,max_id;
        for(int i=1;i<=n;i++){
            if(max_xa<a[i]){
                max_xa=a[i];
                max_id=i;
            }
        }
        for(int i=1;i<=m;i++){
            if(a[max_id]<=b[i])return 0;
        }
        int min_nb=INF,min_id;
        for(int i=1;i<=m;i++){
            if(min_nb>b[i]){
                min_nb=b[i];
                min_id=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(b[min_id]>=a[i])return 0;
        }
        //cout<<check(max_id-1,min_id-1,0,0)<<" "<<check(max_id+1,min_id+1,0,1)<<"\n";
        return check(max_id-1,min_id-1,0,0)&&check(max_id+1,min_id+1,0,1);
    }
    else{
        //cout<<"?";
        int min_na=INF,min_id;
        for(int i=1;i<=n;i++){
            if(min_na>a[i]){
                min_na=a[i];
                min_id=i;
            }
        }
        for(int i=1;i<=m;i++){
            if(a[min_id]>=b[i])return 0;
        }
        int max_xb=0,max_id;
        for(int i=1;i<=m;i++){
            if(max_xb<b[i]){
                max_xb=b[i];
                max_id=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(b[max_id]<=a[i])return 0;
        }
        //cout<<check(max_id-1,min_id-1,0,0)<<" "<<check(max_id+1,min_id+1,0,1)<<"\n";
        return check(min_id-1,max_id-1,1,0)&&check(min_id+1,max_id+1,1,1);
    }
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        scanf("%lld",&ay[i]);
        a[i]=ay[i];
    }
    for(int j=1;j<=m;j++){
        scanf("%lld",&by[j]);
        b[j]=by[j];
    }
    cout<<fun();
    while(q--){
        int kx,ky;
        scanf("%lld%lld",&kx,&ky);
        for(int i=1;i<=n;i++){
            a[i]=ay[i];
        }
        for(int j=1;j<=m;j++){
            b[j]=by[j];
        }
        for(int i=1;i<=kx;i++){
            int pos,c;
            scanf("%lld%lld",&pos,&c);
            a[pos]=c;
        }
        for(int i=1;i<=ky;i++){
            int pos,c;
            scanf("%lld%lld",&pos,&c);
            b[pos]=c;
        }
        cout<<fun();
    }
    cout<<"\n";
    return 0;
}