#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005],st[100005][20],st2[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=1;i--){
		st[i][0]=a[i];
	}
	for(int i=1;i<=n-1;i++){
		st2[i]+=v[i];
	}
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))-1][j-1]);
	int i=1,j=0,nu=0,mo=0;
	while(j!=n){
		while(st[i][j]<=st[i][j+1]){
			j++;
		}
		j--;
		mo+=((st2[j]-st2[i-1]-nu)/d+bool((st2[j]-st2[i-1]-nu)%d))*st[i][j];
		nu=(st2[j]-st2[i-1]-nu)%d;	
		j++;
		i=j;
	}
	cout<<mo;
	return 0;
}
