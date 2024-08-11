#include<bits/stdc++.h>
using namespace std;
int ans;
int n;
int a[10];
bool change(int x,int y){
	int a1=x/10000,a2=x/1000%10,a3=x/100%10,a4=x/10%10,a5=x%10;
	int b1=y/10000,b2=y/1000%10,b3=y/100%10,b4=y/10%10,b5=y%10;
	if(a1==b1&&a2==b2&&a3==b3&&a4==b4&&a5==b5){
		return 0;
	}
	if(a1!=b1&&a2==b2&&a3==b3&&a4==b4&&a5==b5){
		return 1;
	}
	if(a1==b1&&a2!=b2&&a3==b3&&a4==b4&&a5==b5){
		return 1;
	}
	if(a1==b1&&a2==b2&&a3!=b3&&a4==b4&&a5==b5){
		return 1;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4!=b4&&a5==b5){
		return 1;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4==b4&&a5!=b5){
		return 1;
	}
	if(a1!=b1&&a2!=b2&&a3==b3&&a4==b4&&a5==b5){
		if(a1-b1==a2-b2){
			return 1;
		}
		return 0;
	}
	if(a1==b1&&a2!=b2&&a3!=b3&&a4==b4&&a5==b5){
		if(a3-b3==a2-b2){
			return 1;
		}
		return 0;
	}
	if(a1==b1&&a2==b2&&a3!=b3&&a4!=b4&&a5==b5){
		if(a3-b3==a4-b4){
			return 1;
		}
		return 0;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4!=b4&&a5!=b5){
		if(a4-b4==a5-b5){
			return 1;
		}
		return 0;
	}
	return 0;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			int tmp;
			scanf("%d",&tmp);
			a[i]=a[i]*10+tmp;
		}
	}
	if(n==1){
		printf("%d",81);
		return 0;
	}
	for(int i=0;i<=99999;i++){
		bool flag=0;
		for(int j=1;j<=n;j++){
			if(!change(a[j],i)){
				flag=1;
				break;
			}
		}
		if(!flag){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
