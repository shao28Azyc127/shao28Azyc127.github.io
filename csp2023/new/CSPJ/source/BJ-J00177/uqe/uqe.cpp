#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>n>>m;
	for(int a,b,c;n--;){
		scanf("%d%d%d",&a,&b,&c);
		int dlt=b*b-4*a*c;
		int dlts=sqrt(dlt);
		if(dlt<0)printf("NO\n");
		else if(dlt==0){
			
			int gd=__gcd(-b,2*a);
			if((-b)*a<0)printf("-");
			if(gd==2*a)printf("%d\n",abs(-b)/abs(2*a));
			else printf("%d/%d\n",abs(-b/gd),abs(2*a/gd));
		}
		else {
			if(c==0){
				if(-b*a>0){
					int gd=__gcd(-b,a);
					if(gd==a)printf("%d\n",abs(-b)/abs(a));
					else printf("%d/%d\n",abs(-b/gd),abs(a/gd));
				}
				else printf("0\n");
			}
			else if(b==0){
				
			}
			else if(dlts*dlts==dlt){
				int gd=__gcd(-b+dlts,2*a);
				if((-b+dlts)*2*a<0)printf("-");
				if(gd==2*a)printf("%d\n",abs(-b+dlts)/abs(2*a));
				else printf("%d/%d\n",abs((-b+dlts)/gd),abs((2*a)/gd));
			}
		}
	}
	return 0;
}