#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],ans;
bool check(int x,int y){
	int z=x,w=0,k,c[7],di=0;
	for(int i=1;i<=5;i++) c[i]=0;
	while(z!=0){
		w++;
		z/=10;
	}
	k=5-w+1;
	for(int i=5;i>=k;i--){
		c[i]=x%10;
		x/=10;
	}
	//for(int i=1;i<=5;i++) cout<<c[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=5;i++)
		if(c[i]==a[y][i]) di++;
	if(di==4) return true;
	if(di==5||di<3) return false;
	int w1=0,w2=0,z1=0,z2=0;
	for(int i=1;i<=5;i++){
		if(c[i]!=a[y][i]){
			if(w1==0) w1=i;
			else w2=i;
		}
	}
	if(w1+1!=w2) return false;
	if(a[y][w1]<c[w1]) z1=9-c[w1]+1+a[y][w1];
	else z1=a[y][w1]-c[w1];
	if(a[y][w2]<c[w2]) z2=9-c[w2]+1+a[y][w2];
	else z2=a[y][w2]-c[w2];
	if(z1!=z2) return false;
	return true;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<=99999;i++){
		bool b=true;
		for(int j=1;j<=n;j++){
			if(!check(i,j)) b=false;
		}
		if(b==true) ans++;
	}
	cout<<ans;
	return 0;
}
