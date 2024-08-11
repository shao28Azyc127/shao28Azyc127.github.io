/*
  hmz is cute!
---------------------------
  You've got to have faith
  Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY int
#define ll long long
#define INF (TY)(1e9)
#define mod (TY)(1e9+7)
#define pb push_back
#define IL inline
#define MAXN 500005
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
}TY id,n,m,q,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
bool dp[2005][2005][2];
IL bool solve(){
    TY len1=n,len2=m;
    if(c[1]>d[1])swap(c,d),swap(len1,len2);
    if(c[1]==d[1])return false;
    if(id<=7){
        For(i,0,len1)For(j,0,len2)For(k,0,1)dp[i][j][k]=0;
        dp[0][0][0]=dp[0][0][1]=1;
        For(i,0,len1)For(j,0,len2)For(k,0,1)if(dp[i][j][k]){
            if(c[i+1]<d[j+1])dp[i+1][j+1][0]=dp[i+1][j+1][1]=1;
            if(!k){
                if(c[i]<d[j+1]&&i)dp[i][j+1][k]=1;
            }else{
                if(c[i+1]<d[j]&&j)dp[i+1][j][k]=1;
            }
        }return dp[len1][len2][0]|dp[len1][len2][1];
    }else{
        TY lst=INF,maxx=0,id=1;
        For(i,1,len1+1){
            if(i==1)lst=c[i];
            else{
                if(c[i]<lst||i==len1+1){
                    while(id<=len2&&d[id]<=maxx){
                        if(d[id]<=lst)return false;
                        ++id;
                    }if(id>len2||d[id]<=lst)return false;
                    lst=c[i];maxx=0;
                }else maxx=max(maxx,c[i]);
            }
        }return true;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    /* init */
    id=qr();n=qr();m=qr();q=qr();
    For(i,1,n)a[i]=qr();For(i,1,m)b[i]=qr();
    For(i,0,q){
        For(j,1,n)c[j]=a[j];For(j,1,m)d[j]=b[j];
        TY u=(i==0?0:qr()),v=(i==0?0:qr());
        For(j,1,u){
            TY x=qr(),y=qr();
            c[x]=y;
        }For(j,1,v){
            TY x=qr(),y=qr();
            d[x]=y;
        }putchar(solve()?'1':'0');
    }
    return 0;
}