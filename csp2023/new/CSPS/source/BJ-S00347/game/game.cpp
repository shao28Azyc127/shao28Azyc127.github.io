#include<bits/stdc++.h>
using namespace std;
int n;
char a[2000010],b[2000010];
bool check(int s){
	while(s){
		for(int i=1; i<=s; ++i){
			if(i==s)
				return 0;
			if(b[i]==b[i+1]){
				for(int j=i+2; j<=s; ++j)
					b[j-2]=b[j];
				break;
			}
		}
		s-=2;
	}
	return 1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",a+1);
	int res=0;
	for(int i=1; i<n; ++i){
		for(int j=i+1; j<=n; j+=2){
			for(int k=i; k<=j; ++k)
				b[k-i+1]=a[k];
			if(check(j-i+1)){
				++res;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}