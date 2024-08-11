#include<iostream>
using namespace std;
int n=0,d=0,u[100005],a[100005],p=0,num=1,sum=0,x=0;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>u[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n]=100005;
	p=(num*u[1]-sum)/d;
	if((num*u[1]-sum)%d!=0){
		p++;
	}
	x+=p*a[1];
	sum+=(p*d)%u[1];
	sum%=d;
	num=1;
	cout<<num<<"\n";
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			num++;
			p=(num*u[i]-sum)/d;
			if((num*u[i]-sum)%d!=0){
				p++;
			}
			x+=p*a[i];
			sum+=(p*d)%u[i];
			sum%=d;
			num=1;
		}
	}
	cout<<x;
	return 0;
}
