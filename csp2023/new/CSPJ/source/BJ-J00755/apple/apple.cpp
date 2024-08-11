#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,ans=0,take_n,c=0;
bool flag=0;
int main() {
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	while(n>0) {
		ans++;
		if(n%3==1&&!flag) {
			take_n=ans;
			flag=1;
		}
		n-=(n-1)/3+1;
	}
	cout<<ans<<" "<<take_n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}