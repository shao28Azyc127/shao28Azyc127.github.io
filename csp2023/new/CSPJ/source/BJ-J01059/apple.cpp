#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,x;
bool f;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	while(n){
		if(n%3==1&&!f){
			x=cnt;
			f=1;
		}
		n-=(n+2)/3;
		cnt++;
		
	}
	printf("%d %d",cnt-1,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
