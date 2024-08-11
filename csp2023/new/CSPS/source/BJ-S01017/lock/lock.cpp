#include<bits/stdc++.h>
using namespace std;
int a[10][10],s[105],top=0,vis[15],tot=0,all[15],sum[15];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=5;++j)
			scanf("%d",&a[i][j]);
	if(n==1){
		printf("81");
		return 0;
	}
	if(n==2){
		for(k=1;k<=5;++k)
			if(a[1][k]!=a[2][k])
				s[++top]=k;
		if(top==5){
				printf("0");
				return 0;
		}
		cout<<36<<endl;
		return 0;
	}
	for(i=1;i<n;++i){
		for(j=i+1;j<=n;++j){
			top=0;
			int f=0;
			for(k=1;k<=5;++k)
				if(a[j][k]!=a[i][k])
					s[++top]=k;
			if(top>2){
				printf("0");
				return 0;
			}
			for(k=1;k<=tot;++k){
				if(all[k]==s[1]){
					f=1;
					sum[k]++;
					break;
				}
			}
			if(f==0)
				all[++tot]=s[1],sum[tot]=1;
			f=0;
			for(k=1;k<=tot;++k){
				if(all[k]==s[2]){
					f=1;
					sum[k]++;
					break;
				}
			}
			if(f==0)
				all[++tot]=s[2],sum[tot]=1;
		}
	}
	if(tot>2)
		printf("0");
	else{
		printf("%d",(10-sum[1])+(10-sum[2]));
	}
	return 0;
}
