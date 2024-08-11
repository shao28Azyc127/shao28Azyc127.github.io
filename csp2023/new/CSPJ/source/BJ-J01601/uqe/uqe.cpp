#include <bits/stdc++.h>
using namespace std;
void fileio(string fname){
	string in=fname+".in",out=fname+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}
#define LD long double
const LD eps=1e-8;
const int N=5e6+10;
int M,cnt,prime[N];bool del[N];
void init(){
	for(int i=2;i<N;++i){
		if(!del[i]){
			prime[cnt++]=i;
		}
		for(int j=0;j<cnt && prime[j]<=N/i;++j){
			del[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void write(int a,int b){
	int d=gcd(a,b);
	a/=d,b/=d;
	if(b==1){
		printf("%d",a);
		return;
	}
	if(b<0){
		b*=-1,a*=-1;
	}
	printf("%d/%d",a,b);
}
void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int delta=1.*b*b-4.*a*c;
	if(delta<0){
		cout<<"NO\n";
		return;
	}
	// cout<<delta<<' ';
	int q2=1,tmp=delta,j=0;
	while(tmp>1){
		if(tmp%prime[j]==0){
			int tcnt=0,res=1;
			while(tmp%prime[j]==0){
				tcnt++;
				tmp/=prime[j];
				res*=prime[j];
			}
			if(!(tcnt&1)){
				q2*=sqrt(res);
			}
			else{
				res/=prime[j];
				q2*=sqrt(res);
			}
		}
		j++;
	}
	int r=delta/(q2*q2);b=-b;
	// cout<<q2<<'\n';
	
	// if(!r){
	// 	b+=(q2/a2);
	// 	write(b,a*2);
	// 	return;
	// }
	if(r==1){
		b+=(a*2);
	}
	if(b!=0){
		write(b,a*2);
		// if(delta!=0){
		// 	printf("+");
		// }
	}
	if(q2==a*2 && r!=1){
		if(delta!=0 && a>0){
			putchar('+');
		}
		else if(a<0){
			putchar('-');
		}
		printf("sqrt(%d)\n",r);
		return;
	}
	if(q2%(a*2)==0 && r!=1){
		int temp=q2/(a*2);
		if(delta!=0 && a>0){
			if(temp>0){
				putchar('+');
			}
			else{
				putchar('-');
				temp=-temp;
			}
		}
		else if(a<0){
			if(temp>0){
				putchar('-');
			}
			else{
				putchar('+');
				temp=-temp;
			}
		}
		if(temp==1){
			printf("sqrt(%d)\n",r);
			return;
		}
		printf("%d*sqrt(%d)\n",temp,r);
		return;
	}
	if((a*2)*q2==0 && r!=1){
		if(delta!=0 && a>0){
			putchar('+');
		}
		else if(a<0){
			putchar('-');
		}
		printf("sqrt(%d)",r);
		if((a*2)/q2!=1){
			printf("/%d",(a*2)/q2);
		}
		putchar('\n');
		return;
	}
	puts("");
	//
	// if(!r) return;
	// if(a2<0) a2*=-1,q2*=-1;
	// if(a2>0)putchar('+');
	// else putchar('-');
	// if(q2!=1) printf("%d*",q2);
	// if(r!=1)printf("sqrt(%d)",r);
	// if(a2!=1 && r!=0) printf("/%d",a2);
	// puts("");
}
signed main(){
	fileio("uqe");
	init();
	int TestCase=1;
	scanf("%d%d",&TestCase,&M);
	while(TestCase--){
		solve();
	}
	return 0;
}