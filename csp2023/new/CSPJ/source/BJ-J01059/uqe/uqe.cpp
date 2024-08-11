#include<bits/stdc++.h>
using namespace std;
int a,b,c,t,m;
int dt;
double x;
bool yn(int a){
	int b=sqrt(a);
	if(a==b*b)return 1;
	else return 0;
}
int main(){
	//freopen("uqe.in","r",stdin);
	//freopen("uqe.out","w",stdout);
	scanf("%d%d",&t,&m);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		/*dt=b*b-4*a*c;
		if(dt<0){
			printf("NO");
			continue;
		}else{
			x=-b+sqrt(dt)/(2*a);
			if(yn(dt)){
				int q=1;
				double p=1;
				while(q++){
					if(q*x==(int)(q*x))break;
				}
				while(p++){
					if(p/q==x)break;
				}
				if(q==1)printf("%d",(int)p);
				else printf("%d/%d",(int)p,q);
			}else{
				
			}
		}*/
	}
	cout<<0;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
