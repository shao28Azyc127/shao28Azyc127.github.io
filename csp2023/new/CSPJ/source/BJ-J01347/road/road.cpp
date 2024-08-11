#include<iostream>
#include<cstdio>
using namespace std;
int n,m,o1[10001],q=0,y=0,nn=1;
int a[10001],b[10001];
void kaishi(int p){
	if(p==n) return;
	int u=1,shu=0;
	for(int i=p+1;i<=n;i++){
		int t=y;
		if(b[i]<b[p]&&y<a[p]){
			for(int j=p;j<i;j++){
				y+=o1[j]*m;
				shu+=a[j];
			}
			for(int j=1;j<=n;j++){
				if(y-m>=shu) y-=m;
				else break;
			}
			q+=(y-t)/m*b[p];
			for(int j=1;j<=n;j++){
				if(y-m>=shu) y-=m;
				else break;
			}
			break;
		}
		u++;
	}
	y-=a[p];
	kaishi(p+1);
	return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<n;i++){
		o1[i]=(a[i]%m==0?a[i]/m:a[i]/m+1);
	}
	kaishi(nn);
	cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}