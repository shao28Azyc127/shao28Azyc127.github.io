#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,p1,q1,x,r,q2;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%d %d",&t,&m);
	for(int s=0;s<t;s++){
		scanf("%d %d %d",&a,&b,&c);
		r=b*b-4*a*c;
		if(r<0){
			printf("NO\n");
			continue;
		}
		if(a<0){
			a=0-a;
			b=0-b;
			c=0-c;
		}
		if(r==0){
			p1=0-b;
			q1=2*a;
			if(p1%q1==0){
				p1=p1/q1;
				q1=1;
			}
			for(int i=2;i<=sqrt(q1);i++){
				while(q1%i==0&&p1%i==0){
					q1=q1/i;
					p1=p1/i;
				}
			}
			if(q1==1){
				printf("%d\n",p1);
			}
			else{
				printf("%d/%d\n",p1,q1);
			}
		}
		else{
			p1=0-b;
			q1=2*a;
			x=1;
			q2=2*a;
			for(int i=2;i<=sqrt(r);i++){
				while(r%(i*i)==0){
					r=r/(i*i);
					x*=i;
				}
			}
			if(r==1){
				p1+=x;
				if(p1%q1==0){
					p1=p1/q1;
					q1=1;
				}
				for(int i=2;i<=sqrt(q1);i++){
					while(q1%i==0&&p1%i==0){
						q1=q1/i;
						p1=p1/i;
					}
				}
				if(q1==1){
					printf("%d\n",p1);
				}
				else{
					printf("%d/%d\n",p1,q1);
				}	
			}
			else{
				if(p1!=0){
					if(p1%q1==0){
						p1=p1/q1;
						q1=1;
					}
					for(int i=2;i<=sqrt(q1);i++){
						while(q1%i==0&&p1%i==0){
							q1=q1/i;
							p1=p1/i;
						}
					}
					if(q1==1){
						printf("%d+",p1);
					}
					else{
						printf("%d/%d+",p1,q1);
					}
				}
				if(x%q2==0){
					x=x/q2;
					q2=1;
				}
				for(int i=2;i<=sqrt(q2);i++){
					while(q2%i==0&&x%i==0){
						q2=q2/i;
						x=x/i;
					}
				}
				if(x==1&&q2==1){
					printf("sqrt(%d)\n",r);
				}
				else if(x==1){
					printf("sqrt(%d)/%d\n",r,q2);
				}
				else if(q2==1){
					printf("%d*sqrt(%d)\n",x,r);
				}
				else{
					printf("%d*sqrt(%d)/%d\n",x,r,q2);
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}