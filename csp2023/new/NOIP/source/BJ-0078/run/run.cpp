/*
  hmz is cute!
---------------------------
  You've got to have faith
  Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY long long
#define ll long long
#define INF (TY)(1e18)
#define mod (TY)(1e9+7)
#define pb push_back
#define IL inline
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    while(ch<'0'||ch>'9')v=(ch=='-'?-1:1),ch=getchar();
    while(ch>='0'&&ch<='9')u=u*10+(ch-'0'),ch=getchar();
    return u*v;
}IL void qw(TY now){
    if(now<0){putchar('-');now=-now;}
    if(!now){putchar('0');return;}
    if(now>=10)qw(now/10);putchar('0'+now%10);
}IL void qw(TY now,char ch){qw(now);putchar(ch);}
IL bool ischar(char ch){return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');}
IL char getc(){
    char ch=getchar();
    while(!ischar(ch))ch=getchar();
    return ch;
}IL string qs(){
    string lst="";char ch=getchar();
    while(!ischar(ch))ch=getchar();
    while(ischar(ch))lst+=ch,ch=getchar();
    return lst;
}IL void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
IL TY Mod(TY k){return (k>=mod?k-mod:k);}
IL TY Ceil(TY x,TY y){return x/y+(x%y!=0);}
IL TY Pow(TY a,TY b){
    TY base=a,ans=1;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;
    }return ans;
}TY id,T,n,m,k,d,dp1[1005][1005],cnt[1005][1005],maxx[1005],dp2[MAXN],sum[MAXN];
struct node{TY x,y,w;}s[MAXN];
IL bool cmp(node x,node y){return x.y==y.y?x.x<y.x:x.y<y.y;}
struct Tree{
    TY tree[MAXN<<2];
    IL void build(){For(i,1,(m+1)<<2)tree[i]=-INF;}
    void update(TY now,TY l,TY r,TY x,TY w){
        if(l==r){tree[now]=w;return;}
        TY mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,w);
        else update(now<<1|1,mid+1,r,x,w);
        tree[now]=max(tree[now<<1],tree[now<<1|1]);
    }TY query(TY now,TY l,TY r,TY x,TY y){
        if(l>y||r<x)return -INF;
        if(x<=l&&r<=y)return tree[now];
        TY mid=(l+r)>>1;
        return max(query(now<<1,l,mid,x,y),query(now<<1|1,mid+1,r,x,y));
    }
}tr;
IL TY Find(TY w){
    TY l=1,r=m,ans=0;
    while(l<=r){
        TY mid=(l+r)>>1;
        if(s[mid].y<w)ans=mid,l=mid+1;
        else r=mid-1;
    }return dp2[ans];
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    /* init */
    id=qr();T=qr();while(T--){
        TY ans=0;
        n=qr();m=qr();k=qr();d=qr();
        For(i,1,m)s[i].x=qr(),s[i].y=qr(),s[i].w=qr();
        if(id<=9){
            memset(dp1,-0x3f,sizeof(dp1));
            memset(cnt,0,sizeof(cnt));
            memset(maxx,-0x3f,sizeof(maxx));
            dp1[0][0]=0;maxx[0]=0;
            For(i,1,m)cnt[s[i].x][s[i].y]+=s[i].w;
            For(i,1,n)For(j,1,n)cnt[i][j]+=cnt[i][j-1];
            For(i,1,n)For(j,0,k){
                if(j)dp1[i][j]=max(dp1[i][j],dp1[i-1][j-1]+cnt[i][j]-d);
                else dp1[i][j]=maxx[i-1];
                maxx[i]=max(maxx[i],dp1[i][j]);
                ans=max(ans,dp1[i][j]);
            }qw(ans,'\n');
        }else{
            TY Ans=0;
            tr.build();
            memset(dp2,-0x3f,sizeof(dp2));
            For(i,1,m){
                sum[i]=sum[i-1]+s[i].w;
                TY a=s[i].x,b=s[i].y;
                s[i].x=a-b+1;s[i].y=a;
            }tr.update(1,0,m,0,0);dp2[0]=0;
            For(i,1,m){
                TY l=1,r=i-1,ans=i;
                while(l<=r){
                    TY mid=(l+r)>>1;
                    if(s[i].y-s[mid].x+1<=k)ans=mid,r=mid-1;
                    else l=mid+1;
                }tr.update(1,0,m,i,Find(s[i].x-1)-sum[i-1]+(s[i].x-1)*d);
                dp2[i]=max(dp2[i-1],tr.query(1,0,m,ans,i)+sum[i]-s[i].y*d);
                Ans=max(Ans,dp2[i]);
            }qw(Ans,'\n');
        }
    }
    return 0;
}