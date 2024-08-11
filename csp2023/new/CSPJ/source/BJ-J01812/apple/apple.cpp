#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;
int a1,a2;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	cnt=n;
	while(cnt!=0){
		++a1;
		if(cnt%3==1){
			if(a2==0){
				a2=a1;
			}
		}
		cnt-=(cnt-1)/3+1;
	}
	printf("%d %d",a1,a2);
	return 0;
}
