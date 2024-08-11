#include <bits/stdc++.h>
#define ll long long 
#define M 1000000005
using namespace std;

ll c,n,m,q,amin=M,bmin=M,amax,bmax,cnt,e,d,x,y;
ll a[500005],an[500005],b[500005],bn[500005];

inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		an[i]=a[i];
		if(a[i]<amin){
			amin=a[i];
		}
		if(a[i]>amax){
			amax=a[i];
		}
	}
	for(ll i=1;i<=m;i++){
		b[i]=read();
		bn[i]=b[i];
		if(b[i]<bmin){
			bmin=b[i];
		}
		if(b[i]>bmax){
			bmax=b[i];
		}
	}
	for(int zzz=0;zzz<=q;zzz++){
		if(c==1||c==2){
			if((an[1]<bn[1]&&an[n]<bn[m])||(an[1]>bn[1]&&an[n]>bn[m])){
				putchar('1');
			}else{
				putchar('0');
			}
		}else{
			amin=M,bmin=M,amax=0,bmax=0;
			for(ll i=1;i<=n;i++){
				if(an[i]<amin){
					amin=an[i];
				}
				if(an[i]>amax){
					amax=an[i];
				}
			}
			for(ll i=1;i<=m;i++){
				if(bn[i]<bmin){
					bmin=bn[i];
				}
				if(bn[i]>bmax){
					bmax=bn[i];
				}
			}
			cnt=0;
			if(an[1]>bn[1]){
				cnt++;
			}
			if(an[n]>bn[m]){
				cnt++;
			}
			if(amin>bmin){
				cnt++;
			}
			if(amax>bmax){
				cnt++;
			}
			if(cnt==0||cnt==4){
				putchar('1');
			}else{
				putchar('0');
			}
		}
		if(zzz==q){
			break;
		}
		e=read(),d=read();
		for(ll i=1;i<=n;i++){
			an[i]=a[i];
		}
		for(ll i=1;i<=m;i++){
			bn[i]=b[i];
		}
		for(ll i=1;i<=e;i++){
			x=read(),y=read();
			an[x]=y;
		}
		for(ll i=1;i<=d;i++){
			x=read(),y=read();
			bn[x]=y;
		}
	}
	printf("\n");
	return 0;
}
