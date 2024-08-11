/*
 hmz is cute!
----------------------------
 You've got to have faith
 Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY int
#define ll long long
#define db double
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define INF (TY)(1e9)
#define mod (TY)(1e9+7)
#define IL inline
#define pb push_back
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())v=(ch=='-'?-1:1);
    for(;ch>='0'&&ch<='9';ch=getchar())u=u*10+(ch-'0');
    return u*v;
}IL void qw(TY now){
    if(now<0){putchar('-');now=-now;}
    if(!now){putchar('0');return;}
    if(now>=10)qw(now/10);putchar(now%10+'0');
}IL void qw(TY now,char c){qw(now);putchar(c);}
IL bool ischar(char c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z');}
IL char getc(){
    char ch=getchar();
    while(!ischar(ch))ch=getchar();
    return ch;
}IL string qs(){
    string lst="";char ch=getc();
    while(!ischar(ch))ch=getchar();
    while(ischar(ch))lst+=ch,ch=getchar();
    return lst;
}IL void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
IL TY Mod(TY a){return (a>=mod?a-mod:a);}
IL TY Ceil(TY a,TY b){return a/b+(a%b!=0);}
IL TY Pow(TY a,TY b){
    TY ans=1,base=a;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;b>>=1;
    }return ans;
}TY n,k,now=-1;
string belong[MAXN];
map<string,TY> ans;
map<string,TY> len;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    /* init */
    len["byte"]=1;len["short"]=2;len["int"]=4;len["long"]=8;
    n=qr();
    For(i,1,n){
    	TY op=qr();
    	if(op==2){
    		string a=qs(),b=qs();
    		TY k=len[a];
    		ans[b]=now+1;
    		For(j,now+1,now+k)belong[j]=b;
    		now+=k;
		}else if(op==3){
			string a=qs();
			qw(ans[a],'\n');
		}else if(op==4){
			TY pos=qr();
			if(belong[pos]=="")ws("ERR\n");
			else ws(belong[pos]+'\n');
		}
	}
    return 0;
}