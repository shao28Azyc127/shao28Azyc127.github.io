#include <bits/stdc++.h>
using namespace std;
int n,d,nd,a;
bool flag;

int e(int x){
	if(x%3!=0){
		return x/3+1;
	}
	else{
		return x/3;
	}
}

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	
	if(n%3-1==0){
		flag=true;
	}
	
	a=n;
	while(1){
		//printf("%d",a);
		nd++;
		a=a-e(a);
		//printf("a=%d nd=%d",a,nd);
		//if(a%3-1==0) break;
		if(a%3-1==0) break;
	}
	a=n;
	while(a>0){
		//printf("%d",a);
		d++;
		a-=e(a);
		if(a==0) break;
	}
	cout << d << " ";
	
	if(flag){
		cout << 1;
	}
	else{
		cout << nd+1;
	}
	return 0;
}
