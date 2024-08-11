#include<bits/stdc++.h>
using namespace std;
int n,len;struct Node{int x1,x2,x3,x4,x5;}a[100],zt[100];
struct P{int nu1,bh,nu2;};
void csh(){
	for(int i=1;i<=9;i++){
		zt[++len].x1=(a[1].x1+i)%10;
		zt[len].x2=a[1].x2;zt[len].x3=a[1].x3;
		zt[len].x4=a[1].x4;zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x2=(a[1].x2+i)%10;
		zt[len].x1=a[1].x1;zt[len].x3=a[1].x3;
		zt[len].x4=a[1].x4;zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x3=(a[1].x3+i)%10;
		zt[len].x2=a[1].x2;zt[len].x1=a[1].x1;
		zt[len].x4=a[1].x4;zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x4=(a[1].x4+i)%10;
		zt[len].x2=a[1].x2;zt[len].x3=a[1].x3;
		zt[len].x1=a[1].x1;zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x5=(a[1].x5+i)%10;
		zt[len].x2=a[1].x2;zt[len].x3=a[1].x3;
		zt[len].x4=a[1].x4;zt[len].x1=a[1].x1;
	}for(int i=1;i<=9;i++){
		zt[++len].x1=(a[1].x1+i)%10;
		zt[len].x2=(a[1].x2+i)%10;
		zt[len].x3=a[1].x3;
		zt[len].x4=a[1].x4;
		zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x3=(a[1].x3+i)%10;
		zt[len].x2=(a[1].x2+i)%10;
		zt[len].x1=a[1].x1;
		zt[len].x4=a[1].x4;
		zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x3=(a[1].x3+i)%10;
		zt[len].x4=(a[1].x4+i)%10;
		zt[len].x1=a[1].x1;
		zt[len].x2=a[1].x2;
		zt[len].x5=a[1].x5;
	}for(int i=1;i<=9;i++){
		zt[++len].x4=(a[1].x4+i)%10;
		zt[len].x5=(a[1].x5+i)%10;
		zt[len].x3=a[1].x3;
		zt[len].x1=a[1].x1;
		zt[len].x2=a[1].x2;
	}
}
bool check1(Node x,Node y){
	P d[10];int s=0;
	if(x.x1!=y.x1)d[++s].nu1=x.x1,d[s].bh=1,d[s].nu2=y.x1;
	if(x.x2!=y.x2)d[++s].nu1=x.x2,d[s].bh=2,d[s].nu2=y.x2;
	if(x.x3!=y.x3)d[++s].nu1=x.x3,d[s].bh=3,d[s].nu2=y.x3;
	if(x.x4!=y.x4)d[++s].nu1=x.x4,d[s].bh=4,d[s].nu2=y.x4;
	if(x.x5!=y.x5)d[++s].nu1=x.x5,d[s].bh=5,d[s].nu2=y.x5;
	if(s==1)return true;
	if(s==0)return false;
	if(s==2){
		if(abs(d[1].bh-d[2].bh)>1)return false;
		int c1=d[1].nu1-d[1].nu2,c2=d[2].nu1-d[2].nu2;
		if(c1==c2)return true;
		if(d[1].nu1<d[2].nu1){
			if((d[2].nu1-d[2].nu2)-(d[1].nu1-d[1].nu2)==10)return true;
		}if(d[1].nu1>d[2].nu1){
			if((d[1].nu1-d[1].nu2)-(d[2].nu1-d[2].nu2)==10)return true;
		}return false;
	}return false;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++){
		cin>>a[i].x1>>a[i].x2>>a[i].x3>>a[i].x4>>a[i].x5;
	}if(n==1){
		cout<<81<<endl;
		return 0;
	}len=0;csh();int ans=0,k=0;
	for(int ls=1;ls<=len;ls++){
		k=0;for(int i=2;i<=n;i++){
			if(!check1(a[i],zt[ls])){
				k=1;
			}
		}if(k==0)ans++;
	}cout<<ans<<endl;return 0;
}