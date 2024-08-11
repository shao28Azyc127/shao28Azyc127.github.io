#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int delta;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
bool check(int x){
	int tmp=sqrt(x);
	return tmp*tmp==x;
}
int func(int x){
	for(int i=1000;i>=1;i--){
		if(x%(i*i)==0){
			return i*i;
		}
	}
	return 1;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(false);
	int T,M;
	scanf("%d %d",&T,&M);
	while(T--){
		scanf("%d %d %d",&a,&b,&c);
		delta=b*b-4*a*c;
		if(delta<0){
			printf("NO\n");
		}else if(delta==0){
			if((b>0&&a>0)||(b<0&&a<0)){
				printf("-");
			}
			if(a<0){
				a=-a;
			}
			if(b<0){
				b=-b;
			}
			int d=gcd(b,2*a);
			b=b/d;
			a=a*2/d;
			if(a==1){
				printf("%d\n",b);
			}else{
				printf("%d/%d\n",b,a);
			}
		}else{
			if(check(delta)){
				delta=sqrt(delta);
				int p,q;
				if(a<0){
					int p1=-b+delta;
					int p2=-b-delta;
					if(p1>=0&&p2>=0){
						p=max(p1,p2);
					}else if(p1>=0&&p2<0){
						p=p2;
					}else if(p1<0&&p2>=0){
						p=p1;
					}else{
						p=min(p1,p2);
					}
				}else{
					p=-b+delta;
				}
				q=2*a;
				if(p==0){
					printf("0\n");
					continue;
				}else if((p>0&&q<0)||(p<0&&q>0)){
					printf("-");
				}
				if(p<0){
					p=-p;
				}
				if(q<0){
					q=-q;
				}
				int d=gcd(p,q);
				p/=d;
				q/=d;
				if(q==1){
					printf("%d\n",p);
				}else{
					printf("%d/%d\n",p,q);
				}
			}else{
				int A=2*a;
				if((b>0&&a>0)||(b<0&&a<0)){
					printf("-");
				}
				if(a<0){
					a=-a;
				}
				if(b<0){
					b=-b;
				}
				int d=gcd(b,2*a);
				b=b/d;
				a=a*2/d;
				if(b!=0){
					if(a==1){
						printf("%d",b);
					}else{
						printf("%d/%d",b,a);
					}
				}
				if(b!=0){
					printf("+");
				}
				if(A<0){
					A=-A;
				}
				int p=1,q=A;
				int D=func(delta);
				p*=sqrt(D);
				delta/=D;
				if(p==q){
					printf("sqrt(%d)\n",delta);
				}else if(p%q==0){
					printf("%d*sqrt(%d)\n",p/q,delta);
				}else{
					int d=gcd(p,q);
					p/=d;
					q/=d;
					if(p==1){
						printf("sqrt(%d)/%d\n",delta,q);
					}else{
						printf("%d*sqrt(%d)/%d\n",p,delta,q);
					}
				}
			}
		}
	}
	return 0;
}
