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
#define MAXN 3005
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
}TY n,m;string s[MAXN],t[MAXN],maxx[MAXN];
IL bool cmp1(char x,char y){return x<y;}
IL bool cmp2(char x,char y){return x>y;}
IL bool cmp3(string x,string y){return x<y;}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    
    n=qr();m=qr();
    For(i,1,n){
        s[i]=qs();maxx[i]=s[i];
        sort(s[i].begin(),s[i].end(),cmp1);
        sort(maxx[i].begin(),maxx[i].end(),cmp2);
        t[i]=maxx[i];
    }sort(maxx+1,maxx+1+n,cmp3);
    For(i,1,n)putchar(n==1||s[i]<(t[i]==maxx[1]?maxx[2]:maxx[1])?'1':'0');
    return 0;
}