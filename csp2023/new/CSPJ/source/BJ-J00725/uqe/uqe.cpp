#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int x,int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(y,y%x);
}
int f(int n){
	int ans;
	for(int i=1;i*i<=n;i++){
		if(n%(i*i)==0) ans=i;
	}
	return ans;
}
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int del=b*b-4*a*c;
        if(del<0){
            printf("NO\n");
            continue;
        }
        if(sqrt(del)*sqrt(del)==del){
            int fm=2*a,fz=-b+sqrt(del);
            int tmp=gcd(fm,fz);
            fm/=tmp;
            fz/=tmp;
            if(fm==1) printf("%d\n",fz);
            else printf("%d/%d\n",fz,fm);
        }
        else{
            int fm=2*a;
            int fz=-b;
            if(fz!=0){
            	int tmp=gcd(fm,fz);
            	fm/=tmp;
            	fz/=tmp;
          	  	if(fm==1) printf("%d+",fz);
            	else printf("%d/%d+",fz,fm);
            }
            int fz2=f(del);
            if(fz2/fm==1 && fz2%fm==0){
            	printf("sqrt(%d)\n",del);
            }
            else{
            	int tmp=gcd(fm,fz2);
            	fm/=tmp;
            	fz2/=tmp;
            	if(fm==1) printf("%d*sqrt(%d)\n",fz2,del);
            	else if(fz==1) printf("sqrt(%d)/%d\n",del,fm);
            	else{
            		printf("%d*sqrt(%d)/%d\n",fz2,del,fm);
            	}
            }
        }
    }
    return 0;
}