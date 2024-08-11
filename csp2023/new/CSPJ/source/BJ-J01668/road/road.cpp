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
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);//"W"
}
const int N=1e5+10;
ll n,d,a[N],b[N],ans,now;
int main(){
    fre();
    cin>>n>>d;
    for(int i=1;i<n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    for(int i=1;i<n;++i){
	int pos=n;
	ll dis=a[i];
	for(int j=i+1;j<n;++j){
	    if(b[j]<b[i]){
		pos=j;
		break;
	    }
	    dis+=a[j];
	}
	ll num;
	dis-=now;
	if(dis%d==0)num=dis/d;
	else num=dis/d+1;
	ans+=num*b[i];
	now=num*d-dis;
	i=pos-1;
	//2c_s
    }
    cout<<ans;
    return 0;
}
