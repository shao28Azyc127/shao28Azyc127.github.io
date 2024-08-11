#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define ll long long
using namespace std;
inline int read(){int x=1,f=0;char ch=getchar();
    while(ch<'0' && ch>'9'){if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){f=f*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,M;
int gcd(int x,int y){
	if(x%y==0) return y;
	return gcd(y,x%y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
	T=read(),M=read();
	while(T--){
		int a=read(),b=read(),c=read();
		int qwq=pow(b,2)-4*a*c;
		if(qwq < 0){printf("NO\n");continue;}
		else printf("%d\n",(sqrt(qwq)-b)/(2*a));
	}
    return 0;
}
