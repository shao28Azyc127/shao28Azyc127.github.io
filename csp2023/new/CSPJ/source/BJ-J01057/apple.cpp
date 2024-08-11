#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id,z=1;
}a[1000005];
bool cmp(node x,node y){
	if(x.z!=y.z) return x.z>y.z;
	return x.id<y.id;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int x=n;
	int c=0,c1;
	for(int i=1;i<=n;i++){
		a[i].id=i;
	}
	while(x!=0){
		c++;
		int b=0;
		for(int i=1;i<=x;i+=3){
			if(a[i].z==0) break;
			a[i].z=0;
			if(a[i].id==n) c1=c;
			b++;
		}
		x-=b;
		sort(a+1,a+n+1,cmp);
	}
	cout<<c<<" "<<c1;
	return 0;
}