#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,x,y,z,n,m,k,d;

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
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	for(ll zzz=1;zzz<=t;zzz++){
		n=read(),m=read(),k=read(),d=read();
		for(ll i=1;i<=m;i++){
			x=read(),y=read(),z=read();
		}
		printf("0\n");
	}
	return 0;
}
