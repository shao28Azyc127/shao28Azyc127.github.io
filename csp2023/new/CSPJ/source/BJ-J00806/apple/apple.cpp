#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	scanf("%d",&n);
	int m=n,ans=0,day=0,cnt=0;
	while(n!=0){
		cnt=(n-1)/3;
		if(cnt!=0){
			if(3*cnt+1==m&&ans==0) ans=day+1;
			n=n-cnt-1;
		}
		else{
			day+=n;
			if(ans==0) ans=day;
			n=0;
		}
		day++;
	}
	printf("%d %d",day-1,ans);
	//if(system("diff apple.out apple.ans")) printf("AC");
	//else printf("WA");
	return 0;
}