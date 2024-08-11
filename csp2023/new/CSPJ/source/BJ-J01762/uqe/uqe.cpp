#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int t,m,r,k,a[N],b[N],c[N];
double gc;
inline bool isInt(double x){
	return x-floor(x)==0.0;
}
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%d%d",&t,&m);
	for(int i=0;i<t;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	for(int i=0;i<t;i++){
		if(b[i]==0&&c[i]==0) puts("0");
		else if(b[i]==0){
			if(c[i]>0) puts("NO");
			else{
				gc=sqrt(-c[i]);
				if(isInt(gc)) printf("%d\n",(int)gc/a[i]);
				else{
					r=-c[i];
					for(int j=-c[i]-1;j>0;j--){
						if((-c[i])%(j*j)==0){
							k=j; r=(-c[i])/(j*j);
							break;
						}
					}
					if(a[i]!=1){
						if(k!=0){
							if(isInt((double)k/a[i])) cout << k/a[i] << "*" <<"sqrt(" << r << ")\n";
							else{
								int g=gcd(a[i],k);
								a[i]/=g;
								k/=g;
								cout << k << "*" <<"sqrt(" << r << ")\n" << "/" << a[i];
							}
						}
						else cout << "sqrt(" << r << ")\n" << "/" << a[i];
					}
					else{
						if(k!=0) cout << k << "*" <<"sqrt(" << r << ")\n";
						else cout << "sqrt(" << r << ")\n";
					}
				}
			}
		}
		else if(c[i]==0) puts("0");
	}
	return 0;
}
