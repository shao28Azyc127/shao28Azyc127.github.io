#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
double x1,x2,a,b,c,dt,p1,p2;
int hhh(int dt){
	int vis[1010]={};
	int ans=1;
	for(int i=2;i*i<=dt;i++){
		while(dt%i==0){
			dt/=i;
			vis[i]++;
		}
	}
	for(int i=2;i*i<=dt;i++){
		if(vis[i]>=2){
			ans*=pow(i,vis[i]/2);
		}
	}
	return ans;
}
signed main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
  	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a,&b,&c);
		printf("%lld\n",i);
		dt=b*b-4*a*c;
		if(dt<0){
			printf("NO");
		}else{
			p1=(-b)/2*a;
			if(p1!=0){
				if(p1/1==p1){
					printf("%lld",(int)(p1));
				}else{
					printf("%lld/%lld",(int)(-b),(int)(2*a));
				}
			}
			p2=hhh(dt);
			if(p2!=1){
				if(p1!=0){
					printf("+");
				}
				printf("%lld*sqrt(%lld)",(int)(p2),(int)(dt/p2));
			}else{
				if(p1!=0){
					printf("+");
				}
				printf("sqrt(%lld)",(int)(dt/p2));
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
