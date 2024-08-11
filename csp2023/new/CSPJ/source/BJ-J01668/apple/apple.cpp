#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pf push_front
using namespace std;
inline ll read(){
    ll k=0,flag=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')flag=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=(k<<1)+(k<<3)+(c^48);
        c=getchar();
    }
    return k*flag;
}
inline void print(ll n){
    if(n<0){
        putchar('-');
        n=-n;
    }
    if(n>9)print(n/10);
    putchar(n%10+'0');
    return ;
}
inline void fre(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);//"W"
}
ll n;
const int N=1e6+10;
int a[N],ans,num;
int main(){
    fre();
    cin>>n;
    for(int i=1;num<n;++i){
	int cnt=0;
	for(int j=1;j<=n;++j){
	    if(!a[j]){
		a[j]=i;
		++num;
		break;
	    }
	}
	for(int j=1;j<=n;++j){
	    if(cnt==2&&!a[j]){
		a[j]=i;
		++num;
		cnt=0;
	    }
	    if(!a[j])++cnt;
	}
	ans=i;
    }
    cout<<ans<<" "<<a[n];
    return 0;
}
