#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}string s;
int S[maxn];
void slv(){
    int n=read();cin>>s;s=" "+s;
    ll res=0;
    up(i,1,n){
        int top=0;
        up(j,i,n){
            if(top&&S[top]==s[j])top--;
            else S[++top]=s[j];
            if(!top)res++;
        }
    }cout<<res<<'\n';
}int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}