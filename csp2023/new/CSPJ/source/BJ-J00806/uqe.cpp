#include<bits/stdc++.h>
using namespace std;
int q,p,q1,q2,q3,r;
void gcd(){
	int f1=0,f2=0;
	if(q<0) f1=1;
	if(p<0) f2=1;
	q=abs(q);
	p=abs(p);
	for(int i=2;i<=min(p,q);i++){
		if(p%i==0&&q%i==0){
			while(1){
				if(p%i!=0||q%i!=0) break;
				p/=i;
				q/=i;
			}
		}
	}
	if(f1==1) q*=-1;
	if(f2==1) p*=-1;
}
void pp(){
	int i=2;
	while(1){
		if(i*i>=q2) break;
		while(1){
			i++;
			if(int(sqrt(i))==sqrt(i)) break;
		}
		if(q2%i==0)
			while(q2%i!=0){q2/=i;r*=sqrt(i);}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m,a,b,c,derta;
	float x1,x2;
	scanf("%d%d",&t,&m);
	for(int i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		derta=b*b-4*a*c;
		if(derta<0) printf("NO\n");
		else{
			x1=(sqrt(derta)-b)/(2*a);
			x2=(-1*sqrt(derta)-b)/(2*a);
			if(x2*x2*a+x2*b+c==0||x2*x2*a+x2*b+c==0){
				if(x1>x2){
					q=sqrt(derta)-b;
					p=2*a;
				}
				else{
					q=derta-b;
					p=2*a;
				}
				swap(p,q);
				gcd();
				if(q==1) printf("%d",p);
				else printf("%d/%d",p,q);
			}
			else{
				if(x1>x2){
					swap(x1,x2);
				}
				q1=x2-int(x2);
				q2=(x2-q1)*(x2-q1);
				r=1;
				pp();
				if(q1!=0){
					if(x1>x2){
						q1=sqrt(derta)-b;
						p=2*a;
					}
					else{
						q1=derta-b;
						p=2*a;
					}
					swap(q1,p);
					gcd();
					if(q1==1) printf("%d+",p);
					else printf("%d/%d+",p,q1);
				}
				if(q2==1) printf("sqrt(%d)",r);
				else if(1/q2==int(1/q2)) printf("sqrt(%d)/%d",r,int(1.0/q2));
				else printf("%d*sqrt(%d)",int(q2),r);
			}
			printf("\n");
		}
	}
	return 0;
}
