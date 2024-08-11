#include<bits/stdc++.h>
using namespace std;
int n,d,a[100001],b[100001],sum=0,num=0,min1=100005,min2;
int y=0,num1=0;
void r(int x,int i){
	if(x+i>n){
		if(y%d==0){
			num=y/d;
			num1+=num*d-y;
			if(num1/d==1){
				num--;
				num1=num1/d+num1%d;
			}
			sum+=b[x]*num;
		}
		else{
			num=y/d+1;
			num1+=num*d-y;
			if(num1/d==1){
				num--;
				num1=num1/d+num1%d;
			}
			sum+=b[x]*num;
		}
		return;
	}
	y=y+a[x+i-1];
	if(b[x+i]<b[x]){
		if(y%d==0){
			num=y/d;
			num1+=num*d-y;
			if(num1/d==1){
				num--;
				num1=num1/d+num1%d;
			}
			sum+=b[x]*num;
			//cout<<sum<<' '<<num<<' '<<num1<<endl;
		}
		else{
			num=y/d+1;
			num1+=num*d-y;
			if(num1/d==1){
				num--;
				num1=num1/d+num1%d;
			}
			sum+=b[x]*num;
			//cout<<sum<<' '<<num<<' '<<num1<<endl;
		}
		y=0;
		r(x+i,1);
	}
	else{
		r(x,i+1);
	}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&d);
    for(int i=1;i<n;i++){
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
    	scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]<min1){
			min1=b[i];
			min2=i;
		}
	}
	if(min2==1){
		int num1=0;
		for(int i=1;i<n;i++){
			num1+=a[i];
		}
		if(num1%d==0){
			cout<<num1/d*b[1];
			return 0;
		}
		else{
			cout<<(num1/d+1)*b[1];
			return 0;
		}
	}
	r(1,1);
	cout<<sum;
    return 0;
}
