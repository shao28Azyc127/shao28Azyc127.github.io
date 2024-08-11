#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],l=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,v=1,mon=0;
	cin>>n>>m;
	for(int i=1;i<n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	while(v<n){
		int tmp=b[v],sum=a[v];
		while(b[v]<=b[v+1]){
			v++;
			sum+=a[v];
		}
		v++;
		int s=(sum+m-1-l)/m;
		mon+=s*tmp;
		l+=s*m;
		l-=sum;
	}
	cout<<mon;
}
