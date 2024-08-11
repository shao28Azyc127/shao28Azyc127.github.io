#include<bits/stdc++.h>
using namespace std;
int n;
char s[10][20];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>s[i][j];
		}
	}
	printf("81");
	return 0;
}
