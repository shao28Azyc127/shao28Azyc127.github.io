#include<bits/stdc++.h>
using namespace std;
long long top=1;
long long gcdt(long long x1,long long x2){
	long long i,minn=min(x1,x2);
	for(i=minn;i>=1;--i)
		if(x1%i==0&&x2%i==0)
			return i;
	return 1;
}
long long chai(long long d){
	long long yu=d,i;
	for(i=sqrt(d);i>=2;--i){
		if((yu%(i*i))==0){
			top*=i;
			yu=yu/(i*i);
		}
	}
	return yu;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	long long t,o,m,a,b,c;
	scanf("%lld%lld",&t,&m);
	for(o=1;o<=t;++o){
		scanf("%lld%lld%lld",&a,&b,&c);
		long long derta=b*b-(4*a*c);
		top=1;
		//cout<<sqrt(derta)<<endl;
		//无解
		if(derta<0){
			printf("NO\n");
			continue;
		}
		long long x=max(((-1)*b+sqrt(derta))/(2*a),((-1)*b-sqrt(derta))/(2*a));
		//方程解为整数
		if(x*x*a+b*x+c==0){
			printf("%lld\n",x);
			continue;
		}
		//derta为完全平方数
		long long p=sqrt(derta);
		if(p*p==derta){
			int t;
			if(a<0)
				t=(-1)*b-sqrt(derta);
			else//a>0
				t=(-1)*b+sqrt(derta);
			if((abs(t))%(abs(2*a))==0)
				printf("%lld\n",t/(-2*a));
			else{
				long long g=gcdt(abs(2*a),abs(t));
				//cout<<g<<endl;
				if(g<0)
					g*=(-1);
				if((t<0&&a<0)||(t>0&&a<0))
					printf("%lld/%lld\n",(-1)*t/g,(-2)*a/g);
				else
					printf("%lld/%lld\n",t/g,2*a/g);
			}
			continue;
		}
		int f=0;
		if((-1)*b!=0&&(2*a)!=0){
			f=1;
			if((abs(b))%(abs(2*a))==0)
				printf("%lld",(-1)*b/(2*a));
			else{
				long long g=gcdt(abs(2*a),abs(-1*b));
				if(g<0)
					g*=(-1);
				if(((-1*b)<0&&a<0)||((-1*b)>0&&a<0))
					printf("%lld/%lld",b/g,(-2)*a/g);
				else
					printf("%lld/%lld",(-1)*b/g,2*a/g);
			}
		}
		if(derta==0){
			printf("\n");
			continue;
		}
		long long ov=chai(derta); //top根号里剩余的 ov拆出来的
		swap(ov,top);
		if(a<0)//ov变号
			ov*=(-1);
		//cout<<"ov"<<ov<<endl;
		if((abs(ov))%(abs(2*a))==0){
			if(ov/(2*a)>0&&f==1)
				printf("+");
			if(ov/(2*a)!=1&&ov/(2*a)!=-1)
				printf("%lld*",ov/(2*a));
			//	printf("%d*sqrt(%d)\n",ov/(2*a),top);
			printf("sqrt(");
			printf("%lld",top);
			printf(")");
			printf("\n");
		}
		else{
			long long g=gcdt(abs(2*a),abs(ov));
			if(g<0)
				g*=(-1);
			if(f==1){
			if((ov*(-1)>0&&a<0)||(ov>0&&a>0))
				printf("+");
			else
				printf("-");
			}
			//printf("%d*sqrt(%d)/%d\n",(-1)*ov/g,top,(-2)*a/g);
			if((ov/g)!=1&&(ov/g)!=-1)
				printf("%lld*",abs(ov/g));
			printf("sqrt(");
			printf("%lld",top);
			printf(")/");
			if((2*a/g)!=1&&(2*a/g)!=-1)
				printf("%lld",abs(2*a/g));
			printf("\n");
			/*else{
				if(ov>0)
					printf("+");
				else
					printf("-");
				//printf("%d*sqrt(%d)/%d\n",ov/g,top,2*a/g);
				if((ov/g)!=1&&(ov/g)!=-1)
					printf("%d*",abs(ov/g));
				printf("sqrt(");
				printf("%d",top);
				printf(")/");
				if((2*a/g)!=1&&(2*a/g)!=-1)
					printf("%d",abs(2*a/g));
				printf("\n");
			}*/
		}
	}
	return 0;
}
